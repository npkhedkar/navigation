/*******************************************************************************
* File Name: NewFrame.h
* Version 1.70
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
#if !defined(CY_ISR_NewFrame_H)
#define CY_ISR_NewFrame_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void NewFrame_Start(void);
void NewFrame_StartEx(cyisraddress address);
void NewFrame_Stop(void);

CY_ISR_PROTO(NewFrame_Interrupt);

void NewFrame_SetVector(cyisraddress address);
cyisraddress NewFrame_GetVector(void);

void NewFrame_SetPriority(uint8 priority);
uint8 NewFrame_GetPriority(void);

void NewFrame_Enable(void);
uint8 NewFrame_GetState(void);
void NewFrame_Disable(void);

void NewFrame_SetPending(void);
void NewFrame_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the NewFrame ISR. */
#define NewFrame_INTC_VECTOR            ((reg32 *) NewFrame__INTC_VECT)

/* Address of the NewFrame ISR priority. */
#define NewFrame_INTC_PRIOR             ((reg8 *) NewFrame__INTC_PRIOR_REG)

/* Priority of the NewFrame interrupt. */
#define NewFrame_INTC_PRIOR_NUMBER      NewFrame__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable NewFrame interrupt. */
#define NewFrame_INTC_SET_EN            ((reg32 *) NewFrame__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the NewFrame interrupt. */
#define NewFrame_INTC_CLR_EN            ((reg32 *) NewFrame__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the NewFrame interrupt state to pending. */
#define NewFrame_INTC_SET_PD            ((reg32 *) NewFrame__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the NewFrame interrupt. */
#define NewFrame_INTC_CLR_PD            ((reg32 *) NewFrame__INTC_CLR_PD_REG)


#endif /* CY_ISR_NewFrame_H */


/* [] END OF FILE */
