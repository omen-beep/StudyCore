#include "MCAL_Interrupt_Manager.h"

static volatile uint8 RB4_Flag = 1;
static volatile uint8 RB5_Flag = 1;
static volatile uint8 RB6_Flag = 1;
static volatile uint8 RB7_Flag = 1;

#if INTERRUPT_PRIO_LEVEL_ENABLE==INTERRUPT_FEATURE_ENABLE
void __interrupt() InterruptManagerHigh(void){
    if((INTERRUPT_ENABLE == INTCONbits.INT0IE) && (INTERRUPT_OCCUR == INTCONbits.INT0IF)){
        INT0_ISR();
    }
    else{}
    if((INTERRUPT_ENABLE == INTCON3bits.INT2IE) && (INTERRUPT_OCCUR == INTCON3bits.INT2IF)){
        INT2_ISR();
    }
    else{}
}

void __interrupt(low_priority) InterruptManagerLow(void){
    if((INTERRUPT_ENABLE == INTCON3bits.INT1IE) && (INTERRUPT_OCCUR == INTCON3bits.INT1IF)){
        INT1_ISR();
    }
    else{}
}

#else
void __interrupt() InterruptManagerLow(void){
    if((INTERRUPT_ENABLE == PIE1bits.SSPIE) && (INTERRUPT_OCCUR == PIR1bits.SSPIF)){
        I2C_ISR();
    }
    else{}
    if((INTERRUPT_ENABLE == PIE2bits.BCLIE) && (INTERRUPT_OCCUR == PIR2bits.BCLIF)){
        I2C_BUS_ISR();
    }
    else{}
    if((INTERRUPT_ENABLE == PIE1bits.RCIE) && (INTERRUPT_OCCUR == PIR1bits.RCIF)){
        USART_RX_ISR();
    }
    else{}
    if((INTERRUPT_ENABLE == PIE1bits.TXIE) && (INTERRUPT_OCCUR == PIR1bits.TXIF)){
        USART_TX_ISR();
    }
    else{}
    if((INTERRUPT_ENABLE == PIE2bits.CCP2IE) && (INTERRUPT_OCCUR == PIR2bits.CCP2IF)){
        CCP2_ISR();
    }
    else{}
    if((INTERRUPT_ENABLE == PIE1bits.CCP1IE) && (INTERRUPT_OCCUR == PIR1bits.CCP1IF)){
        CCP1_ISR();
    }
    else{}
    if((INTERRUPT_ENABLE == PIE1bits.TMR2IE) && (INTERRUPT_OCCUR == PIR1bits.TMR2IF)){
        TMR2_ISR();
    }
    else{}
    if((INTERRUPT_ENABLE == PIE2bits.TMR3IE) && (INTERRUPT_OCCUR == PIR2bits.TMR3IF)){
        TMR3_ISR();
    }
    else{}
    if((INTERRUPT_ENABLE == PIE1bits.TMR1IE) && (INTERRUPT_OCCUR == PIR1bits.TMR1IF)){
        TMR1_ISR();
    }
    else{}
    if((INTERRUPT_ENABLE == INTCONbits.TMR0IE) && (INTERRUPT_OCCUR == INTCONbits.TMR0IF)){
        TMR0_ISR();
    }
    else{}
    if((INTERRUPT_ENABLE == PIE1bits.ADIE) && (INTERRUPT_OCCUR == PIR1bits.ADIF)){
        ADC_ISR();
    }
    else{}
    if((INTERRUPT_ENABLE == INTCONbits.INT0IE) && (INTERRUPT_OCCUR == INTCONbits.INT0IF)){
        INT0_ISR();
    }
    else{}
    if((INTERRUPT_ENABLE == INTCON3bits.INT1IE) && (INTERRUPT_OCCUR == INTCON3bits.INT1IF)){
        INT1_ISR();
    }
    else{}
    if((INTERRUPT_ENABLE == INTCON3bits.INT2IE) && (INTERRUPT_OCCUR == INTCON3bits.INT2IF)){
        INT2_ISR();
    }
    else{}
    
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB4 == HIGH) && (1 == RB4_Flag)){
        RB4_Flag = 0;
        RB4_ISR(1);
    }
    else{}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB4 == LOW) && (0 == RB4_Flag)){
        RB4_Flag = 1;
        RB4_ISR(0);
    }
    else{}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB5 == HIGH) && (1 == RB5_Flag)){
        RB5_Flag = 0;
        RB5_ISR(1);
    }
    else{}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB5 == LOW) && (0 == RB5_Flag)){
        RB5_Flag = 1;
        RB5_ISR(0);
    }
    else{}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB6 == HIGH) && (1 == RB6_Flag)){
        RB6_Flag = 0;
        RB6_ISR(1);
    }
    else{}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB6 == LOW) && (0 == RB6_Flag)){
        RB6_Flag = 1;
        RB6_ISR(0);
    }
    else{}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB7 == HIGH) && (1 == RB7_Flag)){
        RB7_Flag = 0;
        RB7_ISR(1);
    }
    else{}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && (PORTBbits.RB7 == LOW) && (0 == RB7_Flag)){
        RB7_Flag = 1;
        RB7_ISR(0);
    }
    else{}
}
#endif
