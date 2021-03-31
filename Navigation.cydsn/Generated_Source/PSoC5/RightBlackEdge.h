/*******************************************************************************
* File Name: RightBlackEdge.h
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
#if !defined(CY_ISR_RightBlackEdge_H)
#define CY_ISR_RightBlackEdge_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void RightBlackEdge_Start(void);
void RightBlackEdge_StartEx(cyisraddress address);
void RightBlackEdge_Stop(void);

CY_ISR_PROTO(RightBlackEdge_Interrupt);

void RightBlackEdge_SetVector(cyisraddress address);
cyisraddress RightBlackEdge_GetVector(void);

void RightBlackEdge_SetPriority(uint8 priority);
uint8 RightBlackEdge_GetPriority(void);

void RightBlackEdge_Enable(void);
uint8 RightBlackEdge_GetState(void);
void RightBlackEdge_Disable(void);

void RightBlackEdge_SetPending(void);
void RightBlackEdge_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the RightBlackEdge ISR. */
#define RightBlackEdge_INTC_VECTOR            ((reg32 *) RightBlackEdge__INTC_VECT)

/* Address of the RightBlackEdge ISR priority. */
#define RightBlackEdge_INTC_PRIOR             ((reg8 *) RightBlackEdge__INTC_PRIOR_REG)

/* Priority of the RightBlackEdge interrupt. */
#define RightBlackEdge_INTC_PRIOR_NUMBER      RightBlackEdge__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable RightBlackEdge interrupt. */
#define RightBlackEdge_INTC_SET_EN            ((reg32 *) RightBlackEdge__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the RightBlackEdge interrupt. */
#define RightBlackEdge_INTC_CLR_EN            ((reg32 *) RightBlackEdge__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the RightBlackEdge interrupt state to pending. */
#define RightBlackEdge_INTC_SET_PD            ((reg32 *) RightBlackEdge__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the RightBlackEdge interrupt. */
#define RightBlackEdge_INTC_CLR_PD            ((reg32 *) RightBlackEdge__INTC_CLR_PD_REG)


#endif /* CY_ISR_RightBlackEdge_H */


/* [] END OF FILE */
