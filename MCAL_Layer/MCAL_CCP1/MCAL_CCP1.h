/* 
 * File:   MCAL_CCP1.h
 * Author: Eng.Yassmin
 *
 * Created on November 26, 2024, 1:32 PM
 */

#ifndef MCAL_CCP1_H
#define	MCAL_CCP1_H
/* Includes Section */
#include <xc.h>
#include "../GPIO/HAL_GPIO.h"
#include "../MCAL_STD_TYPES.h"
#include "../MCAL_Interrupts/MCAL_Internal_Interrupt.h"
#include "MCAL_CCP1_CFG.h"
#include "../../MCAL_Layer/MCAL_TIMER2/MCAL_TIMER2.h"
/* Macro Declaration Section */
/* CCP1 Module Mode Select  */
#define CCP_MODULE_DISABLE                 ((uint8)0x00)
#define CCP_CAPTURE_MODE_1_FALLING_EDGE    ((uint8)0x04)
#define CCP_CAPTURE_MODE_1_RISING_EDGE     ((uint8)0x05)
#define CCP_CAPTURE_MODE_4_RISING_EDGE     ((uint8)0x06)
#define CCP_CAPTURE_MODE_16_RISING_EDGE    ((uint8)0x07)
#define CCP_COMPARE_MODE_SET_PIN_LOW       ((uint8)0x08)
#define CCP_COMPARE_MODE_SET_PIN_HIGH      ((uint8)0x09)
#define CCP_COMPARE_MODE_TOGGLE_ON_MATCH   ((uint8)0x02)
#define CCP_COMPARE_MODE_GEN_SW_INTERRUPT  ((uint8)0x0A)
#define CCP_COMPARE_MODE_GEN_EVENT         ((uint8)0x0B)
#define CCP_PWM_MODE                       ((uint8)0x0C)

/* CCP1 Capture Mode State  */
#define CCP1_CAPTURE_NOT_READY              0X00
#define CCP1_CAPTURE_READY                  0X01

/* CCP1 Compare Mode State  */
#define CCP1_COMPARE_NOT_READY              0X00
#define CCP1_COMPARE_READY                  0X01
/* Macro Function Declaration Section */
#define CCP1_SET_MODE(_CONFIG)  (CCP1CONbits.CCP1M = _CONFIG)
#define CCP2_SET_MODE(_CONFIG)  (CCP2CONbits.CCP2M = _CONFIG)
/* Data Type Section */
typedef enum{
    CCP_CAPTURE_MODE_SELECTED = 0, /* Select CCP1 Capture Mode */
    CCP_COMPARE_MODE_SELECTED,     /* Select CCP1 Compare Mode */
    CCP_PWM_MODE_SELECTED          /* Select CCP1 PWM Mode */
}ccp1_mode_t;

typedef union{
    struct{
        uint8 ccpr_low;  /* CCPR1 low register */
        uint8 ccpr_high; /* CCPR1 high register */
    };
    struct{
        uint16 ccpr_16Bit; /* Read CCPR1 as a 16 Bit value */
    };
}CCP_REG_T;

typedef enum{
    CCP1_INST = 0,
    CCP2_INST
}ccp_inst_t;

typedef enum{
    CCP1_CCP2_TIMER3 = 0,
    CCP1_TIMER1_CCP2_TIMER3,
    CCP1_CCP2_TIMER1
}ccp_capture_timer_t;

/*
  @Summary      CCP Module configurations
  @Description  This data type used to describe the module initialization configuration
*/
typedef struct{
    ccp_inst_t ccp_inst;
    ccp1_mode_t ccp_mode;      /* CCP main mode */
    uint8 ccp_mode_variant;    /* CCP selected mode variant */
    pin_config_t ccp_pin;      /* CCP Pin I/O configurations */
    ccp_capture_timer_t ccp_capture_timer;
#if (CCP1_CFG_MODE_SELECTED==CCP_CFG_PMW_MODE) || (CCP2_CFG_MODE_SELECTED==CCP_CFG_PMW_MODE)
    uint32 PWM_Frequency;      /* CCP PWM mode frequency */
    uint8 timer2_postscaler_value : 4;
    uint8 timer2_prescaler_value : 2;
#endif
#if CCP1_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    void (* CCP1_InterruptHandler)(void);   /* Call back used for all CCP1 Modes */
    Interrupt_Prio_t CCP1_priority;   /* Configure the CCP1 mode interrupt */
#endif
#if CCP2_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    void (* CCP2_InterruptHandler)(void);   /* Call back used for all CCP2 Modes */
    Interrupt_Prio_t CCP2_priority;   /* Configure the CCP1 mode interrupt */
#endif
}ccp_t;

/* ----------------- Software Interfaces Declarations -----------------*/
STD_ReturnType CCP_Init(const ccp_t *_ccp_obj);
STD_ReturnType CCP_DeInit(const ccp_t *_ccp_obj);

#if (CCP1_CFG_MODE_SELECTED==CCP_CAPTURE_MODE_MODE)
STD_ReturnType CCP1_IsCapturedDataReady(uint8 *_capture_status);
STD_ReturnType CCP1_Capture_Mode_Read_Value(uint16 *capture_value);
#endif

#if (CCP1_CFG_MODE_SELECTED==CCP_COMPARE_MODE_MODE)
STD_ReturnType CCP_IsCompareComplete(uint8 *_compare_status);
STD_ReturnType CCP_Compare_Mode_Set_Value(const ccp_t *_ccp_obj, uint16 compare_value);
#endif

#if (CCP1_CFG_MODE_SELECTED==CCP_CFG_PMW_MODE)
STD_ReturnType CCP_PWM_Set_Duty(const ccp_t *_ccp_obj, const uint8 _duty);
STD_ReturnType CCP_PWM_Start(const ccp_t *_ccp_obj);
STD_ReturnType CCP_PWM_Stop(const ccp_t *_ccp_obj);
#endif
#endif	/* MCAL_CCP1_H */

