/*******************************************************************************
* File Name: VerifyCompIn.h  
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

#if !defined(CY_PINS_VerifyCompIn_H) /* Pins VerifyCompIn_H */
#define CY_PINS_VerifyCompIn_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "VerifyCompIn_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 VerifyCompIn__PORT == 15 && ((VerifyCompIn__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    VerifyCompIn_Write(uint8 value);
void    VerifyCompIn_SetDriveMode(uint8 mode);
uint8   VerifyCompIn_ReadDataReg(void);
uint8   VerifyCompIn_Read(void);
void    VerifyCompIn_SetInterruptMode(uint16 position, uint16 mode);
uint8   VerifyCompIn_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the VerifyCompIn_SetDriveMode() function.
     *  @{
     */
        #define VerifyCompIn_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define VerifyCompIn_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define VerifyCompIn_DM_RES_UP          PIN_DM_RES_UP
        #define VerifyCompIn_DM_RES_DWN         PIN_DM_RES_DWN
        #define VerifyCompIn_DM_OD_LO           PIN_DM_OD_LO
        #define VerifyCompIn_DM_OD_HI           PIN_DM_OD_HI
        #define VerifyCompIn_DM_STRONG          PIN_DM_STRONG
        #define VerifyCompIn_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define VerifyCompIn_MASK               VerifyCompIn__MASK
#define VerifyCompIn_SHIFT              VerifyCompIn__SHIFT
#define VerifyCompIn_WIDTH              1u

/* Interrupt constants */
#if defined(VerifyCompIn__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in VerifyCompIn_SetInterruptMode() function.
     *  @{
     */
        #define VerifyCompIn_INTR_NONE      (uint16)(0x0000u)
        #define VerifyCompIn_INTR_RISING    (uint16)(0x0001u)
        #define VerifyCompIn_INTR_FALLING   (uint16)(0x0002u)
        #define VerifyCompIn_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define VerifyCompIn_INTR_MASK      (0x01u) 
#endif /* (VerifyCompIn__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VerifyCompIn_PS                     (* (reg8 *) VerifyCompIn__PS)
/* Data Register */
#define VerifyCompIn_DR                     (* (reg8 *) VerifyCompIn__DR)
/* Port Number */
#define VerifyCompIn_PRT_NUM                (* (reg8 *) VerifyCompIn__PRT) 
/* Connect to Analog Globals */                                                  
#define VerifyCompIn_AG                     (* (reg8 *) VerifyCompIn__AG)                       
/* Analog MUX bux enable */
#define VerifyCompIn_AMUX                   (* (reg8 *) VerifyCompIn__AMUX) 
/* Bidirectional Enable */                                                        
#define VerifyCompIn_BIE                    (* (reg8 *) VerifyCompIn__BIE)
/* Bit-mask for Aliased Register Access */
#define VerifyCompIn_BIT_MASK               (* (reg8 *) VerifyCompIn__BIT_MASK)
/* Bypass Enable */
#define VerifyCompIn_BYP                    (* (reg8 *) VerifyCompIn__BYP)
/* Port wide control signals */                                                   
#define VerifyCompIn_CTL                    (* (reg8 *) VerifyCompIn__CTL)
/* Drive Modes */
#define VerifyCompIn_DM0                    (* (reg8 *) VerifyCompIn__DM0) 
#define VerifyCompIn_DM1                    (* (reg8 *) VerifyCompIn__DM1)
#define VerifyCompIn_DM2                    (* (reg8 *) VerifyCompIn__DM2) 
/* Input Buffer Disable Override */
#define VerifyCompIn_INP_DIS                (* (reg8 *) VerifyCompIn__INP_DIS)
/* LCD Common or Segment Drive */
#define VerifyCompIn_LCD_COM_SEG            (* (reg8 *) VerifyCompIn__LCD_COM_SEG)
/* Enable Segment LCD */
#define VerifyCompIn_LCD_EN                 (* (reg8 *) VerifyCompIn__LCD_EN)
/* Slew Rate Control */
#define VerifyCompIn_SLW                    (* (reg8 *) VerifyCompIn__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define VerifyCompIn_PRTDSI__CAPS_SEL       (* (reg8 *) VerifyCompIn__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define VerifyCompIn_PRTDSI__DBL_SYNC_IN    (* (reg8 *) VerifyCompIn__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define VerifyCompIn_PRTDSI__OE_SEL0        (* (reg8 *) VerifyCompIn__PRTDSI__OE_SEL0) 
#define VerifyCompIn_PRTDSI__OE_SEL1        (* (reg8 *) VerifyCompIn__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define VerifyCompIn_PRTDSI__OUT_SEL0       (* (reg8 *) VerifyCompIn__PRTDSI__OUT_SEL0) 
#define VerifyCompIn_PRTDSI__OUT_SEL1       (* (reg8 *) VerifyCompIn__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define VerifyCompIn_PRTDSI__SYNC_OUT       (* (reg8 *) VerifyCompIn__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(VerifyCompIn__SIO_CFG)
    #define VerifyCompIn_SIO_HYST_EN        (* (reg8 *) VerifyCompIn__SIO_HYST_EN)
    #define VerifyCompIn_SIO_REG_HIFREQ     (* (reg8 *) VerifyCompIn__SIO_REG_HIFREQ)
    #define VerifyCompIn_SIO_CFG            (* (reg8 *) VerifyCompIn__SIO_CFG)
    #define VerifyCompIn_SIO_DIFF           (* (reg8 *) VerifyCompIn__SIO_DIFF)
#endif /* (VerifyCompIn__SIO_CFG) */

/* Interrupt Registers */
#if defined(VerifyCompIn__INTSTAT)
    #define VerifyCompIn_INTSTAT            (* (reg8 *) VerifyCompIn__INTSTAT)
    #define VerifyCompIn_SNAP               (* (reg8 *) VerifyCompIn__SNAP)
    
	#define VerifyCompIn_0_INTTYPE_REG 		(* (reg8 *) VerifyCompIn__0__INTTYPE)
#endif /* (VerifyCompIn__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_VerifyCompIn_H */


/* [] END OF FILE */
