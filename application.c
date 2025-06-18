/* 
 * File:   application.c
 * Author: Eng.Yasmine
 *
 * Created on September 29, 2024, 1:00 PM
 */

#include "application.h"
#define SLAVE_1 0x60
#define SLAVE_2 0x62

mssp_i2c_t i2c_obj = {
    .i2c_cfg.i2c_SMBus_ctrl = I2C_SMBus_Disable,
    .i2c_clock = 100000,
    .i2c_cfg.i2c_cfg_mode = I2C_Master_Mode_Defined_Clock,
    .i2c_cfg.i2c_slew_rate = I2C_Slew_Rate_Disable,
    .i2c_cfg.i2c_mode = MSSP_I2C_Master_Mode,
//    .I2C_DefaultInterruptHandler = NULL,
//    .I2C_Report_Receive_Overflow = NULL,
//    .I2C_Report_Write_Collision = NULL
};
uint8 ack;
void mssp_i2c_send_1_byte(uint32 slave_add, uint32 dataa){
    MSSP_I2C_Master_Send_Start(&i2c_obj);
    MSSP_I2C_Master_Write(&i2c_obj, slave_add, &ack);
    MSSP_I2C_Master_Write(&i2c_obj, dataa, &ack);
    MSSP_I2C_Master_Send_Stop(&i2c_obj);
}

int main() {
    STD_ReturnType ret = E_NOK;
    application_init();
    ret = MSSP_I2C_Init(&i2c_obj);
    
    
    
    while(1){
    mssp_i2c_send_1_byte(SLAVE_1, 'a');
    __delay_ms(1500);
    mssp_i2c_send_1_byte(SLAVE_2, 'b');
    __delay_ms(1500);
    mssp_i2c_send_1_byte(SLAVE_1, 'c');
    __delay_ms(1500);
    mssp_i2c_send_1_byte(SLAVE_2, 'd');
    __delay_ms(1500);
    }
    return (EXIT_SUCCESS);
}

void application_init(void){
    STD_ReturnType ret = E_NOK;
    ECU_Layer_Init();
}