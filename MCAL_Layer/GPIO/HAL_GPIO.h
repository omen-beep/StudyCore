/* 
 * File:   HAL_GPIO.h   
 * Author: Eng.Yasmine
 *
 * Created on September 29, 2024, 1:00 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H
/* Includes Section */
//#include <pic18f4620.h>
#include "../MCAL_STD_TYPES.h"
#include "../Device_Config.h"
#include "HAL_GPIO_CFG.h"
/* Macro Declaration Section */
#define BIT_MASK                1
#define PORT_PIN_MAX_NUMBER     8
#define PORT_MAX_NUMBER         5
#define PORT_MASK              0xFF

/* Macro Function Declaration Section */
#define HWREG8(_X)      (*((volatile uint8)(_X)))

#define SET_BIT(REG, BIT_POSN)        (REG |= (BIT_MASK << BIT_POSN))
#define CLEAR_BIT(REG, BIT_POSN)      (REG &= ~(BIT_MASK << BIT_POSN))
#define TOGGLE_BIT(REG, BIT_POSN)     (REG ^= (BIT_MASK << BIT_POSN))
#define READ_BIT(REG, BIT_POSN)       (REG >> BIT_POSN & BIT_MASK)
#define _XTAL_FREQ 8000000
/* Data Type Section */
typedef enum{
    LOW = 0,
    HIGH
}logic_t;

typedef enum{
    OUTPUT = 0,
    INPUT
}direction_t;

typedef enum{
    pin0 = 0,
    pin1,
    pin2,
    pin3,
    pin4,
    pin5,
    pin6,
    pin7
}pin_index_t;

typedef enum{
    PORTA_INDEX = 0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_index_t;

typedef struct{
    uint8 port      : 3; /* #ref port_index_t*/
    uint8 pin       : 3; /* #ref pin_index_t*/
    uint8 direction : 1; /* #ref direction_t*/
    uint8 logic     : 1; /* #ref logic_t*/
}pin_config_t;

/* Function Declaration Section */
STD_ReturnType gpio_pin_direction_init(const pin_config_t *pin_config);
STD_ReturnType gpio_pin_direction_status(const pin_config_t *pin_config, direction_t *direction_status);
STD_ReturnType gpio_pin_write_logic(const pin_config_t *pin_config, logic_t logic);
STD_ReturnType gpio_pin_read_logic(const pin_config_t *pin_config, logic_t *logic);
STD_ReturnType gpio_pin_toggle_logic(const pin_config_t *pin_config);
STD_ReturnType gpio_pin_init(const pin_config_t *pin_config);

STD_ReturnType gpio_port_direction_init(port_index_t port, uint8 direction);
STD_ReturnType gpio_port_direction_status(port_index_t port, uint8 *direction_status);
STD_ReturnType gpio_pport_write_logic(port_index_t port, uint8 logic);
STD_ReturnType gpio_port_read_logic(port_index_t port, uint8 *logic);
STD_ReturnType gpio_port_toggle_logic(port_index_t port);
#endif	/* HAL_GPIO_H */

