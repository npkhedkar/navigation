/*******************************************************************************
* File Name: VerifyCompOut.h  
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

#if !defined(CY_PINS_VerifyCompOut_H) /* Pins VerifyCompOut_H */
#define CY_PINS_VerifyCompOut_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "VerifyCompOut_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 VerifyCompOut__PORT == 15 && ((VerifyCompOut__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    VerifyCompOut_Write(uint8 value);
void    VerifyCompOut_SetDriveMode(uint8 mode);
uint8   VerifyCompOut_ReadDataReg(void);
uint8   VerifyCompOut_Read(void);
void    VerifyCompOut_SetInterruptMode(uint16 position, uint16 mode);
uint8   VerifyCompOut_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the VerifyCompOut_SetDriveMode() function.
     *  @{
     */
        #define VerifyCompOut_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define VerifyCompOut_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define VerifyCompOut_DM_RES_UP          PIN_DM_RES_UP
        #define VerifyCompOut_DM_RES_DWN         PIN_DM_RES_DWN
        #define VerifyCompOut_DM_OD_LO           PIN_DM_OD_LO
        #define VerifyCompOut_DM_OD_HI           PIN_DM_OD_HI
        #define VerifyCompOut_DM_STRONG          PIN_DM_STRONG
        #define VerifyCompOut_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define VerifyCompOut_MASK               VerifyCompOut__MASK
#define VerifyCompOut_SHIFT              VerifyCompOut__SHIFT
#define VerifyCompOut_WIDTH              1u

/* Interrupt constants */
#if defined(VerifyCompOut__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in VerifyCompOut_SetInterruptMode() function.
     *  @{
     */
        #define VerifyCompOut_INTR_NONE      (uint16)(0x0000u)
        #define VerifyCompOut_INTR_RISING    (uint16)(0x0001u)
        #define VerifyCompOut_INTR_FALLING   (uint16)(0x0002u)
        #define VerifyCompOut_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define VerifyCompOut_INTR_MASK      (0x01u) 
#endif /* (VerifyCompOut__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VerifyCompOut_PS                     (* (reg8 *) VerifyCompOut__PS)
/* Data Register */
#define VerifyCompOut_DR                     (* (reg8 *) VerifyCompOut__DR)
/* Port Number */
#define VerifyCompOut_PRT_NUM                (* (reg8 *) VerifyCompOut__PRT) 
/* Connect to Analog Globals */                                                  
#define VerifyCompOut_AG                     (* (reg8 *) VerifyCompOut__AG)                       
/* Analog MUX bux enable */
#define VerifyCompOut_AMUX                   (* (reg8 *) VerifyCompOut__AMUX) 
/* Bidirectional Enable */                                                        
#define VerifyCompOut_BIE                    (* (reg8 *) VerifyCompOut__BIE)
/* Bit-mask for Aliased Register Access */
#define VerifyCompOut_BIT_MASK               (* (reg8 *) VerifyCompOut__BIT_MASK)
/* Bypass Enable */
#define VerifyCompOut_BYP                    (* (reg8 *) VerifyCompOut__BYP)
/* Port wide control signals */                                                   
#define VerifyCompOut_CTL                    (* (reg8 *) VerifyCompOut__CTL)
/* Drive Modes */
#define VerifyCompOut_DM0                    (* (reg8 *) VerifyCompOut__DM0) 
#define VerifyCompOut_DM1                    (* (reg8 *) VerifyCompOut__DM1)
#define VerifyCompOut_DM2                    (* (reg8 *) VerifyCompOut__DM2) 
/* Input Buffer Disable Override */
#define VerifyCompOut_INP_DIS                (* (reg8 *) VerifyCompOut__INP_DIS)
/* LCD Common or Segment Drive */
#define VerifyCompOut_LCD_COM_SEG            (* (reg8 *) VerifyCompOut__LCD_COM_SEG)
/* Enable Segment LCD */
#define VerifyCompOut_LCD_EN                 (* (reg8 *) VerifyCompOut__LCD_EN)
/* Slew Rate Control */
#define VerifyCompOut_SLW                    (* (reg8 *) VerifyCompOut__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define VerifyCompOut_PRTDSI__CAPS_SEL       (* (reg8 *) VerifyCompOut__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define VerifyCompOut_PRTDSI__DBL_SYNC_IN    (* (reg8 *) VerifyCompOut__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define VerifyCompOut_PRTDSI__OE_SEL0        (* (reg8 *) VerifyCompOut__PRTDSI__OE_SEL0) 
#define VerifyCompOut_PRTDSI__OE_SEL1        (* (reg8 *) VerifyCompOut__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define VerifyCompOut_PRTDSI__OUT_SEL0       (* (reg8 *) VerifyCompOut__PRTDSI__OUT_SEL0) 
#define VerifyCompOut_PRTDSI__OUT_SEL1       (* (reg8 *) VerifyCompOut__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define VerifyCompOut_PRTDSI__SYNC_OUT       (* (reg8 *) VerifyCompOut__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(VerifyCompOut__SIO_CFG)
    #define VerifyCompOut_SIO_HYST_EN        (* (reg8 *) VerifyCompOut__SIO_HYST_EN)
    #define VerifyCompOut_SIO_REG_HIFREQ     (* (reg8 *) VerifyCompOut__SIO_REG_HIFREQ)
    #define VerifyCompOut_SIO_CFG            (* (reg8 *) VerifyCompOut__SIO_CFG)
    #define VerifyCompOut_SIO_DIFF           (* (reg8 *) VerifyCompOut__SIO_DIFF)
#endif /* (VerifyCompOut__SIO_CFG) */

/* Interrupt Registers */
#if defined(VerifyCompOut__INTSTAT)
    #define VerifyCompOut_INTSTAT            (* (reg8 *) VerifyCompOut__INTSTAT)
    #define VerifyCompOut_SNAP               (* (reg8 *) VerifyCompOut__SNAP)
    
	#define VerifyCompOut_0_INTTYPE_REG 		(* (reg8 *) VerifyCompOut__0__INTTYPE)
#endif /* (VerifyCompOut__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_VerifyCompOut_H */


/* [] END OF FILE */
