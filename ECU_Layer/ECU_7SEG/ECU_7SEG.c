#include "ECU_7SEG.h"

STD_ReturnType Seg_Init(const segment_t *seg){
    STD_ReturnType ret = E_OK;

    if(NULL == seg){
        ret = E_NOK;
    }
    else{
        
        ret = gpio_pin_init(&(seg->multip_pin[MULTIP_PIN_1]));
        ret = gpio_pin_init(&(seg->multip_pin[MULTIP_PIN_2]));
        ret = gpio_pin_init(&(seg->multip_pin[MULTIP_PIN_3]));
        ret = gpio_pin_init(&(seg->multip_pin[MULTIP_PIN_4]));
    }
    return ret;
}
STD_ReturnType Seg_Write(const segment_t *seg, uint8 Number){
    STD_ReturnType ret = E_OK;

    if((NULL == seg) || (Number > 9)){
        ret = E_NOK;
    }
    else{
        ret = gpio_pin_write_logic(&(seg->multip_pin[MULTIP_PIN_1]), Number&0x01);
        ret = gpio_pin_write_logic(&(seg->multip_pin[MULTIP_PIN_2]), Number>>1&0x01);
        ret = gpio_pin_write_logic(&(seg->multip_pin[MULTIP_PIN_3]), Number>>2&0x01);
        ret = gpio_pin_write_logic(&(seg->multip_pin[MULTIP_PIN_4]), Number>>3&0x01);
    }   
    return ret;
}