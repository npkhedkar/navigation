/*******************************************************************************
* File Name: HSync.h  
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

#if !defined(CY_PINS_HSync_H) /* Pins HSync_H */
#define CY_PINS_HSync_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "HSync_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 HSync__PORT == 15 && ((HSync__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    HSync_Write(uint8 value);
void    HSync_SetDriveMode(uint8 mode);
uint8   HSync_ReadDataReg(void);
uint8   HSync_Read(void);
void    HSync_SetInterruptMode(uint16 position, uint16 mode);
uint8   HSync_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the HSync_SetDriveMode() function.
     *  @{
     */
        #define HSync_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define HSync_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define HSync_DM_RES_UP          PIN_DM_RES_UP
        #define HSync_DM_RES_DWN         PIN_DM_RES_DWN
        #define HSync_DM_OD_LO           PIN_DM_OD_LO
        #define HSync_DM_OD_HI           PIN_DM_OD_HI
        #define HSync_DM_STRONG          PIN_DM_STRONG
        #define HSync_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define HSync_MASK               HSync__MASK
#define HSync_SHIFT              HSync__SHIFT
#define HSync_WIDTH              1u

/* Interrupt constants */
#if defined(HSync__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in HSync_SetInterruptMode() function.
     *  @{
     */
        #define HSync_INTR_NONE      (uint16)(0x0000u)
        #define HSync_INTR_RISING    (uint16)(0x0001u)
        #define HSync_INTR_FALLING   (uint16)(0x0002u)
        #define HSync_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define HSync_INTR_MASK      (0x01u) 
#endif /* (HSync__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HSync_PS                     (* (reg8 *) HSync__PS)
/* Data Register */
#define HSync_DR                     (* (reg8 *) HSync__DR)
/* Port Number */
#define HSync_PRT_NUM                (* (reg8 *) HSync__PRT) 
/* Connect to Analog Globals */                                                  
#define HSync_AG                     (* (reg8 *) HSync__AG)                       
/* Analog MUX bux enable */
#define HSync_AMUX                   (* (reg8 *) HSync__AMUX) 
/* Bidirectional Enable */                                                        
#define HSync_BIE                    (* (reg8 *) HSync__BIE)
/* Bit-mask for Aliased Register Access */
#define HSync_BIT_MASK               (* (reg8 *) HSync__BIT_MASK)
/* Bypass Enable */
#define HSync_BYP                    (* (reg8 *) HSync__BYP)
/* Port wide control signals */                                                   
#define HSync_CTL                    (* (reg8 *) HSync__CTL)
/* Drive Modes */
#define HSync_DM0                    (* (reg8 *) HSync__DM0) 
#define HSync_DM1                    (* (reg8 *) HSync__DM1)
#define HSync_DM2                    (* (reg8 *) HSync__DM2) 
/* Input Buffer Disable Override */
#define HSync_INP_DIS                (* (reg8 *) HSync__INP_DIS)
/* LCD Common or Segment Drive */
#define HSync_LCD_COM_SEG            (* (reg8 *) HSync__LCD_COM_SEG)
/* Enable Segment LCD */
#define HSync_LCD_EN                 (* (reg8 *) HSync__LCD_EN)
/* Slew Rate Control */
#define HSync_SLW                    (* (reg8 *) HSync__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define HSync_PRTDSI__CAPS_SEL       (* (reg8 *) HSync__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define HSync_PRTDSI__DBL_SYNC_IN    (* (reg8 *) HSync__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define HSync_PRTDSI__OE_SEL0        (* (reg8 *) HSync__PRTDSI__OE_SEL0) 
#define HSync_PRTDSI__OE_SEL1        (* (reg8 *) HSync__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define HSync_PRTDSI__OUT_SEL0       (* (reg8 *) HSync__PRTDSI__OUT_SEL0) 
#define HSync_PRTDSI__OUT_SEL1       (* (reg8 *) HSync__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define HSync_PRTDSI__SYNC_OUT       (* (reg8 *) HSync__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(HSync__SIO_CFG)
    #define HSync_SIO_HYST_EN        (* (reg8 *) HSync__SIO_HYST_EN)
    #define HSync_SIO_REG_HIFREQ     (* (reg8 *) HSync__SIO_REG_HIFREQ)
    #define HSync_SIO_CFG            (* (reg8 *) HSync__SIO_CFG)
    #define HSync_SIO_DIFF           (* (reg8 *) HSync__SIO_DIFF)
#endif /* (HSync__SIO_CFG) */

/* Interrupt Registers */
#if defined(HSync__INTSTAT)
    #define HSync_INTSTAT            (* (reg8 *) HSync__INTSTAT)
    #define HSync_SNAP               (* (reg8 *) HSync__SNAP)
    
	#define HSync_0_INTTYPE_REG 		(* (reg8 *) HSync__0__INTTYPE)
#endif /* (HSync__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_HSync_H */


/* [] END OF FILE */
