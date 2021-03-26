/*******************************************************************************
* File Name: Black.h
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
#if !defined(CY_ISR_Black_H)
#define CY_ISR_Black_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Black_Start(void);
void Black_StartEx(cyisraddress address);
void Black_Stop(void);

CY_ISR_PROTO(Black_Interrupt);

void Black_SetVector(cyisraddress address);
cyisraddress Black_GetVector(void);

void Black_SetPriority(uint8 priority);
uint8 Black_GetPriority(void);

void Black_Enable(void);
uint8 Black_GetState(void);
void Black_Disable(void);

void Black_SetPending(void);
void Black_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Black ISR. */
#define Black_INTC_VECTOR            ((reg32 *) Black__INTC_VECT)

/* Address of the Black ISR priority. */
#define Black_INTC_PRIOR             ((reg8 *) Black__INTC_PRIOR_REG)

/* Priority of the Black interrupt. */
#define Black_INTC_PRIOR_NUMBER      Black__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Black interrupt. */
#define Black_INTC_SET_EN            ((reg32 *) Black__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Black interrupt. */
#define Black_INTC_CLR_EN            ((reg32 *) Black__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Black interrupt state to pending. */
#define Black_INTC_SET_PD            ((reg32 *) Black__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Black interrupt. */
#define Black_INTC_CLR_PD            ((reg32 *) Black__INTC_CLR_PD_REG)


#endif /* CY_ISR_Black_H */


/* [] END OF FILE */
