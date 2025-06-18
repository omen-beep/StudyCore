#include "MCAL_USART.h"


#if USART_TX_INTERRUPT_FEATURE_ENABLE
static void (*USART_TX_InterruptHandler)(void) = NULL;
void USART_TX_ISR(void){
    USART_TX_Interrupt_Disable();
    if(USART_TX_InterruptHandler){
        USART_TX_InterruptHandler();
    }
}
#endif

#if USART_RX_INTERRUPT_FEATURE_ENABLE
static void (*USART_RX_InterruptHandler)(void) = NULL;
static void (*USART_FRROR_InterruptHandler)(void) = NULL;
static void (*USART_ORROR_InterruptHandler)(void) = NULL;
void USART_RX_ISR(void){
    if(USART_RX_InterruptHandler){
        USART_RX_InterruptHandler();
    }
    else{}
    if(USART_ORROR_InterruptHandler){
        USART_ORROR_InterruptHandler();
    }
    else{}
    if(USART_FRROR_InterruptHandler){
        USART_FRROR_InterruptHandler();
    }
    else{}
}
#endif


static void USART_Baud_Rate_Calculation(const USART_t *usart);
static void USART_TX_INIT(const USART_t *usart);
static void USART_RX_INIT(const USART_t *usart);

STD_ReturnType USART_ASYNC_INIT(const USART_t *usart){
     STD_ReturnType ret = E_OK;
    if(NULL == usart){
        ret = E_NOK;
    }
    else{
        RCSTAbits.SPEN = USART_DISABLE;
        TRISCbits.RC7 = 1;
        TRISCbits.RC6 = 1;
        USART_Baud_Rate_Calculation(usart);
        USART_TX_INIT(usart);
        USART_RX_INIT(usart);
        RCSTAbits.SPEN = USART_ENABLE;
    }
    return ret;
}
STD_ReturnType USART_ASYNC_DEINIT(const USART_t *usart){
     STD_ReturnType ret = E_OK;
    if(NULL == usart){
        ret = E_NOK;
    }
    else{
        RCSTAbits.SPEN = USART_DISABLE;
    }
    return ret;
}
STD_ReturnType USART_ASYNC_ReadByte_Blocking(const USART_t *usart, uint8 *data){
     STD_ReturnType ret = E_OK;
    if(NULL == usart){
        ret = E_NOK;
    }
    else{
        while(!PIR1bits.RC1IF){}
        *data = RCREG;
    }
    return ret;
}
STD_ReturnType USART_ASYNC_ReadByte(const USART_t *usart, uint8 *data){
     STD_ReturnType ret = E_OK;
    if(NULL == usart){
        ret = E_NOK;
    }
    else{
        if(1 == PIR1bits.RC1IF){
        *data = RCREG;
        }
        else{ret = E_NOK;
        }
    }
    return ret;
}
STD_ReturnType USART_ASYNC_RX_Restart(void){
     STD_ReturnType ret = E_OK;
     RCSTAbits.CREN = 0;
     RCSTAbits.CREN = 1;
    return ret;
}
STD_ReturnType USART_ASYNC_WriteByte_Blocking(const USART_t *usart, uint8 data){
     STD_ReturnType ret = E_OK;
    if(NULL == usart){
        ret = E_NOK;
    }
    else{
        while(!TXSTAbits.TRMT){}
#if USART_TX_INTERRUPT_FEATURE_ENABLE
        USART_TX_Interrupt_Enable();
#endif
        TXREG = data;
    }
    return ret;
}
STD_ReturnType USART_ASYNC_WriteString_Blocking(const USART_t *usart, uint8 *data, uint16 str_len){
     STD_ReturnType ret = E_OK;
    if((NULL == usart) || (NULL == data)){
        ret = E_NOK;
    }
    else{
        for(uint16 i = 0; i < str_len; i++){
            ret = USART_ASYNC_WriteByte_Blocking(usart, data[i]);
        }
    }
    return ret;
}
STD_ReturnType USART_ASYNC_WriteByte(const USART_t *usart, uint8 data){
     STD_ReturnType ret = E_OK;
    if(NULL == usart){
        ret = E_NOK;
    }
    else{
        if(1 == TXSTAbits.TRMT){
#if USART_TX_INTERRUPT_FEATURE_ENABLE
        USART_TX_Interrupt_Enable();
#endif
        TXREG = data;
        }
    }
    return ret;
}
STD_ReturnType USART_ASYNC_WriteString(const USART_t *usart, uint8 *data, uint16 str_len){
     STD_ReturnType ret = E_OK;
    if((NULL == usart) || (NULL == data)){
        ret = E_NOK;
    }
    else{
        for(uint16 i = 0; i < str_len; i++){
            ret = USART_ASYNC_WriteByte(usart, data[i]);
        }
    }
    return ret;
}

