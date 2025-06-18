/* 
 * File:   MCAL_USART.h
 * Author: Eng.Yassmin
 *
 * Created on December 9, 2024, 2:14 PM
 */

#ifndef MCAL_USART_H
#define	MCAL_USART_H
/* Includes Section */
#include <xc.h>
#include "../GPIO/HAL_GPIO.h"
#include "../MCAL_STD_TYPES.h"
#include "../MCAL_Interrupts/MCAL_Internal_Interrupt.h"
#include "MCAL_USART_CFG.h"
/* Macro Declaration Section */
#define USART_ENABLE                1
#define USART_DISABLE               0

#define USART_SYNC_MODE             1
#define USART_ASYNC_MODE            0

#define USART_ASYNC_HIGH_SPEED      1
#define USART_ASYNC_LOW_SPEED       0

#define USART_16BIT_BAURDRATE_GEN   1
#define USART_8BIT_BAURDRATE_GEN    0

#define USART_ASYNC_TX_ENABLE       1
#define USART_ASYNC_TX_DISABLE      0

#define USART_ASYNC_INTERRUPT_TX_ENABLE       1
#define USART_ASYNC_INTERRUPT_TX_DISABLE      0

#define USART_ASYNC_9BIT_TX_ENABLE            1
#define USART_ASYNC_9BIT_TX_DISABLE           0

#define USART_ASYNC_RX_ENABLE       1
#define USART_ASYNC_RX_DISABLE      0

#define USART_ASYNC_INTERRUPT_RX_ENABLE       1
#define USART_ASYNC_INTERRUPT_RX_DISABLE      0

#define USART_ASYNC_9BIT_RX_ENABLE            1
#define USART_ASYNC_9BIT_RX_DISABLE           0

#define USART_FRAMING_ERROR_DETECTED          1
#define USART_FRAMING_ERROR_CLEARED           0

#define USART_OVERRUN_ERROR_DETECTED          1
#define USART_OVERRUN_ERROR_CLEARED           0
/* Macro Function Declaration Section */

/* Data Type Section */
typedef enum{
    BAUDRATE_ASYN_8BIT_LOW_SPEED,
    BAUDRATE_ASYN_8BIT_HIGH_SPEED,
    BAUDRATE_ASYN_16BIT_LOW_SPEED,
    BAUDRATE_ASYN_16BIT_HIGH_SPEED,
    BAUDRATE_SYNC_8BIT,
    BAUDRATE_SYNC_16BIT  
}BAUDRATE_GEN_t;

typedef struct{
    uint8 USART_TX_ENABLE              :1;
    uint8 USART_INTERRUPT_TX_ENABLE    :1;
    uint8 USART_9BIT_TX_ENABLE         :1;
    uint8 reserved                     :5;
}USART_TX_CFG_t;

typedef struct{
    uint8 USART_RX_ENABLE              :1;
    uint8 USART_INTERRUPT_RX_ENABLE    :1;
    uint8 USART_9BIT_RX_ENABLE         :1;
    uint8 reserved                     :5;
}USART_RX_CFG_t;

typedef union{
    struct{
        uint8 USART_FRAME_ERROR        :1;
        uint8 USART_OVERRUN_ERROR      :1;
        uint8 reserved                 :6;
    };
    uint8 status;
}USART_ERROR_STATUS_t;

typedef struct{
    uint32 baud_rate_value;
    BAUDRATE_GEN_t baud_rate_cfg;
    USART_TX_CFG_t tx_cfg;
    USART_RX_CFG_t rx_cfg;
    USART_ERROR_STATUS_t error_status;
    
    void (*FERR_InterruptHandler)(void);
    void (*OERR_InterruptHandler)(void);
    
    #if USART_TX_INTERRUPT_FEATURE_ENABLE
    void (*TX_InterruptHandler)(void);
    #if INTERRUPT_PRIO_LEVEL_ENABLE
    Interrupt_Prio_t Priority_TX;
    #endif
    #endif

    #if USART_RX_INTERRUPT_FEATURE_ENABLE
    void (*RX_InterruptHandler)(void);
    #if INTERRUPT_PRIO_LEVEL_ENABLE
    Interrupt_Prio_t Priority_RX;
    #endif
    #endif

}USART_t;
/* Function Declaration Section */
STD_ReturnType USART_ASYNC_INIT(const USART_t *usart);
STD_ReturnType USART_ASYNC_DEINIT(const USART_t *usart);

STD_ReturnType USART_ASYNC_ReadByte_Blocking(const USART_t *usart, uint8 *data);
STD_ReturnType USART_ASYNC_ReadByte(const USART_t *usart, uint8 *data);
STD_ReturnType USART_ASYNC_RX_Restart(void);

STD_ReturnType USART_ASYNC_WriteByte_Blocking(const USART_t *usart, uint8 data);
STD_ReturnType USART_ASYNC_WriteString_Blocking(const USART_t *usart, uint8 *data, uint16 str_len);

STD_ReturnType USART_ASYNC_WriteByte(const USART_t *usart, uint8 data);
STD_ReturnType USART_ASYNC_WriteString(const USART_t *usart, uint8 *data, uint16 str_len);
#endif	/* MCAL_USART_H */

