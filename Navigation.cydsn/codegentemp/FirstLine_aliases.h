/*******************************************************************************
* File Name: FirstLine.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_FirstLine_ALIASES_H) /* Pins FirstLine_ALIASES_H */
#define CY_PINS_FirstLine_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define FirstLine_0			(FirstLine__0__PC)
#define FirstLine_0_INTR	((uint16)((uint16)0x0001u << FirstLine__0__SHIFT))

#define FirstLine_INTR_ALL	 ((uint16)(FirstLine_0_INTR))

#endif /* End Pins FirstLine_ALIASES_H */


/* [] END OF FILE */
