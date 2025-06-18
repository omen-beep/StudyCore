#include "MCAL_TIMER3.h"


#if TIMER3_INTERRUPT_FEATURE_ENABLE
static void (*TMR3_InterruptHandler)(void) = NULL;
uint16 Timer3_Preload_Value = ZERO_INIT;
void TMR3_ISR(void){
    TIMER3_Interrupt_Flag_Clear();
    TMR3H = (uint8)(Timer3_Preload_Value >> 8);
    TMR3L = (uint8)(Timer3_Preload_Value);
    if(TMR3_InterruptHandler){
        TMR3_InterruptHandler();
    }
}
#endif

static inline void Timer3_Counter_Timer_MODE(const timer3_t *timer);
static inline void Timer3_BIT_SIZE(const timer3_t *timer);

STD_ReturnType Timer3_Init(const timer3_t *timer){
     STD_ReturnType ret = E_OK;
    if(NULL == timer){
        ret = E_NOK;
    }
    else{
        TIMER3_DISABLE();
        #if TIMER3_INTERRUPT_FEATURE_ENABLE
        Timer3_Preload_Value = timer->timer3_preload_value;
        TIMER3_Interrupt_Enable();
        TIMER3_Interrupt_Flag_Clear();
        TMR3_InterruptHandler = timer->Interrupt_CallBack;
        #if INTERRUPT_PRIO_LEVEL_ENABLE
        INTERRUPT_PriorityEnable();
        if(INTERRUPT_PRIO_HIGH == timer->Interrupt_Prio_t){
            INTERRUPT_GlobalInterruptHighEnable();
            TIMER3_INTERRUPT_HIGH_PRIO();
        }
        else if(INTERRUPT_PRIO_LOW == timer->Interrupt_Prio_t){
            INTERRUPT_GlobalInterruptLowEnable();
            TIMER3_INTERRUPT_LOW_PRIO();
        }
        else{}
        #else
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralEnable();
        #endif
        #endif
        TIMRE3_PRESCALER_SELECT(timer->prescaler_value);
        Timer3_Counter_Timer_MODE(timer);
        Timer3_BIT_SIZE(timer);
        TMR3H = (uint8)((timer->timer3_preload_value) >> 8);
        TMR3L = (uint8)(timer->timer3_preload_value);
        TIMER3_ENABLE();
    }
    return ret;
}
STD_ReturnType Timer3_DeInit(const timer3_t *timer){
     STD_ReturnType ret = E_OK;
    if(NULL == timer){
        ret = E_NOK;
    }
    else{
        #if TIMER3_INTERRUPT_FEATURE_ENABLE
        TIMER3_Interrupt_Flag_Clear();
        TIMER3_Interrupt_Disable();
        #endif
        TIMER3_DISABLE();
    }
    return ret;
}
STD_ReturnType Timer3_Write(const timer3_t *timer, uint16 value){
     STD_ReturnType ret = E_OK;
    if(NULL == timer){
        ret = E_NOK;
    }
    else{
        TMR3H = (uint8)(value >> 8);
        TMR3L = (uint8)(value);
    }
    return ret;
}
STD_ReturnType Timer3_Read(const timer3_t *timer, uint16 *value){
     STD_ReturnType ret = E_OK;
     uint8 L_TMR3L = ZERO_INIT, L_TMR3H = ZERO_INIT;
    if((NULL == timer) || (NULL == value)){
        ret = E_NOK;
    }
    else{
        L_TMR3L = TMR3L;
        L_TMR3H = TMR3H;
        *value = (uint16)((TMR3H << 8) + TMR3L);
    }
    return ret;
}

static inline void Timer3_Counter_Timer_MODE(const timer3_t *timer){
    if(TIMER3_TIMER_MODE == timer->timer3_counter_timer_cfg){
        TIMER3_TIMER_CFG();
    }
    else if(TIMER3_COUNTER_MODE == timer->timer3_counter_timer_cfg){
        TIMER3_COUNTER_CFG();
        if(TIMER3_ASYNC_COUNTER_MODE == timer->timer3_async_cfg){
            TIMER3_ASYNC_COUNTER_CFG();
        }
        else if(TIMER3_SYNC_COUNTER_MODE == timer->timer3_async_cfg){
            TIMER3_SYNC_COUNTER_CFG();
        }
        else{}
    }
    else{}
}

static inline void Timer3_BIT_SIZE(const timer3_t *timer){
    if(TIMER3_8BIT_MODE == timer->timer3_bit_mode){
        TIMER3_8BIT_CFG();
    }
    else if(TIMER3_16BIT_MODE == timer->timer3_bit_mode){
        TIMER3_16BIT_CFG();
    }
    else{}
}