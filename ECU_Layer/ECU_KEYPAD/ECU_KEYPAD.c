#include "ECU_KEYPAD.h"


static const uint8 btn_values[KEYPAD_ROW_PINS][KEYPAD_COL_PINS] = {
                                                        {'7', '8', '9', '/'},
                                                        {'4', '5', '6', '*'},
                                                        {'1', '2', '3', '-'},
                                                        {'#', '0', '=', '+'},
                                                     };


STD_ReturnType Keypad_Init(const keypad_t *keypad){
    STD_ReturnType ret = E_OK;
    uint8 ROWS_COUNTER = ZERO_INIT, COL_COUNTER = ZERO_INIT;
    if(NULL == keypad){
        ret = E_NOK;
    }
    else{
        for(ROWS_COUNTER = 0; ROWS_COUNTER < KEYPAD_ROW_PINS; ROWS_COUNTER++){
            ret = gpio_pin_init(&(keypad->KEYPAD_ROW[ROWS_COUNTER]));
        }
        for(COL_COUNTER = 0; COL_COUNTER < KEYPAD_COL_PINS; COL_COUNTER++){
            ret = gpio_pin_direction_init(&(keypad->KEYPAD_COL[COL_COUNTER]));
        }
    }
    return ret;
}
STD_ReturnType Keypad_Get_Value(const keypad_t *keypad, uint8 *value){
    STD_ReturnType ret = E_OK;
    logic_t COL_LOGIC = LOW;
    uint8 ROWS_COUNTER = ZERO_INIT, COL_COUNTER = ZERO_INIT, COUNTER = ZERO_INIT;
    if((NULL == keypad) || (NULL == value)){
        ret = E_NOK;
    }
    else{
        for(ROWS_COUNTER = 0; ROWS_COUNTER < KEYPAD_ROW_PINS; ROWS_COUNTER++){
            for(COUNTER = 0; COUNTER < KEYPAD_ROW_PINS; COUNTER++){
            ret = gpio_pin_write_logic(&(keypad->KEYPAD_ROW[COUNTER]), LOW);
            }
            ret = gpio_pin_write_logic(&(keypad->KEYPAD_ROW[ROWS_COUNTER]), HIGH);
            for(COL_COUNTER = 0; COL_COUNTER < KEYPAD_COL_PINS; COL_COUNTER++){
                ret = gpio_pin_read_logic(&(keypad->KEYPAD_COL[COL_COUNTER]), &COL_LOGIC);
                if(HIGH == COL_LOGIC){
                  *value = btn_values[ROWS_COUNTER][COL_COUNTER];
                }
            }
        }
    }
    return ret;
}