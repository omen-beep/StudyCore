/* 
 * File:   MCAL_Interrupt_CFG.h
 * Author: Eng.Yassmin
 *
 * Created on October 31, 2024, 1:31 PM
 */

#ifndef MCAL_INTERRUPT_CFG_H
#define	MCAL_INTERRUPT_CFG_H
/* Includes Section */
#include <xc.h>
#include "../MCAL_STD_TYPES.h"
#include "MCAL_Interrupt_Gen_CFG.h"
#include "../GPIO/HAL_GPIO.h"
/* Macro Declaration Section */
#define INTERRUPT_ENABLE         1
#define INTERRUPT_DISABLE        0
#define INTERRUPT_OCCUR          1
#define INTERRUPT_NOT_OCCUR      0
#define INTERRUPT_PRIO_ENABLE    1
#define INTERRUPT_PRIO_DISABLE   0
/* Macro Function Declaration Section */
#if INTERRUPT_PRIO_LEVEL_ENABLE==INTERRUPT_FEATURE_ENABLE
/* Enables Priority Interrupts */
#define INTERRUPT_PriorityEnable()              (RCONbits.IPEN = 1)
/* Disables Priority Interrupts */
#define INTERRUPT_PriorityDisable()             (RCONbits.IPEN = 0)

/* Enables Global High Priority Interrupts */
#define INTERRUPT_GlobalInterruptHighEnable()   (INTCONbits.GIEH = 1)
/* Disables Global High Priority Interrupts */
#define INTERRUPT_GlobalInterruptHighDisable()  (INTCONbits.GIEH = 0)

/* Enables Global Low Priority Interrupts */
#define INTERRUPT_GlobalInterruptLowEnable()    (INTCONbits.GIEL = 1)
/* Disables Global Low Priority Interrupts */
#define INTERRUPT_GlobalInterruptLowDisable()   (INTCONbits.GIEL = 0)
#else
/* Enables Peripheral Interrupts */
#define INTERRUPT_PeripheralEnable()            (INTCONbits.PEIE = 1)
/* Disables Peripheral Interrupts */
#define INTERRUPT_PeripheralDisable()           (INTCONbits.PEIE = 0)

/* Enables Global Interrupts */
#define INTERRUPT_GlobalInterruptEnable()   (INTCONbits.GIE = 1)
/* Disables Global Interrupts */
#define INTERRUPT_GlobalInterruptDisable()  (INTCONbits.GIE = 0)
#endif

/* Data Type Section */
typedef enum{
   INTERRUPT_PRIO_LOW = 0,
   INTERRUPT_PRIO_HIGH
}Interrupt_Prio_t;
/* Function Declaration Section */
#endif	/* MCAL_INTERRUPT_CFG_H */

