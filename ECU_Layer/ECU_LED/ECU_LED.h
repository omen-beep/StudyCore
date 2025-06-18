/* 
 * File:   ECU_LED.h
 * Author: Eng.Yasmine
 *
 * Created on September 29, 2024, 1:00 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

/* Includes Section */
#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"
#include "ECU_LED_CFG.h"
/* Macro Declaration Section */

/* Macro Function Declaration Section */

/* Data Type Section */
typedef enum{
    LED_OFF,
    LED_ON
}led_status_t;

typedef struct{
    uint8 port_name  : 4;
    uint8 pin        : 3;
    uint8 led_status : 1;
}led_t;

/* Function Declaration Section */

STD_ReturnType LED_init(const led_t *led);
STD_ReturnType LED_TURN_ON(const led_t *led);
STD_ReturnType LED_TURN_OFF(const led_t *led);
STD_ReturnType LED_TURN_TOGGLE(const led_t *led);


#endif	/* ECU_LED_H */

