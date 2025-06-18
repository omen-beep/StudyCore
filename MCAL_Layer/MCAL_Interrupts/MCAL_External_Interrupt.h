/* 
 * File:   MCAL_External_Interrupt.h
 * Author: Eng.Yassmin
 *
 * Created on October 31, 2024, 1:32 PM
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H
/* Includes Section */
#include "MCAL_Interrupt_CFG.h"
/* Macro Declaration Section */

/* Macro Function Declaration Section */
#if INTERRUPT_EXTERNAL_FEATURE_INTx_ENABLE==INTERRUPT_FEATURE_ENABLE
/* Enables INT0 Interrupt */
#define EXT_INT0_Interrupt_Enable()          (INTCONbits.INT0IE = 1)
/* Disables INT0 Interrupt */
#define EXT_INT0_Interrupt_Disable()         (INTCONbits.INT0IE = 0)
/* Clears INT0 Interrupt Flag */
#define EXT_INT0_Interrupt_Flag_Clear()      (INTCONbits.INT0IF = 0)
/* Interrupts INT0 on Rising Edge */
#define EXT_INT0_RisingEdge()                (INTCON2bits.INTEDG0 = 1)
/* Interrupts INT0 on Falling Edge */
#define EXT_INT0_FallingEdge()               (INTCON2bits.INTEDG0 = 0)

/* Enables INT1 Interrupt */
#define EXT_INT1_Interrupt_Enable()          (INTCON3bits.INT1IE = 1)
/* Disables INT1 Interrupt */
#define EXT_INT1_Interrupt_Disable()         (INTCON3bits.INT1IE = 0)
/* Clears INT0 Interrupt Flag */
#define EXT_INT1_Interrupt_Flag_Clear()      (INTCON3bits.INT1IF = 0)
/* Interrupts INT1 on Rising Edge */
#define EXT_INT1_RisingEdge()                (INTCON2bits.INTEDG1 = 1)
/* Interrupts INT1 on Falling Edge */
#define EXT_INT1_FallingEdge()               (INTCON2bits.INTEDG1 = 0)

/* Enables INT2 Interrupt */
#define EXT_INT2_Interrupt_Enable()          (INTCON3bits.INT2IE = 1)
/* Disables INT2 Interrupt */
#define EXT_INT2_Interrupt_Disable()         (INTCON3bits.INT2IE = 0)
/* Clears INT2 Interrupt Flag */
#define EXT_INT2_Interrupt_Flag_Clear()      (INTCON3bits.INT2IF = 0)
/* Interrupts INT2 on Rising Edge */
#define EXT_INT2_RisingEdge()                (INTCON2bits.INTEDG2 = 1)
/* Interrupts INT2 on Falling Edge */
#define EXT_INT2_FallingEdge()               (INTCON2bits.INTEDG2 = 0)

#if INTERRUPT_PRIO_LEVEL_ENABLE==INTERRUPT_FEATURE_ENABLE
/* Sets INT1 to High Priority */
#define EXT_INT1_PRIO_HIGH()                 (INTCON3bits.INT1IP = 1)
/* Sets INT1 to Low Priority */
#define EXT_INT1_PRIO_LOW()                  (INTCON3bits.INT1IP = 0)
/* Sets INT2 to High Priority */
#define EXT_INT2_PRIO_HIGH()                 (INTCON3bits.INT2IP = 1)
/* Sets INT12 to Low Priority */
#define EXT_INT2_PRIO_LOW()                  (INTCON3bits.INT2IP = 0)
#endif

#endif


#if INTERRUPT_EXTERNAL_FEATURE_OnChange_ENABLE==INTERRUPT_FEATURE_ENABLE
/* Enables RBx Interrupt */
#define EXT_RBx_Interrupt_Enable()          (INTCONbits.RBIE = 1)
/* Disables IRBx Interrupt */
#define EXT_RBx_Interrupt_Disable()         (INTCONbits.RBIE = 0)
/* Clears RBx Interrupt Flag */
#define EXT_RBx_Interrupt_Flag_Clear()      (INTCONbits.RBIF = 0)

#if INTERRUPT_PRIO_LEVEL_ENABLE==INTERRUPT_FEATURE_ENABLE
/* Sets RBx to High Priority */
#define EXT_RBx_PRIO_HIGH()                 (INTCON2bits.RBIP = 1)
/* Sets RBx to Low Priority */
#define EXT_RBx_PRIO_LOW()                  (INTCON2bits.RBIP = 0)
#endif

#endif
/* Data Type Section */
typedef enum{
    INTERRUPT_FALLING_EDGE = 0,
    INTERRUPT_RISING_EDGE
}Interrupt_INTx_Edge_t;

typedef enum{
    INTERRUPT_EXT_INT0 = 0,
    INTERRUPT_EXT_INT1,
    INTERRUPT_EXT_INT2
}Interrupt_INTx_SRC_t;

typedef struct{
    void (*Interrupt_CallBack) (void);
    pin_config_t MCU_Pin;
    Interrupt_INTx_Edge_t Edge;
    Interrupt_INTx_SRC_t Source;
    Interrupt_Prio_t Priority;
}Interrupt_INTx_t;
typedef struct{
    void (*Interrupt_CallBack_HIGH) (void);
    void (*Interrupt_CallBack_LOW) (void);
    pin_config_t MCU_Pin;
    Interrupt_Prio_t Priority;
}Interrupt_RBx_t;
/* Function Declaration Section */
STD_ReturnType Interrupt_INTx_Init(const Interrupt_INTx_t *int_obj);
STD_ReturnType Interrupt_INTx_DeInit(const Interrupt_INTx_t *int_obj);

STD_ReturnType Interrupt_RBx_Init(const Interrupt_RBx_t *int_obj);
STD_ReturnType Interrupt_RBx_DeInit(const Interrupt_RBx_t *int_obj);
#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

