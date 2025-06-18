/* 
 * File:   MCAL_TIMER.h
 * Author: Eng.Yassmin
 *
 * Created on November 17, 2024, 1:21 PM
 */

#ifndef MCAL_TIMER_H
#define	MCAL_TIMER_H
/* Includes Section */
#include <xc.h>
#include "MCAL_TIMER_CFG.h"
#include "../GPIO/HAL_GPIO.h"
#include "../../MCAL_Layer/MCAL_STD_TYPES.h"
#include "../MCAL_Interrupts/MCAL_Internal_Interrupt.h"

/* Macro Declaration Section */
#define TIMER_PRESCALER_ENABLE     1
#define TIMER_PRESCALER_DISABLE    0

#define TIMER_FALLING_EDGE         1
#define TIMER_RISING_EDGE          0

#define TIMER_TIMER_MODE           1
#define TIMER_COUNTER_MODE         0

#define TIMER_8BIT_MODE            1
#define TIMER_16BIT_MODE           0
/* Macro Function Declaration Section */
#define TIMER0_ENABLE()              (T0CONbits.TMR0ON = 1)
#define TIMER0_DISABLE()             (T0CONbits.TMR0ON = 0)

#define TIMRE0_PRESCALER_ENABLE()    (T0CONbits.PSA = 0)
#define TIMRE0_PRESCALER_DISABLE()   (T0CONbits.PSA = 1)

#define TIMRE0_RISING_EDGE()         (T0CONbits.T0SE = 0)
#define TIMRE0_FALLING_EDGE()        (T0CONbits.T0SE = 1)

#define TIMER0_TIMER_MODE()          (T0CONbits.T0CS = 0)
#define TIMER0_COUNTER_MODE()        (T0CONbits.T0CS = 1)

#define TIMER0_8BIT_MODE()           (T0CONbits.T08BIT = 1)
#define TIMER0_16BIT_MODE()          (T0CONbits.T08BIT = 0)
/* Data Type Section */ 
typedef enum{
    TIMER0_PRESCALER_DIV_2 = 0,
    TIMER0_PRESCALER_DIV_4,
    TIMER0_PRESCALER_DIV_8,
    TIMER0_PRESCALER_DIV_16,
    TIMER0_PRESCALER_DIV_32,
    TIMER0_PRESCALER_DIV_64,
    TIMER0_PRESCALER_DIV_128,
    TIMER0_PRESCALER_DIV_256 
}timer0_prescaler_select_t;

typedef struct{
    #if TIMER0_INTERRUPT_FEATURE_ENABLE
    void (*Interrupt_CallBack) (void);
    #if INTERRUPT_PRIO_LEVEL_ENABLE
    Interrupt_Prio_t Priority;
    #endif
    #endif
    uint8 prescaler_status            :1;
    timer0_prescaler_select_t prescaler_value;
    uint8 timer0_edge_cfg             :1;
    uint8 timer0_counter_timer_cfg    :1;
    uint8 timer0_bit_mode             :1;
    uint8 reserved                    :4;
    uint16 timer0_preload_value;
    
}timer0_t;
/* Function Declaration Section */
STD_ReturnType Timer0_Init(const timer0_t *timer);
STD_ReturnType Timer0_DeInit(const timer0_t *timer);
STD_ReturnType Timer0_Write(const timer0_t *timer, uint16 value);
STD_ReturnType Timer0_Read(const timer0_t *timer, uint16 *value);
#endif	/* MCAL_TIMER_H */

