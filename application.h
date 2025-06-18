/* 
 * File:   application.h
 * Author: Eng.Yassmin
 *
 * Created on September 29, 2024, 1:41 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H
/* Includes Section */
#include "ECU_Layer/ECU_LAYER_INIT/ECU_LAYER_INIT.h"
/* Macro Declaration Section */

/* Macro Function Declaration Section */

/* Data Type Section */
extern keypad_t keypad_1;
extern LCD_4bit_t LCD_4bit;
extern LCD_8bit_t LCD_8bit;
/* Function Declaration Section */
void application_init(void);
#define _XTAL_FREQ 8000000

#endif	/* APPLICATION_H */

