/*******************************************************************************
* File Name: VideoTimerL.h
* Version 2.80
*
*  Description:
*     Contains the function prototypes and constants available to the timer
*     user module.
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_TIMER_VideoTimerL_H)
#define CY_TIMER_VideoTimerL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 VideoTimerL_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Timer_v2_80 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults
**************************************/

#define VideoTimerL_Resolution                 16u
#define VideoTimerL_UsingFixedFunction         0u
#define VideoTimerL_UsingHWCaptureCounter      0u
#define VideoTimerL_SoftwareCaptureMode        0u
#define VideoTimerL_SoftwareTriggerMode        0u
#define VideoTimerL_UsingHWEnable              1u
#define VideoTimerL_EnableTriggerMode          0u
#define VideoTimerL_InterruptOnCaptureCount    1u
#define VideoTimerL_RunModeUsed                0u
#define VideoTimerL_ControlRegRemoved          0u

#if defined(VideoTimerL_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG)
    #define VideoTimerL_UDB_CONTROL_REG_REMOVED            (0u)
#elif  (VideoTimerL_UsingFixedFunction)
    #define VideoTimerL_UDB_CONTROL_REG_REMOVED            (0u)
#else 
    #define VideoTimerL_UDB_CONTROL_REG_REMOVED            (1u)
#endif /* End VideoTimerL_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG */


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for Timer Component
 *************************************************************************/
typedef struct
{
    uint8 TimerEnableState;
    #if(!VideoTimerL_UsingFixedFunction)

        uint16 TimerUdb;
        uint8 InterruptMaskValue;
        #if (VideoTimerL_UsingHWCaptureCounter)
            uint8 TimerCaptureCounter;
        #endif /* variable declarations for backing up non retention registers in CY_UDB_V1 */

        #if (!VideoTimerL_UDB_CONTROL_REG_REMOVED)
            uint8 TimerControlRegister;
        #endif /* variable declaration for backing up enable state of the Timer */
    #endif /* define backup variables only for UDB implementation. Fixed function registers are all retention */

}VideoTimerL_backupStruct;


/***************************************
*       Function Prototypes
***************************************/

void    VideoTimerL_Start(void) ;
void    VideoTimerL_Stop(void) ;

void    VideoTimerL_SetInterruptMode(uint8 interruptMode) ;
uint8   VideoTimerL_ReadStatusRegister(void) ;
/* Deprecated function. Do not use this in future. Retained for backward compatibility */
#define VideoTimerL_GetInterruptSource() VideoTimerL_ReadStatusRegister()

#if(!VideoTimerL_UDB_CONTROL_REG_REMOVED)
    uint8   VideoTimerL_ReadControlRegister(void) ;
    void    VideoTimerL_WriteControlRegister(uint8 control) ;
#endif /* (!VideoTimerL_UDB_CONTROL_REG_REMOVED) */

uint16  VideoTimerL_ReadPeriod(void) ;
void    VideoTimerL_WritePeriod(uint16 period) ;
uint16  VideoTimerL_ReadCounter(void) ;
void    VideoTimerL_WriteCounter(uint16 counter) ;
uint16  VideoTimerL_ReadCapture(void) ;
void    VideoTimerL_SoftwareCapture(void) ;

#if(!VideoTimerL_UsingFixedFunction) /* UDB Prototypes */
    #if (VideoTimerL_SoftwareCaptureMode)
        void    VideoTimerL_SetCaptureMode(uint8 captureMode) ;
    #endif /* (!VideoTimerL_UsingFixedFunction) */

    #if (VideoTimerL_SoftwareTriggerMode)
        void    VideoTimerL_SetTriggerMode(uint8 triggerMode) ;
    #endif /* (VideoTimerL_SoftwareTriggerMode) */

    #if (VideoTimerL_EnableTriggerMode)
        void    VideoTimerL_EnableTrigger(void) ;
        void    VideoTimerL_DisableTrigger(void) ;
    #endif /* (VideoTimerL_EnableTriggerMode) */


    #if(VideoTimerL_InterruptOnCaptureCount)
        void    VideoTimerL_SetInterruptCount(uint8 interruptCount) ;
    #endif /* (VideoTimerL_InterruptOnCaptureCount) */

    #if (VideoTimerL_UsingHWCaptureCounter)
        void    VideoTimerL_SetCaptureCount(uint8 captureCount) ;
        uint8   VideoTimerL_ReadCaptureCount(void) ;
    #endif /* (VideoTimerL_UsingHWCaptureCounter) */

    void VideoTimerL_ClearFIFO(void) ;
