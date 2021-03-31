/*******************************************************************************
* File Name: VideoTimerR_PM.c
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

#include "VideoTimerR.h"

static VideoTimerR_backupStruct VideoTimerR_backup;


/*******************************************************************************
* Function Name: VideoTimerR_SaveConfig
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
*  VideoTimerR_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void VideoTimerR_SaveConfig(void) 
{
    #if (!VideoTimerR_UsingFixedFunction)
        VideoTimerR_backup.TimerUdb = VideoTimerR_ReadCounter();
        VideoTimerR_backup.InterruptMaskValue = VideoTimerR_STATUS_MASK;
        #if (VideoTimerR_UsingHWCaptureCounter)
            VideoTimerR_backup.TimerCaptureCounter = VideoTimerR_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!VideoTimerR_UDB_CONTROL_REG_REMOVED)
            VideoTimerR_backup.TimerControlRegister = VideoTimerR_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: VideoTimerR_RestoreConfig
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
*  VideoTimerR_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void VideoTimerR_RestoreConfig(void) 
{   
    #if (!VideoTimerR_UsingFixedFunction)

        VideoTimerR_WriteCounter(VideoTimerR_backup.TimerUdb);
        VideoTimerR_STATUS_MASK =VideoTimerR_backup.InterruptMaskValue;
        #if (VideoTimerR_UsingHWCaptureCounter)
            VideoTimerR_SetCaptureCount(VideoTimerR_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!VideoTimerR_UDB_CONTROL_REG_REMOVED)
            VideoTimerR_WriteControlRegister(VideoTimerR_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: VideoTimerR_Sleep
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
*  VideoTimerR_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void VideoTimerR_Sleep(void) 
{
    #if(!VideoTimerR_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(VideoTimerR_CTRL_ENABLE == (VideoTimerR_CONTROL & VideoTimerR_CTRL_ENABLE))
        {
            /* Timer is enabled */
            VideoTimerR_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            VideoTimerR_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    VideoTimerR_Stop();
    VideoTimerR_SaveConfig();
}


/*******************************************************************************
* Function Name: VideoTimerR_Wakeup
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
*  VideoTimerR_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void VideoTimerR_Wakeup(void) 
{
    VideoTimerR_RestoreConfig();
    #if(!VideoTimerR_UDB_CONTROL_REG_REMOVED)
        if(VideoTimerR_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                VideoTimerR_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
