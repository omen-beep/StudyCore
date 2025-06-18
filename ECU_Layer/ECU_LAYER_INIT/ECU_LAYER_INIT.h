/* 
 * File:   ECU_LAYER_INIT.h
 * Author: Eng.Yassmin
 *
 * Created on October 21, 2024, 1:48 PM
 */

#ifndef ECU_LAYER_INIT_H
#define	ECU_LAYER_INIT_H
/* Includes Section */
#include "../../ECU_Layer/ECU_LED/ECU_LED.h"
#include "../ECU_BUTTON/ECU_BUTTON.h"
#include "../ECU_RELAY/ECU_RELAY.h"
#include "../ECU_DC_MOTOR/ECU_DC_MOTOR.h"
#include "../ECU_7SEG/ECU_7SEG.h"
#include "../ECU_KEYPAD/ECU_KEYPAD.h"
#include "../ECU_LCD/ECU_LCD.h"
#include "../../MCAL_Layer/MCAL_EEPROM/MCAL_EEPROM.h"
#include "../../MCAL_Layer/MCAL_Interrupts/MCAL_External_Interrupt.h"
#include "../../MCAL_Layer/MCAL_ADC/MCAL_ADC.h"
#include "../../MCAL_Layer/MCAL_TIMER/MCAL_TIMER.h"
#include "../../MCAL_Layer/TIMER1/TIMER1.h"
#include "../../MCAL_Layer/MCAL_TIMER2/MCAL_TIMER2.h"
#include "../../MCAL_Layer/MCAL_TIMER3/MCAL_TIMER3.h"
#include "../../MCAL_Layer/MCAL_CCP1/MCAL_CCP1.h"
#include "../../MCAL_Layer/MCAL_USART/MCAL_USART.h"
#include "../../MCAL_Layer/MCAL_I2C/MCAL_I2C.h"
/* Macro Declaration Section */

/* Macro Function Declaration Section */

/* Data Type Section */

/* Function Declaration Section */
void ECU_Layer_Init(void);
#endif	/* ECU_LAYER_INIT_H */

