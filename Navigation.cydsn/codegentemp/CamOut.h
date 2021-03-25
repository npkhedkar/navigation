/*******************************************************************************
* File Name: CamOut.h  
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

#if !defined(CY_PINS_CamOut_H) /* Pins CamOut_H */
#define CY_PINS_CamOut_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CamOut_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CamOut__PORT == 15 && ((CamOut__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    CamOut_Write(uint8 value);
void    CamOut_SetDriveMode(uint8 mode);
uint8   CamOut_ReadDataReg(void);
uint8   CamOut_Read(void);
void    CamOut_SetInterruptMode(uint16 position, uint16 mode);
uint8   CamOut_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the CamOut_SetDriveMode() function.
     *  @{
     */
        #define CamOut_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define CamOut_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define CamOut_DM_RES_UP          PIN_DM_RES_UP
        #define CamOut_DM_RES_DWN         PIN_DM_RES_DWN
        #define CamOut_DM_OD_LO           PIN_DM_OD_LO
        #define CamOut_DM_OD_HI           PIN_DM_OD_HI
        #define CamOut_DM_STRONG          PIN_DM_STRONG
        #define CamOut_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define CamOut_MASK               CamOut__MASK
#define CamOut_SHIFT              CamOut__SHIFT
#define CamOut_WIDTH              1u

/* Interrupt constants */
#if defined(CamOut__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in CamOut_SetInterruptMode() function.
     *  @{
     */
        #define CamOut_INTR_NONE      (uint16)(0x0000u)
        #define CamOut_INTR_RISING    (uint16)(0x0001u)
        #define CamOut_INTR_FALLING   (uint16)(0x0002u)
        #define CamOut_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define CamOut_INTR_MASK      (0x01u) 
#endif /* (CamOut__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CamOut_PS                     (* (reg8 *) CamOut__PS)
/* Data Register */
#define CamOut_DR                     (* (reg8 *) CamOut__DR)
/* Port Number */
#define CamOut_PRT_NUM                (* (reg8 *) CamOut__PRT) 
/* Connect to Analog Globals */                                                  
#define CamOut_AG                     (* (reg8 *) CamOut__AG)                       
/* Analog MUX bux enable */
#define CamOut_AMUX                   (* (reg8 *) CamOut__AMUX) 
/* Bidirectional Enable */                                                        
#define CamOut_BIE                    (* (reg8 *) CamOut__BIE)
/* Bit-mask for Aliased Register Access */
#define CamOut_BIT_MASK               (* (reg8 *) CamOut__BIT_MASK)
/* Bypass Enable */
#define CamOut_BYP                    (* (reg8 *) CamOut__BYP)
/* Port wide control signals */                                                   
#define CamOut_CTL                    (* (reg8 *) CamOut__CTL)
/* Drive Modes */
#define CamOut_DM0                    (* (reg8 *) CamOut__DM0) 
#define CamOut_DM1                    (* (reg8 *) CamOut__DM1)
#define CamOut_DM2                    (* (reg8 *) CamOut__DM2) 
/* Input Buffer Disable Override */
#define CamOut_INP_DIS                (* (reg8 *) CamOut__INP_DIS)
/* LCD Common or Segment Drive */
#define CamOut_LCD_COM_SEG            (* (reg8 *) CamOut__LCD_COM_SEG)
/* Enable Segment LCD */
#define CamOut_LCD_EN                 (* (reg8 *) CamOut__LCD_EN)
/* Slew Rate Control */
#define CamOut_SLW                    (* (reg8 *) CamOut__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CamOut_PRTDSI__CAPS_SEL       (* (reg8 *) CamOut__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CamOut_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CamOut__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CamOut_PRTDSI__OE_SEL0        (* (reg8 *) CamOut__PRTDSI__OE_SEL0) 
#define CamOut_PRTDSI__OE_SEL1        (* (reg8 *) CamOut__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CamOut_PRTDSI__OUT_SEL0       (* (reg8 *) CamOut__PRTDSI__OUT_SEL0) 
#define CamOut_PRTDSI__OUT_SEL1       (* (reg8 *) CamOut__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CamOut_PRTDSI__SYNC_OUT       (* (reg8 *) CamOut__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(CamOut__SIO_CFG)
    #define CamOut_SIO_HYST_EN        (* (reg8 *) CamOut__SIO_HYST_EN)
    #define CamOut_SIO_REG_HIFREQ     (* (reg8 *) CamOut__SIO_REG_HIFREQ)
    #define CamOut_SIO_CFG            (* (reg8 *) CamOut__SIO_CFG)
    #define CamOut_SIO_DIFF           (* (reg8 *) CamOut__SIO_DIFF)
#endif /* (CamOut__SIO_CFG) */

/* Interrupt Registers */
#if defined(CamOut__INTSTAT)
    #define CamOut_INTSTAT            (* (reg8 *) CamOut__INTSTAT)
    #define CamOut_SNAP               (* (reg8 *) CamOut__SNAP)
    
	#define CamOut_0_INTTYPE_REG 		(* (reg8 *) CamOut__0__INTTYPE)
#endif /* (CamOut__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CamOut_H */


/* [] END OF FILE */
