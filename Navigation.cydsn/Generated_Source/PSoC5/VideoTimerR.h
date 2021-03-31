/*******************************************************************************
* File Name: VideoTimerR.h
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

#if !defined(CY_TIMER_VideoTimerR_H)
#define CY_TIMER_VideoTimerR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 VideoTimerR_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Timer_v2_80 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults
**************************************/

#define VideoTimerR_Resolution                 16u
#define VideoTimerR_UsingFixedFunction         0u
#define VideoTimerR_UsingHWCaptureCounter      1u
#define VideoTimerR_SoftwareCaptureMode        0u
#define VideoTimerR_SoftwareTriggerMode        0u
#define VideoTimerR_UsingHWEnable              1u
#define VideoTimerR_EnableTriggerMode          0u
#define VideoTimerR_InterruptOnCaptureCount    1u
#define VideoTimerR_RunModeUsed                2u
#define VideoTimerR_ControlRegRemoved          0u

#if defined(VideoTimerR_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG)
    #define VideoTimerR_UDB_CONTROL_REG_REMOVED            (0u)
#elif  (VideoTimerR_UsingFixedFunction)
    #define VideoTimerR_UDB_CONTROL_REG_REMOVED            (0u)
#else 
    #define VideoTimerR_UDB_CONTROL_REG_REMOVED            (1u)
#endif /* End VideoTimerR_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG */


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for Timer Component
 *************************************************************************/
typedef struct
{
    uint8 TimerEnableState;
    #if(!VideoTimerR_UsingFixedFunction)

        uint16 TimerUdb;
        uint8 InterruptMaskValue;
        #if (VideoTimerR_UsingHWCaptureCounter)
            uint8 TimerCaptureCounter;
        #endif /* variable declarations for backing up non retention registers in CY_UDB_V1 */

        #if (!VideoTimerR_UDB_CONTROL_REG_REMOVED)
            uint8 TimerControlRegister;
        #endif /* variable declaration for backing up enable state of the Timer */
    #endif /* define backup variables only for UDB implementation. Fixed function registers are all retention */

}VideoTimerR_backupStruct;


/***************************************
*       Function Prototypes
***************************************/

void    VideoTimerR_Start(void) ;
void    VideoTimerR_Stop(void) ;

void    VideoTimerR_SetInterruptMode(uint8 interruptMode) ;
uint8   VideoTimerR_ReadStatusRegister(void) ;
/* Deprecated function. Do not use this in future. Retained for backward compatibility */
#define VideoTimerR_GetInterruptSource() VideoTimerR_ReadStatusRegister()

#if(!VideoTimerR_UDB_CONTROL_REG_REMOVED)
    uint8   VideoTimerR_ReadControlRegister(void) ;
    void    VideoTimerR_WriteControlRegister(uint8 control) ;
#endif /* (!VideoTimerR_UDB_CONTROL_REG_REMOVED) */

uint16  VideoTimerR_ReadPeriod(void) ;
void    VideoTimerR_WritePeriod(uint16 period) ;
uint16  VideoTimerR_ReadCounter(void) ;
void    VideoTimerR_WriteCounter(uint16 counter) ;
uint16  VideoTimerR_ReadCapture(void) ;
void    VideoTimerR_SoftwareCapture(void) ;

#if(!VideoTimerR_UsingFixedFunction) /* UDB Prototypes */
    #if (VideoTimerR_SoftwareCaptureMode)
        void    VideoTimerR_SetCaptureMode(uint8 captureMode) ;
    #endif /* (!VideoTimerR_UsingFixedFunction) */

    #if (VideoTimerR_SoftwareTriggerMode)
        void    VideoTimerR_SetTriggerMode(uint8 triggerMode) ;
    #endif /* (VideoTimerR_SoftwareTriggerMode) */

    #if (VideoTimerR_EnableTriggerMode)
        void    VideoTimerR_EnableTrigger(void) ;
        void    VideoTimerR_DisableTrigger(void) ;
    #endif /* (VideoTimerR_EnableTriggerMode) */


    #if(VideoTimerR_InterruptOnCaptureCount)
        void    VideoTimerR_SetInterruptCount(uint8 interruptCount) ;
    #endif /* (VideoTimerR_InterruptOnCaptureCount) */

    #if (VideoTimerR_UsingHWCaptureCounter)
        void    VideoTimerR_SetCaptureCount(uint8 captureCount) ;
        uint8   VideoTimerR_ReadCaptureCount(void) ;
    #endif /* (VideoTimerR_UsingHWCaptureCounter) */

    void VideoTimerR_ClearFIFO(void) ;
