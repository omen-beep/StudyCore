/* 
 * File:   MCAL_STD_TYPES.h
 * Author: Eng.Yassmin
 *
 * Created on September 29, 2024, 1:29 PM
 */


#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/* Includes Section */
#include "STD_Lib.h"
#include "Compiler.h"
/* Macro Declaration Section */
#define STD_HIGH       0x01
#define STD_LOW        0x00

#define CONFIG_ENABLE  0x01
#define CONFIG_DISABLE 0x00

#define STD_ON         0x01
#define STD_OFF        0x00

#define STD_ACTIVE     0x01
#define STD_IDLE       0x00

#define E_OK           (STD_ReturnType)0x01
#define E_NOK          (STD_ReturnType)0x00

#define ZERO_INIT      0x00
/* Macro Function Declaration Section */

/* Data Type Section */
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;

typedef uint8 STD_ReturnType;

/* Function Declaration Section */


#endif	/* MCAL_STD_TYPES_H */

