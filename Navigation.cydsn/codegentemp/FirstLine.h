/*******************************************************************************
* File Name: FirstLine.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_FirstLine_H) /* Pins FirstLine_H */
#define CY_PINS_FirstLine_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "FirstLine_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 FirstLine__PORT == 15 && ((FirstLine__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    FirstLine_Write(uint8 value);
void    FirstLine_SetDriveMode(uint8 mode);
uint8   FirstLine_ReadDataReg(void);
uint8   FirstLine_Read(void);
void    FirstLine_SetInterruptMode(uint16 position, uint16 mode);
uint8   FirstLine_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the FirstLine_SetDriveMode() function.
     *  @{
     */
        #define FirstLine_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define FirstLine_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define FirstLine_DM_RES_UP          PIN_DM_RES_UP
        #define FirstLine_DM_RES_DWN         PIN_DM_RES_DWN
        #define FirstLine_DM_OD_LO           PIN_DM_OD_LO
        #define FirstLine_DM_OD_HI           PIN_DM_OD_HI
        #define FirstLine_DM_STRONG          PIN_DM_STRONG
        #define FirstLine_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define FirstLine_MASK               FirstLine__MASK
#define FirstLine_SHIFT              FirstLine__SHIFT
#define FirstLine_WIDTH              1u

/* Interrupt constants */
#if defined(FirstLine__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in FirstLine_SetInterruptMode() function.
     *  @{
     */
        #define FirstLine_INTR_NONE      (uint16)(0x0000u)
        #define FirstLine_INTR_RISING    (uint16)(0x0001u)
        #define FirstLine_INTR_FALLING   (uint16)(0x0002u)
        #define FirstLine_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define FirstLine_INTR_MASK      (0x01u) 
#endif /* (FirstLine__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define FirstLine_PS                     (* (reg8 *) FirstLine__PS)
/* Data Register */
#define FirstLine_DR                     (* (reg8 *) FirstLine__DR)
/* Port Number */
#define FirstLine_PRT_NUM                (* (reg8 *) FirstLine__PRT) 
/* Connect to Analog Globals */                                                  
#define FirstLine_AG                     (* (reg8 *) FirstLine__AG)                       
/* Analog MUX bux enable */
#define FirstLine_AMUX                   (* (reg8 *) FirstLine__AMUX) 
/* Bidirectional Enable */                                                        
#define FirstLine_BIE                    (* (reg8 *) FirstLine__BIE)
/* Bit-mask for Aliased Register Access */
#define FirstLine_BIT_MASK               (* (reg8 *) FirstLine__BIT_MASK)
/* Bypass Enable */
#define FirstLine_BYP                    (* (reg8 *) FirstLine__BYP)
/* Port wide control signals */                                                   
#define FirstLine_CTL                    (* (reg8 *) FirstLine__CTL)
/* Drive Modes */
#define FirstLine_DM0                    (* (reg8 *) FirstLine__DM0) 
#define FirstLine_DM1                    (* (reg8 *) FirstLine__DM1)
#define FirstLine_DM2                    (* (reg8 *) FirstLine__DM2) 
/* Input Buffer Disable Override */
#define FirstLine_INP_DIS                (* (reg8 *) FirstLine__INP_DIS)
/* LCD Common or Segment Drive */
#define FirstLine_LCD_COM_SEG            (* (reg8 *) FirstLine__LCD_COM_SEG)
/* Enable Segment LCD */
#define FirstLine_LCD_EN                 (* (reg8 *) FirstLine__LCD_EN)
/* Slew Rate Control */
#define FirstLine_SLW                    (* (reg8 *) FirstLine__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define FirstLine_PRTDSI__CAPS_SEL       (* (reg8 *) FirstLine__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define FirstLine_PRTDSI__DBL_SYNC_IN    (* (reg8 *) FirstLine__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define FirstLine_PRTDSI__OE_SEL0        (* (reg8 *) FirstLine__PRTDSI__OE_SEL0) 
#define FirstLine_PRTDSI__OE_SEL1        (* (reg8 *) FirstLine__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define FirstLine_PRTDSI__OUT_SEL0       (* (reg8 *) FirstLine__PRTDSI__OUT_SEL0) 
#define FirstLine_PRTDSI__OUT_SEL1       (* (reg8 *) FirstLine__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define FirstLine_PRTDSI__SYNC_OUT       (* (reg8 *) FirstLine__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(FirstLine__SIO_CFG)
    #define FirstLine_SIO_HYST_EN        (* (reg8 *) FirstLine__SIO_HYST_EN)
    #define FirstLine_SIO_REG_HIFREQ     (* (reg8 *) FirstLine__SIO_REG_HIFREQ)
    #define FirstLine_SIO_CFG            (* (reg8 *) FirstLine__SIO_CFG)
    #define FirstLine_SIO_DIFF           (* (reg8 *) FirstLine__SIO_DIFF)
#endif /* (FirstLine__SIO_CFG) */

/* Interrupt Registers */
#if defined(FirstLine__INTSTAT)
    #define FirstLine_INTSTAT            (* (reg8 *) FirstLine__INTSTAT)
    #define FirstLine_SNAP               (* (reg8 *) FirstLine__SNAP)
    
	#define FirstLine_0_INTTYPE_REG 		(* (reg8 *) FirstLine__0__INTTYPE)
#endif /* (FirstLine__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_FirstLine_H */


/* [] END OF FILE */
