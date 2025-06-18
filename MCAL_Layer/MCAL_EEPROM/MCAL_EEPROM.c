#include "MCAL_EEPROM.h"

STD_ReturnType DATA_EEPROM_WriteByte(uint16 bAdd, uint16 bData){
    STD_ReturnType ret = E_OK;
    uint8 Global_Interrupt_Status = INTCONbits.GIE;
    EEADRH = (uint8)((bAdd >> 8) & 0x03);
    EEADR = (uint8)(bAdd & 0xFF);
    //EEDATA = bData;
    EECON1bits.EEPGD = ACCESS_EEPROM_PROGRAM_MEMORY;
    EECON1bits.CFGS = ACCESS_FLASH_EEPROM_MEMORY;
    EECON1bits.WREN = ALLOW_WRITE_CYCLE_FLASH_EEPROM;

    ret = INTERRUPT_GlobalInterruptDisable();

    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = INIT_EEPROM_DATA_WRITE_ERASE_CYCLE;
    while(EECON1bits.WR);
    EECON1bits.WREN = INHIBIT_WRITE_CYCLE_FLASH_EEPROM;
    INTCONbits.GIE = Global_Interrupt_Status;
    
    return ret;
}

STD_ReturnType DATA_EEPROM_ReadByte(uint16 bAdd, uint16 *bData){
    STD_ReturnType ret = E_OK;
    if(NULL == bData){
        ret = E_NOK;
    }
    else{
    EEADRH = (uint8)((bAdd >> 8) & 0x03);
    EEADR = (uint8)(bAdd & 0xFF);
    EECON1bits.EEPGD = ACCESS_EEPROM_PROGRAM_MEMORY;
    EECON1bits.CFGS = ACCESS_FLASH_EEPROM_MEMORY;
    EECON1bits.RD = INIT_EEPROM_DATA_READ_CYCLE;
    NOP();
    NOP();
    *bData = EEDATA;
    
    }
    return ret;
}