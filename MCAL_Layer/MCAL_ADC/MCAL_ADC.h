/* 
 * File:   MCAL_ADC.h
 * Author: Eng.Yassmin
 *
 * Created on November 11, 2024, 1:51 PM
 */

#ifndef MCAL_ADC_H
#define	MCAL_ADC_H
/* Includes Section */
#include <xc.h>
#include "MCAL_ADC_CFG.h"
#include "../MCAL_STD_TYPES.h"
#include "../GPIO/HAL_GPIO.h"
#include "../MCAL_Interrupts/MCAL_Internal_Interrupt.h"
/* Macro Declaration Section */
#define ADC_AN0_ANALOG_FUNC     0x0E
#define ADC_AN1_ANALOG_FUNC     0x0D
#define ADC_AN2_ANALOG_FUNC     0x0C
#define ADC_AN3_ANALOG_FUNC     0x0B
#define ADC_AN4_ANALOG_FUNC     0x0A
#define ADC_AN5_ANALOG_FUNC     0x09
#define ADC_AN6_ANALOG_FUNC     0x08
#define ADC_AN7_ANALOG_FUNC     0x07
#define ADC_AN8_ANALOG_FUNC     0x06
#define ADC_AN9_ANALOG_FUNC     0x05
#define ADC_AN10_ANALOG_FUNC    0x04
#define ADC_AN11_ANALOG_FUNC    0x03
#define ADC_AN12_ANALOG_FUNC    0x02
#define ADC_ALL_ANALOG_FUNC     0x01
#define ADC_ALL_DIGITAL_FUNC    0x0F

#define ADC_RESULT_RIGHT   0x01
#define ADC_RESULT_LEFT    0x00

#define ADC_VOLTAGE_REFERENCE_ENABLE   0x01
#define ADC_VOLTAGE_REFERENCE_DISABLE  0x00

#define ADC_CONVERSION_COMPLETED      0x01
#define ADC_CONVERSION_UNCOMPLETED    0x00


/* Macro Function Declaration Section */
#define ADC_CONVERSION_STATUS() (ADCON0bits.GO_nDONE)

#define ADC_CONVERSION_START()  (ADCON0bits.GODONE = 1)

#define ADC_CONVERTER_ENABLE()  (ADCON0bits.ADON = 1)
#define ADC_CONVERTER_DISABLE() (ADCON0bits.ADON = 0)

#define ADC_ENABLE_VOLTAGE_REFERENCE()  do{ADCON1bits.VCFG1 = 1;\
                                          ADCON1bits.VCFG0 = 1;\
                                          }while(0)
#define ADC_DISABLE_VOLTAGE_REFERENCE() do{ADCON1bits.VCFG1 = 0;\
                                          ADCON1bits.VCFG0 = 0;\
                                          }while(0)

#define ADC_ANALOG_DIGITAL_PORT_CFG(_CONFIG)    (ADCON1bits.PCFG = _CONFIG)

#define ADC_LEFT_FORMAT()    (ADCON2bits.ADFM = 0);
#define ADC_RIGHT_FORMAT()   (ADCON2bits.ADFM = 1);
/* Data Type Section */
typedef enum {
    channel_1 = 0,
    channel_2,
    channel_3,
    channel_4,
    channel_5,
    channel_6,
    channel_7,
    channel_8,
    channel_9,
    channel_10,
    channel_11,
    channel_12,
    channel_13  
    
}ADC_CHANNEL_SELECT_t;

typedef enum{
    ADC_0_TAD = 0,
    ADC_2_TAD,
    ADC_4_TAD,
    ADC_6_TAD,
    ADC_8_TAD,
    ADC_12_TAD,
    ADC_16_TAD,
    ADC_20_TAD
    
}ADC_AQUISITION_TIME_t;

typedef enum{
    ADC_CONVERSION_CLOCK_FOSC_DIV_2 = 0,
    ADC_CONVERSION_CLOCK_FOSC_DIV_8,
    ADC_CONVERSION_CLOCK_FOSC_DIV_32,
    ADC_CONVERSION_CLOCK_FOSC_DIV_FRC,
    ADC_CONVERSION_CLOCK_FOSC_DIV_4,
    ADC_CONVERSION_CLOCK_FOSC_DIV_16,
    ADC_CONVERSION_CLOCK_FOSC_DIV_64
    
}ADC_CONVERSION_CLOCK_t;

typedef struct{
#if ADC_INTERRUPT_FEATURE_ENABLE
    void (*ADC_InterruptHandler)(void);
#if INTERRUPT_PRIO_LEVEL_ENABLE
    Interrupt_Prio_t Priority;
#endif
#endif
    ADC_CHANNEL_SELECT_t channel;
    ADC_AQUISITION_TIME_t aquisition_time;
    ADC_CONVERSION_CLOCK_t conversion_clock;
    uint8 voltage_reference  :1;
    uint8 result_format      :1;
    uint8  ADC_RESERVED      :6;
}ADC_CONFIG_t;
/* Function Declaration Section */
STD_ReturnType ADC_Init(const ADC_CONFIG_t *adc);
STD_ReturnType ADC_Deinit(const ADC_CONFIG_t *adc);
STD_ReturnType ADC_SELECT_CHANNEL(const ADC_CONFIG_t *adc, ADC_CHANNEL_SELECT_t channel);
STD_ReturnType ADC_START_CONVERSION(const ADC_CONFIG_t *adc);
STD_ReturnType ADC_CONVERSION_STATUS_(const ADC_CONFIG_t *adc, uint8 *conversion_status);
STD_ReturnType ADC_CONVERSION_RESULT(const ADC_CONFIG_t *adc, uint16 *conversion_result);
STD_ReturnType ADC_CONVERSION(const ADC_CONFIG_t *adc, uint16 *conversion_result, ADC_CHANNEL_SELECT_t channel);
STD_ReturnType ADC_CONVERSION_INTERRUPT(const ADC_CONFIG_t *adc, ADC_CHANNEL_SELECT_t channel);

#endif	/* MCAL_ADC_H */

