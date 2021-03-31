/*******************************************************************************
* File Name: LBlackEdge.h  
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

#if !defined(CY_PINS_LBlackEdge_H) /* Pins LBlackEdge_H */
#define CY_PINS_LBlackEdge_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LBlackEdge_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LBlackEdge__PORT == 15 && ((LBlackEdge__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    LBlackEdge_Write(uint8 value);
void    LBlackEdge_SetDriveMode(uint8 mode);
uint8   LBlackEdge_ReadDataReg(void);
uint8   LBlackEdge_Read(void);
void    LBlackEdge_SetInterruptMode(uint16 position, uint16 mode);
uint8   LBlackEdge_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the LBlackEdge_SetDriveMode() function.
     *  @{
     */
        #define LBlackEdge_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define LBlackEdge_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define LBlackEdge_DM_RES_UP          PIN_DM_RES_UP
        #define LBlackEdge_DM_RES_DWN         PIN_DM_RES_DWN
        #define LBlackEdge_DM_OD_LO           PIN_DM_OD_LO
        #define LBlackEdge_DM_OD_HI           PIN_DM_OD_HI
        #define LBlackEdge_DM_STRONG          PIN_DM_STRONG
        #define LBlackEdge_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define LBlackEdge_MASK               LBlackEdge__MASK
#define LBlackEdge_SHIFT              LBlackEdge__SHIFT
#define LBlackEdge_WIDTH              1u

/* Interrupt constants */
#if defined(LBlackEdge__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LBlackEdge_SetInterruptMode() function.
     *  @{
     */
        #define LBlackEdge_INTR_NONE      (uint16)(0x0000u)
        #define LBlackEdge_INTR_RISING    (uint16)(0x0001u)
        #define LBlackEdge_INTR_FALLING   (uint16)(0x0002u)
        #define LBlackEdge_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define LBlackEdge_INTR_MASK      (0x01u) 
#endif /* (LBlackEdge__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LBlackEdge_PS                     (* (reg8 *) LBlackEdge__PS)
/* Data Register */
#define LBlackEdge_DR                     (* (reg8 *) LBlackEdge__DR)
/* Port Number */
#define LBlackEdge_PRT_NUM                (* (reg8 *) LBlackEdge__PRT) 
/* Connect to Analog Globals */                                                  
#define LBlackEdge_AG                     (* (reg8 *) LBlackEdge__AG)                       
/* Analog MUX bux enable */
#define LBlackEdge_AMUX                   (* (reg8 *) LBlackEdge__AMUX) 
/* Bidirectional Enable */                                                        
#define LBlackEdge_BIE                    (* (reg8 *) LBlackEdge__BIE)
/* Bit-mask for Aliased Register Access */
#define LBlackEdge_BIT_MASK               (* (reg8 *) LBlackEdge__BIT_MASK)
/* Bypass Enable */
#define LBlackEdge_BYP                    (* (reg8 *) LBlackEdge__BYP)
/* Port wide control signals */                                                   
#define LBlackEdge_CTL                    (* (reg8 *) LBlackEdge__CTL)
/* Drive Modes */
#define LBlackEdge_DM0                    (* (reg8 *) LBlackEdge__DM0) 
#define LBlackEdge_DM1                    (* (reg8 *) LBlackEdge__DM1)
#define LBlackEdge_DM2                    (* (reg8 *) LBlackEdge__DM2) 
/* Input Buffer Disable Override */
#define LBlackEdge_INP_DIS                (* (reg8 *) LBlackEdge__INP_DIS)
/* LCD Common or Segment Drive */
#define LBlackEdge_LCD_COM_SEG            (* (reg8 *) LBlackEdge__LCD_COM_SEG)
/* Enable Segment LCD */
#define LBlackEdge_LCD_EN                 (* (reg8 *) LBlackEdge__LCD_EN)
/* Slew Rate Control */
#define LBlackEdge_SLW                    (* (reg8 *) LBlackEdge__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LBlackEdge_PRTDSI__CAPS_SEL       (* (reg8 *) LBlackEdge__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LBlackEdge_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LBlackEdge__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LBlackEdge_PRTDSI__OE_SEL0        (* (reg8 *) LBlackEdge__PRTDSI__OE_SEL0) 
#define LBlackEdge_PRTDSI__OE_SEL1        (* (reg8 *) LBlackEdge__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LBlackEdge_PRTDSI__OUT_SEL0       (* (reg8 *) LBlackEdge__PRTDSI__OUT_SEL0) 
#define LBlackEdge_PRTDSI__OUT_SEL1       (* (reg8 *) LBlackEdge__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LBlackEdge_PRTDSI__SYNC_OUT       (* (reg8 *) LBlackEdge__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(LBlackEdge__SIO_CFG)
    #define LBlackEdge_SIO_HYST_EN        (* (reg8 *) LBlackEdge__SIO_HYST_EN)
    #define LBlackEdge_SIO_REG_HIFREQ     (* (reg8 *) LBlackEdge__SIO_REG_HIFREQ)
    #define LBlackEdge_SIO_CFG            (* (reg8 *) LBlackEdge__SIO_CFG)
    #define LBlackEdge_SIO_DIFF           (* (reg8 *) LBlackEdge__SIO_DIFF)
#endif /* (LBlackEdge__SIO_CFG) */

/* Interrupt Registers */
#if defined(LBlackEdge__INTSTAT)
    #define LBlackEdge_INTSTAT            (* (reg8 *) LBlackEdge__INTSTAT)
    #define LBlackEdge_SNAP               (* (reg8 *) LBlackEdge__SNAP)
    
	#define LBlackEdge_0_INTTYPE_REG 		(* (reg8 *) LBlackEdge__0__INTTYPE)
#endif /* (LBlackEdge__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LBlackEdge_H */


/* [] END OF FILE */
