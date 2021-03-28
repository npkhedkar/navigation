/*******************************************************************************
* File Name: OddEvenTimer_PM.c
* Version 2.80
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "OddEvenTimer.h"

static OddEvenTimer_backupStruct OddEvenTimer_backup;


/*******************************************************************************
* Function Name: OddEvenTimer_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  OddEvenTimer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void OddEvenTimer_SaveConfig(void) 
{
    #if (!OddEvenTimer_UsingFixedFunction)
        OddEvenTimer_backup.TimerUdb = OddEvenTimer_ReadCounter();
        OddEvenTimer_backup.InterruptMaskValue = OddEvenTimer_STATUS_MASK;
        #if (OddEvenTimer_UsingHWCaptureCounter)
            OddEvenTimer_backup.TimerCaptureCounter = OddEvenTimer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!OddEvenTimer_UDB_CONTROL_REG_REMOVED)
            OddEvenTimer_backup.TimerControlRegister = OddEvenTimer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: OddEvenTimer_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  OddEvenTimer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void OddEvenTimer_RestoreConfig(void) 
{   
    #if (!OddEvenTimer_UsingFixedFunction)

        OddEvenTimer_WriteCounter(OddEvenTimer_backup.TimerUdb);
        OddEvenTimer_STATUS_MASK =OddEvenTimer_backup.InterruptMaskValue;
        #if (OddEvenTimer_UsingHWCaptureCounter)
            OddEvenTimer_SetCaptureCount(OddEvenTimer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!OddEvenTimer_UDB_CONTROL_REG_REMOVED)
            OddEvenTimer_WriteControlRegister(OddEvenTimer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: OddEvenTimer_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  OddEvenTimer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void OddEvenTimer_Sleep(void) 
{
    #if(!OddEvenTimer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(OddEvenTimer_CTRL_ENABLE == (OddEvenTimer_CONTROL & OddEvenTimer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            OddEvenTimer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            OddEvenTimer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    OddEvenTimer_Stop();
    OddEvenTimer_SaveConfig();
}


/*******************************************************************************
* Function Name: OddEvenTimer_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  OddEvenTimer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void OddEvenTimer_Wakeup(void) 
{
    OddEvenTimer_RestoreConfig();
    #if(!OddEvenTimer_UDB_CONTROL_REG_REMOVED)
        if(OddEvenTimer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                OddEvenTimer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
