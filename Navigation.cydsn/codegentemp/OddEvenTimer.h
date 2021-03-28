/*******************************************************************************
* File Name: OddEvenTimer.h
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

#if !defined(CY_TIMER_OddEvenTimer_H)
#define CY_TIMER_OddEvenTimer_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 OddEvenTimer_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Timer_v2_80 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults
**************************************/

#define OddEvenTimer_Resolution                 32u
#define OddEvenTimer_UsingFixedFunction         0u
#define OddEvenTimer_UsingHWCaptureCounter      1u
#define OddEvenTimer_SoftwareCaptureMode        0u
#define OddEvenTimer_SoftwareTriggerMode        0u
#define OddEvenTimer_UsingHWEnable              0u
#define OddEvenTimer_EnableTriggerMode          0u
#define OddEvenTimer_InterruptOnCaptureCount    0u
#define OddEvenTimer_RunModeUsed                0u
#define OddEvenTimer_ControlRegRemoved          0u

#if defined(OddEvenTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG)
    #define OddEvenTimer_UDB_CONTROL_REG_REMOVED            (0u)
#elif  (OddEvenTimer_UsingFixedFunction)
    #define OddEvenTimer_UDB_CONTROL_REG_REMOVED            (0u)
#else 
    #define OddEvenTimer_UDB_CONTROL_REG_REMOVED            (1u)
#endif /* End OddEvenTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG */


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for Timer Component
 *************************************************************************/
typedef struct
{
    uint8 TimerEnableState;
    #if(!OddEvenTimer_UsingFixedFunction)

        uint32 TimerUdb;
        uint8 InterruptMaskValue;
        #if (OddEvenTimer_UsingHWCaptureCounter)
            uint8 TimerCaptureCounter;
        #endif /* variable declarations for backing up non retention registers in CY_UDB_V1 */

        #if (!OddEvenTimer_UDB_CONTROL_REG_REMOVED)
            uint8 TimerControlRegister;
        #endif /* variable declaration for backing up enable state of the Timer */
    #endif /* define backup variables only for UDB implementation. Fixed function registers are all retention */

}OddEvenTimer_backupStruct;


/***************************************
*       Function Prototypes
***************************************/

void    OddEvenTimer_Start(void) ;
void    OddEvenTimer_Stop(void) ;

void    OddEvenTimer_SetInterruptMode(uint8 interruptMode) ;
uint8   OddEvenTimer_ReadStatusRegister(void) ;
/* Deprecated function. Do not use this in future. Retained for backward compatibility */
#define OddEvenTimer_GetInterruptSource() OddEvenTimer_ReadStatusRegister()

#if(!OddEvenTimer_UDB_CONTROL_REG_REMOVED)
    uint8   OddEvenTimer_ReadControlRegister(void) ;
    void    OddEvenTimer_WriteControlRegister(uint8 control) ;
#endif /* (!OddEvenTimer_UDB_CONTROL_REG_REMOVED) */

uint32  OddEvenTimer_ReadPeriod(void) ;
void    OddEvenTimer_WritePeriod(uint32 period) ;
uint32  OddEvenTimer_ReadCounter(void) ;
void    OddEvenTimer_WriteCounter(uint32 counter) ;
uint32  OddEvenTimer_ReadCapture(void) ;
void    OddEvenTimer_SoftwareCapture(void) ;

#if(!OddEvenTimer_UsingFixedFunction) /* UDB Prototypes */
    #if (OddEvenTimer_SoftwareCaptureMode)
        void    OddEvenTimer_SetCaptureMode(uint8 captureMode) ;
    #endif /* (!OddEvenTimer_UsingFixedFunction) */

    #if (OddEvenTimer_SoftwareTriggerMode)
        void    OddEvenTimer_SetTriggerMode(uint8 triggerMode) ;
    #endif /* (OddEvenTimer_SoftwareTriggerMode) */

    #if (OddEvenTimer_EnableTriggerMode)
        void    OddEvenTimer_EnableTrigger(void) ;
        void    OddEvenTimer_DisableTrigger(void) ;
    #endif /* (OddEvenTimer_EnableTriggerMode) */


    #if(OddEvenTimer_InterruptOnCaptureCount)
        void    OddEvenTimer_SetInterruptCount(uint8 interruptCount) ;
    #endif /* (OddEvenTimer_InterruptOnCaptureCount) */

    #if (OddEvenTimer_UsingHWCaptureCounter)
        void    OddEvenTimer_SetCaptureCount(uint8 captureCount) ;
        uint8   OddEvenTimer_ReadCaptureCount(void) ;
    #endif /* (OddEvenTimer_UsingHWCaptureCounter) */

    void OddEvenTimer_ClearFIFO(void) ;
