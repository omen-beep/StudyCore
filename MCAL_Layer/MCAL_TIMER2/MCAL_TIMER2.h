/* 
 * File:   MCAL_TIMER2.h
 * Author: Eng.Yassmin
 *
 * Created on November 23, 2024, 1:55 PM
 */

#ifndef MCAL_TIMER2_H
#define	MCAL_TIMER2_H
/* Includes Section */
#include <xc.h>
#include "../GPIO/HAL_GPIO.h"
#include "../../MCAL_Layer/MCAL_STD_TYPES.h"
#include "../MCAL_Interrupts/MCAL_Internal_Interrupt.h"

/* Macro Declaration Section */

/* Macro Function Declaration Section */
#define TIMER2_ENABLE()              (T2CONbits.TMR2ON = 1)
#define TIMER2_DISABLE()             (T2CONbits.TMR2ON = 0)

#define TIMRE2_PRESCALER_SELECT(timer2_prescaler)    (T2CONbits.T2CKPS = timer2_prescaler)
#define TIMRE2_POSTSCALER_SELECT(timer2_postscaler)    (T2CONbits.TOUTPS = timer2_postscaler)

/* Data Type Section */ 
typedef enum{
    TIMER2_PRESCALER_DIV_1 = 0,
    TIMER2_PRESCALER_DIV_4,
    TIMER2_PRESCALER_DIV_16,
}timer2_prescaler_select_t;

typedef enum{
    TIMER2_POSTSCALER_DIV_1 = 0,
    TIMER2_POSTSCALER_DIV_2,
    TIMER2_POSTSCALER_DIV_3,
    TIMER2_POSTSCALER_DIV_4,
    TIMER2_POSTSCALER_DIV_5,
    TIMER2_POSTSCALER_DIV_6,
    TIMER2_POSTSCALER_DIV_7,
    TIMER2_POSTSCALER_DIV_8,
    TIMER2_POSTSCALER_DIV_9,
    TIMER2_POSTSCALER_DIV_10,
    TIMER2_POSTSCALER_DIV_11,
    TIMER2_POSTSCALER_DIV_12,
    TIMER2_POSTSCALER_DIV_13,
    TIMER2_POSTSCALER_DIV_14,
    TIMER2_POSTSCALER_DIV_15,
    TIMER2_POSTSCALER_DIV_16
}timer2_postscaler_select_t;

typedef struct{
    #if TIMER2_INTERRUPT_FEATURE_ENABLE
    void (*Interrupt_CallBack) (void);
    #if INTERRUPT_PRIO_LEVEL_ENABLE
    Interrupt_Prio_t Priority;
    #endif
    #endif
    timer2_prescaler_select_t prescaler_value;
    timer2_postscaler_select_t postscaler_value;
    uint8 timer2_preload_value;
    
}timer2_t;
/* Function Declaration Section */
STD_ReturnType Timer2_Init(const timer2_t *timer);
STD_ReturnType Timer2_DeInit(const timer2_t *timer);
STD_ReturnType Timer2_Write(const timer2_t *timer, uint8 value);
STD_ReturnType Timer2_Read(const timer2_t *timer, uint8 *value);
#endif	/* MCAL_TIMER2_H */

