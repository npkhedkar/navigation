/*******************************************************************************
* File Name: Counter.h
* Version 1.0
*
* Description:
*  This header file contains registers and constants associated with the
*  Count7 component.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_COUNT7_Counter_H)
#define CY_COUNT7_Counter_H

#include "cyfitter.h"

#if ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) || \
     (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC4) || \
     (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC5))
    #include "cytypes.h"
    #include "CyLib.h"
#else
    #include "syslib/cy_syslib.h"
#endif


/***************************************
* Function Prototypes
***************************************/
void  Counter_Init(void) ;
void  Counter_Enable(void) ;
void  Counter_Start(void) ;
void  Counter_Stop(void) ;
void  Counter_WriteCounter(uint8 count) ;
uint8 Counter_ReadCounter(void) ;
void  Counter_WritePeriod(uint8 period) ;
uint8 Counter_ReadPeriod(void) ;
void  Counter_SaveConfig(void) ;
void  Counter_RestoreConfig(void) ;
void  Counter_Sleep(void) ;
void  Counter_Wakeup(void) ;


/***************************************
*     Data Struct Definitions
***************************************/
/* Structure to save registers before go to sleep */
typedef struct
{
    uint8 enableState;
    uint8 count;
} Counter_BACKUP_STRUCT;


/***************************************
*           Global Variables
***************************************/
extern Counter_BACKUP_STRUCT Counter_backup;
extern uint8 Counter_initVar;


/***************************************
* Initial Parameter
***************************************/
#define Counter_INITIAL_PERIOD               (15u)


/***************************************
* Registers
***************************************/
#define Counter_COUNT_REG                    (*(reg8 *) Counter_Counter7__COUNT_REG)
#define Counter_COUNT_PTR                    ( (reg8 *) Counter_Counter7__COUNT_REG)
#define Counter_PERIOD_REG                   (*(reg8 *) Counter_Counter7__PERIOD_REG)
#define Counter_PERIOD_PTR                   ( (reg8 *) Counter_Counter7__PERIOD_REG)
#define Counter_AUX_CONTROL_REG              (*(reg8 *) Counter_Counter7__CONTROL_AUX_CTL_REG)
#define Counter_AUX_CONTROL_PTR              ( (reg8 *) Counter_Counter7__CONTROL_AUX_CTL_REG)


/***************************************
* Register Constants
***************************************/
#define Counter_COUNTER_START                (0x20u)

/* This constant is used to mask the TC bit (bit#7) in the Count register */
#define Counter_COUNT_7BIT_MASK              (0x7Fu)


#endif /* CY_COUNT7_Counter_H */


/* [] END OF FILE */
