#include "MCAL_TIMER2.h"

#if TIMER2_INTERRUPT_FEATURE_ENABLE
static void (*TMR2_InterruptHandler)(void) = NULL;
uint8 Timer2_Preload_Value = ZERO_INIT;
void TMR2_ISR(void){
    TIMER2_Interrupt_Flag_Clear();
    TMR2 = Timer2_Preload_Value;
    if(TMR2_InterruptHandler){
        TMR2_InterruptHandler();
    }
}
#endif



STD_ReturnType Timer2_Init(const timer2_t *timer){
     STD_ReturnType ret = E_OK;
    if(NULL == timer){
        ret = E_NOK;
    }
    else{
        TIMER2_DISABLE();
        #if TIMER2_INTERRUPT_FEATURE_ENABLE
        Timer2_Preload_Value = timer->timer2_preload_value;
        TIMER2_Interrupt_Enable();
        TIMER2_Interrupt_Flag_Clear();
        TMR2_InterruptHandler = timer->Interrupt_CallBack;
        #if INTERRUPT_PRIO_LEVEL_ENABLE
        INTERRUPT_PriorityEnable();
        if(INTERRUPT_PRIO_HIGH == timer->Interrupt_Prio_t){
            INTERRUPT_GlobalInterruptHighEnable();
            TIMER2_INTERRUPT_HIGH_PRIO();
        }
        else if(INTERRUPT_PRIO_LOW == timer->Interrupt_Prio_t){
            INTERRUPT_GlobalInterruptLowEnable();
            TIMER2_INTERRUPT_LOW_PRIO();
        }
        else{}
        #else
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralEnable();
        #endif
        #endif
        TIMRE2_PRESCALER_SELECT(timer->prescaler_value);
        TIMRE2_POSTSCALER_SELECT(timer->postscaler_value);
        TMR2 = (uint8)(timer->timer2_preload_value);
        TIMER2_ENABLE();
    }
    return ret;
}
STD_ReturnType Timer2_DeInit(const timer2_t *timer){
     STD_ReturnType ret = E_OK;
    if(NULL == timer){
        ret = E_NOK;
    }
    else{
        
        #if TIMER2_INTERRUPT_FEATURE_ENABLE
        TIMER2_Interrupt_Flag_Clear();
        TIMER2_Interrupt_Disable();
        #endif
        TIMER2_DISABLE();
    }
    return ret;
}
STD_ReturnType Timer2_Write(const timer2_t *timer, uint8 value){
     STD_ReturnType ret = E_OK;
    if(NULL == timer){
        ret = E_NOK;
    }
    else{
        TMR2 = value;
    }
    return ret;
}
STD_ReturnType Timer2_Read(const timer2_t *timer, uint8 *value){
     STD_ReturnType ret = E_OK;
    if((NULL == timer) || (NULL == value)){
        ret = E_NOK;
    }
    else{
        
        *value = TMR2;
    }
    return ret;
}
