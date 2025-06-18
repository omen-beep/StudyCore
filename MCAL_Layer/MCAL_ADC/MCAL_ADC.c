#include "MCAL_ADC.h"

#if ADC_INTERRUPT_FEATURE_ENABLE
static void (*ADC_InterruptHandler) (void) = NULL;
#endif

static inline void ADC_INPUT_CHANNEL_PIN_CONFIG(ADC_CHANNEL_SELECT_t channel);
static inline void ADC_SELECT_RESULT_FORMAT(const ADC_CONFIG_t *adc);
static inline void ADC_SELECT_VOLTAGE_REFERENCE(const ADC_CONFIG_t *adc);

void ADC_ISR(void){
    ADC_Interrupt_Flag_Clear();
    /* code */
    if(ADC_InterruptHandler){
        ADC_InterruptHandler();
    }
}

STD_ReturnType ADC_Init(const ADC_CONFIG_t *adc){
    STD_ReturnType ret = E_OK;
    if(NULL == adc){
        ret = E_NOK;
    }
    else{
        ADC_CONVERTER_DISABLE();
        ADCON2bits.ACQT = adc->aquisition_time;
        ADCON2bits.ADCS = adc->conversion_clock;
        ADCON0bits.CHS = adc->channel;
        ADC_INPUT_CHANNEL_PIN_CONFIG(adc->channel);
        #if ADC_INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PeripheralEnable();
        INTERRUPT_GlobalInterruptEnable();
        ADC_Interrupt_Enable();
        ADC_Interrupt_Flag_Clear();
        #if INTERRUPT_PRIO_LEVEL_ENABLE
        if(INTERRUPT_PRIO_HIGH == adc->Priority){ADC_INTERRUPT_HIGH_PRIO();}
        else if(INTERRUPT_PRIO_LOW == adc->Priority){ADC_INTERRUPT_LOW_PRIO();}
        else{}
        #endif
        ADC_InterruptHandler = adc->ADC_InterruptHandler;
        #endif
        ADC_SELECT_RESULT_FORMAT(adc);
        ADC_SELECT_VOLTAGE_REFERENCE(adc);
        ADC_CONVERTER_ENABLE();
    }
    return ret;
}
STD_ReturnType ADC_Deinit(const ADC_CONFIG_t *adc){
    STD_ReturnType ret = E_OK;
    if(NULL == adc){
        ret = E_NOK;
    }
    else{
        ADC_CONVERTER_DISABLE();
        #if ADC_INTERRUPT_FEATURE_ENABLE
        ADC_Interrupt_Disable();
        ADC_Interrupt_Flag_Clear();
        #endif
    }
    return ret;
}
STD_ReturnType ADC_SELECT_CHANNEL(const ADC_CONFIG_t *adc, ADC_CHANNEL_SELECT_t channel){
    STD_ReturnType ret = E_OK;
    if(NULL == adc){
        ret = E_NOK;
    }
    else{
        ADCON0bits.CHS = channel;
        ADC_INPUT_CHANNEL_PIN_CONFIG(channel);
    }
    return ret;
}
STD_ReturnType ADC_START_CONVERSION(const ADC_CONFIG_t *adc){
    STD_ReturnType ret = E_OK;
    if(NULL == adc){
        ret = E_NOK;
    }
    else{
        ADC_CONVERSION_START();
    }
    return ret;
}
STD_ReturnType ADC_CONVERSION_STATUS_(const ADC_CONFIG_t *adc, uint8 *conversion_status){
    STD_ReturnType ret = E_OK;
    if((NULL == adc) || (NULL == conversion_status)){
        ret = E_NOK;
    }
    else{
        *conversion_status = (uint8)(!ADC_CONVERSION_STATUS()); //1 if complete
    }
    return ret;
}
STD_ReturnType ADC_CONVERSION_RESULT(const ADC_CONFIG_t *adc, uint16 *conversion_result){
    STD_ReturnType ret = E_OK;
    if((NULL == adc) || (NULL == conversion_result)){
        ret = E_NOK;
    }
    else{
        if(ADC_RESULT_RIGHT == adc->result_format){
            *conversion_result = (uint16)((ADRESH << 8) + ADRESL);
        }
        else if(ADC_RESULT_LEFT == adc->result_format){
            *conversion_result = (uint16)(((ADRESH << 8) + ADRESL) >> 6);
        }
        else{}
    }
    return ret;
}
STD_ReturnType ADC_CONVERSION(const ADC_CONFIG_t *adc, uint16 *conversion_result, ADC_CHANNEL_SELECT_t channel){
    STD_ReturnType ret = E_OK;
    if((NULL == adc) || (NULL == conversion_result)){
        ret = E_NOK;
    }
    else{
        ret = ADC_SELECT_CHANNEL(adc, channel);
        ret |= ADC_START_CONVERSION(adc);
        while(ADC_CONVERSION_STATUS());
        ret |= ADC_CONVERSION_RESULT(adc, conversion_result);

    }
    return ret;
}

STD_ReturnType ADC_CONVERSION_INTERRUPT(const ADC_CONFIG_t *adc, ADC_CHANNEL_SELECT_t channel){
    STD_ReturnType ret = E_OK;
    if(NULL == adc){
        ret = E_NOK;
    }
    else{
        ret = ADC_SELECT_CHANNEL(adc, channel);
        ret |= ADC_START_CONVERSION(adc);
    }
    return ret;
}

static inline void ADC_INPUT_CHANNEL_PIN_CONFIG(ADC_CHANNEL_SELECT_t channel){
    switch(channel){
        case(channel_1): SET_BIT(TRISA, _TRISA_RA0_POSN); break;
        case(channel_2): SET_BIT(TRISA, _TRISA_RA1_POSN); break;
        case(channel_3): SET_BIT(TRISA, _TRISA_RA2_POSN); break;
        case(channel_4): SET_BIT(TRISA, _TRISA_RA3_POSN); break;
        case(channel_5): SET_BIT(TRISA, _TRISA_RA5_POSN); break;
        case(channel_6): SET_BIT(TRISE, _TRISE_RE0_POSN); break;
        case(channel_7): SET_BIT(TRISE, _TRISE_RE1_POSN); break;
        case(channel_8): SET_BIT(TRISE, _TRISE_RE2_POSN); break;
        case(channel_9): SET_BIT(TRISB, _TRISB_RB0_POSN); break;
        case(channel_10): SET_BIT(TRISB, _TRISB_RB1_POSN); break;
        case(channel_11): SET_BIT(TRISB, _TRISB_RB2_POSN); break;
        case(channel_12): SET_BIT(TRISB, _TRISB_RB3_POSN); break;
        case(channel_13): SET_BIT(TRISB, _TRISB_RB4_POSN); break;
        default: break;
    }
}

static inline void ADC_SELECT_RESULT_FORMAT(const ADC_CONFIG_t *adc){
    if(ADC_RESULT_RIGHT == adc->result_format){
        ADC_RIGHT_FORMAT();
    }
    else if(ADC_RESULT_LEFT == adc->result_format){
        ADC_LEFT_FORMAT();
    }
    else{}
}

static inline void ADC_SELECT_VOLTAGE_REFERENCE(const ADC_CONFIG_t *adc){
    if(ADC_VOLTAGE_REFERENCE_ENABLE == adc->voltage_reference){
        ADC_ENABLE_VOLTAGE_REFERENCE();
    }
    else if(ADC_VOLTAGE_REFERENCE_DISABLE == adc->voltage_reference){
        ADC_DISABLE_VOLTAGE_REFERENCE();
    }
    else{}
}