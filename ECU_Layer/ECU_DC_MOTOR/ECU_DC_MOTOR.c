#include "ECU_DC_MOTOR.h"

STD_ReturnType Motor_Init(const dc_motor_t *dc_motor){
    STD_ReturnType ret = E_OK;
    if(NULL == dc_motor){
        ret = E_NOK;
    }
    else{
     ret = gpio_pin_init(&(dc_motor->dc_motor[DC_MOTOR_PIN_1]));
     ret = gpio_pin_init(&(dc_motor->dc_motor[DC_MOTOR_PIN_2]));
    }
    return ret;
}

STD_ReturnType Motor_Forward(const dc_motor_t *dc_motor){
    STD_ReturnType ret = E_OK;
    if(NULL == dc_motor){
        ret = E_NOK;
    }
    else{
     ret = gpio_pin_write_logic(&(dc_motor->dc_motor[DC_MOTOR_PIN_1]), HIGH);
     ret = gpio_pin_write_logic(&(dc_motor->dc_motor[DC_MOTOR_PIN_2]), LOW);
    }
    return ret;
}
STD_ReturnType Motor_Backward(const dc_motor_t *dc_motor){
    STD_ReturnType ret = E_OK;
    if(NULL == dc_motor){
        ret = E_NOK;
    }
    else{
        ret = gpio_pin_write_logic(&(dc_motor->dc_motor[DC_MOTOR_PIN_1]), LOW);
        ret = gpio_pin_write_logic(&(dc_motor->dc_motor[DC_MOTOR_PIN_2]), HIGH);
    }
    return ret;
}
STD_ReturnType Motor_Stop(const dc_motor_t *dc_motor){
    STD_ReturnType ret = E_OK;
    if(NULL == dc_motor){
        ret = E_NOK;
    }
    else{  
     ret = gpio_pin_write_logic(&(dc_motor->dc_motor[DC_MOTOR_PIN_1]), LOW);
     ret = gpio_pin_write_logic(&(dc_motor->dc_motor[DC_MOTOR_PIN_2]), LOW);
    }
    return ret;
}