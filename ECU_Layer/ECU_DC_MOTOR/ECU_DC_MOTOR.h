/*
 * File:   ECU_DC_MOTOR.h
 * Author: Eng.Yassmin
 *
 * Created on October 16, 2024, 3:11 PM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H
/* Includes Section */
#include "ECU_DC_MOTOR_CFG.h"
#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"
/* Macro Declaration Section */
#define DC_MOTOR_ON_STATUS      0x01
#define DC_MOTOR_OFF_STATUS     0x00
#define DC_MOTOR_PIN_1          0x00
#define DC_MOTOR_PIN_2          0x01
/* Macro Function Declaration Section */

/* Data Type Section */
typedef struct {
pin_config_t dc_motor[2];
}dc_motor_t;
/* Function Declaration Section */
STD_ReturnType Motor_Init(const dc_motor_t *dc_motor);
STD_ReturnType Motor_Forward(const dc_motor_t *dc_motor);
STD_ReturnType Motor_Backward(const dc_motor_t *dc_motor);
STD_ReturnType Motor_Stop(const dc_motor_t *dc_motor);
#endif	/* ECU_DC_MOTOR_H */