#endif /* UDB Prototypes */

/* Sleep Retention APIs */
void VideoTimerR_Init(void)          ;
void VideoTimerR_Enable(void)        ;
void VideoTimerR_SaveConfig(void)    ;
void VideoTimerR_RestoreConfig(void) ;
void VideoTimerR_Sleep(void)         ;
void VideoTimerR_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Timer__CaptureModes, Used in Capture Mode */
#define VideoTimerR__B_TIMER__CM_NONE 0
#define VideoTimerR__B_TIMER__CM_RISINGEDGE 1
#define VideoTimerR__B_TIMER__CM_FALLINGEDGE 2
#define VideoTimerR__B_TIMER__CM_EITHEREDGE 3
#define VideoTimerR__B_TIMER__CM_SOFTWARE 4



/* Enumerated Type B_Timer__TriggerModes, Used in Trigger Mode */
#define VideoTimerR__B_TIMER__TM_NONE 0x00u
#define VideoTimerR__B_TIMER__TM_RISINGEDGE 0x04u
#define VideoTimerR__B_TIMER__TM_FALLINGEDGE 0x08u
#define VideoTimerR__B_TIMER__TM_EITHEREDGE 0x0Cu
#define VideoTimerR__B_TIMER__TM_SOFTWARE 0x10u


/***************************************
*    Initialial Parameter Constants
***************************************/

#define VideoTimerR_INIT_PERIOD             65535u
#define VideoTimerR_INIT_CAPTURE_MODE       ((uint8)((uint8)2u << VideoTimerR_CTRL_CAP_MODE_SHIFT))
#define VideoTimerR_INIT_TRIGGER_MODE       ((uint8)((uint8)0u << VideoTimerR_CTRL_TRIG_MODE_SHIFT))
#if (VideoTimerR_UsingFixedFunction)
    #define VideoTimerR_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << VideoTimerR_STATUS_TC_INT_MASK_SHIFT)) | \
                                                  ((uint8)((uint8)1 << VideoTimerR_STATUS_CAPTURE_INT_MASK_SHIFT)))
#else
    #define VideoTimerR_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << VideoTimerR_STATUS_TC_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)1 << VideoTimerR_STATUS_CAPTURE_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << VideoTimerR_STATUS_FIFOFULL_INT_MASK_SHIFT)))
#endif /* (VideoTimerR_UsingFixedFunction) */
#define VideoTimerR_INIT_CAPTURE_COUNT      (2u)
#define VideoTimerR_INIT_INT_CAPTURE_COUNT  ((uint8)((uint8)(1u - 1u) << VideoTimerR_CTRL_INTCNT_SHIFT))


/***************************************
*           Registers
***************************************/

