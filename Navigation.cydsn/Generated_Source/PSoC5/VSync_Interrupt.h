/*******************************************************************************
* File Name: VSync_Interrupt.h
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
#if !defined(CY_ISR_VSync_Interrupt_H)
#define CY_ISR_VSync_Interrupt_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void VSync_Interrupt_Start(void);
void VSync_Interrupt_StartEx(cyisraddress address);
void VSync_Interrupt_Stop(void);

CY_ISR_PROTO(VSync_Interrupt_Interrupt);

void VSync_Interrupt_SetVector(cyisraddress address);
cyisraddress VSync_Interrupt_GetVector(void);

void VSync_Interrupt_SetPriority(uint8 priority);
uint8 VSync_Interrupt_GetPriority(void);

void VSync_Interrupt_Enable(void);
uint8 VSync_Interrupt_GetState(void);
void VSync_Interrupt_Disable(void);

void VSync_Interrupt_SetPending(void);
void VSync_Interrupt_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the VSync_Interrupt ISR. */
#define VSync_Interrupt_INTC_VECTOR            ((reg32 *) VSync_Interrupt__INTC_VECT)

/* Address of the VSync_Interrupt ISR priority. */
#define VSync_Interrupt_INTC_PRIOR             ((reg8 *) VSync_Interrupt__INTC_PRIOR_REG)

/* Priority of the VSync_Interrupt interrupt. */
#define VSync_Interrupt_INTC_PRIOR_NUMBER      VSync_Interrupt__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable VSync_Interrupt interrupt. */
#define VSync_Interrupt_INTC_SET_EN            ((reg32 *) VSync_Interrupt__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the VSync_Interrupt interrupt. */
#define VSync_Interrupt_INTC_CLR_EN            ((reg32 *) VSync_Interrupt__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the VSync_Interrupt interrupt state to pending. */
#define VSync_Interrupt_INTC_SET_PD            ((reg32 *) VSync_Interrupt__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the VSync_Interrupt interrupt. */
#define VSync_Interrupt_INTC_CLR_PD            ((reg32 *) VSync_Interrupt__INTC_CLR_PD_REG)


#endif /* CY_ISR_VSync_Interrupt_H */


/* [] END OF FILE */
