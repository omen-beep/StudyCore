/* 
 * File:   TIMER1.h
 * Author: Eng.Yassmin
 *
 * Created on November 22, 2024, 3:31 PM
 */

#ifndef TIMER1_H
#define	TIMER1_H
/* Includes Section */
#include <xc.h>
#include "../GPIO/HAL_GPIO.h"
#include "../../MCAL_Layer/MCAL_STD_TYPES.h"
#include "../MCAL_Interrupts/MCAL_Internal_Interrupt.h"
/* Macro Declaration Section */
#define TIMER1_TIMER_MODE           1
#define TIMER1_COUNTER_MODE         0

#define TIMER1_ASYNC_COUNTER_MODE   1
#define TIMER1_SYNC_COUNTER_MODE    0

#define TIMER1_OSC_ENABLE           1
#define TIMER1_OSC_DISABLE          0

#define TIMER1_8BIT_MODE            0
#define TIMER1_16BIT_MODE           1
/* Macro Function Declaration Section */
#define TIMER1_ENABLE()              (T1CONbits.TMR1ON = 1)
#define TIMER1_DISABLE()             (T1CONbits.TMR1ON = 0)

#define TIMER1_TIMER_CFG()          (T1CONbits.TMR1CS = 0)
#define TIMER1_COUNTER_CFG()        (T1CONbits.TMR1CS = 1)

#define TIMER1_ASYNC_COUNTER_CFG()  (T1CONbits.T1SYNC = 1)
#define TIMER1_SYNC_COUNTER_CFG()   (T1CONbits.T1SYNC = 0)

#define TIMER1_OSC_HW_ENABLE()          (T1CONbits.T1OSCEN = 1)
#define TIMER1_OSC_HW_DISABLE()         (T1CONbits.T1OSCEN = 0)

#define TIMRE1_PRESCALER_SELECT(timer1_prescaler)    (T1CONbits.T1CKPS = timer1_prescaler)

#define TIMER1_CLOCK_SYS_STATUS()    (T1CONbits.T1RUN)

#define TIMER1_8BIT_CFG()           (T1CONbits.RD16 = 0)
#define TIMER1_16BIT_CFG()          (T1CONbits.RD16 = 1)

/* Data Type Section */
typedef enum{
    TIMER1_PRESCALER_DIV_1 = 0,
    TIMER1_PRESCALER_DIV_2,
    TIMER1_PRESCALER_DIV_4,
    TIMER1_PRESCALER_DIV_8,
}timer1_prescaler_select_t;

typedef struct{
    #if TIMER1_INTERRUPT_FEATURE_ENABLE
    void (*Interrupt_CallBack) (void);
    #if INTERRUPT_PRIO_LEVEL_ENABLE
    Interrupt_Prio_t Priority;
    #endif
    #endif
    
    timer1_prescaler_select_t prescaler_value;
    uint8 timer1_counter_timer_cfg    :1;
    uint8 timer1_async_cfg            :1;
    uint8 timer1_osc_cfg              :1;
    uint8 timer1_bit_mode             :1;
    uint8 reserved                    :4;
    uint16 timer1_preload_value;
    
}timer1_t;
/* Function Declaration Section */
STD_ReturnType Timer1_Init(const timer1_t *timer);
STD_ReturnType Timer1_DeInit(const timer1_t *timer);
STD_ReturnType Timer1_Write(const timer1_t *timer, uint16 value);
STD_ReturnType Timer1_Read(const timer1_t *timer, uint16 *value);
#endif	/* TIMER1_H */

