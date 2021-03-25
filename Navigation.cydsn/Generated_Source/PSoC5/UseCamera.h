/*******************************************************************************
* File Name: UseCamera.h
* Version 1.71
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_UseCamera_H)
#define CY_ISR_UseCamera_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void UseCamera_Start(void);
void UseCamera_StartEx(cyisraddress address);
void UseCamera_Stop(void);

CY_ISR_PROTO(UseCamera_Interrupt);

void UseCamera_SetVector(cyisraddress address);
cyisraddress UseCamera_GetVector(void);

void UseCamera_SetPriority(uint8 priority);
uint8 UseCamera_GetPriority(void);

void UseCamera_Enable(void);
uint8 UseCamera_GetState(void);
void UseCamera_Disable(void);

void UseCamera_SetPending(void);
void UseCamera_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the UseCamera ISR. */
#define UseCamera_INTC_VECTOR            ((reg32 *) UseCamera__INTC_VECT)

/* Address of the UseCamera ISR priority. */
#define UseCamera_INTC_PRIOR             ((reg8 *) UseCamera__INTC_PRIOR_REG)

/* Priority of the UseCamera interrupt. */
#define UseCamera_INTC_PRIOR_NUMBER      UseCamera__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable UseCamera interrupt. */
#define UseCamera_INTC_SET_EN            ((reg32 *) UseCamera__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the UseCamera interrupt. */
#define UseCamera_INTC_CLR_EN            ((reg32 *) UseCamera__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the UseCamera interrupt state to pending. */
#define UseCamera_INTC_SET_PD            ((reg32 *) UseCamera__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the UseCamera interrupt. */
#define UseCamera_INTC_CLR_PD            ((reg32 *) UseCamera__INTC_CLR_PD_REG)


#endif /* CY_ISR_UseCamera_H */


/* [] END OF FILE */
