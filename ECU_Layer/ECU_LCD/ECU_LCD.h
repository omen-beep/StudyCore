/* 
 * File:   ECU_LCD.h
 * Author: Eng.Yassmin
 *
 * Created on October 24, 2024, 12:28 PM
 */

#ifndef ECU_LCD_H
#define	ECU_LCD_H
/* Includes Section */
#include "ECU_LCD_CFG.h"
#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"
/* Macro Declaration Section */
#define _LCD_CLEAR                     0x01
#define _LCD_RETURN_HOME               0x02
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON   0x05        
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF  0x04     
#define _LCD_ENTRY_MODE_INC_SHIFT_ON   0x07      
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF  0x06      
#define _LCD_CURSOR_OFF_DISPLAY_ON     0x0C
#define _LCD_CURSOR_OFF_DISPLAY_OFF    0x08
#define _LCD_CURSOR_ON_BLINK_ON        0x0F
#define _LCD_CURSOR_ON_BLINK_OFF       0x0E
#define _LCD_DISPLAY_SHIFT_RIGHT       0x1C
#define _LCD_DISPLAY_SHIFT_LEFT        0x18
#define _LCD_8BIT_MODE_2_LINE          0x38
#define _LCD_4BIT_MODE_2_LINE          0x28
#define _LCD_CGRAM_START               0x40
#define _LCD_DDRAM_START               0x80

#define ROW1 1
#define ROW2 2
#define ROW3 3
#define ROW4 4
/* Macro Function Declaration Section */

/* Data Type Section */
typedef struct{
    pin_config_t data_pins[4];
    pin_config_t rs_pin;
    pin_config_t en_pin;
}LCD_4bit_t;

typedef struct{
    pin_config_t data_pins[9];
    pin_config_t rs_pin;
    pin_config_t en_pin;
}LCD_8bit_t;
/* Function Declaration Section */
STD_ReturnType LCD_Init_4bit(const LCD_4bit_t *LCD);
STD_ReturnType LCD_Send_Command_4bit(const LCD_4bit_t *LCD, uint8 command);
STD_ReturnType LCD_Send_Char_Data_4bit(const LCD_4bit_t *LCD, uint8 data);
STD_ReturnType LCD_Send_Char_Data_Pos_4bit(const LCD_4bit_t *LCD, uint8 row, uint8 col, uint8 data);
STD_ReturnType LCD_Send_String_4bit(const LCD_4bit_t *LCD, uint8 *string);
STD_ReturnType LCD_Send_String_Pos_4bit(const LCD_4bit_t *LCD, uint8 row, uint8 col, uint8 *string);
STD_ReturnType LCD_Send_Cust_Char_4bit(const LCD_4bit_t *LCD, uint8 row, uint8 col, uint8 _char[], uint8 mem_pos);

STD_ReturnType LCD_Init_8bit(const LCD_8bit_t *LCD);
STD_ReturnType LCD_Send_Command_8bit(const LCD_8bit_t *LCD, uint8 command);
STD_ReturnType LCD_Send_Char_Data_8bit(const LCD_8bit_t *LCD, uint8 data);
STD_ReturnType LCD_Send_Char_Data_Pos_8bit(const LCD_8bit_t *LCD, uint8 row, uint8 col, uint8 data);
STD_ReturnType LCD_Send_String_8bit(const LCD_8bit_t *LCD, uint8 *string);
STD_ReturnType LCD_Send_String_Pos_8bit(const LCD_8bit_t *LCD, uint8 row, uint8 col, uint8 *string);
STD_ReturnType LCD_Send_Cust_Char_8bit(const LCD_8bit_t *LCD, uint8 row, uint8 col, uint8 _char[], uint8 mem_pos);

STD_ReturnType convert_byte_to_string(uint8 value, uint8 *string);
STD_ReturnType convert_short_to_string(uint16 value, uint8 *string);
STD_ReturnType convert_int_to_string(uint32 value, uint8 *string);
#endif	/* ECU_LCD_H */

