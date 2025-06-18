/* 
 * File:   MCAL_Internal_Interrupt.h
 * Author: Eng.Yassmin
 *
 * Created on October 31, 2024, 1:32 PM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H
/* Includes Section */
#include "MCAL_Interrupt_CFG.h"
/* Macro Declaration Section */

/* Macro Function Declaration Section */
#if ADC_INTERRUPT_FEATURE_ENABLE
/* Enables ADC Interrupt */
#define ADC_Interrupt_Enable()          (PIE1bits.ADIE = 1)
/* Disables ADC Interrupt */
#define ADC_Interrupt_Disable()         (PIE1bits.ADIE = 0)
/* Clears ADC Interrupt Flag */
#define ADC_Interrupt_Flag_Clear()      (PIR1bits.ADIF = 0)

#if INTERRUPT_PRIO_LEVEL_ENABLE
/* Sets ADC to High Priority */
#define ADC_INTERRUPT_HIGH_PRIO()         (IPR1bits.ADIP = 1)
/* Sets ADC to Low Priority */
#define ADC_INTERRUPT_LOW_PRIO()          (IPR1bits.ADIP = 0)
#endif
#endif

#if TIMER0_INTERRUPT_FEATURE_ENABLE
/* Enables TIMER0 Interrupt */
#define TIMER0_Interrupt_Enable()          (INTCONbits.TMR0IE = 1)
/* Disables TIMER0 Interrupt */
#define TIMER0_Interrupt_Disable()         (INTCONbits.TMR0IE = 0)
/* Clears TIMER0 Interrupt Flag */
#define TIMER0_Interrupt_Flag_Clear()      (INTCONbits.TMR0IF = 0)

#if INTERRUPT_PRIO_LEVEL_ENABLE
/* Sets TIMER0 to High Priority */
#define TIMER0_INTERRUPT_HIGH_PRIO()         (INTCON2bits.TMR0IP = 1)
/* Sets TIMER0 to Low Priority */
#define TIMER0_INTERRUPT_LOW_PRIO()          (INTCON2bits.TMR0IP = 0)
#endif
#endif

#if TIMER1_INTERRUPT_FEATURE_ENABLE
/* Enables TIMER1 Interrupt */
#define TIMER1_Interrupt_Enable()          (PIE1bits.TMR1IE = 1)
/* Disables TIMER1 Interrupt */
#define TIMER1_Interrupt_Disable()         (PIE1bits.TMR1IE = 0)
/* Clears TIMER1 Interrupt Flag */
#define TIMER1_Interrupt_Flag_Clear()      (PIR1bits.TMR1IF = 0)

#if INTERRUPT_PRIO_LEVEL_ENABLE
/* Sets TIMER1 to High Priority */
#define TIMER1_INTERRUPT_HIGH_PRIO()         (IPR1bits.TMR1IP = 1)
/* Sets TIMER1 to Low Priority */
#define TIMER1_INTERRUPT_LOW_PRIO()          (IPR1bits.TMR1IP = 0)
#endif
#endif

#if TIMER2_INTERRUPT_FEATURE_ENABLE
/* Enables TIMER2 Interrupt */
#define TIMER2_Interrupt_Enable()          (PIE1bits.TMR2IE = 1)
/* Disables TIMER2 Interrupt */
#define TIMER2_Interrupt_Disable()         (PIE1bits.TMR2IE = 0)
/* Clears TIMER2 Interrupt Flag */
#define TIMER2_Interrupt_Flag_Clear()      (PIR1bits.TMR2IF = 0)

#if INTERRUPT_PRIO_LEVEL_ENABLE
/* Sets TIMER2 to High Priority */
#define TIMER2_INTERRUPT_HIGH_PRIO()         (IPR1bits.TMR2IP = 1)
/* Sets TIMER2 to Low Priority */
#define TIMER2_INTERRUPT_LOW_PRIO()          (IPR1bits.TMR2IP = 0)
#endif
#endif

#if TIMER3_INTERRUPT_FEATURE_ENABLE
/* Enables TIMER3 Interrupt */
#define TIMER3_Interrupt_Enable()          (PIE2bits.TMR3IE = 1)
/* Disables TIMER3 Interrupt */
#define TIMER3_Interrupt_Disable()         (PIE2bits.TMR3IE = 0)
/* Clears TIMER3 Interrupt Flag */
#define TIMER3_Interrupt_Flag_Clear()      (PIR2bits.TMR3IF = 0)

#if INTERRUPT_PRIO_LEVEL_ENABLE
/* Sets TIMER3 to High Priority */
#define TIMER3_INTERRUPT_HIGH_PRIO()         (IPR2bits.TMR3IP = 1)
/* Sets TIMER3 to Low Priority */
#define TIMER3_INTERRUPT_LOW_PRIO()          (IPR2bits.TMR3IP = 0)
#endif
#endif

