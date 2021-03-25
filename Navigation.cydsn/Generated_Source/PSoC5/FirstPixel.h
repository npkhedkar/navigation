/*******************************************************************************
* File Name: FirstPixel.h
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
#if !defined(CY_ISR_FirstPixel_H)
#define CY_ISR_FirstPixel_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void FirstPixel_Start(void);
void FirstPixel_StartEx(cyisraddress address);
void FirstPixel_Stop(void);

CY_ISR_PROTO(FirstPixel_Interrupt);

void FirstPixel_SetVector(cyisraddress address);
cyisraddress FirstPixel_GetVector(void);

void FirstPixel_SetPriority(uint8 priority);
uint8 FirstPixel_GetPriority(void);

void FirstPixel_Enable(void);
uint8 FirstPixel_GetState(void);
void FirstPixel_Disable(void);

void FirstPixel_SetPending(void);
void FirstPixel_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the FirstPixel ISR. */
#define FirstPixel_INTC_VECTOR            ((reg32 *) FirstPixel__INTC_VECT)

/* Address of the FirstPixel ISR priority. */
#define FirstPixel_INTC_PRIOR             ((reg8 *) FirstPixel__INTC_PRIOR_REG)

/* Priority of the FirstPixel interrupt. */
#define FirstPixel_INTC_PRIOR_NUMBER      FirstPixel__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable FirstPixel interrupt. */
#define FirstPixel_INTC_SET_EN            ((reg32 *) FirstPixel__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the FirstPixel interrupt. */
#define FirstPixel_INTC_CLR_EN            ((reg32 *) FirstPixel__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the FirstPixel interrupt state to pending. */
#define FirstPixel_INTC_SET_PD            ((reg32 *) FirstPixel__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the FirstPixel interrupt. */
#define FirstPixel_INTC_CLR_PD            ((reg32 *) FirstPixel__INTC_CLR_PD_REG)


#endif /* CY_ISR_FirstPixel_H */


/* [] END OF FILE */
