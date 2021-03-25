/*******************************************************************************
* File Name: OddEven.h  
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

#if !defined(CY_PINS_OddEven_H) /* Pins OddEven_H */
#define CY_PINS_OddEven_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "OddEven_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 OddEven__PORT == 15 && ((OddEven__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    OddEven_Write(uint8 value);
void    OddEven_SetDriveMode(uint8 mode);
uint8   OddEven_ReadDataReg(void);
uint8   OddEven_Read(void);
void    OddEven_SetInterruptMode(uint16 position, uint16 mode);
uint8   OddEven_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the OddEven_SetDriveMode() function.
     *  @{
     */
        #define OddEven_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define OddEven_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define OddEven_DM_RES_UP          PIN_DM_RES_UP
        #define OddEven_DM_RES_DWN         PIN_DM_RES_DWN
        #define OddEven_DM_OD_LO           PIN_DM_OD_LO
        #define OddEven_DM_OD_HI           PIN_DM_OD_HI
        #define OddEven_DM_STRONG          PIN_DM_STRONG
        #define OddEven_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define OddEven_MASK               OddEven__MASK
#define OddEven_SHIFT              OddEven__SHIFT
#define OddEven_WIDTH              1u

/* Interrupt constants */
#if defined(OddEven__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in OddEven_SetInterruptMode() function.
     *  @{
     */
        #define OddEven_INTR_NONE      (uint16)(0x0000u)
        #define OddEven_INTR_RISING    (uint16)(0x0001u)
        #define OddEven_INTR_FALLING   (uint16)(0x0002u)
        #define OddEven_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define OddEven_INTR_MASK      (0x01u) 
#endif /* (OddEven__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define OddEven_PS                     (* (reg8 *) OddEven__PS)
/* Data Register */
#define OddEven_DR                     (* (reg8 *) OddEven__DR)
/* Port Number */
#define OddEven_PRT_NUM                (* (reg8 *) OddEven__PRT) 
/* Connect to Analog Globals */                                                  
#define OddEven_AG                     (* (reg8 *) OddEven__AG)                       
/* Analog MUX bux enable */
#define OddEven_AMUX                   (* (reg8 *) OddEven__AMUX) 
/* Bidirectional Enable */                                                        
#define OddEven_BIE                    (* (reg8 *) OddEven__BIE)
/* Bit-mask for Aliased Register Access */
#define OddEven_BIT_MASK               (* (reg8 *) OddEven__BIT_MASK)
/* Bypass Enable */
#define OddEven_BYP                    (* (reg8 *) OddEven__BYP)
/* Port wide control signals */                                                   
#define OddEven_CTL                    (* (reg8 *) OddEven__CTL)
/* Drive Modes */
#define OddEven_DM0                    (* (reg8 *) OddEven__DM0) 
#define OddEven_DM1                    (* (reg8 *) OddEven__DM1)
#define OddEven_DM2                    (* (reg8 *) OddEven__DM2) 
/* Input Buffer Disable Override */
#define OddEven_INP_DIS                (* (reg8 *) OddEven__INP_DIS)
/* LCD Common or Segment Drive */
#define OddEven_LCD_COM_SEG            (* (reg8 *) OddEven__LCD_COM_SEG)
/* Enable Segment LCD */
#define OddEven_LCD_EN                 (* (reg8 *) OddEven__LCD_EN)
/* Slew Rate Control */
#define OddEven_SLW                    (* (reg8 *) OddEven__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define OddEven_PRTDSI__CAPS_SEL       (* (reg8 *) OddEven__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define OddEven_PRTDSI__DBL_SYNC_IN    (* (reg8 *) OddEven__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define OddEven_PRTDSI__OE_SEL0        (* (reg8 *) OddEven__PRTDSI__OE_SEL0) 
#define OddEven_PRTDSI__OE_SEL1        (* (reg8 *) OddEven__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define OddEven_PRTDSI__OUT_SEL0       (* (reg8 *) OddEven__PRTDSI__OUT_SEL0) 
#define OddEven_PRTDSI__OUT_SEL1       (* (reg8 *) OddEven__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define OddEven_PRTDSI__SYNC_OUT       (* (reg8 *) OddEven__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(OddEven__SIO_CFG)
    #define OddEven_SIO_HYST_EN        (* (reg8 *) OddEven__SIO_HYST_EN)
    #define OddEven_SIO_REG_HIFREQ     (* (reg8 *) OddEven__SIO_REG_HIFREQ)
    #define OddEven_SIO_CFG            (* (reg8 *) OddEven__SIO_CFG)
    #define OddEven_SIO_DIFF           (* (reg8 *) OddEven__SIO_DIFF)
#endif /* (OddEven__SIO_CFG) */

/* Interrupt Registers */
#if defined(OddEven__INTSTAT)
    #define OddEven_INTSTAT            (* (reg8 *) OddEven__INTSTAT)
    #define OddEven_SNAP               (* (reg8 *) OddEven__SNAP)
    
	#define OddEven_0_INTTYPE_REG 		(* (reg8 *) OddEven__0__INTTYPE)
#endif /* (OddEven__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_OddEven_H */


/* [] END OF FILE */
