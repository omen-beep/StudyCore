/* 
 * File:   MCAL_TIMER3.h
 * Author: Eng.Yassmin
 *
 * Created on November 23, 2024, 1:58 PM
 */

#ifndef MCAL_TIMER3_H
#define	MCAL_TIMER3_H
/* Includes Section */
#include <xc.h>
#include "../GPIO/HAL_GPIO.h"
#include "../../MCAL_Layer/MCAL_STD_TYPES.h"
#include "../MCAL_Interrupts/MCAL_Internal_Interrupt.h"

/* Macro Declaration Section */
#define TIMER3_TIMER_MODE           0
#define TIMER3_COUNTER_MODE         1

#define TIMER3_8BIT_MODE            0
#define TIMER3_16BIT_MODE           1

#define TIMER3_ASYNC_COUNTER_MODE   0
#define TIMER3_SYNC_COUNTER_MODE    1


/* Macro Function Declaration Section */
#define TIMER3_ENABLE()              (T3CONbits.TMR3ON = 1)
#define TIMER3_DISABLE()             (T3CONbits.TMR3ON = 0)

#define TIMER3_ASYNC_COUNTER_CFG()   (T3CONbits.T3SYNC = 1)
#define TIMER3_SYNC_COUNTER_CFG()    (T3CONbits.T3SYNC = 0)

#define TIMRE3_PRESCALER_SELECT(timer3_prescaler)    (T3CONbits.T3CKPS = timer3_prescaler)

#define TIMER3_TIMER_CFG()           (T3CONbits.TMR3CS = 0)
#define TIMER3_COUNTER_CFG()         (T3CONbits.TMR3CS = 1)

#define TIMER3_8BIT_CFG()            (T3CONbits.RD16 = 0)
#define TIMER3_16BIT_CFG()           (T3CONbits.RD16 = 1)
/* Data Type Section */ 
typedef enum{
    TIMER3_PRESCALER_DIV_1 = 0,
    TIMER3_PRESCALER_DIV_2,
    TIMER3_PRESCALER_DIV_4,
    TIMER3_PRESCALER_DIV_8,
}timer3_prescaler_select_t;

typedef struct{
    #if TIMER3_INTERRUPT_FEATURE_ENABLE
    void (*Interrupt_CallBack) (void);
    #if INTERRUPT_PRIO_LEVEL_ENABLE
    Interrupt_Prio_t Priority;
    #endif
    #endif
    timer3_prescaler_select_t prescaler_value;
    uint8 timer3_counter_timer_cfg    :1;
    uint8 timer3_async_cfg            :1;
    uint8 timer3_bit_mode             :1;
    uint8 reserved                    :5;
    uint16 timer3_preload_value;
    
}timer3_t;
/* Function Declaration Section */
STD_ReturnType Timer3_Init(const timer3_t *timer);
STD_ReturnType Timer3_DeInit(const timer3_t *timer);
STD_ReturnType Timer3_Write(const timer3_t *timer, uint16 value);
STD_ReturnType Timer3_Read(const timer3_t *timer, uint16 *value);
#endif	/* MCAL_TIMER3_H */

