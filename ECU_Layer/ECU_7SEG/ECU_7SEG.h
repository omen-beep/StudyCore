/* 
 * File:   ECU_7SEG.h
 * Author: Eng.Yassmin
 *
 * Created on October 20, 2024, 3:02 PM
 */

#ifndef ECU_7SEG_H
#define	ECU_7SEG_H
/* Includes Section */
#include "ECU_7SEG_CFG.h"
#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"
/* Macro Declaration Section */
#define MULTIP_PIN_1     0
#define MULTIP_PIN_2     1
#define MULTIP_PIN_3     2
#define MULTIP_PIN_4     3
/* Macro Function Declaration Section */

/* Data Type Section */
typedef enum{
    SEG_COMMON_ANODE,
    SEG_COMMON_CATHODE
}seg_type_t;

typedef struct {
    pin_config_t multip_pin[4];
    seg_type_t seg_type;
}segment_t;
/* Function Declaration Section */
STD_ReturnType Seg_Init(const segment_t *seg);
STD_ReturnType Seg_Write(const segment_t *seg, uint8 Number);
#endif	/* ECU_7SEG_H */