#if (VideoTimerR_UsingFixedFunction) /* Implementation Specific Registers and Register Constants */


    /***************************************
    *    Fixed Function Registers
    ***************************************/

    #define VideoTimerR_STATUS         (*(reg8 *) VideoTimerR_TimerHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define VideoTimerR_STATUS_MASK    (*(reg8 *) VideoTimerR_TimerHW__SR0 )
    #define VideoTimerR_CONTROL        (*(reg8 *) VideoTimerR_TimerHW__CFG0)
    #define VideoTimerR_CONTROL2       (*(reg8 *) VideoTimerR_TimerHW__CFG1)
    #define VideoTimerR_CONTROL2_PTR   ( (reg8 *) VideoTimerR_TimerHW__CFG1)
    #define VideoTimerR_RT1            (*(reg8 *) VideoTimerR_TimerHW__RT1)
    #define VideoTimerR_RT1_PTR        ( (reg8 *) VideoTimerR_TimerHW__RT1)

    #if (CY_PSOC3 || CY_PSOC5LP)
        #define VideoTimerR_CONTROL3       (*(reg8 *) VideoTimerR_TimerHW__CFG2)
        #define VideoTimerR_CONTROL3_PTR   ( (reg8 *) VideoTimerR_TimerHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define VideoTimerR_GLOBAL_ENABLE  (*(reg8 *) VideoTimerR_TimerHW__PM_ACT_CFG)
    #define VideoTimerR_GLOBAL_STBY_ENABLE  (*(reg8 *) VideoTimerR_TimerHW__PM_STBY_CFG)

    #define VideoTimerR_CAPTURE_LSB         (* (reg16 *) VideoTimerR_TimerHW__CAP0 )
    #define VideoTimerR_CAPTURE_LSB_PTR       ((reg16 *) VideoTimerR_TimerHW__CAP0 )
    #define VideoTimerR_PERIOD_LSB          (* (reg16 *) VideoTimerR_TimerHW__PER0 )
    #define VideoTimerR_PERIOD_LSB_PTR        ((reg16 *) VideoTimerR_TimerHW__PER0 )
    #define VideoTimerR_COUNTER_LSB         (* (reg16 *) VideoTimerR_TimerHW__CNT_CMP0 )
    #define VideoTimerR_COUNTER_LSB_PTR       ((reg16 *) VideoTimerR_TimerHW__CNT_CMP0 )


    /***************************************
    *    Register Constants
    ***************************************/

    /* Fixed Function Block Chosen */
    #define VideoTimerR_BLOCK_EN_MASK                     VideoTimerR_TimerHW__PM_ACT_MSK
    #define VideoTimerR_BLOCK_STBY_EN_MASK                VideoTimerR_TimerHW__PM_STBY_MSK

    /* Control Register Bit Locations */
    /* Interrupt Count - Not valid for Fixed Function Block */
    #define VideoTimerR_CTRL_INTCNT_SHIFT                  0x00u
    /* Trigger Polarity - Not valid for Fixed Function Block */
    #define VideoTimerR_CTRL_TRIG_MODE_SHIFT               0x00u
    /* Trigger Enable - Not valid for Fixed Function Block */
    #define VideoTimerR_CTRL_TRIG_EN_SHIFT                 0x00u
    /* Capture Polarity - Not valid for Fixed Function Block */
    #define VideoTimerR_CTRL_CAP_MODE_SHIFT                0x00u
    /* Timer Enable - As defined in Register Map, part of TMRX_CFG0 register */
    #define VideoTimerR_CTRL_ENABLE_SHIFT                  0x00u

    /* Control Register Bit Masks */
    #define VideoTimerR_CTRL_ENABLE                        ((uint8)((uint8)0x01u << VideoTimerR_CTRL_ENABLE_SHIFT))

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define VideoTimerR_CTRL2_IRQ_SEL_SHIFT                 0x00u
    #define VideoTimerR_CTRL2_IRQ_SEL                      ((uint8)((uint8)0x01u << VideoTimerR_CTRL2_IRQ_SEL_SHIFT))

    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        /* As defined by Verilog Implementation */
        #define VideoTimerR_CTRL_MODE_SHIFT                 0x01u
        #define VideoTimerR_CTRL_MODE_MASK                 ((uint8)((uint8)0x07u << VideoTimerR_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Control3 Register Bit Locations */
        #define VideoTimerR_CTRL_RCOD_SHIFT        0x02u
        #define VideoTimerR_CTRL_ENBL_SHIFT        0x00u
        #define VideoTimerR_CTRL_MODE_SHIFT        0x00u

        /* Control3 Register Bit Masks */
        #define VideoTimerR_CTRL_RCOD_MASK  ((uint8)((uint8)0x03u << VideoTimerR_CTRL_RCOD_SHIFT)) /* ROD and COD bit masks */
        #define VideoTimerR_CTRL_ENBL_MASK  ((uint8)((uint8)0x80u << VideoTimerR_CTRL_ENBL_SHIFT)) /* HW_EN bit mask */
        #define VideoTimerR_CTRL_MODE_MASK  ((uint8)((uint8)0x03u << VideoTimerR_CTRL_MODE_SHIFT)) /* Run mode bit mask */

        #define VideoTimerR_CTRL_RCOD       ((uint8)((uint8)0x03u << VideoTimerR_CTRL_RCOD_SHIFT))
        #define VideoTimerR_CTRL_ENBL       ((uint8)((uint8)0x80u << VideoTimerR_CTRL_ENBL_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define VideoTimerR_RT1_SHIFT                       0x04u
    /* Sync TC and CMP bit masks */
    #define VideoTimerR_RT1_MASK                        ((uint8)((uint8)0x03u << VideoTimerR_RT1_SHIFT))
    #define VideoTimerR_SYNC                            ((uint8)((uint8)0x03u << VideoTimerR_RT1_SHIFT))
    #define VideoTimerR_SYNCDSI_SHIFT                   0x00u
    /* Sync all DSI inputs with Mask  */
    #define VideoTimerR_SYNCDSI_MASK                    ((uint8)((uint8)0x0Fu << VideoTimerR_SYNCDSI_SHIFT))
    /* Sync all DSI inputs */
    #define VideoTimerR_SYNCDSI_EN                      ((uint8)((uint8)0x0Fu << VideoTimerR_SYNCDSI_SHIFT))

    #define VideoTimerR_CTRL_MODE_PULSEWIDTH            ((uint8)((uint8)0x01u << VideoTimerR_CTRL_MODE_SHIFT))
    #define VideoTimerR_CTRL_MODE_PERIOD                ((uint8)((uint8)0x02u << VideoTimerR_CTRL_MODE_SHIFT))
    #define VideoTimerR_CTRL_MODE_CONTINUOUS            ((uint8)((uint8)0x00u << VideoTimerR_CTRL_MODE_SHIFT))

    /* Status Register Bit Locations */
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define VideoTimerR_STATUS_TC_SHIFT                 0x07u
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define VideoTimerR_STATUS_CAPTURE_SHIFT            0x06u
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define VideoTimerR_STATUS_TC_INT_MASK_SHIFT        (VideoTimerR_STATUS_TC_SHIFT - 0x04u)
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define VideoTimerR_STATUS_CAPTURE_INT_MASK_SHIFT   (VideoTimerR_STATUS_CAPTURE_SHIFT - 0x04u)

    /* Status Register Bit Masks */
    #define VideoTimerR_STATUS_TC                       ((uint8)((uint8)0x01u << VideoTimerR_STATUS_TC_SHIFT))
    #define VideoTimerR_STATUS_CAPTURE                  ((uint8)((uint8)0x01u << VideoTimerR_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on TC */
    #define VideoTimerR_STATUS_TC_INT_MASK              ((uint8)((uint8)0x01u << VideoTimerR_STATUS_TC_INT_MASK_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on Capture */
    #define VideoTimerR_STATUS_CAPTURE_INT_MASK         ((uint8)((uint8)0x01u << VideoTimerR_STATUS_CAPTURE_INT_MASK_SHIFT))