static void USART_Baud_Rate_Calculation(const USART_t *usart){
     float Baud_Rate_Temp = 0;
        switch(usart->baud_rate_cfg){
            case(BAUDRATE_ASYN_8BIT_LOW_SPEED):
                TXSTAbits.BRGH = USART_ASYNC_LOW_SPEED;
                TXSTAbits.SYNC = USART_ASYNC_MODE;
                BAUDCONbits.BRG16 = USART_8BIT_BAURDRATE_GEN;
                Baud_Rate_Temp = ((_XTAL_FREQ/(float)usart->baud_rate_value)/64) - 1;
                break;
            case(BAUDRATE_ASYN_8BIT_HIGH_SPEED):
                TXSTAbits.BRGH = USART_ASYNC_HIGH_SPEED;
                TXSTAbits.SYNC = USART_ASYNC_MODE;
                BAUDCONbits.BRG16 = USART_8BIT_BAURDRATE_GEN;
                Baud_Rate_Temp = ((_XTAL_FREQ/(float)usart->baud_rate_value)/16) - 1;
                break;
            case(BAUDRATE_ASYN_16BIT_LOW_SPEED):
                TXSTAbits.BRGH = USART_ASYNC_LOW_SPEED;
                TXSTAbits.SYNC = USART_ASYNC_MODE;
                BAUDCONbits.BRG16 = USART_16BIT_BAURDRATE_GEN;
                Baud_Rate_Temp = ((_XTAL_FREQ/(float)usart->baud_rate_value)/16) - 1;
                break;
            case(BAUDRATE_ASYN_16BIT_HIGH_SPEED):
                TXSTAbits.BRGH = USART_ASYNC_HIGH_SPEED;
                TXSTAbits.SYNC = USART_ASYNC_MODE;
                BAUDCONbits.BRG16 = USART_16BIT_BAURDRATE_GEN;
                Baud_Rate_Temp = ((_XTAL_FREQ/(float)usart->baud_rate_value)/4) - 1;
                break;
            case(BAUDRATE_SYNC_8BIT):
                TXSTAbits.SYNC = USART_SYNC_MODE;
                BAUDCONbits.BRG16 = USART_8BIT_BAURDRATE_GEN;
                Baud_Rate_Temp = ((_XTAL_FREQ/(float)usart->baud_rate_value)/4) - 1;
                break;
            case(BAUDRATE_SYNC_16BIT):
                TXSTAbits.SYNC = USART_SYNC_MODE;
                BAUDCONbits.BRG16 = USART_16BIT_BAURDRATE_GEN;
                Baud_Rate_Temp = ((_XTAL_FREQ/(float)usart->baud_rate_value)/4) - 1;
                break;
            default:
                
                break;
        }
     SPBRG = (uint8)((uint32)Baud_Rate_Temp);
     SPBRGH = (uint8)(((uint32)Baud_Rate_Temp) >> 8);
}

