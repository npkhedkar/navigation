/*******************************************************************************
* File Name: RBlackEdge.h  
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

#if !defined(CY_PINS_RBlackEdge_H) /* Pins RBlackEdge_H */
#define CY_PINS_RBlackEdge_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RBlackEdge_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RBlackEdge__PORT == 15 && ((RBlackEdge__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    RBlackEdge_Write(uint8 value);
void    RBlackEdge_SetDriveMode(uint8 mode);
uint8   RBlackEdge_ReadDataReg(void);
uint8   RBlackEdge_Read(void);
void    RBlackEdge_SetInterruptMode(uint16 position, uint16 mode);
uint8   RBlackEdge_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the RBlackEdge_SetDriveMode() function.
     *  @{
     */
        #define RBlackEdge_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define RBlackEdge_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define RBlackEdge_DM_RES_UP          PIN_DM_RES_UP
        #define RBlackEdge_DM_RES_DWN         PIN_DM_RES_DWN
        #define RBlackEdge_DM_OD_LO           PIN_DM_OD_LO
        #define RBlackEdge_DM_OD_HI           PIN_DM_OD_HI
        #define RBlackEdge_DM_STRONG          PIN_DM_STRONG
        #define RBlackEdge_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define RBlackEdge_MASK               RBlackEdge__MASK
#define RBlackEdge_SHIFT              RBlackEdge__SHIFT
#define RBlackEdge_WIDTH              1u

/* Interrupt constants */
#if defined(RBlackEdge__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in RBlackEdge_SetInterruptMode() function.
     *  @{
     */
        #define RBlackEdge_INTR_NONE      (uint16)(0x0000u)
        #define RBlackEdge_INTR_RISING    (uint16)(0x0001u)
        #define RBlackEdge_INTR_FALLING   (uint16)(0x0002u)
        #define RBlackEdge_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define RBlackEdge_INTR_MASK      (0x01u) 
#endif /* (RBlackEdge__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RBlackEdge_PS                     (* (reg8 *) RBlackEdge__PS)
/* Data Register */
#define RBlackEdge_DR                     (* (reg8 *) RBlackEdge__DR)
/* Port Number */
#define RBlackEdge_PRT_NUM                (* (reg8 *) RBlackEdge__PRT) 
/* Connect to Analog Globals */                                                  
#define RBlackEdge_AG                     (* (reg8 *) RBlackEdge__AG)                       
/* Analog MUX bux enable */
#define RBlackEdge_AMUX                   (* (reg8 *) RBlackEdge__AMUX) 
/* Bidirectional Enable */                                                        
#define RBlackEdge_BIE                    (* (reg8 *) RBlackEdge__BIE)
/* Bit-mask for Aliased Register Access */
#define RBlackEdge_BIT_MASK               (* (reg8 *) RBlackEdge__BIT_MASK)
/* Bypass Enable */
#define RBlackEdge_BYP                    (* (reg8 *) RBlackEdge__BYP)
/* Port wide control signals */                                                   
#define RBlackEdge_CTL                    (* (reg8 *) RBlackEdge__CTL)
/* Drive Modes */
#define RBlackEdge_DM0                    (* (reg8 *) RBlackEdge__DM0) 
#define RBlackEdge_DM1                    (* (reg8 *) RBlackEdge__DM1)
#define RBlackEdge_DM2                    (* (reg8 *) RBlackEdge__DM2) 
/* Input Buffer Disable Override */
#define RBlackEdge_INP_DIS                (* (reg8 *) RBlackEdge__INP_DIS)
/* LCD Common or Segment Drive */
#define RBlackEdge_LCD_COM_SEG            (* (reg8 *) RBlackEdge__LCD_COM_SEG)
/* Enable Segment LCD */
#define RBlackEdge_LCD_EN                 (* (reg8 *) RBlackEdge__LCD_EN)
/* Slew Rate Control */
#define RBlackEdge_SLW                    (* (reg8 *) RBlackEdge__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RBlackEdge_PRTDSI__CAPS_SEL       (* (reg8 *) RBlackEdge__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RBlackEdge_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RBlackEdge__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RBlackEdge_PRTDSI__OE_SEL0        (* (reg8 *) RBlackEdge__PRTDSI__OE_SEL0) 
#define RBlackEdge_PRTDSI__OE_SEL1        (* (reg8 *) RBlackEdge__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RBlackEdge_PRTDSI__OUT_SEL0       (* (reg8 *) RBlackEdge__PRTDSI__OUT_SEL0) 
#define RBlackEdge_PRTDSI__OUT_SEL1       (* (reg8 *) RBlackEdge__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RBlackEdge_PRTDSI__SYNC_OUT       (* (reg8 *) RBlackEdge__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(RBlackEdge__SIO_CFG)
    #define RBlackEdge_SIO_HYST_EN        (* (reg8 *) RBlackEdge__SIO_HYST_EN)
    #define RBlackEdge_SIO_REG_HIFREQ     (* (reg8 *) RBlackEdge__SIO_REG_HIFREQ)
    #define RBlackEdge_SIO_CFG            (* (reg8 *) RBlackEdge__SIO_CFG)
    #define RBlackEdge_SIO_DIFF           (* (reg8 *) RBlackEdge__SIO_DIFF)
#endif /* (RBlackEdge__SIO_CFG) */

/* Interrupt Registers */
#if defined(RBlackEdge__INTSTAT)
    #define RBlackEdge_INTSTAT            (* (reg8 *) RBlackEdge__INTSTAT)
    #define RBlackEdge_SNAP               (* (reg8 *) RBlackEdge__SNAP)
    
	#define RBlackEdge_0_INTTYPE_REG 		(* (reg8 *) RBlackEdge__0__INTTYPE)
#endif /* (RBlackEdge__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RBlackEdge_H */


/* [] END OF FILE */
