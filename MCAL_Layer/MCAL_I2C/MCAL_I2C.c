#include "MCAL_I2C.h"
#if I2C_INTERRUPT_FEATURE_ENABLE
   static void(*I2C_Report_Write_Collision)(void) = NULL;
   static  void(*I2C_Report_Receive_Overflow)(void) = NULL;
   static  void(*I2C_DefaultInterruptHandler)(void) = NULL;
   
    
#endif
void I2C_ISR(void){
#if I2C_INTERRUPT_FEATURE_ENABLE
       I2C_Interrupt_Flag_Clear();
       if(I2C_DefaultInterruptHandler){
           I2C_DefaultInterruptHandler();
       }
#endif
    }
    void I2C_BUS_ISR(void){
#if I2C_INTERRUPT_FEATURE_ENABLE
        I2C_BUS_Col_Interrupt_Flag_Clear();
        if(I2C_Report_Write_Collision){
            I2C_Report_Write_Collision();
        }
#endif
    }

static inline void MSSP_I2C_MODE_GPIO_CFG(void);
static inline void I2C_Master_Clock_CFG(const mssp_i2c_t *mssp);
static inline void I2C_Slave_Clock_CFG(const mssp_i2c_t *mssp);

STD_ReturnType MSSP_I2C_Init(const mssp_i2c_t *mssp){
     STD_ReturnType ret = E_OK;
    if(NULL == mssp){
        ret = E_NOK;
    }
    else{
       I2C_Module_Disable_CFG();
       if(MSSP_I2C_Master_Mode == mssp->i2c_cfg.i2c_mode){
           I2C_Master_Clock_CFG(mssp);
       }
       else if(MSSP_I2C_Slave_Mode == mssp->i2c_cfg.i2c_mode){
           if(I2C_General_Call_Enable == mssp->i2c_cfg.i2c_gen_call){
               I2C_General_Call_Enable_CFG();
           }
           else if(I2C_General_Call_Disable == mssp->i2c_cfg.i2c_gen_call){
               I2C_General_Call_Disable_CFG();
           }
           else{}
           SSPCON1bits.WCOL = 0;
           SSPCON1bits.SSPOV = 0;
           SSPCON1bits.CKP = 1;
           SSPADD = mssp->i2c_cfg.i2c_slave_address;
           I2C_Slave_Clock_CFG(mssp);
       }
       else{}
       MSSP_I2C_MODE_GPIO_CFG();
       if(I2C_Slew_Rate_Enable == mssp->i2c_cfg.i2c_slew_rate){
           I2C_Slew_Rate_Enable_CFG();
       }
       else if(I2C_Slew_Rate_Disable == mssp->i2c_cfg.i2c_slew_rate){
           I2C_Slew_Rate_Disable_CFG();
       }
       else{}
       
       if(I2C_SMBus_Enable == mssp->i2c_cfg.i2c_SMBus_ctrl){
           I2C_SMbus_Ctrl_Enable_CFG();
       }
       else if(I2C_SMBus_Disable == mssp->i2c_cfg.i2c_SMBus_ctrl){
           I2C_SMbus_Ctrl_Disable_CFG();
       }
       else{}
       
#if I2C_INTERRUPT_FEATURE_ENABLE
        I2C_Interrupt_Enable();
        I2C_BUS_Col_Interrupt_Enable();
        I2C_Interrupt_Flag_Clear();
        I2C_BUS_Col_Interrupt_Flag_Clear();
        I2C_Report_Write_Collision = mssp->I2C_Report_Write_Collision;
        I2C_Report_Receive_Overflow = mssp->I2C_Report_Receive_Overflow;
        I2C_DefaultInterruptHandler = mssp->I2C_DefaultInterruptHandler;
        
        #if INTERRUPT_PRIO_LEVEL_ENABLE
        INTERRUPT_PriorityEnable();
        if(INTERRUPT_PRIO_HIGH == mssp->mssp_prio){
            INTERRUPT_GlobalInterruptHighEnable();
            I2C_INTERRUPT_HIGH_PRIO();
        }
        else if(INTERRUPT_PRIO_LOW == mssp->mssp_prio){
            INTERRUPT_GlobalInterruptLowEnable();
            I2C_INTERRUPT_LOW_PRIO();
        }
        else{}
        
        if(INTERRUPT_PRIO_HIGH == mssp->bus_prio){
            INTERRUPT_GlobalInterruptHighEnable();
            I2C_BUS_Col_INTERRUPT_HIGH_PRIO();
        }
        else if(INTERRUPT_PRIO_LOW == mssp->bus_prio){
            INTERRUPT_GlobalInterruptLowEnable();
            I2C_BUS_Col_INTERRUPT_LOW_PRIO();
        }
        else{}
#else
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralEnable();
#endif
#endif
       I2C_Module_Enable_CFG();
    }
    return ret;
}
STD_ReturnType MSSP_I2C_DeInit(const mssp_i2c_t *mssp){
     STD_ReturnType ret = E_OK;
    if(NULL == mssp){
        ret = E_NOK;
    }
    else{
       I2C_Module_Disable_CFG();
        #if I2C_INTERRUPT_FEATURE_ENABLE
        I2C_Interrupt_Disable();
        I2C_BUS_Col_Interrupt_Disable();
        #endif
    }
    return ret;
}
STD_ReturnType MSSP_I2C_Master_Send_Start(const mssp_i2c_t *mssp){
     STD_ReturnType ret = E_OK;
    if(NULL == mssp){
        ret = E_NOK;
    }
    else{
        SSPCON2bits.SEN = 1;
        while(SSPCON2bits.SEN);
        PIR1bits.SSPIF = 0;
        if(I2C_Start_Bit_Detected == SSPSTATbits.S){
            ret = E_OK;
        }
        else if(I2C_Start_Bit_Not_Detected == SSPSTATbits.S){
            ret = E_NOK;
        }
        else{}
    }
    return ret;
}
STD_ReturnType MSSP_I2C_Master_Send_Repeasted_Start(const mssp_i2c_t *mssp){
     STD_ReturnType ret = E_OK;
    if(NULL == mssp){
        ret = E_NOK;
    }
    else{
      SSPCON2bits.RSEN = 1;
      while(SSPCON2bits.RSEN);
       PIR1bits.SSPIF = 0;
    }
    return ret;
}
STD_ReturnType MSSP_I2C_Master_Send_Stop(const mssp_i2c_t *mssp){
     STD_ReturnType ret = E_OK;
    if(NULL == mssp){
        ret = E_NOK;
    }
    else{
        SSPCON2bits.PEN = 1;
       while(SSPCON2bits.PEN);
       PIR1bits.SSPIF = 0;
       if(I2C_Stop_Bit_Detected == SSPSTATbits.P){
            ret = E_OK;
        }
        else if(I2C_Stop_Bit_Not_Detected == SSPSTATbits.P){
            ret = E_NOK;
        }
        else{}
    }
    return ret;
}
STD_ReturnType MSSP_I2C_Master_Write(const mssp_i2c_t *mssp, uint32 data_, uint8 *_ack){
     STD_ReturnType ret = E_OK;
    if(NULL == mssp){
        ret = E_NOK;
    }
    else{
        SSPBUF = data_;
        while(!PIR1bits.SSPIF);
        PIR1bits.SSPIF = 0;
        if(I2C_ACK_RECEIVED_FROM_SLAVE == SSPCON2bits.ACKSTAT){
            *_ack = I2C_ACK_RECEIVED_FROM_SLAVE; /* Acknowledge was received from slave */
        }
        else{
            *_ack = I2C_ACK_NOT_RECEIVED_FROM_SLAVE; /* Acknowledge was not received from slave */
        }
    }
    return ret;
}
STD_ReturnType MSSP_I2C_Master_Read(const mssp_i2c_t *mssp, uint8 ack, uint32 *data_){
     STD_ReturnType ret = E_OK;
    if((NULL == mssp) || (NULL == data_)){
        ret = E_NOK;
    }
    else{
       I2C_Master_Receive_Enable_CFG();
       while(!SSPSTATbits.BF);
       *data_ = SSPBUF;
       if(I2C_MASTER_SEND_ACK == ack){
           SSPCON2bits.ACKDT = 0;
           SSPCON2bits.ACKEN = 1;
       }
       else if(I2C_MASTER_SEND_NOT_ACK == ack){
           SSPCON2bits.ACKDT = 1;
           SSPCON2bits.ACKEN = 1;
       }
       else{}
    }
    return ret;
}

static inline void MSSP_I2C_MODE_GPIO_CFG(void){
    TRISCbits.TRISC3 = 1;
    TRISCbits.TRISC4 = 1;
}

static inline void I2C_Master_Clock_CFG(const mssp_i2c_t *mssp){
    SSPCON1bits.SSPM = mssp->i2c_cfg.i2c_cfg_mode;
    SSPADD = (uint8)(((_XTAL_FREQ / 4.0)/mssp->i2c_clock) - 1);
}
static inline void I2C_Slave_Clock_CFG(const mssp_i2c_t *mssp){
    SSPCON1bits.SSPM = mssp->i2c_cfg.i2c_cfg_mode;
}