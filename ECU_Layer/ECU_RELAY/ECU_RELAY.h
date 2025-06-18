/* 
 * File:   ECU_RELAY.h
 * Author: Eng.Yassmin
 *
 * Created on October 15, 2024, 1:19 PM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H
/* Includes Section */
#include "ECU_RELAY_CFG.h"
#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"
/* Macro Declaration Section */
#define RELAY_ON_STATUS      0x01
#define RELAY_OFF_STATUS     0x00
/* Macro Function Declaration Section */

/* Data Type Section */
typedef struct{
    uint8 relay_port    :4;
    uint8 relay_pin     :3;
    uint8 relay_status  :1; 
}relay_t;
/* Function Declaration Section */
STD_ReturnType Relay_Init(const relay_t *relay);
STD_ReturnType Relay_ON(const relay_t *relay);
STD_ReturnType Relay_OFF(const relay_t *relay);

#endif	/* ECU_RELAY_H */