#endif /* UDB Prototypes */

/* Sleep Retention APIs */
void VideoTimerL_Init(void)          ;
void VideoTimerL_Enable(void)        ;
void VideoTimerL_SaveConfig(void)    ;
void VideoTimerL_RestoreConfig(void) ;
void VideoTimerL_Sleep(void)         ;
void VideoTimerL_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Timer__CaptureModes, Used in Capture Mode */
#define VideoTimerL__B_TIMER__CM_NONE 0
#define VideoTimerL__B_TIMER__CM_RISINGEDGE 1
#define VideoTimerL__B_TIMER__CM_FALLINGEDGE 2
#define VideoTimerL__B_TIMER__CM_EITHEREDGE 3
#define VideoTimerL__B_TIMER__CM_SOFTWARE 4



/* Enumerated Type B_Timer__TriggerModes, Used in Trigger Mode */
#define VideoTimerL__B_TIMER__TM_NONE 0x00u
#define VideoTimerL__B_TIMER__TM_RISINGEDGE 0x04u
#define VideoTimerL__B_TIMER__TM_FALLINGEDGE 0x08u
#define VideoTimerL__B_TIMER__TM_EITHEREDGE 0x0Cu
#define VideoTimerL__B_TIMER__TM_SOFTWARE 0x10u


/***************************************
*    Initialial Parameter Constants
***************************************/

#define VideoTimerL_INIT_PERIOD             65535u
#define VideoTimerL_INIT_CAPTURE_MODE       ((uint8)((uint8)1u << VideoTimerL_CTRL_CAP_MODE_SHIFT))
#define VideoTimerL_INIT_TRIGGER_MODE       ((uint8)((uint8)0u << VideoTimerL_CTRL_TRIG_MODE_SHIFT))
#if (VideoTimerL_UsingFixedFunction)
    #define VideoTimerL_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << VideoTimerL_STATUS_TC_INT_MASK_SHIFT)) | \
                                                  ((uint8)((uint8)1 << VideoTimerL_STATUS_CAPTURE_INT_MASK_SHIFT)))
#else
    #define VideoTimerL_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << VideoTimerL_STATUS_TC_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)1 << VideoTimerL_STATUS_CAPTURE_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << VideoTimerL_STATUS_FIFOFULL_INT_MASK_SHIFT)))
#endif /* (VideoTimerL_UsingFixedFunction) */
#define VideoTimerL_INIT_CAPTURE_COUNT      (3u)
#define VideoTimerL_INIT_INT_CAPTURE_COUNT  ((uint8)((uint8)(1u - 1u) << VideoTimerL_CTRL_INTCNT_SHIFT))


/***************************************
*           Registers
***************************************/

