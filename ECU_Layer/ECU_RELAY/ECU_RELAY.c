#include "ECU_RELAY.h"

/**
 * @brief initializes the relay
 * @param relay points to the relay config
 * @return status of the function:
 *          E_OK: function successful
 *          E_NOK: function failed
 */
STD_ReturnType Relay_Init(const relay_t *relay){
STD_ReturnType ret = E_OK;
    if(NULL == relay){
        ret = E_NOK;
    }
    else{
        pin_config_t pin_config = {
        .direction = OUTPUT,
        .logic = relay->relay_status,
        .pin = relay->relay_pin,
        .port = relay->relay_port
        };
    gpio_pin_init(&pin_config);
    }
    return ret;
}
/**
 * @brief turns on the relay
 * @param relay points to the relay config
 * @return status of the function:
 *          E_OK: function successful
 *          E_NOK: function failed
 */
STD_ReturnType Relay_ON(const relay_t *relay){
    STD_ReturnType ret = E_OK;
    if(NULL == relay){
        ret = E_NOK;
    }
    else{
        pin_config_t pin_config = {
        .direction = OUTPUT,
        .logic = relay->relay_status,
        .pin = relay->relay_pin,
        .port = relay->relay_port
        };
    gpio_pin_write_logic(&pin_config, HIGH);
    }
    return ret;
}
/**
 * @brief turns off the relay
 * @param relay points to the relay config
 * @return status of the function:
 *          E_OK: function successful
 *          E_NOK: function failed
 */
STD_ReturnType Relay_OFF(const relay_t *relay){
    STD_ReturnType ret = E_OK;
    if(NULL == relay){
        ret = E_NOK;
    }
    else{
        pin_config_t pin_config = {
        .direction = OUTPUT,
        .logic = relay->relay_status,
        .pin = relay->relay_pin,
        .port = relay->relay_port
        };
    gpio_pin_write_logic(&pin_config, LOW);
    }
    return ret;
}
