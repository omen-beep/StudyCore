#include "ECU_BUTTON.h"

/**
 * @brief initializes the button
 * @param Button points to the button config
 * @return status of the function:
 *           E_OK: function successful
 *           E_NOK: function failed
 */
STD_ReturnType Button_Init(const button_init_t *Button){
    STD_ReturnType ret = E_OK;
    if(NULL == Button){
        ret = E_NOK;
    }
    else{
        ret = gpio_pin_direction_init(&(Button->button));
    }
    return ret;
}

/**
 * @brief reads the state of the button
 * @param Button points to the button config
 * @param Button_State returns the button state
 * @return status of the function:
 *           E_OK: function successful
 *           E_NOK: function failed
 */
STD_ReturnType Button_Read(const button_init_t *Button, button_state_t *Button_State){
    STD_ReturnType ret = E_OK;
    logic_t logic = LOW;
    if((NULL == Button) || (NULL == Button_State)){
        ret = E_NOK;
    }
    else{
        ret = gpio_pin_read_logic(&(Button->button), &logic);
        if((BUTTON_ACTIVE_HIGH == Button->button_connection) && (ret = E_OK)){
           switch (logic){
               case (HIGH):
                   *Button_State = BUTTON_PRESSED;
                   break;
               case (LOW):
                   *Button_State = BUTTON_RELEASED;
                   break;
               default:
                   ret = E_NOK;
                   break;
           }
        }
        else if((BUTTON_ACTIVE_LOW == Button->button_connection) && (ret = E_OK)){
           switch (logic){
               case (LOW):
                   *Button_State = BUTTON_PRESSED;
                   break;
               case (HIGH):
                   *Button_State = BUTTON_RELEASED;
                   break;
               default:
                   ret = E_NOK;
                   break;
           }  
        }
        else{}
    }
    return ret;
}

