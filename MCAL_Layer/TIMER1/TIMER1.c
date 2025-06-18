#include "TIMER1.h"

#if TIMER1_INTERRUPT_FEATURE_ENABLE
static void (*TMR1_InterruptHandler)(void) = NULL;
uint16 Preload_Value = ZERO_INIT;
void TMR1_ISR(void){
    TIMER1_Interrupt_Flag_Clear();
    TMR1H = (uint8)(Preload_Value >> 8);
    TMR1L = (uint8)(Preload_Value);
    if(TMR1_InterruptHandler){
        TMR1_InterruptHandler();
    }
}
#endif

static inline void Timer1_Counter_Timer_MODE(const timer1_t *timer);

STD_ReturnType Timer1_Init(const timer1_t *timer){
     STD_ReturnType ret = E_OK;
    if(NULL == timer){
        ret = E_NOK;
    }
    else{
        TIMER1_DISABLE();
        #if TIMER1_INTERRUPT_FEATURE_ENABLE
        Preload_Value = timer->timer1_preload_value;
        TIMER1_Interrupt_Enable();
        TIMER1_Interrupt_Flag_Clear();
        TMR1_InterruptHandler = timer->Interrupt_CallBack;
        #if INTERRUPT_PRIO_LEVEL_ENABLE
        INTERRUPT_PriorityEnable();
        if(INTERRUPT_PRIO_HIGH == timer->Interrupt_Prio_t){
            INTERRUPT_GlobalInterruptHighEnable();
            TIMER1_INTERRUPT_HIGH_PRIO();
        }
        else if(INTERRUPT_PRIO_LOW == timer->Interrupt_Prio_t){
            INTERRUPT_GlobalInterruptLowEnable();
            TIMER1_INTERRUPT_LOW_PRIO();
        }
        else{}
        #else
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralEnable();
        #endif
        #endif
        TIMRE1_PRESCALER_SELECT(timer->prescaler_value);
        Timer1_Counter_Timer_MODE(timer);
        TMR1H = (uint8)((timer->timer1_preload_value) >> 8);
        TMR1L = (uint8)(timer->timer1_preload_value);
        TIMER1_ENABLE();
    }
    return ret;
}
STD_ReturnType Timer1_DeInit(const timer1_t *timer){
     STD_ReturnType ret = E_OK;
    if(NULL == timer){
        ret = E_NOK;
    }
    else{
        
        #if TIMER1_INTERRUPT_FEATURE_ENABLE
        TIMER1_Interrupt_Flag_Clear();
        TIMER1_Interrupt_Disable();
        #endif
        TIMER1_DISABLE();
    }
    return ret;
}
STD_ReturnType Timer1_Write(const timer1_t *timer, uint16 value){
     STD_ReturnType ret = E_OK;
    if(NULL == timer){
        ret = E_NOK;
    }
    else{
        TMR1H = (uint8)(value >> 8);
        TMR1L = (uint8)(value);
    }
    return ret;
}
STD_ReturnType Timer1_Read(const timer1_t *timer, uint16 *value){
     STD_ReturnType ret = E_OK;
     uint8 L_TMR1L = ZERO_INIT, L_TMR1H = ZERO_INIT;
    if((NULL == timer) || (NULL == value)){
        ret = E_NOK;
    }
    else{
        L_TMR1L = TMR1L;
        L_TMR1H = TMR1H;
        *value = (uint16)((TMR1H << 8) + TMR1L);
    }
    return ret;
}



static inline void Timer1_Counter_Timer_MODE(const timer1_t *timer){
    if(TIMER1_TIMER_MODE == timer->timer1_counter_timer_cfg){
        TIMER1_TIMER_CFG();
    }
    else if(TIMER1_COUNTER_MODE == timer->timer1_counter_timer_cfg){
        TIMER1_COUNTER_CFG();
        if(TIMER1_ASYNC_COUNTER_MODE == timer->timer1_async_cfg){
            TIMER1_ASYNC_COUNTER_CFG();
        }
        else if(TIMER1_SYNC_COUNTER_MODE == timer->timer1_async_cfg){
            TIMER1_SYNC_COUNTER_CFG();
        }
        else{}
    }
    else{}
}
