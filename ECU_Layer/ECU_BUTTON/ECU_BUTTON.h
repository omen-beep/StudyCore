/* 
 * File:   ECU_BUTTON.h
 * Author: Eng.Yassmin
 *
 * Created on October 14, 2024, 2:14 PM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H
/* Includes Section */
#include "ECU_BUTTON_CFG.h"
#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"
/* Macro Declaration Section */

/* Macro Function Declaration Section */

/* Data Type Section */
typedef enum{
    BUTTON_PRESSED = 0,
    BUTTON_RELEASED
}button_state_t;

typedef enum{
    BUTTON_ACTIVE_HIGH = 0,
    BUTTON_ACTIVE_LOW
}button_connection_t;

typedef struct{
pin_config_t button;
button_state_t button_state;
button_connection_t button_connection;
}button_init_t;

/* Function Declaration Section */
STD_ReturnType Button_Init(const button_init_t *Button);
STD_ReturnType Button_Read(const button_init_t *Button, button_state_t *Button_State);

#endif	/* ECU_BUTTON_H */

