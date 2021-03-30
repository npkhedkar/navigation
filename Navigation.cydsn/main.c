/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "stdio.h"

// Error checking - FINAL mean Speed
int ticks = 0;
double time = 0;

// Constants
double PI = 3.141592;       // pi approximation
double LENGTH = 0.12435;    //(D=2.375in) in ft (distance to travel 1/5 of a rotation)
double FREQ = 10000;        // clock freqency
double COUNTDOWN = 65536;   // max of 8-bit counter for Timer module
int ON = 255;               // sets pwm to 255
int OFF = 0;                // sets pwm to 0
int TICKCUTOFF = 338;       // maximum number of ticks seen before robot stops moving

// used to deal with countdown timer underflow issues
int oldTime = 0;
int currentTime = 0;


double setSpeed = 2.0;      // optimal speed target [ft/s]
double KP = 280;            // proportional control param
double KI = 5;              // integral control param
double KD = 15;             // derivative control param

char strbuf[16];            // buffer for lcd display
char uartbuf[128];          // buffer for UART remote data collection

double eTime;               // elapsed time
double speed;               // current calculated speed
double error;               // delta between current speed and optimal speed

double oldError = 4.0;      // error memory used in derivative control
double errorDiff;           // error delta for old and current error used in derivative control

double sum = 0;             // error sum used in integral control
double avgError;            // avg error used in integral control

double dutyCycle;           // outputed duty cycle

double lineTime;            // time to detect line in a given row
int PICWIDTH = 320;         // number of pixels going sideways across a video image
int PICHEIGHT = 240;        // number of pixels going down a video image
int FPS = 30;               // frames per second
int LPF = 525;              // number of lines per frame (standard)
int LPS;                    // lines per second (LPF * FPS)
double HFREQ;               // frequency of line reads
int VFREQ = 60;             // frequency of frame reads
int OEFREQ = 30;            // frequency of original frame reads (since 2 copies per frame)

// interrupt flags
int hallFlag = 0;
int blackFlag = 0;

// navigation
double firstPixelTime = 445; // the location (in timer) of the left edge of the black line
int CENTERSERVO = 155;     // default PWM setting for the center servo
int setservo;              // saves the current servo alignment
int oldsetservo = 155;
double servoKP = 1;
double servoKI;
double servoKD;

double pixelError;



// interrupt sets hall flag to 1 when magnet is passed over HE
CY_ISR(inter1) {
    hallFlag = 1;
    Timer_ReadStatusRegister();
}

CY_ISR(inter2) {
    VideoTimer_ReadStatusRegister(); // reset blackflag register 
}

CY_ISR(inter3) {
    blackFlag = 1;
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    char strbuf[16];
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    LCD_Start();
    HE_Interrupt_Start();
    HE_Interrupt_SetVector(inter1);
    Timer_Start();
    UART_Start();
    PWM_Start();
    
    // VideoTimer
    VideoTimer_Start();
    
    // VDAC
    VDAC_Start();
    VDAC_SetSpeed(VDAC_LOWSPEED);
    VDAC_SetRange(VDAC_RANGE_1V);
    VDAC_SetValue(128);
    
    // Comparator
    Comp_Start();
    Comp_SetSpeed(Comp_HIGHSPEED);
    
    // Servo PWM
    ServoPWM_Start();
    ServoPWM_WriteCompare(CENTERSERVO);
    
    // Video Frame Interrupt
    NewFrame_Start();
    NewFrame_SetVector(inter2);
    
    // Black Edge Interrupt
    Black_Start();
    Black_SetVector(inter3);
    
    /*
    PWM_WriteCompare(200);
    
    sprintf(strbuf,"Optimal speed: %.0f,", setSpeed);
    LCD_Position(0,0);
    LCD_PrintString(strbuf);
    */
    
    int blackTime;

    for(;;)
    {
        if (blackFlag == 1) { // collect data
            blackTime = COUNTDOWN - VideoTimer_ReadCapture();
            
            /*
            // Bang Bang test
            if (blackTime < 440) {
                setservo = 100; // go left
            } else if (blackTime > 450) {
                setservo = 198; // go right
            } else {
                setservo = 155; // go straight
            }
            ServoPWM_WriteCompare(setservo);
            */
            /*
            // print black timer (UART)
            sprintf(uartbuf, "Black edge Time: %d\n", blackTime);
            UART_PutString(uartbuf);
            */
            
            // PID Control
            oldsetservo = setservo;
            pixelError = firstPixelTime - blackTime;
            setservo = -5 * pixelError + 155; // kp = -10
            if (setservo > 198) {setservo = 198; }
            else if (setservo < 105 || oldsetservo - setservo > 105) {setservo = 105; }
            ServoPWM_WriteCompare((uint8) setservo);
            
            // LCD out
            LCD_ClearDisplay();
            sprintf(strbuf, "Location: %d,", blackTime);
            LCD_PrintString(strbuf);
            
            // reset flag
            blackFlag = 0;    
        }
        
        if(hallFlag == 1){
            // Stops robot movement after predetermined number of ticks (~40 feet)
            if(ticks > TICKCUTOFF) {
                sprintf(uartbuf, "Total Time: %.3f, Length: %.3f\n", time, ticks*LENGTH);
                UART_PutString(uartbuf);
                PWM_WriteCompare(0);
                
                // kills UART reciver
                UART_PutString("&&&");
            }
            else {    
                // deals with timer underflow
                currentTime = Timer_ReadCapture();
                if (currentTime >= oldTime)
                    oldTime += COUNTDOWN;
                
                // elapsed time calc
                eTime = (oldTime - currentTime)/FREQ;
                oldTime = currentTime;
                
                // accounting for total ticks and time (used for final mean speed confirmation)
                ticks += 1;
                time += eTime;
                
                speed = LENGTH/eTime; // current speed [ft/s]
                
                // used for bench testing psoc speed functionality
                LCD_ClearDisplay();
                sprintf(strbuf,"%-16.4f",speed);
                LCD_Position(0,0);
                LCD_PrintString(strbuf);
                
                // used in kp error
                error = setSpeed - speed;
                
                // used in ki error
                sum += error;             
                avgError = sum / ticks;
 
                // used in kd error
                errorDiff = error - oldError;
                oldError = error;
                
                // controller response
                dutyCycle = KP*error + KI*avgError + KD*errorDiff;
                
                // ensures that the duty cycle is within the range [0,255]
                if(dutyCycle > 255) { dutyCycle = ON;}
                else if(dutyCycle < 0) { dutyCycle = OFF;}
                dutyCycle = (uint8) dutyCycle;
               
                // output duty cycle
                PWM_WriteCompare(dutyCycle);
                
                // remote UART data collection
                sprintf(uartbuf, "Tick Num: %5d, Current Speed: %5.2f, Error: %5.2f, Duty Cycle: %5.2f, eTime: %5.4f\n", ticks, speed, error, dutyCycle, eTime);
                UART_PutString(uartbuf);
            }
            
            // stop interrupt
            hallFlag = 0;
        }
        
      
        
       
    }
}

/* [] END OF FILE */