#else   /* UDB Registers and Register Constants */


    /***************************************
    *           UDB Registers
    ***************************************/

    #define VideoTimerR_STATUS              (* (reg8 *) VideoTimerR_TimerUDB_rstSts_stsreg__STATUS_REG )
    #define VideoTimerR_STATUS_MASK         (* (reg8 *) VideoTimerR_TimerUDB_rstSts_stsreg__MASK_REG)
    #define VideoTimerR_STATUS_AUX_CTRL     (* (reg8 *) VideoTimerR_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define VideoTimerR_CONTROL             (* (reg8 *) VideoTimerR_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    
    #if(VideoTimerR_Resolution <= 8u) /* 8-bit Timer */
        #define VideoTimerR_CAPTURE_LSB         (* (reg8 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define VideoTimerR_CAPTURE_LSB_PTR       ((reg8 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define VideoTimerR_PERIOD_LSB          (* (reg8 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define VideoTimerR_PERIOD_LSB_PTR        ((reg8 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define VideoTimerR_COUNTER_LSB         (* (reg8 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__A0_REG )
        #define VideoTimerR_COUNTER_LSB_PTR       ((reg8 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__A0_REG )
    #elif(VideoTimerR_Resolution <= 16u) /* 8-bit Timer */
        #if(CY_PSOC3) /* 8-bit addres space */
            #define VideoTimerR_CAPTURE_LSB         (* (reg16 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define VideoTimerR_CAPTURE_LSB_PTR       ((reg16 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define VideoTimerR_PERIOD_LSB          (* (reg16 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define VideoTimerR_PERIOD_LSB_PTR        ((reg16 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define VideoTimerR_COUNTER_LSB         (* (reg16 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__A0_REG )
            #define VideoTimerR_COUNTER_LSB_PTR       ((reg16 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define VideoTimerR_CAPTURE_LSB         (* (reg16 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__16BIT_F0_REG )
            #define VideoTimerR_CAPTURE_LSB_PTR       ((reg16 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__16BIT_F0_REG )
            #define VideoTimerR_PERIOD_LSB          (* (reg16 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__16BIT_D0_REG )
            #define VideoTimerR_PERIOD_LSB_PTR        ((reg16 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__16BIT_D0_REG )
            #define VideoTimerR_COUNTER_LSB         (* (reg16 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__16BIT_A0_REG )
            #define VideoTimerR_COUNTER_LSB_PTR       ((reg16 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */
    #elif(VideoTimerR_Resolution <= 24u)/* 24-bit Timer */
        #define VideoTimerR_CAPTURE_LSB         (* (reg32 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define VideoTimerR_CAPTURE_LSB_PTR       ((reg32 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define VideoTimerR_PERIOD_LSB          (* (reg32 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define VideoTimerR_PERIOD_LSB_PTR        ((reg32 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define VideoTimerR_COUNTER_LSB         (* (reg32 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__A0_REG )
        #define VideoTimerR_COUNTER_LSB_PTR       ((reg32 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__A0_REG )
    #else /* 32-bit Timer */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define VideoTimerR_CAPTURE_LSB         (* (reg32 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define VideoTimerR_CAPTURE_LSB_PTR       ((reg32 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define VideoTimerR_PERIOD_LSB          (* (reg32 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define VideoTimerR_PERIOD_LSB_PTR        ((reg32 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define VideoTimerR_COUNTER_LSB         (* (reg32 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__A0_REG )
            #define VideoTimerR_COUNTER_LSB_PTR       ((reg32 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define VideoTimerR_CAPTURE_LSB         (* (reg32 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__32BIT_F0_REG )
            #define VideoTimerR_CAPTURE_LSB_PTR       ((reg32 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__32BIT_F0_REG )
            #define VideoTimerR_PERIOD_LSB          (* (reg32 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__32BIT_D0_REG )
            #define VideoTimerR_PERIOD_LSB_PTR        ((reg32 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__32BIT_D0_REG )
            #define VideoTimerR_COUNTER_LSB         (* (reg32 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__32BIT_A0_REG )
            #define VideoTimerR_COUNTER_LSB_PTR       ((reg32 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */ 
    #endif

    #define VideoTimerR_COUNTER_LSB_PTR_8BIT       ((reg8 *) VideoTimerR_TimerUDB_sT16_timerdp_u0__A0_REG )
    
    #if (VideoTimerR_UsingHWCaptureCounter)
        #define VideoTimerR_CAP_COUNT              (*(reg8 *) VideoTimerR_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define VideoTimerR_CAP_COUNT_PTR          ( (reg8 *) VideoTimerR_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define VideoTimerR_CAPTURE_COUNT_CTRL     (*(reg8 *) VideoTimerR_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
        #define VideoTimerR_CAPTURE_COUNT_CTRL_PTR ( (reg8 *) VideoTimerR_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
    #endif /* (VideoTimerR_UsingHWCaptureCounter) */


    /***************************************
    *       Register Constants
    ***************************************/

    /* Control Register Bit Locations */
    #define VideoTimerR_CTRL_INTCNT_SHIFT              0x00u       /* As defined by Verilog Implementation */
    #define VideoTimerR_CTRL_TRIG_MODE_SHIFT           0x02u       /* As defined by Verilog Implementation */
    #define VideoTimerR_CTRL_TRIG_EN_SHIFT             0x04u       /* As defined by Verilog Implementation */
    #define VideoTimerR_CTRL_CAP_MODE_SHIFT            0x05u       /* As defined by Verilog Implementation */
    #define VideoTimerR_CTRL_ENABLE_SHIFT              0x07u       /* As defined by Verilog Implementation */

    /* Control Register Bit Masks */
    #define VideoTimerR_CTRL_INTCNT_MASK               ((uint8)((uint8)0x03u << VideoTimerR_CTRL_INTCNT_SHIFT))
    #define VideoTimerR_CTRL_TRIG_MODE_MASK            ((uint8)((uint8)0x03u << VideoTimerR_CTRL_TRIG_MODE_SHIFT))
    #define VideoTimerR_CTRL_TRIG_EN                   ((uint8)((uint8)0x01u << VideoTimerR_CTRL_TRIG_EN_SHIFT))
    #define VideoTimerR_CTRL_CAP_MODE_MASK             ((uint8)((uint8)0x03u << VideoTimerR_CTRL_CAP_MODE_SHIFT))
    #define VideoTimerR_CTRL_ENABLE                    ((uint8)((uint8)0x01u << VideoTimerR_CTRL_ENABLE_SHIFT))

    /* Bit Counter (7-bit) Control Register Bit Definitions */
    /* As defined by the Register map for the AUX Control Register */
    #define VideoTimerR_CNTR_ENABLE                    0x20u

    /* Status Register Bit Locations */
    #define VideoTimerR_STATUS_TC_SHIFT                0x00u  /* As defined by Verilog Implementation */
    #define VideoTimerR_STATUS_CAPTURE_SHIFT           0x01u  /* As defined by Verilog Implementation */
    #define VideoTimerR_STATUS_TC_INT_MASK_SHIFT       VideoTimerR_STATUS_TC_SHIFT
    #define VideoTimerR_STATUS_CAPTURE_INT_MASK_SHIFT  VideoTimerR_STATUS_CAPTURE_SHIFT
    #define VideoTimerR_STATUS_FIFOFULL_SHIFT          0x02u  /* As defined by Verilog Implementation */
    #define VideoTimerR_STATUS_FIFONEMP_SHIFT          0x03u  /* As defined by Verilog Implementation */
    #define VideoTimerR_STATUS_FIFOFULL_INT_MASK_SHIFT VideoTimerR_STATUS_FIFOFULL_SHIFT

    /* Status Register Bit Masks */
    /* Sticky TC Event Bit-Mask */
    #define VideoTimerR_STATUS_TC                      ((uint8)((uint8)0x01u << VideoTimerR_STATUS_TC_SHIFT))
    /* Sticky Capture Event Bit-Mask */
    #define VideoTimerR_STATUS_CAPTURE                 ((uint8)((uint8)0x01u << VideoTimerR_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define VideoTimerR_STATUS_TC_INT_MASK             ((uint8)((uint8)0x01u << VideoTimerR_STATUS_TC_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define VideoTimerR_STATUS_CAPTURE_INT_MASK        ((uint8)((uint8)0x01u << VideoTimerR_STATUS_CAPTURE_SHIFT))
    /* NOT-Sticky FIFO Full Bit-Mask */
    #define VideoTimerR_STATUS_FIFOFULL                ((uint8)((uint8)0x01u << VideoTimerR_STATUS_FIFOFULL_SHIFT))
    /* NOT-Sticky FIFO Not Empty Bit-Mask */
    #define VideoTimerR_STATUS_FIFONEMP                ((uint8)((uint8)0x01u << VideoTimerR_STATUS_FIFONEMP_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define VideoTimerR_STATUS_FIFOFULL_INT_MASK       ((uint8)((uint8)0x01u << VideoTimerR_STATUS_FIFOFULL_SHIFT))

    #define VideoTimerR_STATUS_ACTL_INT_EN             0x10u   /* As defined for the ACTL Register */

    /* Datapath Auxillary Control Register definitions */
    #define VideoTimerR_AUX_CTRL_FIFO0_CLR             0x01u   /* As defined by Register map */
    #define VideoTimerR_AUX_CTRL_FIFO1_CLR             0x02u   /* As defined by Register map */
    #define VideoTimerR_AUX_CTRL_FIFO0_LVL             0x04u   /* As defined by Register map */
    #define VideoTimerR_AUX_CTRL_FIFO1_LVL             0x08u   /* As defined by Register map */
    #define VideoTimerR_STATUS_ACTL_INT_EN_MASK        0x10u   /* As defined for the ACTL Register */

#endif /* Implementation Specific Registers and Register Constants */

#endif  /* CY_TIMER_VideoTimerR_H */


/* [] END OF FILE */