#if CCP1_INTERRUPT_FEATURE_ENABLE
/* Enables CCP1 Interrupt */
#define CCP1_Interrupt_Enable()          (PIE1bits.CCP1IE = 1)
/* Disables CCP1 Interrupt */
#define CCP1_Interrupt_Disable()         (PIE1bits.CCP1IE = 0)
/* Clears CCP1 Interrupt Flag */
#define CCP1_Interrupt_Flag_Clear()      (PIR1bits.CCP1IF = 0)

#if INTERRUPT_PRIO_LEVEL_ENABLE
/* Sets CCP1 to High Priority */
#define CCP1_INTERRUPT_HIGH_PRIO()         (IPR1bits.CCP1IP = 1)
/* Sets CCP1 to Low Priority */
#define CCP1_INTERRUPT_LOW_PRIO()          (IPR1bits.CCP1IP = 0)
#endif
#endif

#if CCP2_INTERRUPT_FEATURE_ENABLE
/* Enables CCP2 Interrupt */
#define CCP2_Interrupt_Enable()          (PIE2bits.CCP2IE = 1)
/* Disables CCP2 Interrupt */
#define CCP2_Interrupt_Disable()         (PIE2bits.CCP2IE = 0)
/* Clears CCP2 Interrupt Flag */
#define CCP2_Interrupt_Flag_Clear()      (PIR2bits.CCP2IF = 0)

#if INTERRUPT_PRIO_LEVEL_ENABLE
/* Sets CCP2 to High Priority */
#define CCP2_INTERRUPT_HIGH_PRIO()         (IPR2bits.CCP2IP = 1)
/* Sets CCP2 to Low Priority */
#define CCP2_INTERRUPT_LOW_PRIO()          (IPR2bits.CCP2IP = 0)
#endif
#endif

#if USART_TX_INTERRUPT_FEATURE_ENABLE
/* Enables TX Interrupt */
#define USART_TX_Interrupt_Enable()          (PIE1bits.TXIE = 1)
/* Disables TX Interrupt */
#define USART_TX_Interrupt_Disable()         (PIE1bits.TXIE = 0)

#if INTERRUPT_PRIO_LEVEL_ENABLE
/* Sets TX to High Priority */
#define USART_TX_INTERRUPT_HIGH_PRIO()         (IPR1bits.TXIP = 1)
/* Sets TX to Low Priority */
#define USART_TX_INTERRUPT_LOW_PRIO()          (IPR1bits.TXIP = 0)
#endif
#endif

#if USART_RX_INTERRUPT_FEATURE_ENABLE
/* Enables RX Interrupt */
#define USART_RX_Interrupt_Enable()          (PIE1bits.RCIE = 1)
/* Disables RX Interrupt */
#define USART_RX_Interrupt_Disable()         (PIE1bits.RCIE = 0)

#if INTERRUPT_PRIO_LEVEL_ENABLE
/* Sets RX to High Priority */
#define USART_RX_INTERRUPT_HIGH_PRIO()         (IPR1bits.RCIP = 1)
/* Sets RX to Low Priority */
#define USART_RX_INTERRUPT_LOW_PRIO()          (IPR1bits.RCIP = 0)
#endif
#endif

#if I2C_INTERRUPT_FEATURE_ENABLE
/* Enables I2C Interrupt */
#define I2C_Interrupt_Enable()                  (PIE1bits.SSPIE = 1)
#define I2C_BUS_Col_Interrupt_Enable()          (PIE2bits.BCLIE = 1)
/* Disables I2C Interrupt */
#define I2C_Interrupt_Disable()                 (PIE1bits.SSPIE = 0)
#define I2C_BUS_Col_Interrupt_Disable()         (PIE2bits.BCLIE = 0)
/* Clears I2C Interrupt Flag */
#define I2C_Interrupt_Flag_Clear()              (PIR1bits.SSPIF = 0)
#define I2C_BUS_Col_Interrupt_Flag_Clear()      (PIR2bits.BCLIF = 0)

#if INTERRUPT_PRIO_LEVEL_ENABLE
/* Sets I2C to High Priority */
#define I2C_INTERRUPT_HIGH_PRIO()                 (IPR1bits.SSPIP = 1)
#define I2C_BUS_Col_INTERRUPT_HIGH_PRIO()         (IPR2bits.BCLIP = 1)
/* Sets I2C to Low Priority */
#define I2C_INTERRUPT_LOW_PRIO()                  (IPR1bits.SSPIP = 0)
#define I2C_BUS_Col_INTERRUPT_LOW_PRIO()          (IPR2bits.BCLIP = 0)
#endif
#endif
/* Data Type Section */

/* Function Declaration Section */
#endif	/* MCAL_INTERNAL_INTERRUPT_H */