#endif /* UDB Prototypes */

/* Sleep Retention APIs */
void OddEvenTimer_Init(void)          ;
void OddEvenTimer_Enable(void)        ;
void OddEvenTimer_SaveConfig(void)    ;
void OddEvenTimer_RestoreConfig(void) ;
void OddEvenTimer_Sleep(void)         ;
void OddEvenTimer_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Timer__CaptureModes, Used in Capture Mode */
#define OddEvenTimer__B_TIMER__CM_NONE 0
#define OddEvenTimer__B_TIMER__CM_RISINGEDGE 1
#define OddEvenTimer__B_TIMER__CM_FALLINGEDGE 2
#define OddEvenTimer__B_TIMER__CM_EITHEREDGE 3
#define OddEvenTimer__B_TIMER__CM_SOFTWARE 4



/* Enumerated Type B_Timer__TriggerModes, Used in Trigger Mode */
#define OddEvenTimer__B_TIMER__TM_NONE 0x00u
#define OddEvenTimer__B_TIMER__TM_RISINGEDGE 0x04u
#define OddEvenTimer__B_TIMER__TM_FALLINGEDGE 0x08u
#define OddEvenTimer__B_TIMER__TM_EITHEREDGE 0x0Cu
#define OddEvenTimer__B_TIMER__TM_SOFTWARE 0x10u


/***************************************
*    Initialial Parameter Constants
***************************************/

#define OddEvenTimer_INIT_PERIOD             65535u
#define OddEvenTimer_INIT_CAPTURE_MODE       ((uint8)((uint8)1u << OddEvenTimer_CTRL_CAP_MODE_SHIFT))
#define OddEvenTimer_INIT_TRIGGER_MODE       ((uint8)((uint8)0u << OddEvenTimer_CTRL_TRIG_MODE_SHIFT))
#if (OddEvenTimer_UsingFixedFunction)
    #define OddEvenTimer_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << OddEvenTimer_STATUS_TC_INT_MASK_SHIFT)) | \
                                                  ((uint8)((uint8)0 << OddEvenTimer_STATUS_CAPTURE_INT_MASK_SHIFT)))
#else
    #define OddEvenTimer_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << OddEvenTimer_STATUS_TC_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << OddEvenTimer_STATUS_CAPTURE_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << OddEvenTimer_STATUS_FIFOFULL_INT_MASK_SHIFT)))
#endif /* (OddEvenTimer_UsingFixedFunction) */
#define OddEvenTimer_INIT_CAPTURE_COUNT      (35u)
#define OddEvenTimer_INIT_INT_CAPTURE_COUNT  ((uint8)((uint8)(1u - 1u) << OddEvenTimer_CTRL_INTCNT_SHIFT))


/***************************************
*           Registers
***************************************/