#if (VideoTimerL_UsingFixedFunction) /* Implementation Specific Registers and Register Constants */


    /***************************************
    *    Fixed Function Registers
    ***************************************/

    #define VideoTimerL_STATUS         (*(reg8 *) VideoTimerL_TimerHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define VideoTimerL_STATUS_MASK    (*(reg8 *) VideoTimerL_TimerHW__SR0 )
    #define VideoTimerL_CONTROL        (*(reg8 *) VideoTimerL_TimerHW__CFG0)
    #define VideoTimerL_CONTROL2       (*(reg8 *) VideoTimerL_TimerHW__CFG1)
    #define VideoTimerL_CONTROL2_PTR   ( (reg8 *) VideoTimerL_TimerHW__CFG1)
    #define VideoTimerL_RT1            (*(reg8 *) VideoTimerL_TimerHW__RT1)
    #define VideoTimerL_RT1_PTR        ( (reg8 *) VideoTimerL_TimerHW__RT1)

    #if (CY_PSOC3 || CY_PSOC5LP)
        #define VideoTimerL_CONTROL3       (*(reg8 *) VideoTimerL_TimerHW__CFG2)
        #define VideoTimerL_CONTROL3_PTR   ( (reg8 *) VideoTimerL_TimerHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define VideoTimerL_GLOBAL_ENABLE  (*(reg8 *) VideoTimerL_TimerHW__PM_ACT_CFG)
    #define VideoTimerL_GLOBAL_STBY_ENABLE  (*(reg8 *) VideoTimerL_TimerHW__PM_STBY_CFG)

    #define VideoTimerL_CAPTURE_LSB         (* (reg16 *) VideoTimerL_TimerHW__CAP0 )
    #define VideoTimerL_CAPTURE_LSB_PTR       ((reg16 *) VideoTimerL_TimerHW__CAP0 )
    #define VideoTimerL_PERIOD_LSB          (* (reg16 *) VideoTimerL_TimerHW__PER0 )
    #define VideoTimerL_PERIOD_LSB_PTR        ((reg16 *) VideoTimerL_TimerHW__PER0 )
    #define VideoTimerL_COUNTER_LSB         (* (reg16 *) VideoTimerL_TimerHW__CNT_CMP0 )
    #define VideoTimerL_COUNTER_LSB_PTR       ((reg16 *) VideoTimerL_TimerHW__CNT_CMP0 )


    /***************************************
    *    Register Constants
    ***************************************/

    /* Fixed Function Block Chosen */
    #define VideoTimerL_BLOCK_EN_MASK                     VideoTimerL_TimerHW__PM_ACT_MSK
    #define VideoTimerL_BLOCK_STBY_EN_MASK                VideoTimerL_TimerHW__PM_STBY_MSK

    /* Control Register Bit Locations */
    /* Interrupt Count - Not valid for Fixed Function Block */
    #define VideoTimerL_CTRL_INTCNT_SHIFT                  0x00u
    /* Trigger Polarity - Not valid for Fixed Function Block */
    #define VideoTimerL_CTRL_TRIG_MODE_SHIFT               0x00u
    /* Trigger Enable - Not valid for Fixed Function Block */
    #define VideoTimerL_CTRL_TRIG_EN_SHIFT                 0x00u
    /* Capture Polarity - Not valid for Fixed Function Block */
    #define VideoTimerL_CTRL_CAP_MODE_SHIFT                0x00u
    /* Timer Enable - As defined in Register Map, part of TMRX_CFG0 register */
    #define VideoTimerL_CTRL_ENABLE_SHIFT                  0x00u

    /* Control Register Bit Masks */
    #define VideoTimerL_CTRL_ENABLE                        ((uint8)((uint8)0x01u << VideoTimerL_CTRL_ENABLE_SHIFT))

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define VideoTimerL_CTRL2_IRQ_SEL_SHIFT                 0x00u
    #define VideoTimerL_CTRL2_IRQ_SEL                      ((uint8)((uint8)0x01u << VideoTimerL_CTRL2_IRQ_SEL_SHIFT))

    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        /* As defined by Verilog Implementation */
        #define VideoTimerL_CTRL_MODE_SHIFT                 0x01u
        #define VideoTimerL_CTRL_MODE_MASK                 ((uint8)((uint8)0x07u << VideoTimerL_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Control3 Register Bit Locations */
        #define VideoTimerL_CTRL_RCOD_SHIFT        0x02u
        #define VideoTimerL_CTRL_ENBL_SHIFT        0x00u
        #define VideoTimerL_CTRL_MODE_SHIFT        0x00u

        /* Control3 Register Bit Masks */
        #define VideoTimerL_CTRL_RCOD_MASK  ((uint8)((uint8)0x03u << VideoTimerL_CTRL_RCOD_SHIFT)) /* ROD and COD bit masks */
        #define VideoTimerL_CTRL_ENBL_MASK  ((uint8)((uint8)0x80u << VideoTimerL_CTRL_ENBL_SHIFT)) /* HW_EN bit mask */
        #define VideoTimerL_CTRL_MODE_MASK  ((uint8)((uint8)0x03u << VideoTimerL_CTRL_MODE_SHIFT)) /* Run mode bit mask */

        #define VideoTimerL_CTRL_RCOD       ((uint8)((uint8)0x03u << VideoTimerL_CTRL_RCOD_SHIFT))
        #define VideoTimerL_CTRL_ENBL       ((uint8)((uint8)0x80u << VideoTimerL_CTRL_ENBL_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define VideoTimerL_RT1_SHIFT                       0x04u
    /* Sync TC and CMP bit masks */
    #define VideoTimerL_RT1_MASK                        ((uint8)((uint8)0x03u << VideoTimerL_RT1_SHIFT))
    #define VideoTimerL_SYNC                            ((uint8)((uint8)0x03u << VideoTimerL_RT1_SHIFT))
    #define VideoTimerL_SYNCDSI_SHIFT                   0x00u
    /* Sync all DSI inputs with Mask  */
    #define VideoTimerL_SYNCDSI_MASK                    ((uint8)((uint8)0x0Fu << VideoTimerL_SYNCDSI_SHIFT))
    /* Sync all DSI inputs */
    #define VideoTimerL_SYNCDSI_EN                      ((uint8)((uint8)0x0Fu << VideoTimerL_SYNCDSI_SHIFT))

    #define VideoTimerL_CTRL_MODE_PULSEWIDTH            ((uint8)((uint8)0x01u << VideoTimerL_CTRL_MODE_SHIFT))
    #define VideoTimerL_CTRL_MODE_PERIOD                ((uint8)((uint8)0x02u << VideoTimerL_CTRL_MODE_SHIFT))
    #define VideoTimerL_CTRL_MODE_CONTINUOUS            ((uint8)((uint8)0x00u << VideoTimerL_CTRL_MODE_SHIFT))

    /* Status Register Bit Locations */
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define VideoTimerL_STATUS_TC_SHIFT                 0x07u
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define VideoTimerL_STATUS_CAPTURE_SHIFT            0x06u
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define VideoTimerL_STATUS_TC_INT_MASK_SHIFT        (VideoTimerL_STATUS_TC_SHIFT - 0x04u)
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define VideoTimerL_STATUS_CAPTURE_INT_MASK_SHIFT   (VideoTimerL_STATUS_CAPTURE_SHIFT - 0x04u)

    /* Status Register Bit Masks */
    #define VideoTimerL_STATUS_TC                       ((uint8)((uint8)0x01u << VideoTimerL_STATUS_TC_SHIFT))
    #define VideoTimerL_STATUS_CAPTURE                  ((uint8)((uint8)0x01u << VideoTimerL_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on TC */
    #define VideoTimerL_STATUS_TC_INT_MASK              ((uint8)((uint8)0x01u << VideoTimerL_STATUS_TC_INT_MASK_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on Capture */
    #define VideoTimerL_STATUS_CAPTURE_INT_MASK         ((uint8)((uint8)0x01u << VideoTimerL_STATUS_CAPTURE_INT_MASK_SHIFT))

