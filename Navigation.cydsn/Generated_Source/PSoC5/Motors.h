/*******************************************************************************
* File Name: Motors.h  
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

#if !defined(CY_PINS_Motors_H) /* Pins Motors_H */
#define CY_PINS_Motors_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Motors_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Motors__PORT == 15 && ((Motors__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Motors_Write(uint8 value);
void    Motors_SetDriveMode(uint8 mode);
uint8   Motors_ReadDataReg(void);
uint8   Motors_Read(void);
void    Motors_SetInterruptMode(uint16 position, uint16 mode);
uint8   Motors_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Motors_SetDriveMode() function.
     *  @{
     */
        #define Motors_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Motors_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Motors_DM_RES_UP          PIN_DM_RES_UP
        #define Motors_DM_RES_DWN         PIN_DM_RES_DWN
        #define Motors_DM_OD_LO           PIN_DM_OD_LO
        #define Motors_DM_OD_HI           PIN_DM_OD_HI
        #define Motors_DM_STRONG          PIN_DM_STRONG
        #define Motors_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Motors_MASK               Motors__MASK
#define Motors_SHIFT              Motors__SHIFT
#define Motors_WIDTH              1u

/* Interrupt constants */
#if defined(Motors__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Motors_SetInterruptMode() function.
     *  @{
     */
        #define Motors_INTR_NONE      (uint16)(0x0000u)
        #define Motors_INTR_RISING    (uint16)(0x0001u)
        #define Motors_INTR_FALLING   (uint16)(0x0002u)
        #define Motors_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Motors_INTR_MASK      (0x01u) 
#endif /* (Motors__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Motors_PS                     (* (reg8 *) Motors__PS)
/* Data Register */
#define Motors_DR                     (* (reg8 *) Motors__DR)
/* Port Number */
#define Motors_PRT_NUM                (* (reg8 *) Motors__PRT) 
/* Connect to Analog Globals */                                                  
#define Motors_AG                     (* (reg8 *) Motors__AG)                       
/* Analog MUX bux enable */
#define Motors_AMUX                   (* (reg8 *) Motors__AMUX) 
/* Bidirectional Enable */                                                        
#define Motors_BIE                    (* (reg8 *) Motors__BIE)
/* Bit-mask for Aliased Register Access */
#define Motors_BIT_MASK               (* (reg8 *) Motors__BIT_MASK)
/* Bypass Enable */
#define Motors_BYP                    (* (reg8 *) Motors__BYP)
/* Port wide control signals */                                                   
#define Motors_CTL                    (* (reg8 *) Motors__CTL)
/* Drive Modes */
#define Motors_DM0                    (* (reg8 *) Motors__DM0) 
#define Motors_DM1                    (* (reg8 *) Motors__DM1)
#define Motors_DM2                    (* (reg8 *) Motors__DM2) 
/* Input Buffer Disable Override */
#define Motors_INP_DIS                (* (reg8 *) Motors__INP_DIS)
/* LCD Common or Segment Drive */
#define Motors_LCD_COM_SEG            (* (reg8 *) Motors__LCD_COM_SEG)
/* Enable Segment LCD */
#define Motors_LCD_EN                 (* (reg8 *) Motors__LCD_EN)
/* Slew Rate Control */
#define Motors_SLW                    (* (reg8 *) Motors__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Motors_PRTDSI__CAPS_SEL       (* (reg8 *) Motors__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Motors_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Motors__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Motors_PRTDSI__OE_SEL0        (* (reg8 *) Motors__PRTDSI__OE_SEL0) 
#define Motors_PRTDSI__OE_SEL1        (* (reg8 *) Motors__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Motors_PRTDSI__OUT_SEL0       (* (reg8 *) Motors__PRTDSI__OUT_SEL0) 
#define Motors_PRTDSI__OUT_SEL1       (* (reg8 *) Motors__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Motors_PRTDSI__SYNC_OUT       (* (reg8 *) Motors__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Motors__SIO_CFG)
    #define Motors_SIO_HYST_EN        (* (reg8 *) Motors__SIO_HYST_EN)
    #define Motors_SIO_REG_HIFREQ     (* (reg8 *) Motors__SIO_REG_HIFREQ)
    #define Motors_SIO_CFG            (* (reg8 *) Motors__SIO_CFG)
    #define Motors_SIO_DIFF           (* (reg8 *) Motors__SIO_DIFF)
#endif /* (Motors__SIO_CFG) */

/* Interrupt Registers */
#if defined(Motors__INTSTAT)
    #define Motors_INTSTAT            (* (reg8 *) Motors__INTSTAT)
    #define Motors_SNAP               (* (reg8 *) Motors__SNAP)
    
	#define Motors_0_INTTYPE_REG 		(* (reg8 *) Motors__0__INTTYPE)
#endif /* (Motors__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Motors_H */


/* [] END OF FILE */
