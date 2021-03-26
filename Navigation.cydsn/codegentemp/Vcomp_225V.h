/*******************************************************************************
* File Name: Vcomp_225V.h  
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

#if !defined(CY_PINS_Vcomp_225V_H) /* Pins Vcomp_225V_H */
#define CY_PINS_Vcomp_225V_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Vcomp_225V_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Vcomp_225V__PORT == 15 && ((Vcomp_225V__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Vcomp_225V_Write(uint8 value);
void    Vcomp_225V_SetDriveMode(uint8 mode);
uint8   Vcomp_225V_ReadDataReg(void);
uint8   Vcomp_225V_Read(void);
void    Vcomp_225V_SetInterruptMode(uint16 position, uint16 mode);
uint8   Vcomp_225V_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Vcomp_225V_SetDriveMode() function.
     *  @{
     */
        #define Vcomp_225V_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Vcomp_225V_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Vcomp_225V_DM_RES_UP          PIN_DM_RES_UP
        #define Vcomp_225V_DM_RES_DWN         PIN_DM_RES_DWN
        #define Vcomp_225V_DM_OD_LO           PIN_DM_OD_LO
        #define Vcomp_225V_DM_OD_HI           PIN_DM_OD_HI
        #define Vcomp_225V_DM_STRONG          PIN_DM_STRONG
        #define Vcomp_225V_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Vcomp_225V_MASK               Vcomp_225V__MASK
#define Vcomp_225V_SHIFT              Vcomp_225V__SHIFT
#define Vcomp_225V_WIDTH              1u

/* Interrupt constants */
#if defined(Vcomp_225V__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Vcomp_225V_SetInterruptMode() function.
     *  @{
     */
        #define Vcomp_225V_INTR_NONE      (uint16)(0x0000u)
        #define Vcomp_225V_INTR_RISING    (uint16)(0x0001u)
        #define Vcomp_225V_INTR_FALLING   (uint16)(0x0002u)
        #define Vcomp_225V_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Vcomp_225V_INTR_MASK      (0x01u) 
#endif /* (Vcomp_225V__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Vcomp_225V_PS                     (* (reg8 *) Vcomp_225V__PS)
/* Data Register */
#define Vcomp_225V_DR                     (* (reg8 *) Vcomp_225V__DR)
/* Port Number */
#define Vcomp_225V_PRT_NUM                (* (reg8 *) Vcomp_225V__PRT) 
/* Connect to Analog Globals */                                                  
#define Vcomp_225V_AG                     (* (reg8 *) Vcomp_225V__AG)                       
/* Analog MUX bux enable */
#define Vcomp_225V_AMUX                   (* (reg8 *) Vcomp_225V__AMUX) 
/* Bidirectional Enable */                                                        
#define Vcomp_225V_BIE                    (* (reg8 *) Vcomp_225V__BIE)
/* Bit-mask for Aliased Register Access */
#define Vcomp_225V_BIT_MASK               (* (reg8 *) Vcomp_225V__BIT_MASK)
/* Bypass Enable */
#define Vcomp_225V_BYP                    (* (reg8 *) Vcomp_225V__BYP)
/* Port wide control signals */                                                   
#define Vcomp_225V_CTL                    (* (reg8 *) Vcomp_225V__CTL)
/* Drive Modes */
#define Vcomp_225V_DM0                    (* (reg8 *) Vcomp_225V__DM0) 
#define Vcomp_225V_DM1                    (* (reg8 *) Vcomp_225V__DM1)
#define Vcomp_225V_DM2                    (* (reg8 *) Vcomp_225V__DM2) 
/* Input Buffer Disable Override */
#define Vcomp_225V_INP_DIS                (* (reg8 *) Vcomp_225V__INP_DIS)
/* LCD Common or Segment Drive */
#define Vcomp_225V_LCD_COM_SEG            (* (reg8 *) Vcomp_225V__LCD_COM_SEG)
/* Enable Segment LCD */
#define Vcomp_225V_LCD_EN                 (* (reg8 *) Vcomp_225V__LCD_EN)
/* Slew Rate Control */
#define Vcomp_225V_SLW                    (* (reg8 *) Vcomp_225V__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Vcomp_225V_PRTDSI__CAPS_SEL       (* (reg8 *) Vcomp_225V__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Vcomp_225V_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Vcomp_225V__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Vcomp_225V_PRTDSI__OE_SEL0        (* (reg8 *) Vcomp_225V__PRTDSI__OE_SEL0) 
#define Vcomp_225V_PRTDSI__OE_SEL1        (* (reg8 *) Vcomp_225V__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Vcomp_225V_PRTDSI__OUT_SEL0       (* (reg8 *) Vcomp_225V__PRTDSI__OUT_SEL0) 
#define Vcomp_225V_PRTDSI__OUT_SEL1       (* (reg8 *) Vcomp_225V__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Vcomp_225V_PRTDSI__SYNC_OUT       (* (reg8 *) Vcomp_225V__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Vcomp_225V__SIO_CFG)
    #define Vcomp_225V_SIO_HYST_EN        (* (reg8 *) Vcomp_225V__SIO_HYST_EN)
    #define Vcomp_225V_SIO_REG_HIFREQ     (* (reg8 *) Vcomp_225V__SIO_REG_HIFREQ)
    #define Vcomp_225V_SIO_CFG            (* (reg8 *) Vcomp_225V__SIO_CFG)
    #define Vcomp_225V_SIO_DIFF           (* (reg8 *) Vcomp_225V__SIO_DIFF)
#endif /* (Vcomp_225V__SIO_CFG) */

/* Interrupt Registers */
#if defined(Vcomp_225V__INTSTAT)
    #define Vcomp_225V_INTSTAT            (* (reg8 *) Vcomp_225V__INTSTAT)
    #define Vcomp_225V_SNAP               (* (reg8 *) Vcomp_225V__SNAP)
    
	#define Vcomp_225V_0_INTTYPE_REG 		(* (reg8 *) Vcomp_225V__0__INTTYPE)
#endif /* (Vcomp_225V__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Vcomp_225V_H */


/* [] END OF FILE */
