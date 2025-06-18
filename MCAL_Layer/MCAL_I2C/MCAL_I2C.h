/* 
 * File:   MCAL_I2C.h
 * Author: Eng.Yassmin
 *
 * Created on December 26, 2024, 12:19 PM
 */

#ifndef MCAL_I2C_H
#define	MCAL_I2C_H
/* Includes Section */
#include <xc.h>
#include "../GPIO/HAL_GPIO.h"
#include "../MCAL_STD_TYPES.h"
#include "../MCAL_Interrupts/MCAL_Internal_Interrupt.h"
/* Macro Declaration Section */
#define I2C_Slew_Rate_Disable      1
#define I2C_Slew_Rate_Enable       0

#define I2C_SMBus_Disable          0
#define I2C_SMBus_Enable           1

#define I2C_Last_Byte_Data         1
#define I2C_Last_Byte_Address      0

#define I2C_Stop_Bit_Detected      1
#define I2C_Stop_Bit_Not_Detected  0

#define I2C_Start_Bit_Detected     1
#define I2C_Start_Bit_Not_Detected 0

#define MSSP_I2C_Master_Mode       1
#define MSSP_I2C_Slave_Mode        0

#define I2C_Slave_Mode_7Bit_Address                     0x06U
#define I2C_Slave_Mode_10Bit_Address                    0x07U
#define I2C_Slave_Mode_7Bit_Address_Int_Enable          0x0EU
#define I2C_Slave_Mode_10Bit_Address_Int_Enable         0x0FU
#define I2C_Master_Mode_Defined_Clock                   0x08U
#define I2C_Master_Mode_Firmware_Controlled             0x0bU

#define I2C_General_Call_Enable     1
#define I2C_General_Call_Disable    0

#define I2C_Master_Receive_Enable    1
#define I2C_Master_Receive_Disable   0

#define I2C_ACK_RECEIVED_FROM_SLAVE      0
#define I2C_ACK_NOT_RECEIVED_FROM_SLAVE  1

#define I2C_MASTER_SEND_ACK          0
#define I2C_MASTER_SEND_NOT_ACK      1
/* Macro Function Declaration Section */
#define I2C_Module_Enable_CFG()          (SSPCON1bits.SSPEN = 1)
#define I2C_Module_Disable_CFG()         (SSPCON1bits.SSPEN = 0)

#define I2C_Slew_Rate_Disable_CFG()      (SSPSTATbits.SMP = 1)
#define I2C_Slew_Rate_Enable_CFG()       (SSPSTATbits.SMP = 0)

#define I2C_SMbus_Ctrl_Enable_CFG()      (SSPSTATbits.CKE = 1)
#define I2C_SMbus_Ctrl_Disable_CFG()     (SSPSTATbits.CKE = 0)

#define I2C_General_Call_Enable_CFG()    (SSPCON2bits.GCEN = 1)
#define I2C_General_Call_Disable_CFG()   (SSPCON2bits.GCEN = 0)

#define I2C_Master_Receive_Enable_CFG()  (SSPCON2bits.RCEN = 1)
#define I2C_Master_Receive_Disable_CFG() (SSPCON2bits.RCEN = 0)
/* Data Type Section */
typedef struct{
    uint8 i2c_cfg_mode;
    uint8 i2c_slave_address;
    uint8 i2c_mode         :1;
    uint8 i2c_slew_rate    :1;
    uint8 i2c_SMBus_ctrl   :1;
    uint8 i2c_gen_call     :1;
    uint8 i2c_master_rec   :1;
    uint8 i2c_reserved     :3;
}i2c_cfg_t;

typedef struct{
    i2c_cfg_t i2c_cfg;
    uint32 i2c_clock;
    #if I2C_INTERRUPT_FEATURE_ENABLE
    void(*I2C_Report_Write_Collision)(void);
    void(*I2C_DefaultInterruptHandler)(void);
    void(*I2C_Report_Receive_Overflow)(void);
    #if INTERRUPT_PRIO_LEVEL_ENABLE
    Interrupt_Prio_t mssp_prio;
    Interrupt_Prio_t bus_prio;
    #endif
    #endif
    
}mssp_i2c_t;
/* Function Declaration Section */
STD_ReturnType MSSP_I2C_Init(const mssp_i2c_t *mssp);
STD_ReturnType MSSP_I2C_DeInit(const mssp_i2c_t *mssp);
STD_ReturnType MSSP_I2C_Master_Send_Start(const mssp_i2c_t *mssp);
STD_ReturnType MSSP_I2C_Master_Send_Repeasted_Start(const mssp_i2c_t *mssp);
STD_ReturnType MSSP_I2C_Master_Send_Stop(const mssp_i2c_t *mssp);
STD_ReturnType MSSP_I2C_Master_Write(const mssp_i2c_t *mssp, uint32 data_, uint8 *_ack);
STD_ReturnType MSSP_I2C_Master_Read(const mssp_i2c_t *mssp, uint8 ack, uint32 *data_);
#endif	/* MCAL_I2C_H */

