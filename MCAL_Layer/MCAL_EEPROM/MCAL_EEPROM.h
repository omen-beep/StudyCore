/* 
 * File:   MCAL_EEPROM.h
 * Author: Eng.Yassmin
 *
 * Created on November 8, 2024, 12:36 PM
 */

#ifndef MCAL_EEPROM_H
#define	MCAL_EEPROM_H
/* Includes Section */
#include <xc.h>
#include "../MCAL_STD_TYPES.h"
#include "../MCAL_Interrupts/MCAL_Internal_Interrupt.h"
/* Macro Declaration Section */
#define ACCESS_FLASH_PROGRAM_MEMORY   1
#define ACCESS_EEPROM_PROGRAM_MEMORY  0

#define ACCESS_CONFIG_REGISTERS       1
#define ACCESS_FLASH_EEPROM_MEMORY    0

#define ALLOW_WRITE_CYCLE_FLASH_EEPROM       1
#define INHIBIT_WRITE_CYCLE_FLASH_EEPROM     0

#define INIT_EEPROM_DATA_WRITE_ERASE_CYCLE   1
#define EEPROM_DATA_WRITE_ERASE_CYCLE_COMP   0

#define INIT_EEPROM_DATA_READ_CYCLE      1
#define INHIBIT_EEPROM_DATA_READ_CYCLE   0

/* Macro Function Declaration Section */

/* Data Type Section */

/* Function Declaration Section */
STD_ReturnType DATA_EEPROM_WriteByte(uint16 bAdd, uint16 bData);
STD_ReturnType DATA_EEPROM_ReadByte(uint16 bAdd, uint16 *bData);

#endif	/* MCAL_EEPROM_H */

