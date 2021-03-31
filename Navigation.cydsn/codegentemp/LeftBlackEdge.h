/*******************************************************************************
* File Name: LeftBlackEdge.h
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
#if !defined(CY_ISR_LeftBlackEdge_H)
#define CY_ISR_LeftBlackEdge_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void LeftBlackEdge_Start(void);
void LeftBlackEdge_StartEx(cyisraddress address);
void LeftBlackEdge_Stop(void);

CY_ISR_PROTO(LeftBlackEdge_Interrupt);

void LeftBlackEdge_SetVector(cyisraddress address);
cyisraddress LeftBlackEdge_GetVector(void);

void LeftBlackEdge_SetPriority(uint8 priority);
uint8 LeftBlackEdge_GetPriority(void);

void LeftBlackEdge_Enable(void);
uint8 LeftBlackEdge_GetState(void);
void LeftBlackEdge_Disable(void);

void LeftBlackEdge_SetPending(void);
void LeftBlackEdge_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the LeftBlackEdge ISR. */
#define LeftBlackEdge_INTC_VECTOR            ((reg32 *) LeftBlackEdge__INTC_VECT)

/* Address of the LeftBlackEdge ISR priority. */
#define LeftBlackEdge_INTC_PRIOR             ((reg8 *) LeftBlackEdge__INTC_PRIOR_REG)

/* Priority of the LeftBlackEdge interrupt. */
#define LeftBlackEdge_INTC_PRIOR_NUMBER      LeftBlackEdge__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable LeftBlackEdge interrupt. */
#define LeftBlackEdge_INTC_SET_EN            ((reg32 *) LeftBlackEdge__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the LeftBlackEdge interrupt. */
#define LeftBlackEdge_INTC_CLR_EN            ((reg32 *) LeftBlackEdge__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the LeftBlackEdge interrupt state to pending. */
#define LeftBlackEdge_INTC_SET_PD            ((reg32 *) LeftBlackEdge__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the LeftBlackEdge interrupt. */
#define LeftBlackEdge_INTC_CLR_PD            ((reg32 *) LeftBlackEdge__INTC_CLR_PD_REG)


#endif /* CY_ISR_LeftBlackEdge_H */


/* [] END OF FILE */
