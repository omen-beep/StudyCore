/* 
 * File:   HAL_GPIO.c
 * Author: Eng.Yasmine
 *
 * Created on September 29, 2024, 1:00 PM
 */

#include "HAL_GPIO.h"
volatile uint8 *tris_reg[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
volatile uint8 *lat_reg[] = {&LATA, &LATB, &LATC, &LATD, &LATE};
volatile uint8 *port_reg[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};


/**
 * @brief initializes the direction of a specific pin @ref direction_t
 * @param pin_config pointer to the configuration @ref pin_config_t
 * @return return the status of the function
 *              E_OK : function successful
 *              E_NOK: function failed
 */

#if GPIO_PORT_PIN_CONFIG == CONFIG_ENABLE
STD_ReturnType gpio_pin_direction_init(const pin_config_t *pin_config){
    STD_ReturnType ret = E_OK;
    if((NULL == pin_config) || ((pin_config->pin) > (PORT_PIN_MAX_NUMBER - 1))){
        ret = E_NOK;
    }
    else{
    switch(pin_config->direction){
        case(OUTPUT):
            CLEAR_BIT(*tris_reg[pin_config->port], pin_config->pin);
            break;
        case(INPUT):
            SET_BIT(*tris_reg[pin_config->port], pin_config->pin);
            break;
        default:
            ret = E_NOK; 
    }
    }
    return ret;
}
#endif
/**
 * 
 * @param pin_config pointer to the configuration @ref pin_config_t
 * @param direction_status
 * @return return the status of the function
 *              E_OK : function successful
 *              E_NOK: function failed
 */
#if GPIO_PORT_PIN_CONFIG == CONFIG_ENABLE
STD_ReturnType gpio_pin_direction_status(const pin_config_t *pin_config, direction_t *direction_status){
    STD_ReturnType ret = E_OK;
    if((NULL == pin_config) || (NULL == direction_status)){
        ret = E_NOK;
        printf("NULL INPUT");
    }
    else{
        *direction_status = READ_BIT(*tris_reg[pin_config->port], pin_config->pin);
    }
    return ret;
}
#endif
/**
 * 
 * @param pin_config pointer to the configuration @ref pin_config_t
 * @param logic
 * @return return the status of the function
 *              E_OK : function successful
 *              E_NOK: function failed
 */
#if GPIO_PORT_PIN_CONFIG == CONFIG_ENABLE
STD_ReturnType gpio_pin_write_logic(const pin_config_t *pin_config, logic_t logic){
    STD_ReturnType ret = E_OK;
    if(NULL == pin_config){
        ret = E_NOK;
    }
    else{
    switch(logic){
        case(LOW):
            CLEAR_BIT(*lat_reg[pin_config->port], pin_config->pin);
            break;
        case(HIGH):
            SET_BIT(*lat_reg[pin_config->port], pin_config->pin);
            break;
        default:
            ret = E_NOK; 
    }
    }    
    return ret;
}
#endif
/**
 * 
 * @param pin_config pointer to the configuration @ref pin_config_t
 * @param logic
 * @return return the status of the function
 *              E_OK : function successful
 *              E_NOK: function failed
 */
#if GPIO_PORT_PIN_CONFIG == CONFIG_ENABLE
STD_ReturnType gpio_pin_read_logic(const pin_config_t *pin_config, logic_t *logic){
    STD_ReturnType ret = E_OK;
    if((NULL == pin_config) || (NULL == logic)){
        ret = E_NOK;
        printf("NULL INPUT");
    }
    else{
        *logic = READ_BIT(*port_reg[pin_config->port], pin_config->pin);
    }    
    return ret;
}
#endif
/**
 * 
 * @param pin_config pointer to the configuration @ref pin_config_t
 * @return return the status of the function
 *              E_OK : function successful
 *              E_NOK: function failed
 */
#if GPIO_PORT_PIN_CONFIG == CONFIG_ENABLE
STD_ReturnType gpio_pin_toggle_logic(const pin_config_t *pin_config){
    STD_ReturnType ret = E_OK;
    if(NULL == pin_config){
        ret = E_NOK;
        printf("NULL INPUT");
    }
    else{
        TOGGLE_BIT(*lat_reg[pin_config->port], pin_config->pin);
    }    
    return ret;
}
#endif
/**
 * 
 * @param pin_config pointer to the configuration @ref pin_config_t
 * @return return the status of the function
 *              E_OK : function successful
 *              E_NOK: function failed
 */
#if GPIO_PORT_PIN_CONFIG == CONFIG_ENABLE
STD_ReturnType gpio_pin_init(const pin_config_t *pin_config){
    STD_ReturnType ret = E_OK;
    if(NULL == pin_config){
        ret = E_NOK;
        printf("NULL INPUT");
    }
    else{
    gpio_pin_direction_init(pin_config);
    gpio_pin_write_logic(pin_config, pin_config->logic);
    
    }    
    return ret;
}
#endif
/**
 * 
 * @param port
 * @param direction
 * @return return the status of the function
 *              E_OK : function successful
 *              E_NOK: function failed
 */
#if GPIO_PORT_CONFIG == CONFIG_ENABLE
STD_ReturnType gpio_port_direction_init(port_index_t port, uint8 direction){
    STD_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1){
        ret = E_NOK;
        printf("NULL INPUT");
    }
    else{
        *tris_reg[port] = direction;
    }    
   
    return ret;
}
#endif
/**
 * 
 * @param port
 * @param direction_status
 * @return return the status of the function
 *              E_OK : function successful
 *              E_NOK: function failed
 */
#if GPIO_PORT_CONFIG == CONFIG_ENABLE
STD_ReturnType gpio_port_direction_status(port_index_t port, uint8 *direction_status){
    STD_ReturnType ret = E_OK;
    if((NULL == direction_status) || (port > PORT_MAX_NUMBER-1)){
        ret = E_NOK;
        printf("NULL INPUT");
    }
    else{
    *direction_status = *tris_reg[port];
    }    
    return ret;
}
#endif
/**
 * 
 * @param port
 * @param logic
 * @return return the status of the function
 *              E_OK : function successful
 *              E_NOK: function failed
 */
#if GPIO_PORT_CONFIG == CONFIG_ENABLE
STD_ReturnType gpio_pport_write_logic(port_index_t port, uint8 logic){
    STD_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER-1){
        ret = E_NOK;
        printf("NULL INPUT");
    }
    else{
    *lat_reg[port] = logic;
    }    
    return ret;
}
#endif
/**
 * 
 * @param port
 * @param logic
 * @return return the status of the function
 *              E_OK : function successful
 *              E_NOK: function failed
 */
#if GPIO_PORT_CONFIG == CONFIG_ENABLE
STD_ReturnType gpio_port_read_logic(port_index_t port, uint8 *logic){
    STD_ReturnType ret = E_OK;
    if((NULL == logic) || (port > PORT_MAX_NUMBER-1)){
        ret = E_NOK;
        printf("NULL INPUT");
    }
    else{
    *logic = *lat_reg[port]; 
    }    
    return ret;
}
#endif
/**
 * 
 * @param port
 * @return return the status of the function
 *              E_OK : function successful
 *              E_NOK: function failed
 */
#if GPIO_PORT_CONFIG == CONFIG_ENABLE
STD_ReturnType gpio_port_toggle_logic(port_index_t port){
    STD_ReturnType ret = E_OK;
  if(port > PORT_MAX_NUMBER-1){
        ret = E_NOK;
        printf("NULL INPUT");
    }
    else{
    *lat_reg[port] ^= PORT_MASK;
    }    
    return ret;
}
#endif