static void USART_TX_INIT(const USART_t *usart){
    if(USART_ASYNC_TX_ENABLE == usart->tx_cfg.USART_TX_ENABLE){
        TXSTAbits.TXEN = USART_ASYNC_TX_ENABLE;
    if(USART_ASYNC_INTERRUPT_TX_ENABLE == usart->tx_cfg.USART_INTERRUPT_TX_ENABLE){
        PIE1bits.TXIE = USART_ASYNC_INTERRUPT_TX_ENABLE;
        
        #if USART_TX_INTERRUPT_FEATURE_ENABLE
        USART_TX_Interrupt_Enable();
        USART_TX_InterruptHandler = usart->TX_InterruptHandler;
        #if INTERRUPT_PRIO_LEVEL_ENABLE
        INTERRUPT_PriorityEnable();
        if(INTERRUPT_PRIO_HIGH == usart->Priority_TX){
            INTERRUPT_GlobalInterruptHighEnable();
            USART_TX_INTERRUPT_HIGH_PRIO();
        }
        else if(INTERRUPT_PRIO_LOW == usart->Priority_TX){
            INTERRUPT_GlobalInterruptLowEnable();
            USART_TX_INTERRUPT_LOW_PRIO();
        }
        else{}
        #else
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralEnable();
        #endif
        #endif

    }
    else if(USART_ASYNC_INTERRUPT_TX_DISABLE == usart->tx_cfg.USART_INTERRUPT_TX_ENABLE){
        PIE1bits.TXIE = USART_ASYNC_INTERRUPT_TX_DISABLE;
        USART_TX_Interrupt_Disable();
    }
    else{}
    
    if(USART_ASYNC_9BIT_TX_ENABLE == usart->tx_cfg.USART_9BIT_TX_ENABLE){
        TXSTAbits.TX9 = USART_ASYNC_9BIT_TX_ENABLE;
    }
    else if(USART_ASYNC_9BIT_TX_DISABLE == usart->tx_cfg.USART_9BIT_TX_ENABLE){
        TXSTAbits.TX9 = USART_ASYNC_9BIT_TX_DISABLE;
    }
    else{}
    }
    else{}
}

static void USART_RX_INIT(const USART_t *usart){
    if(USART_ASYNC_RX_ENABLE == usart->rx_cfg.USART_RX_ENABLE){
        RCSTAbits.CREN = USART_ASYNC_RX_ENABLE;
    if(USART_ASYNC_INTERRUPT_RX_ENABLE == usart->rx_cfg.USART_INTERRUPT_RX_ENABLE){
       PIE1bits.RCIE = USART_ASYNC_INTERRUPT_RX_ENABLE;
       
       #if USART_RX_INTERRUPT_FEATURE_ENABLE
        USART_RX_Interrupt_Enable();
        USART_RX_InterruptHandler = usart->RX_InterruptHandler;
        USART_FRROR_InterruptHandler = usart->FERR_InterruptHandler;
        USART_ORROR_InterruptHandler = usart->OERR_InterruptHandler;
        #if INTERRUPT_PRIO_LEVEL_ENABLE
        INTERRUPT_PriorityEnable();
        if(INTERRUPT_PRIO_HIGH == usart->Priority_RX){
            INTERRUPT_GlobalInterruptHighEnable();
            USART_RX_INTERRUPT_HIGH_PRIO();
        }
        else if(INTERRUPT_PRIO_LOW == usart->Priority_RX){
            INTERRUPT_GlobalInterruptLowEnable();
            USART_RX_INTERRUPT_LOW_PRIO();
        }
        else{}
        #else
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralEnable();
        #endif
        #endif

    }
    else if(USART_ASYNC_INTERRUPT_RX_DISABLE == usart->rx_cfg.USART_INTERRUPT_RX_ENABLE){
       PIE1bits.RCIE = USART_ASYNC_INTERRUPT_RX_DISABLE;
       USART_RX_Interrupt_Disable();
    }
    else{}
    
    if(USART_ASYNC_9BIT_RX_ENABLE == usart->rx_cfg.USART_9BIT_RX_ENABLE){
        RCSTAbits.RX9 = USART_ASYNC_9BIT_RX_ENABLE;
    }
    else if(USART_ASYNC_9BIT_RX_DISABLE == usart->rx_cfg.USART_9BIT_RX_ENABLE){
        RCSTAbits.RX9 = USART_ASYNC_9BIT_RX_DISABLE;
    }
    else{}
    }
    else{}
}