#if (OddEvenTimer_UsingFixedFunction) /* Implementation Specific Registers and Register Constants */


    /***************************************
    *    Fixed Function Registers
    ***************************************/

    #define OddEvenTimer_STATUS         (*(reg8 *) OddEvenTimer_TimerHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define OddEvenTimer_STATUS_MASK    (*(reg8 *) OddEvenTimer_TimerHW__SR0 )
    #define OddEvenTimer_CONTROL        (*(reg8 *) OddEvenTimer_TimerHW__CFG0)
    #define OddEvenTimer_CONTROL2       (*(reg8 *) OddEvenTimer_TimerHW__CFG1)
    #define OddEvenTimer_CONTROL2_PTR   ( (reg8 *) OddEvenTimer_TimerHW__CFG1)
    #define OddEvenTimer_RT1            (*(reg8 *) OddEvenTimer_TimerHW__RT1)
    #define OddEvenTimer_RT1_PTR        ( (reg8 *) OddEvenTimer_TimerHW__RT1)

    #if (CY_PSOC3 || CY_PSOC5LP)
        #define OddEvenTimer_CONTROL3       (*(reg8 *) OddEvenTimer_TimerHW__CFG2)
        #define OddEvenTimer_CONTROL3_PTR   ( (reg8 *) OddEvenTimer_TimerHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define OddEvenTimer_GLOBAL_ENABLE  (*(reg8 *) OddEvenTimer_TimerHW__PM_ACT_CFG)
    #define OddEvenTimer_GLOBAL_STBY_ENABLE  (*(reg8 *) OddEvenTimer_TimerHW__PM_STBY_CFG)

    #define OddEvenTimer_CAPTURE_LSB         (* (reg16 *) OddEvenTimer_TimerHW__CAP0 )
    #define OddEvenTimer_CAPTURE_LSB_PTR       ((reg16 *) OddEvenTimer_TimerHW__CAP0 )
    #define OddEvenTimer_PERIOD_LSB          (* (reg16 *) OddEvenTimer_TimerHW__PER0 )
    #define OddEvenTimer_PERIOD_LSB_PTR        ((reg16 *) OddEvenTimer_TimerHW__PER0 )
    #define OddEvenTimer_COUNTER_LSB         (* (reg16 *) OddEvenTimer_TimerHW__CNT_CMP0 )
    #define OddEvenTimer_COUNTER_LSB_PTR       ((reg16 *) OddEvenTimer_TimerHW__CNT_CMP0 )


    /***************************************
    *    Register Constants
    ***************************************/

    /* Fixed Function Block Chosen */
    #define OddEvenTimer_BLOCK_EN_MASK                     OddEvenTimer_TimerHW__PM_ACT_MSK
    #define OddEvenTimer_BLOCK_STBY_EN_MASK                OddEvenTimer_TimerHW__PM_STBY_MSK

    /* Control Register Bit Locations */
    /* Interrupt Count - Not valid for Fixed Function Block */
    #define OddEvenTimer_CTRL_INTCNT_SHIFT                  0x00u
    /* Trigger Polarity - Not valid for Fixed Function Block */
    #define OddEvenTimer_CTRL_TRIG_MODE_SHIFT               0x00u
    /* Trigger Enable - Not valid for Fixed Function Block */
    #define OddEvenTimer_CTRL_TRIG_EN_SHIFT                 0x00u
    /* Capture Polarity - Not valid for Fixed Function Block */
    #define OddEvenTimer_CTRL_CAP_MODE_SHIFT                0x00u
    /* Timer Enable - As defined in Register Map, part of TMRX_CFG0 register */
    #define OddEvenTimer_CTRL_ENABLE_SHIFT                  0x00u

    /* Control Register Bit Masks */
    #define OddEvenTimer_CTRL_ENABLE                        ((uint8)((uint8)0x01u << OddEvenTimer_CTRL_ENABLE_SHIFT))

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define OddEvenTimer_CTRL2_IRQ_SEL_SHIFT                 0x00u
    #define OddEvenTimer_CTRL2_IRQ_SEL                      ((uint8)((uint8)0x01u << OddEvenTimer_CTRL2_IRQ_SEL_SHIFT))

    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        /* As defined by Verilog Implementation */
        #define OddEvenTimer_CTRL_MODE_SHIFT                 0x01u
        #define OddEvenTimer_CTRL_MODE_MASK                 ((uint8)((uint8)0x07u << OddEvenTimer_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Control3 Register Bit Locations */
        #define OddEvenTimer_CTRL_RCOD_SHIFT        0x02u
        #define OddEvenTimer_CTRL_ENBL_SHIFT        0x00u
        #define OddEvenTimer_CTRL_MODE_SHIFT        0x00u

        /* Control3 Register Bit Masks */
        #define OddEvenTimer_CTRL_RCOD_MASK  ((uint8)((uint8)0x03u << OddEvenTimer_CTRL_RCOD_SHIFT)) /* ROD and COD bit masks */
        #define OddEvenTimer_CTRL_ENBL_MASK  ((uint8)((uint8)0x80u << OddEvenTimer_CTRL_ENBL_SHIFT)) /* HW_EN bit mask */
        #define OddEvenTimer_CTRL_MODE_MASK  ((uint8)((uint8)0x03u << OddEvenTimer_CTRL_MODE_SHIFT)) /* Run mode bit mask */

        #define OddEvenTimer_CTRL_RCOD       ((uint8)((uint8)0x03u << OddEvenTimer_CTRL_RCOD_SHIFT))
        #define OddEvenTimer_CTRL_ENBL       ((uint8)((uint8)0x80u << OddEvenTimer_CTRL_ENBL_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define OddEvenTimer_RT1_SHIFT                       0x04u
    /* Sync TC and CMP bit masks */
    #define OddEvenTimer_RT1_MASK                        ((uint8)((uint8)0x03u << OddEvenTimer_RT1_SHIFT))
    #define OddEvenTimer_SYNC                            ((uint8)((uint8)0x03u << OddEvenTimer_RT1_SHIFT))
    #define OddEvenTimer_SYNCDSI_SHIFT                   0x00u
    /* Sync all DSI inputs with Mask  */
    #define OddEvenTimer_SYNCDSI_MASK                    ((uint8)((uint8)0x0Fu << OddEvenTimer_SYNCDSI_SHIFT))
    /* Sync all DSI inputs */
    #define OddEvenTimer_SYNCDSI_EN                      ((uint8)((uint8)0x0Fu << OddEvenTimer_SYNCDSI_SHIFT))

    #define OddEvenTimer_CTRL_MODE_PULSEWIDTH            ((uint8)((uint8)0x01u << OddEvenTimer_CTRL_MODE_SHIFT))
    #define OddEvenTimer_CTRL_MODE_PERIOD                ((uint8)((uint8)0x02u << OddEvenTimer_CTRL_MODE_SHIFT))
    #define OddEvenTimer_CTRL_MODE_CONTINUOUS            ((uint8)((uint8)0x00u << OddEvenTimer_CTRL_MODE_SHIFT))

    /* Status Register Bit Locations */
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define OddEvenTimer_STATUS_TC_SHIFT                 0x07u
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define OddEvenTimer_STATUS_CAPTURE_SHIFT            0x06u
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define OddEvenTimer_STATUS_TC_INT_MASK_SHIFT        (OddEvenTimer_STATUS_TC_SHIFT - 0x04u)
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define OddEvenTimer_STATUS_CAPTURE_INT_MASK_SHIFT   (OddEvenTimer_STATUS_CAPTURE_SHIFT - 0x04u)

    /* Status Register Bit Masks */
    #define OddEvenTimer_STATUS_TC                       ((uint8)((uint8)0x01u << OddEvenTimer_STATUS_TC_SHIFT))
    #define OddEvenTimer_STATUS_CAPTURE                  ((uint8)((uint8)0x01u << OddEvenTimer_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on TC */
    #define OddEvenTimer_STATUS_TC_INT_MASK              ((uint8)((uint8)0x01u << OddEvenTimer_STATUS_TC_INT_MASK_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on Capture */
    #define OddEvenTimer_STATUS_CAPTURE_INT_MASK         ((uint8)((uint8)0x01u << OddEvenTimer_STATUS_CAPTURE_INT_MASK_SHIFT))

