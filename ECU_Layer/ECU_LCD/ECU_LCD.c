#include "ECU_LCD.h"

static STD_ReturnType Send_4bits(const LCD_4bit_t *LCD, uint8 command);
static STD_ReturnType Send_Enable_Signal(const LCD_4bit_t *LCD); 
static STD_ReturnType Send_Enable_Signal_8bit(const LCD_8bit_t *LCD);
static STD_ReturnType Set_Cursor_8bit(const LCD_8bit_t *LCD, uint8 rows, uint8 col);
static STD_ReturnType Set_Cursor_4bit(const LCD_4bit_t *LCD, uint8 rows, uint8 col);

STD_ReturnType LCD_Init_4bit(const LCD_4bit_t *LCD){
    STD_ReturnType ret = E_OK;

    if(NULL == LCD){
        ret = E_NOK;
    }
    else{
      ret = gpio_pin_init(&(LCD->rs_pin));
      ret = gpio_pin_init(&(LCD->en_pin));
      for(uint8 counter = 0; counter < 4; counter++){
          ret = gpio_pin_init(&(LCD->data_pins[counter]));
      }
      __delay_ms(20);
      ret = LCD_Send_Command_4bit(LCD, _LCD_8BIT_MODE_2_LINE);
      __delay_ms(5);
      ret = LCD_Send_Command_4bit(LCD, _LCD_8BIT_MODE_2_LINE);
      __delay_us(150);
      ret = LCD_Send_Command_4bit(LCD, _LCD_8BIT_MODE_2_LINE);
      ret = LCD_Send_Command_4bit(LCD, _LCD_CLEAR);
      ret = LCD_Send_Command_4bit(LCD, _LCD_RETURN_HOME);
      ret = LCD_Send_Command_4bit(LCD, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
      ret = LCD_Send_Command_4bit(LCD, _LCD_CURSOR_OFF_DISPLAY_ON);
      ret = LCD_Send_Command_4bit(LCD, _LCD_4BIT_MODE_2_LINE);
      ret = LCD_Send_Command_4bit(LCD, 0x80);
    }
    return ret;
}
STD_ReturnType LCD_Send_Command_4bit(const LCD_4bit_t *LCD, uint8 command){
    STD_ReturnType ret = E_OK;

    if(NULL == LCD){
        ret = E_NOK;
    }
    else{
        ret = gpio_pin_write_logic(&(LCD->rs_pin), LOW);
        ret = Send_4bits(LCD, command >> 4);
        ret = Send_Enable_Signal(LCD);
        ret = Send_4bits(LCD, command);
        ret = Send_Enable_Signal(LCD);
    }
    return ret;
}
STD_ReturnType LCD_Send_Char_Data_4bit(const LCD_4bit_t *LCD, uint8 data){
    STD_ReturnType ret = E_OK;

    if(NULL == LCD){
        ret = E_NOK;
    }
    else{
        ret = gpio_pin_write_logic(&(LCD->rs_pin), HIGH);
        ret = Send_4bits(LCD, data >> 4);
        ret = Send_Enable_Signal(LCD);
        ret = Send_4bits(LCD, data);
        ret = Send_Enable_Signal(LCD);
    }
    return ret;
}
STD_ReturnType LCD_Send_Char_Data_Pos_4bit(const LCD_4bit_t *LCD, uint8 row, uint8 col, uint8 data){
    STD_ReturnType ret = E_OK;

    if(NULL == LCD){
        ret = E_NOK;
    }
    else{
       ret = Set_Cursor_4bit(LCD, row, col);
       ret = LCD_Send_Char_Data_4bit(LCD, data);
    }
    return ret;
}
STD_ReturnType LCD_Send_String_4bit(const LCD_4bit_t *LCD, uint8 *string){
    STD_ReturnType ret = E_OK;

    if((NULL == LCD) || (NULL == string)){
        ret = E_NOK;
    }
    else{
         while(*string){
            ret = LCD_Send_Char_Data_4bit(LCD, *string++);
        }
    }
    return ret;
}
STD_ReturnType LCD_Send_String_Pos_4bit(const LCD_4bit_t *LCD, uint8 row, uint8 col, uint8 *string){
    STD_ReturnType ret = E_OK;

    if((NULL == LCD) || (NULL == string)){
        ret = E_NOK;
    }
    else{
        ret = Set_Cursor_4bit(LCD, row, col);
        ret = LCD_Send_String_4bit(LCD, string);
    }
    return ret;
}
STD_ReturnType LCD_Send_Cust_Char_4bit(const LCD_4bit_t *LCD, uint8 row, uint8 col, uint8 _char[], uint8 mem_pos){
    STD_ReturnType ret = E_OK;

    if(NULL == LCD){
        ret = E_NOK;
    }
    else{
    ret = LCD_Send_Command_4bit(LCD, (_LCD_CGRAM_START+(mem_pos*8)));
    for(uint8 counter = 0; counter <= 7; counter++){
        ret = LCD_Send_Char_Data_4bit(LCD, _char[counter]);
    }
    ret = LCD_Send_Char_Data_Pos_4bit(LCD, row, col, mem_pos);   
    }
    return ret;
}

STD_ReturnType LCD_Init_8bit(const LCD_8bit_t *LCD){
    STD_ReturnType ret = E_OK;

    if(NULL == LCD){
        ret = E_NOK;
    }
    else{
      ret = gpio_pin_init(&(LCD->rs_pin));
      ret = gpio_pin_init(&(LCD->en_pin));
      for(uint8 counter = 0; counter < 8; counter++){
          ret = gpio_pin_init(&(LCD->data_pins[counter]));
      }
      __delay_ms(20);
      ret = LCD_Send_Command_8bit(LCD, _LCD_8BIT_MODE_2_LINE);
      __delay_ms(5);
      ret = LCD_Send_Command_8bit(LCD, _LCD_8BIT_MODE_2_LINE);
      __delay_us(150);
      ret = LCD_Send_Command_8bit(LCD, _LCD_8BIT_MODE_2_LINE);
      ret = LCD_Send_Command_8bit(LCD, _LCD_CLEAR);
      ret = LCD_Send_Command_8bit(LCD, _LCD_RETURN_HOME);
      ret = LCD_Send_Command_8bit(LCD, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
      ret = LCD_Send_Command_8bit(LCD, _LCD_CURSOR_OFF_DISPLAY_ON);
      ret = LCD_Send_Command_8bit(LCD, _LCD_8BIT_MODE_2_LINE);
    }
    return ret;
}
STD_ReturnType LCD_Send_Command_8bit(const LCD_8bit_t *LCD, uint8 command){
    STD_ReturnType ret = E_OK;
    if(NULL == LCD){
        ret = E_NOK;
    }
    else{
        ret = gpio_pin_write_logic(&(LCD->rs_pin), LOW);
        for(uint8 counter = 0; counter < 8; counter++){
            ret = gpio_pin_write_logic(&(LCD->data_pins[counter]), (command >> counter) & (uint8)0x01);
        }
        Send_Enable_Signal_8bit(LCD);
    }
    return ret;
}
STD_ReturnType LCD_Send_Char_Data_8bit(const LCD_8bit_t *LCD, uint8 data){
    STD_ReturnType ret = E_OK;

    if(NULL == LCD){
        ret = E_NOK;
    }
    else{
        ret = gpio_pin_write_logic(&(LCD->rs_pin), HIGH);
        for(uint8 counter = 0; counter < 8; counter++){
            ret = gpio_pin_write_logic(&(LCD->data_pins[counter]), (data >> counter) & (uint8)0x01);
        }
        Send_Enable_Signal_8bit(LCD);
    }
    return ret;
}
STD_ReturnType LCD_Send_Char_Data_Pos_8bit(const LCD_8bit_t *LCD, uint8 row, uint8 col, uint8 data){
    STD_ReturnType ret = E_OK;

    if(NULL == LCD){
        ret = E_NOK;
    }
    else{
        ret = Set_Cursor_8bit(LCD, row, col);
        ret = LCD_Send_Char_Data_8bit(LCD, data);
    }
    return ret;
}
STD_ReturnType LCD_Send_String_8bit(const LCD_8bit_t *LCD, uint8 *string){
    STD_ReturnType ret = E_OK;

    if((NULL == LCD) || (NULL == string)){
        ret = E_NOK;
    }
    else{
        while(*string){
            ret = LCD_Send_Char_Data_8bit(LCD, *string++);
        }
    }
    return ret;
}
STD_ReturnType LCD_Send_String_Pos_8bit(const LCD_8bit_t *LCD, uint8 row, uint8 col, uint8 *string){
    STD_ReturnType ret = E_OK;

    if((NULL == LCD) || (NULL == string)){
        ret = E_NOK;
    }
    else{
         ret = Set_Cursor_8bit(LCD, row, col);
         ret = LCD_Send_String_8bit(LCD, string);
    }
    return ret;
}
STD_ReturnType LCD_Send_Cust_Char_8bit(const LCD_8bit_t *LCD, uint8 row, uint8 col, uint8 _char[], uint8 mem_pos){
    STD_ReturnType ret = E_OK;

    if(NULL == LCD){
        ret = E_NOK;
    }
    else{
    ret = LCD_Send_Command_8bit(LCD, (_LCD_CGRAM_START+(mem_pos*8)));
    for(uint8 counter = 0; counter <= 7; counter++){
        ret = LCD_Send_Char_Data_8bit(LCD, _char[counter]);
    }
    ret = LCD_Send_Char_Data_Pos_8bit(LCD, row, col, mem_pos);
    }
    return ret;
}

STD_ReturnType convert_byte_to_string(uint8 value, uint8 *str){
STD_ReturnType ret = E_OK;

    if(NULL == str){
        ret = E_NOK;
    }
    else{
        memset(str,'\0',4);
      //  sprintf(str,"%i",value);
    }
    return ret;
}
STD_ReturnType convert_short_to_string(uint16 value, uint8 *str){
STD_ReturnType ret = E_OK;

    if(NULL == str){
        ret = E_NOK;
    }
    else{
        memset(str,'\0',6);
       // sprintf(str,"%i",value);
    }
    return ret;
}
STD_ReturnType convert_int_to_string(uint32 value, uint8 *str){
STD_ReturnType ret = E_OK;

    if(NULL == str){
        ret = E_NOK;
    }
    else{
        memset(str,'\0',11);
      //  sprintf(str,"%i",value);
    }
    return ret;
}
static STD_ReturnType Send_4bits(const LCD_4bit_t *LCD, uint8 command){
    STD_ReturnType ret = E_OK;
    if(NULL == LCD){
        ret = E_NOK;
    }
    else{
        ret = gpio_pin_write_logic(&(LCD->data_pins[0]), (command >> 0) & (uint8)0x01);
        ret = gpio_pin_write_logic(&(LCD->data_pins[1]), (command >> 1) & (uint8)0x01);
        ret = gpio_pin_write_logic(&(LCD->data_pins[2]), (command >> 2) & (uint8)0x01);
        ret = gpio_pin_write_logic(&(LCD->data_pins[3]), (command >> 3) & (uint8)0x01);
    }
    return ret;
}

static STD_ReturnType Send_Enable_Signal(const LCD_4bit_t *LCD){
    STD_ReturnType ret = E_OK;
    ret = gpio_pin_write_logic(&(LCD->en_pin), HIGH);
    __delay_us(5);
    ret = gpio_pin_write_logic(&(LCD->en_pin), LOW);
    return ret;
}

static STD_ReturnType Send_Enable_Signal_8bit(const LCD_8bit_t *LCD){
    STD_ReturnType ret = E_OK;
    ret = gpio_pin_write_logic(&(LCD->en_pin), HIGH);
     __delay_us(5);
    ret = gpio_pin_write_logic(&(LCD->en_pin), LOW);
    return ret;
}

static STD_ReturnType Set_Cursor_8bit(const LCD_8bit_t *LCD, uint8 rows, uint8 col){
    STD_ReturnType ret = E_OK;
    col--;
    if(NULL == LCD){
        ret = E_NOK;
    }
    else{
        switch(rows){
            case ROW1:
                ret = LCD_Send_Command_8bit(LCD, (0x80 + col));
                break;
            case ROW2:
                ret = LCD_Send_Command_8bit(LCD, (0xc0 + col));
                break;
            case ROW3:
                ret = LCD_Send_Command_8bit(LCD, (0x94 + col));
                break;
            case ROW4:
                ret = LCD_Send_Command_8bit(LCD, (0xd4 + col));
                break;
            default: 
                ret = E_NOK;
                break;
        }
    }
    return ret;   
}
static STD_ReturnType Set_Cursor_4bit(const LCD_4bit_t *LCD, uint8 rows, uint8 col){
    STD_ReturnType ret = E_OK;
    col--;
    if(NULL == LCD){
        ret = E_NOK;
    }
    else{
        switch(rows){
            case ROW1:
                ret = LCD_Send_Command_4bit(LCD, (0x80 + col));
                break;
            case ROW2:
                ret = LCD_Send_Command_4bit(LCD, (0xc0 + col));
                break;
            case ROW3:
                ret = LCD_Send_Command_4bit(LCD, (0x94 + col));
                break;
            case ROW4:
                ret = LCD_Send_Command_4bit(LCD, (0xd4 + col));
                break;
            default: 
                ret = E_NOK;
                break;
        }
    }
    return ret;  
}