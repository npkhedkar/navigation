/*******************************************************************************
* File Name: HallEffect.h  
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

#if !defined(CY_PINS_HallEffect_H) /* Pins HallEffect_H */
#define CY_PINS_HallEffect_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "HallEffect_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 HallEffect__PORT == 15 && ((HallEffect__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    HallEffect_Write(uint8 value);
void    HallEffect_SetDriveMode(uint8 mode);
uint8   HallEffect_ReadDataReg(void);
uint8   HallEffect_Read(void);
void    HallEffect_SetInterruptMode(uint16 position, uint16 mode);
uint8   HallEffect_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the HallEffect_SetDriveMode() function.
     *  @{
     */
        #define HallEffect_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define HallEffect_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define HallEffect_DM_RES_UP          PIN_DM_RES_UP
        #define HallEffect_DM_RES_DWN         PIN_DM_RES_DWN
        #define HallEffect_DM_OD_LO           PIN_DM_OD_LO
        #define HallEffect_DM_OD_HI           PIN_DM_OD_HI
        #define HallEffect_DM_STRONG          PIN_DM_STRONG
        #define HallEffect_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define HallEffect_MASK               HallEffect__MASK
#define HallEffect_SHIFT              HallEffect__SHIFT
#define HallEffect_WIDTH              1u

/* Interrupt constants */
#if defined(HallEffect__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in HallEffect_SetInterruptMode() function.
     *  @{
     */
        #define HallEffect_INTR_NONE      (uint16)(0x0000u)
        #define HallEffect_INTR_RISING    (uint16)(0x0001u)
        #define HallEffect_INTR_FALLING   (uint16)(0x0002u)
        #define HallEffect_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define HallEffect_INTR_MASK      (0x01u) 
#endif /* (HallEffect__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HallEffect_PS                     (* (reg8 *) HallEffect__PS)
/* Data Register */
#define HallEffect_DR                     (* (reg8 *) HallEffect__DR)
/* Port Number */
#define HallEffect_PRT_NUM                (* (reg8 *) HallEffect__PRT) 
/* Connect to Analog Globals */                                                  
#define HallEffect_AG                     (* (reg8 *) HallEffect__AG)                       
/* Analog MUX bux enable */
#define HallEffect_AMUX                   (* (reg8 *) HallEffect__AMUX) 
/* Bidirectional Enable */                                                        
#define HallEffect_BIE                    (* (reg8 *) HallEffect__BIE)
/* Bit-mask for Aliased Register Access */
#define HallEffect_BIT_MASK               (* (reg8 *) HallEffect__BIT_MASK)
/* Bypass Enable */
#define HallEffect_BYP                    (* (reg8 *) HallEffect__BYP)
/* Port wide control signals */                                                   
#define HallEffect_CTL                    (* (reg8 *) HallEffect__CTL)
/* Drive Modes */
#define HallEffect_DM0                    (* (reg8 *) HallEffect__DM0) 
#define HallEffect_DM1                    (* (reg8 *) HallEffect__DM1)
#define HallEffect_DM2                    (* (reg8 *) HallEffect__DM2) 
/* Input Buffer Disable Override */
#define HallEffect_INP_DIS                (* (reg8 *) HallEffect__INP_DIS)
/* LCD Common or Segment Drive */
#define HallEffect_LCD_COM_SEG            (* (reg8 *) HallEffect__LCD_COM_SEG)
/* Enable Segment LCD */
#define HallEffect_LCD_EN                 (* (reg8 *) HallEffect__LCD_EN)
/* Slew Rate Control */
#define HallEffect_SLW                    (* (reg8 *) HallEffect__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define HallEffect_PRTDSI__CAPS_SEL       (* (reg8 *) HallEffect__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define HallEffect_PRTDSI__DBL_SYNC_IN    (* (reg8 *) HallEffect__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define HallEffect_PRTDSI__OE_SEL0        (* (reg8 *) HallEffect__PRTDSI__OE_SEL0) 
#define HallEffect_PRTDSI__OE_SEL1        (* (reg8 *) HallEffect__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define HallEffect_PRTDSI__OUT_SEL0       (* (reg8 *) HallEffect__PRTDSI__OUT_SEL0) 
#define HallEffect_PRTDSI__OUT_SEL1       (* (reg8 *) HallEffect__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define HallEffect_PRTDSI__SYNC_OUT       (* (reg8 *) HallEffect__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(HallEffect__SIO_CFG)
    #define HallEffect_SIO_HYST_EN        (* (reg8 *) HallEffect__SIO_HYST_EN)
    #define HallEffect_SIO_REG_HIFREQ     (* (reg8 *) HallEffect__SIO_REG_HIFREQ)
    #define HallEffect_SIO_CFG            (* (reg8 *) HallEffect__SIO_CFG)
    #define HallEffect_SIO_DIFF           (* (reg8 *) HallEffect__SIO_DIFF)
#endif /* (HallEffect__SIO_CFG) */

/* Interrupt Registers */
#if defined(HallEffect__INTSTAT)
    #define HallEffect_INTSTAT            (* (reg8 *) HallEffect__INTSTAT)
    #define HallEffect_SNAP               (* (reg8 *) HallEffect__SNAP)
    
	#define HallEffect_0_INTTYPE_REG 		(* (reg8 *) HallEffect__0__INTTYPE)
#endif /* (HallEffect__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_HallEffect_H */


/* [] END OF FILE */
