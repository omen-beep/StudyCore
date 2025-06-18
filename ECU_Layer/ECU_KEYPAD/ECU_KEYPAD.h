/* 
 * File:   ECU_KEYPAD.h
 * Author: Eng.Yassmin
 *
 * Created on October 21, 2024, 1:14 PM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H
/* Includes Section */
#include "ECU_KEYPAD_CFG.h"
#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"
/* Macro Declaration Section */
#define KEYPAD_ROW_PINS    4
#define KEYPAD_COL_PINS    4
/* Macro Function Declaration Section */

/* Data Type Section */
typedef struct {
    pin_config_t KEYPAD_ROW[KEYPAD_ROW_PINS];
    pin_config_t KEYPAD_COL[KEYPAD_COL_PINS];
}keypad_t;
/* Function Declaration Section */
STD_ReturnType Keypad_Init(const keypad_t *keypad);
STD_ReturnType Keypad_Get_Value(const keypad_t *keypad, uint8 *value);
#endif	/* ECU_KEYPAD_H */

