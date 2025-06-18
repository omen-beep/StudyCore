/* 
 * File:   MCAL_Interrupt_Manager.h
 * Author: Eng.Yassmin
 *
 * Created on October 31, 2024, 1:33 PM
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H
/* Includes Section */
#include "MCAL_Interrupt_CFG.h"
/* Macro Declaration Section */

/* Macro Function Declaration Section */

/* Data Type Section */

/* Function Declaration Section */
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);
void RB4_ISR(uint8 RB4_SRC);
void RB5_ISR(uint8 RB5_SRC);
void RB6_ISR(uint8 RB6_SRC);
void RB7_ISR(uint8 RB7_SRC);
void ADC_ISR(void);
void TMR0_ISR(void);
void TMR1_ISR(void);
void TMR2_ISR(void);
void TMR3_ISR(void);
void CCP1_ISR(void);
void CCP2_ISR(void);
void USART_TX_ISR(void);
void USART_RX_ISR(void);
void I2C_ISR(void);
void I2C_BUS_ISR(void);
#endif	/* MCAL_INTERRUPT_MANAGER_H */

