/* 
 * File:   ECU_LED.c
 * Author: Eng.Yasmine
 *
 * Created on September 29, 2024, 1:00 PM
 */

#include "ECU_LED.h"
/**
 * @brief initializes the assigned pin to OUTPUT and turns the LED off
 * @param led : pointer to the LED module config
 * @return status of the function:
 *              E_OK: function successful
 *              E_NOK: function failed
 */
STD_ReturnType LED_init(const led_t *led){
    STD_ReturnType ret = E_OK;
    if(NULL == led){
        ret = E_NOK;
        printf("ERROR");
    }
    else{
    pin_config_t pin_config = {
      .port = led->port_name,
      .direction = OUTPUT,
      .logic = led->led_status,
      .pin = led->pin
    };
        gpio_pin_init(&pin_config);
    }
    return ret;
}
/**
 * @brief turns the LED on
 * @param led : pointer to the LED module config
 * @return status of the function:
 *              E_OK: function successful
 *              E_NOK: function failed
 */
STD_ReturnType LED_TURN_ON(const led_t *led){
    STD_ReturnType ret = E_OK;
    if(NULL == led){
        ret = E_NOK;
        printf("ERROR");
    }
    else{
       pin_config_t pin_config = {
      .port = led->port_name,
      .direction = OUTPUT,
      .logic = led->led_status,
      .pin = led->pin
    };       
       gpio_pin_write_logic(&pin_config, HIGH);
    }
    return ret;
}
/**
 * @brief turns the LED off
 * @param led : pointer to the LED module config
 * @return status of the function:
 *              E_OK: function successful
 *              E_NOK: function failed
 */
STD_ReturnType LED_TURN_OFF(const led_t *led){
    STD_ReturnType ret = E_OK;
    if(NULL == led){
        ret = E_NOK;
        printf("ERROR");
    }
    else{
       pin_config_t pin_config = {
      .port = led->port_name,
      .direction = OUTPUT,
      .logic = led->led_status,
      .pin = led->pin
    };       
       gpio_pin_write_logic(&pin_config, LOW);
    }
    return ret;
}
/**
 * @brief toggles LED
 * @param led : pointer to the LED module config
 * @return status of the function:
 *              E_OK: function successful
 *              E_NOK: function failed
 */
STD_ReturnType LED_TURN_TOGGLE(const led_t *led){
    STD_ReturnType ret = E_OK;
    if(NULL == led){
        ret = E_NOK;
        printf("ERROR");
    }
    else{
       pin_config_t pin_config = {
      .port = led->port_name,
      .direction = OUTPUT,
      .logic = led->led_status,
      .pin = led->pin
    };       
       gpio_pin_toggle_logic(&pin_config);
    }
    return ret;
}
