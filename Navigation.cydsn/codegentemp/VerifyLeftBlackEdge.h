/*******************************************************************************
* File Name: VerifyLeftBlackEdge.h  
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

#if !defined(CY_PINS_VerifyLeftBlackEdge_H) /* Pins VerifyLeftBlackEdge_H */
#define CY_PINS_VerifyLeftBlackEdge_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "VerifyLeftBlackEdge_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 VerifyLeftBlackEdge__PORT == 15 && ((VerifyLeftBlackEdge__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    VerifyLeftBlackEdge_Write(uint8 value);
void    VerifyLeftBlackEdge_SetDriveMode(uint8 mode);
uint8   VerifyLeftBlackEdge_ReadDataReg(void);
uint8   VerifyLeftBlackEdge_Read(void);
void    VerifyLeftBlackEdge_SetInterruptMode(uint16 position, uint16 mode);
uint8   VerifyLeftBlackEdge_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the VerifyLeftBlackEdge_SetDriveMode() function.
     *  @{
     */
        #define VerifyLeftBlackEdge_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define VerifyLeftBlackEdge_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define VerifyLeftBlackEdge_DM_RES_UP          PIN_DM_RES_UP
        #define VerifyLeftBlackEdge_DM_RES_DWN         PIN_DM_RES_DWN
        #define VerifyLeftBlackEdge_DM_OD_LO           PIN_DM_OD_LO
        #define VerifyLeftBlackEdge_DM_OD_HI           PIN_DM_OD_HI
        #define VerifyLeftBlackEdge_DM_STRONG          PIN_DM_STRONG
        #define VerifyLeftBlackEdge_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define VerifyLeftBlackEdge_MASK               VerifyLeftBlackEdge__MASK
#define VerifyLeftBlackEdge_SHIFT              VerifyLeftBlackEdge__SHIFT
#define VerifyLeftBlackEdge_WIDTH              1u

/* Interrupt constants */
#if defined(VerifyLeftBlackEdge__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in VerifyLeftBlackEdge_SetInterruptMode() function.
     *  @{
     */
        #define VerifyLeftBlackEdge_INTR_NONE      (uint16)(0x0000u)
        #define VerifyLeftBlackEdge_INTR_RISING    (uint16)(0x0001u)
        #define VerifyLeftBlackEdge_INTR_FALLING   (uint16)(0x0002u)
        #define VerifyLeftBlackEdge_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define VerifyLeftBlackEdge_INTR_MASK      (0x01u) 
#endif /* (VerifyLeftBlackEdge__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VerifyLeftBlackEdge_PS                     (* (reg8 *) VerifyLeftBlackEdge__PS)
/* Data Register */
#define VerifyLeftBlackEdge_DR                     (* (reg8 *) VerifyLeftBlackEdge__DR)
/* Port Number */
#define VerifyLeftBlackEdge_PRT_NUM                (* (reg8 *) VerifyLeftBlackEdge__PRT) 
/* Connect to Analog Globals */                                                  
#define VerifyLeftBlackEdge_AG                     (* (reg8 *) VerifyLeftBlackEdge__AG)                       
/* Analog MUX bux enable */
#define VerifyLeftBlackEdge_AMUX                   (* (reg8 *) VerifyLeftBlackEdge__AMUX) 
/* Bidirectional Enable */                                                        
#define VerifyLeftBlackEdge_BIE                    (* (reg8 *) VerifyLeftBlackEdge__BIE)
/* Bit-mask for Aliased Register Access */
#define VerifyLeftBlackEdge_BIT_MASK               (* (reg8 *) VerifyLeftBlackEdge__BIT_MASK)
/* Bypass Enable */
#define VerifyLeftBlackEdge_BYP                    (* (reg8 *) VerifyLeftBlackEdge__BYP)
/* Port wide control signals */                                                   
#define VerifyLeftBlackEdge_CTL                    (* (reg8 *) VerifyLeftBlackEdge__CTL)
/* Drive Modes */
#define VerifyLeftBlackEdge_DM0                    (* (reg8 *) VerifyLeftBlackEdge__DM0) 
#define VerifyLeftBlackEdge_DM1                    (* (reg8 *) VerifyLeftBlackEdge__DM1)
#define VerifyLeftBlackEdge_DM2                    (* (reg8 *) VerifyLeftBlackEdge__DM2) 
/* Input Buffer Disable Override */
#define VerifyLeftBlackEdge_INP_DIS                (* (reg8 *) VerifyLeftBlackEdge__INP_DIS)
/* LCD Common or Segment Drive */
#define VerifyLeftBlackEdge_LCD_COM_SEG            (* (reg8 *) VerifyLeftBlackEdge__LCD_COM_SEG)
/* Enable Segment LCD */
#define VerifyLeftBlackEdge_LCD_EN                 (* (reg8 *) VerifyLeftBlackEdge__LCD_EN)
/* Slew Rate Control */
#define VerifyLeftBlackEdge_SLW                    (* (reg8 *) VerifyLeftBlackEdge__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define VerifyLeftBlackEdge_PRTDSI__CAPS_SEL       (* (reg8 *) VerifyLeftBlackEdge__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define VerifyLeftBlackEdge_PRTDSI__DBL_SYNC_IN    (* (reg8 *) VerifyLeftBlackEdge__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define VerifyLeftBlackEdge_PRTDSI__OE_SEL0        (* (reg8 *) VerifyLeftBlackEdge__PRTDSI__OE_SEL0) 
#define VerifyLeftBlackEdge_PRTDSI__OE_SEL1        (* (reg8 *) VerifyLeftBlackEdge__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define VerifyLeftBlackEdge_PRTDSI__OUT_SEL0       (* (reg8 *) VerifyLeftBlackEdge__PRTDSI__OUT_SEL0) 
#define VerifyLeftBlackEdge_PRTDSI__OUT_SEL1       (* (reg8 *) VerifyLeftBlackEdge__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define VerifyLeftBlackEdge_PRTDSI__SYNC_OUT       (* (reg8 *) VerifyLeftBlackEdge__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(VerifyLeftBlackEdge__SIO_CFG)
    #define VerifyLeftBlackEdge_SIO_HYST_EN        (* (reg8 *) VerifyLeftBlackEdge__SIO_HYST_EN)
    #define VerifyLeftBlackEdge_SIO_REG_HIFREQ     (* (reg8 *) VerifyLeftBlackEdge__SIO_REG_HIFREQ)
    #define VerifyLeftBlackEdge_SIO_CFG            (* (reg8 *) VerifyLeftBlackEdge__SIO_CFG)
    #define VerifyLeftBlackEdge_SIO_DIFF           (* (reg8 *) VerifyLeftBlackEdge__SIO_DIFF)
#endif /* (VerifyLeftBlackEdge__SIO_CFG) */

/* Interrupt Registers */
#if defined(VerifyLeftBlackEdge__INTSTAT)
    #define VerifyLeftBlackEdge_INTSTAT            (* (reg8 *) VerifyLeftBlackEdge__INTSTAT)
    #define VerifyLeftBlackEdge_SNAP               (* (reg8 *) VerifyLeftBlackEdge__SNAP)
    
	#define VerifyLeftBlackEdge_0_INTTYPE_REG 		(* (reg8 *) VerifyLeftBlackEdge__0__INTTYPE)
#endif /* (VerifyLeftBlackEdge__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_VerifyLeftBlackEdge_H */


/* [] END OF FILE */
