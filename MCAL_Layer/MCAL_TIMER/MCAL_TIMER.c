#include "MCAL_TIMER.h"

#if TIMER0_INTERRUPT_FEATURE_ENABLE
static void (*TMR0_InterruptHandler)(void) = NULL;
uint16 Preload_Value = ZERO_INIT;
void TMR0_ISR(void){
    TIMER0_Interrupt_Flag_Clear();
    TMR0H = (uint8)(Preload_Value >> 8);
    TMR0L = (uint8)(Preload_Value);
    if(TMR0_InterruptHandler){
        TMR0_InterruptHandler();
    }
}
#endif

static inline void Timer0_Prescaler(const timer0_t *timer);
static inline void Timer0_Counter_Timer_MODE(const timer0_t *timer);
static inline void Timer0_EDGE_CONFIG(const timer0_t *timer);
static inline void Timer0_BIT_SIZE(const timer0_t *timer);

STD_ReturnType Timer0_Init(const timer0_t *timer){
     STD_ReturnType ret = E_OK;
    if(NULL == timer){
        ret = E_NOK;
    }
    else{
        TIMER0_DISABLE();
        #if TIMER0_INTERRUPT_FEATURE_ENABLE
        Preload_Value = timer->timer0_preload_value;
        TIMER0_Interrupt_Enable();
        TIMER0_Interrupt_Flag_Clear();
        TMR0_InterruptHandler = timer->Interrupt_CallBack;
        #if INTERRUPT_PRIO_LEVEL_ENABLE
        INTERRUPT_PriorityEnable();
        if(INTERRUPT_PRIO_HIGH == timer->Interrupt_Prio_t){
            INTERRUPT_GlobalInterruptHighEnable();
            TIMER0_INTERRUPT_HIGH_PRIO();
        }
        else if(INTERRUPT_PRIO_LOW == timer->Interrupt_Prio_t){
            INTERRUPT_GlobalInterruptLowEnable();
            TIMER0_INTERRUPT_LOW_PRIO();
        }
        else{}
        #else
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralEnable();
        #endif
        #endif
        Timer0_Prescaler(timer);
        Timer0_Counter_Timer_MODE(timer);
        Timer0_BIT_SIZE(timer);
        TMR0H = (uint8)((timer->timer0_preload_value) >> 8);
        TMR0L = (uint8)(timer->timer0_preload_value);
        TIMER0_ENABLE();
    }
    return ret;
}
STD_ReturnType Timer0_DeInit(const timer0_t *timer){
     STD_ReturnType ret = E_OK;
    if(NULL == timer){
        ret = E_NOK;
    }
    else{
        
        #if TIMER0_INTERRUPT_FEATURE_ENABLE
        TIMER0_Interrupt_Flag_Clear();
        TIMER0_Interrupt_Disable();
        #endif
        TIMER0_DISABLE();
    }
    return ret;
}
STD_ReturnType Timer0_Write(const timer0_t *timer, uint16 value){
     STD_ReturnType ret = E_OK;
    if(NULL == timer){
        ret = E_NOK;
    }
    else{
        TMR0H = (uint8)(value >> 8);
        TMR0L = (uint8)(value);
    }
    return ret;
}
STD_ReturnType Timer0_Read(const timer0_t *timer, uint16 *value){
     STD_ReturnType ret = E_OK;
     uint8 L_TMR0L = ZERO_INIT, L_TMR0H = ZERO_INIT;
    if((NULL == timer) || (NULL == value)){
        ret = E_NOK;
    }
    else{
        L_TMR0L = TMR0L;
        L_TMR0H = TMR0H;
        *value = (uint16)((TMR0H << 8) + TMR0L);
    }
    return ret;
}

static inline void Timer0_Prescaler(const timer0_t *timer){
    if(TIMER_PRESCALER_ENABLE == timer->prescaler_status){
        TIMRE0_PRESCALER_ENABLE();
        T0CONbits.T0PS = timer->prescaler_value;
    }
    else if(TIMER_PRESCALER_DISABLE == timer->prescaler_status){
        TIMRE0_PRESCALER_DISABLE();
    }
    else{}
}

static inline void Timer0_Counter_Timer_MODE(const timer0_t *timer){
    if(TIMER_TIMER_MODE == timer->timer0_counter_timer_cfg){
        TIMER0_TIMER_MODE();
    }
    else if(TIMER_COUNTER_MODE == timer->timer0_counter_timer_cfg){
        TIMER0_COUNTER_MODE();
        Timer0_EDGE_CONFIG(timer);
    }
    else{}
}

static inline void Timer0_EDGE_CONFIG(const timer0_t *timer){
    if(TIMER_FALLING_EDGE == timer->timer0_edge_cfg){
        TIMRE0_FALLING_EDGE();
    }
    else if(TIMER_RISING_EDGE == timer->timer0_edge_cfg){
        TIMRE0_RISING_EDGE();
    }
    else{}
}

static inline void Timer0_BIT_SIZE(const timer0_t *timer){
    if(TIMER_8BIT_MODE == timer->timer0_bit_mode){
        TIMER0_8BIT_MODE();
    }
    else if(TIMER_16BIT_MODE == timer->timer0_bit_mode){
        TIMER0_16BIT_MODE();
    }
    else{}
}