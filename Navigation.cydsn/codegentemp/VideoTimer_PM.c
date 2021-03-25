/*******************************************************************************
* File Name: VideoTimer_PM.c
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

#include "VideoTimer.h"

static VideoTimer_backupStruct VideoTimer_backup;


/*******************************************************************************
* Function Name: VideoTimer_SaveConfig
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
*  VideoTimer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void VideoTimer_SaveConfig(void) 
{
    #if (!VideoTimer_UsingFixedFunction)
        VideoTimer_backup.TimerUdb = VideoTimer_ReadCounter();
        VideoTimer_backup.InterruptMaskValue = VideoTimer_STATUS_MASK;
        #if (VideoTimer_UsingHWCaptureCounter)
            VideoTimer_backup.TimerCaptureCounter = VideoTimer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!VideoTimer_UDB_CONTROL_REG_REMOVED)
            VideoTimer_backup.TimerControlRegister = VideoTimer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: VideoTimer_RestoreConfig
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
*  VideoTimer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void VideoTimer_RestoreConfig(void) 
{   
    #if (!VideoTimer_UsingFixedFunction)

        VideoTimer_WriteCounter(VideoTimer_backup.TimerUdb);
        VideoTimer_STATUS_MASK =VideoTimer_backup.InterruptMaskValue;
        #if (VideoTimer_UsingHWCaptureCounter)
            VideoTimer_SetCaptureCount(VideoTimer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!VideoTimer_UDB_CONTROL_REG_REMOVED)
            VideoTimer_WriteControlRegister(VideoTimer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: VideoTimer_Sleep
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
*  VideoTimer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void VideoTimer_Sleep(void) 
{
    #if(!VideoTimer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(VideoTimer_CTRL_ENABLE == (VideoTimer_CONTROL & VideoTimer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            VideoTimer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            VideoTimer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    VideoTimer_Stop();
    VideoTimer_SaveConfig();
}


/*******************************************************************************
* Function Name: VideoTimer_Wakeup
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
*  VideoTimer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void VideoTimer_Wakeup(void) 
{
    VideoTimer_RestoreConfig();
    #if(!VideoTimer_UDB_CONTROL_REG_REMOVED)
        if(VideoTimer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                VideoTimer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