#else   /* UDB Registers and Register Constants */


    /***************************************
    *           UDB Registers
    ***************************************/

    #define VideoTimerL_STATUS              (* (reg8 *) VideoTimerL_TimerUDB_rstSts_stsreg__STATUS_REG )
    #define VideoTimerL_STATUS_MASK         (* (reg8 *) VideoTimerL_TimerUDB_rstSts_stsreg__MASK_REG)
    #define VideoTimerL_STATUS_AUX_CTRL     (* (reg8 *) VideoTimerL_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define VideoTimerL_CONTROL             (* (reg8 *) VideoTimerL_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    
    #if(VideoTimerL_Resolution <= 8u) /* 8-bit Timer */
        #define VideoTimerL_CAPTURE_LSB         (* (reg8 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define VideoTimerL_CAPTURE_LSB_PTR       ((reg8 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define VideoTimerL_PERIOD_LSB          (* (reg8 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define VideoTimerL_PERIOD_LSB_PTR        ((reg8 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define VideoTimerL_COUNTER_LSB         (* (reg8 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__A0_REG )
        #define VideoTimerL_COUNTER_LSB_PTR       ((reg8 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__A0_REG )
    #elif(VideoTimerL_Resolution <= 16u) /* 8-bit Timer */
        #if(CY_PSOC3) /* 8-bit addres space */
            #define VideoTimerL_CAPTURE_LSB         (* (reg16 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define VideoTimerL_CAPTURE_LSB_PTR       ((reg16 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define VideoTimerL_PERIOD_LSB          (* (reg16 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define VideoTimerL_PERIOD_LSB_PTR        ((reg16 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define VideoTimerL_COUNTER_LSB         (* (reg16 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__A0_REG )
            #define VideoTimerL_COUNTER_LSB_PTR       ((reg16 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define VideoTimerL_CAPTURE_LSB         (* (reg16 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__16BIT_F0_REG )
            #define VideoTimerL_CAPTURE_LSB_PTR       ((reg16 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__16BIT_F0_REG )
            #define VideoTimerL_PERIOD_LSB          (* (reg16 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__16BIT_D0_REG )
            #define VideoTimerL_PERIOD_LSB_PTR        ((reg16 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__16BIT_D0_REG )
            #define VideoTimerL_COUNTER_LSB         (* (reg16 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__16BIT_A0_REG )
            #define VideoTimerL_COUNTER_LSB_PTR       ((reg16 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */
    #elif(VideoTimerL_Resolution <= 24u)/* 24-bit Timer */
        #define VideoTimerL_CAPTURE_LSB         (* (reg32 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define VideoTimerL_CAPTURE_LSB_PTR       ((reg32 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define VideoTimerL_PERIOD_LSB          (* (reg32 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define VideoTimerL_PERIOD_LSB_PTR        ((reg32 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define VideoTimerL_COUNTER_LSB         (* (reg32 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__A0_REG )
        #define VideoTimerL_COUNTER_LSB_PTR       ((reg32 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__A0_REG )
    #else /* 32-bit Timer */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define VideoTimerL_CAPTURE_LSB         (* (reg32 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define VideoTimerL_CAPTURE_LSB_PTR       ((reg32 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define VideoTimerL_PERIOD_LSB          (* (reg32 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define VideoTimerL_PERIOD_LSB_PTR        ((reg32 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define VideoTimerL_COUNTER_LSB         (* (reg32 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__A0_REG )
            #define VideoTimerL_COUNTER_LSB_PTR       ((reg32 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define VideoTimerL_CAPTURE_LSB         (* (reg32 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__32BIT_F0_REG )
            #define VideoTimerL_CAPTURE_LSB_PTR       ((reg32 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__32BIT_F0_REG )
            #define VideoTimerL_PERIOD_LSB          (* (reg32 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__32BIT_D0_REG )
            #define VideoTimerL_PERIOD_LSB_PTR        ((reg32 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__32BIT_D0_REG )
            #define VideoTimerL_COUNTER_LSB         (* (reg32 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__32BIT_A0_REG )
            #define VideoTimerL_COUNTER_LSB_PTR       ((reg32 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */ 
    #endif

    #define VideoTimerL_COUNTER_LSB_PTR_8BIT       ((reg8 *) VideoTimerL_TimerUDB_sT16_timerdp_u0__A0_REG )
    
    #if (VideoTimerL_UsingHWCaptureCounter)
        #define VideoTimerL_CAP_COUNT              (*(reg8 *) VideoTimerL_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define VideoTimerL_CAP_COUNT_PTR          ( (reg8 *) VideoTimerL_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define VideoTimerL_CAPTURE_COUNT_CTRL     (*(reg8 *) VideoTimerL_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
        #define VideoTimerL_CAPTURE_COUNT_CTRL_PTR ( (reg8 *) VideoTimerL_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
    #endif /* (VideoTimerL_UsingHWCaptureCounter) */


    /***************************************
    *       Register Constants
    ***************************************/

    /* Control Register Bit Locations */
    #define VideoTimerL_CTRL_INTCNT_SHIFT              0x00u       /* As defined by Verilog Implementation */
    #define VideoTimerL_CTRL_TRIG_MODE_SHIFT           0x02u       /* As defined by Verilog Implementation */
    #define VideoTimerL_CTRL_TRIG_EN_SHIFT             0x04u       /* As defined by Verilog Implementation */
    #define VideoTimerL_CTRL_CAP_MODE_SHIFT            0x05u       /* As defined by Verilog Implementation */
    #define VideoTimerL_CTRL_ENABLE_SHIFT              0x07u       /* As defined by Verilog Implementation */

    /* Control Register Bit Masks */
    #define VideoTimerL_CTRL_INTCNT_MASK               ((uint8)((uint8)0x03u << VideoTimerL_CTRL_INTCNT_SHIFT))
    #define VideoTimerL_CTRL_TRIG_MODE_MASK            ((uint8)((uint8)0x03u << VideoTimerL_CTRL_TRIG_MODE_SHIFT))
    #define VideoTimerL_CTRL_TRIG_EN                   ((uint8)((uint8)0x01u << VideoTimerL_CTRL_TRIG_EN_SHIFT))
    #define VideoTimerL_CTRL_CAP_MODE_MASK             ((uint8)((uint8)0x03u << VideoTimerL_CTRL_CAP_MODE_SHIFT))
    #define VideoTimerL_CTRL_ENABLE                    ((uint8)((uint8)0x01u << VideoTimerL_CTRL_ENABLE_SHIFT))

    /* Bit Counter (7-bit) Control Register Bit Definitions */
    /* As defined by the Register map for the AUX Control Register */
    #define VideoTimerL_CNTR_ENABLE                    0x20u

    /* Status Register Bit Locations */
    #define VideoTimerL_STATUS_TC_SHIFT                0x00u  /* As defined by Verilog Implementation */
    #define VideoTimerL_STATUS_CAPTURE_SHIFT           0x01u  /* As defined by Verilog Implementation */
    #define VideoTimerL_STATUS_TC_INT_MASK_SHIFT       VideoTimerL_STATUS_TC_SHIFT
    #define VideoTimerL_STATUS_CAPTURE_INT_MASK_SHIFT  VideoTimerL_STATUS_CAPTURE_SHIFT
    #define VideoTimerL_STATUS_FIFOFULL_SHIFT          0x02u  /* As defined by Verilog Implementation */
    #define VideoTimerL_STATUS_FIFONEMP_SHIFT          0x03u  /* As defined by Verilog Implementation */
    #define VideoTimerL_STATUS_FIFOFULL_INT_MASK_SHIFT VideoTimerL_STATUS_FIFOFULL_SHIFT

    /* Status Register Bit Masks */
    /* Sticky TC Event Bit-Mask */
    #define VideoTimerL_STATUS_TC                      ((uint8)((uint8)0x01u << VideoTimerL_STATUS_TC_SHIFT))
    /* Sticky Capture Event Bit-Mask */
    #define VideoTimerL_STATUS_CAPTURE                 ((uint8)((uint8)0x01u << VideoTimerL_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define VideoTimerL_STATUS_TC_INT_MASK             ((uint8)((uint8)0x01u << VideoTimerL_STATUS_TC_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define VideoTimerL_STATUS_CAPTURE_INT_MASK        ((uint8)((uint8)0x01u << VideoTimerL_STATUS_CAPTURE_SHIFT))
    /* NOT-Sticky FIFO Full Bit-Mask */
    #define VideoTimerL_STATUS_FIFOFULL                ((uint8)((uint8)0x01u << VideoTimerL_STATUS_FIFOFULL_SHIFT))
    /* NOT-Sticky FIFO Not Empty Bit-Mask */
    #define VideoTimerL_STATUS_FIFONEMP                ((uint8)((uint8)0x01u << VideoTimerL_STATUS_FIFONEMP_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define VideoTimerL_STATUS_FIFOFULL_INT_MASK       ((uint8)((uint8)0x01u << VideoTimerL_STATUS_FIFOFULL_SHIFT))

    #define VideoTimerL_STATUS_ACTL_INT_EN             0x10u   /* As defined for the ACTL Register */

    /* Datapath Auxillary Control Register definitions */
    #define VideoTimerL_AUX_CTRL_FIFO0_CLR             0x01u   /* As defined by Register map */
    #define VideoTimerL_AUX_CTRL_FIFO1_CLR             0x02u   /* As defined by Register map */
    #define VideoTimerL_AUX_CTRL_FIFO0_LVL             0x04u   /* As defined by Register map */
    #define VideoTimerL_AUX_CTRL_FIFO1_LVL             0x08u   /* As defined by Register map */
    #define VideoTimerL_STATUS_ACTL_INT_EN_MASK        0x10u   /* As defined for the ACTL Register */

#endif /* Implementation Specific Registers and Register Constants */

#endif  /* CY_TIMER_VideoTimerL_H */


/* [] END OF FILE */