#else   /* UDB Registers and Register Constants */


    /***************************************
    *           UDB Registers
    ***************************************/

    #define OddEvenTimer_STATUS              (* (reg8 *) OddEvenTimer_TimerUDB_rstSts_stsreg__STATUS_REG )
    #define OddEvenTimer_STATUS_MASK         (* (reg8 *) OddEvenTimer_TimerUDB_rstSts_stsreg__MASK_REG)
    #define OddEvenTimer_STATUS_AUX_CTRL     (* (reg8 *) OddEvenTimer_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define OddEvenTimer_CONTROL             (* (reg8 *) OddEvenTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    
    #if(OddEvenTimer_Resolution <= 8u) /* 8-bit Timer */
        #define OddEvenTimer_CAPTURE_LSB         (* (reg8 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__F0_REG )
        #define OddEvenTimer_CAPTURE_LSB_PTR       ((reg8 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__F0_REG )
        #define OddEvenTimer_PERIOD_LSB          (* (reg8 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__D0_REG )
        #define OddEvenTimer_PERIOD_LSB_PTR        ((reg8 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__D0_REG )
        #define OddEvenTimer_COUNTER_LSB         (* (reg8 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__A0_REG )
        #define OddEvenTimer_COUNTER_LSB_PTR       ((reg8 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__A0_REG )
    #elif(OddEvenTimer_Resolution <= 16u) /* 8-bit Timer */
        #if(CY_PSOC3) /* 8-bit addres space */
            #define OddEvenTimer_CAPTURE_LSB         (* (reg16 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__F0_REG )
            #define OddEvenTimer_CAPTURE_LSB_PTR       ((reg16 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__F0_REG )
            #define OddEvenTimer_PERIOD_LSB          (* (reg16 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__D0_REG )
            #define OddEvenTimer_PERIOD_LSB_PTR        ((reg16 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__D0_REG )
            #define OddEvenTimer_COUNTER_LSB         (* (reg16 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__A0_REG )
            #define OddEvenTimer_COUNTER_LSB_PTR       ((reg16 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define OddEvenTimer_CAPTURE_LSB         (* (reg16 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__16BIT_F0_REG )
            #define OddEvenTimer_CAPTURE_LSB_PTR       ((reg16 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__16BIT_F0_REG )
            #define OddEvenTimer_PERIOD_LSB          (* (reg16 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__16BIT_D0_REG )
            #define OddEvenTimer_PERIOD_LSB_PTR        ((reg16 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__16BIT_D0_REG )
            #define OddEvenTimer_COUNTER_LSB         (* (reg16 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__16BIT_A0_REG )
            #define OddEvenTimer_COUNTER_LSB_PTR       ((reg16 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */
    #elif(OddEvenTimer_Resolution <= 24u)/* 24-bit Timer */
        #define OddEvenTimer_CAPTURE_LSB         (* (reg32 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__F0_REG )
        #define OddEvenTimer_CAPTURE_LSB_PTR       ((reg32 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__F0_REG )
        #define OddEvenTimer_PERIOD_LSB          (* (reg32 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__D0_REG )
        #define OddEvenTimer_PERIOD_LSB_PTR        ((reg32 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__D0_REG )
        #define OddEvenTimer_COUNTER_LSB         (* (reg32 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__A0_REG )
        #define OddEvenTimer_COUNTER_LSB_PTR       ((reg32 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__A0_REG )
    #else /* 32-bit Timer */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define OddEvenTimer_CAPTURE_LSB         (* (reg32 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__F0_REG )
            #define OddEvenTimer_CAPTURE_LSB_PTR       ((reg32 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__F0_REG )
            #define OddEvenTimer_PERIOD_LSB          (* (reg32 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__D0_REG )
            #define OddEvenTimer_PERIOD_LSB_PTR        ((reg32 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__D0_REG )
            #define OddEvenTimer_COUNTER_LSB         (* (reg32 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__A0_REG )
            #define OddEvenTimer_COUNTER_LSB_PTR       ((reg32 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define OddEvenTimer_CAPTURE_LSB         (* (reg32 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__32BIT_F0_REG )
            #define OddEvenTimer_CAPTURE_LSB_PTR       ((reg32 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__32BIT_F0_REG )
            #define OddEvenTimer_PERIOD_LSB          (* (reg32 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__32BIT_D0_REG )
            #define OddEvenTimer_PERIOD_LSB_PTR        ((reg32 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__32BIT_D0_REG )
            #define OddEvenTimer_COUNTER_LSB         (* (reg32 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__32BIT_A0_REG )
            #define OddEvenTimer_COUNTER_LSB_PTR       ((reg32 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */ 
    #endif

    #define OddEvenTimer_COUNTER_LSB_PTR_8BIT       ((reg8 *) OddEvenTimer_TimerUDB_sT32_timerdp_u0__A0_REG )
    
    #if (OddEvenTimer_UsingHWCaptureCounter)
        #define OddEvenTimer_CAP_COUNT              (*(reg8 *) OddEvenTimer_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define OddEvenTimer_CAP_COUNT_PTR          ( (reg8 *) OddEvenTimer_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define OddEvenTimer_CAPTURE_COUNT_CTRL     (*(reg8 *) OddEvenTimer_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
        #define OddEvenTimer_CAPTURE_COUNT_CTRL_PTR ( (reg8 *) OddEvenTimer_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
    #endif /* (OddEvenTimer_UsingHWCaptureCounter) */


    /***************************************
    *       Register Constants
    ***************************************/

    /* Control Register Bit Locations */
    #define OddEvenTimer_CTRL_INTCNT_SHIFT              0x00u       /* As defined by Verilog Implementation */
    #define OddEvenTimer_CTRL_TRIG_MODE_SHIFT           0x02u       /* As defined by Verilog Implementation */
    #define OddEvenTimer_CTRL_TRIG_EN_SHIFT             0x04u       /* As defined by Verilog Implementation */
    #define OddEvenTimer_CTRL_CAP_MODE_SHIFT            0x05u       /* As defined by Verilog Implementation */
    #define OddEvenTimer_CTRL_ENABLE_SHIFT              0x07u       /* As defined by Verilog Implementation */

    /* Control Register Bit Masks */
    #define OddEvenTimer_CTRL_INTCNT_MASK               ((uint8)((uint8)0x03u << OddEvenTimer_CTRL_INTCNT_SHIFT))
    #define OddEvenTimer_CTRL_TRIG_MODE_MASK            ((uint8)((uint8)0x03u << OddEvenTimer_CTRL_TRIG_MODE_SHIFT))
    #define OddEvenTimer_CTRL_TRIG_EN                   ((uint8)((uint8)0x01u << OddEvenTimer_CTRL_TRIG_EN_SHIFT))
    #define OddEvenTimer_CTRL_CAP_MODE_MASK             ((uint8)((uint8)0x03u << OddEvenTimer_CTRL_CAP_MODE_SHIFT))
    #define OddEvenTimer_CTRL_ENABLE                    ((uint8)((uint8)0x01u << OddEvenTimer_CTRL_ENABLE_SHIFT))

    /* Bit Counter (7-bit) Control Register Bit Definitions */
    /* As defined by the Register map for the AUX Control Register */
    #define OddEvenTimer_CNTR_ENABLE                    0x20u

    /* Status Register Bit Locations */
    #define OddEvenTimer_STATUS_TC_SHIFT                0x00u  /* As defined by Verilog Implementation */
    #define OddEvenTimer_STATUS_CAPTURE_SHIFT           0x01u  /* As defined by Verilog Implementation */
    #define OddEvenTimer_STATUS_TC_INT_MASK_SHIFT       OddEvenTimer_STATUS_TC_SHIFT
    #define OddEvenTimer_STATUS_CAPTURE_INT_MASK_SHIFT  OddEvenTimer_STATUS_CAPTURE_SHIFT
    #define OddEvenTimer_STATUS_FIFOFULL_SHIFT          0x02u  /* As defined by Verilog Implementation */
    #define OddEvenTimer_STATUS_FIFONEMP_SHIFT          0x03u  /* As defined by Verilog Implementation */
    #define OddEvenTimer_STATUS_FIFOFULL_INT_MASK_SHIFT OddEvenTimer_STATUS_FIFOFULL_SHIFT

    /* Status Register Bit Masks */
    /* Sticky TC Event Bit-Mask */
    #define OddEvenTimer_STATUS_TC                      ((uint8)((uint8)0x01u << OddEvenTimer_STATUS_TC_SHIFT))
    /* Sticky Capture Event Bit-Mask */
    #define OddEvenTimer_STATUS_CAPTURE                 ((uint8)((uint8)0x01u << OddEvenTimer_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define OddEvenTimer_STATUS_TC_INT_MASK             ((uint8)((uint8)0x01u << OddEvenTimer_STATUS_TC_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define OddEvenTimer_STATUS_CAPTURE_INT_MASK        ((uint8)((uint8)0x01u << OddEvenTimer_STATUS_CAPTURE_SHIFT))
    /* NOT-Sticky FIFO Full Bit-Mask */
    #define OddEvenTimer_STATUS_FIFOFULL                ((uint8)((uint8)0x01u << OddEvenTimer_STATUS_FIFOFULL_SHIFT))
    /* NOT-Sticky FIFO Not Empty Bit-Mask */
    #define OddEvenTimer_STATUS_FIFONEMP                ((uint8)((uint8)0x01u << OddEvenTimer_STATUS_FIFONEMP_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define OddEvenTimer_STATUS_FIFOFULL_INT_MASK       ((uint8)((uint8)0x01u << OddEvenTimer_STATUS_FIFOFULL_SHIFT))

    #define OddEvenTimer_STATUS_ACTL_INT_EN             0x10u   /* As defined for the ACTL Register */

    /* Datapath Auxillary Control Register definitions */
    #define OddEvenTimer_AUX_CTRL_FIFO0_CLR             0x01u   /* As defined by Register map */
    #define OddEvenTimer_AUX_CTRL_FIFO1_CLR             0x02u   /* As defined by Register map */
    #define OddEvenTimer_AUX_CTRL_FIFO0_LVL             0x04u   /* As defined by Register map */
    #define OddEvenTimer_AUX_CTRL_FIFO1_LVL             0x08u   /* As defined by Register map */
    #define OddEvenTimer_STATUS_ACTL_INT_EN_MASK        0x10u   /* As defined for the ACTL Register */

#endif /* Implementation Specific Registers and Register Constants */

#endif  /* CY_TIMER_OddEvenTimer_H */


/* [] END OF FILE */
