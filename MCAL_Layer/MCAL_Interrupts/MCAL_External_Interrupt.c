#include "MCAL_External_Interrupt.h"


static void (*INT0_InterruptHandler) (void) = NULL;
static void (*INT1_InterruptHandler) (void) = NULL;
static void (*INT2_InterruptHandler) (void) = NULL;

static void (*RB4_InterruptHandler_HIGH) (void) = NULL;
static void (*RB4_InterruptHandler_LOW) (void) = NULL;

static void (*RB5_InterruptHandler_HIGH) (void) = NULL;
static void (*RB5_InterruptHandler_LOW) (void) = NULL;

static void (*RB6_InterruptHandler_HIGH) (void) = NULL;
static void (*RB6_InterruptHandler_LOW) (void) = NULL;

static void (*RB7_InterruptHandler_HIGH) (void) = NULL;
static void (*RB7_InterruptHandler_LOW) (void) = NULL;

static STD_ReturnType Interrupt_INTx_Enable(const Interrupt_INTx_t *int_obj);
static STD_ReturnType Interrupt_INTx_Disable(const Interrupt_INTx_t *int_obj);
static STD_ReturnType Interrupt_INTx_Edge_Init(const Interrupt_INTx_t *int_obj);
static STD_ReturnType Interrupt_INTx_Priority_Init(const Interrupt_INTx_t *int_obj);
static STD_ReturnType Interrupt_INTx_Pin_Init(const Interrupt_INTx_t *int_obj);
static STD_ReturnType Interrupt_INTx_Clear_Flag(const Interrupt_INTx_t *int_obj);

static STD_ReturnType Interrupt_INT0_Handler(void (*INT_InterruptHandler) (void));
static STD_ReturnType Interrupt_INT1_Handler(void (*INT_InterruptHandler) (void));
static STD_ReturnType Interrupt_INT2_Handler(void (*INT_InterruptHandler) (void));
static STD_ReturnType Interrupt_INTx_Handler(const Interrupt_INTx_t *int_obj);

void RB4_ISR(uint8 RB4_SRC){
    EXT_RBx_Interrupt_Flag_Clear() ;
    /* code */
    if(HIGH==RB4_SRC){
        if(RB4_InterruptHandler_HIGH){
        RB4_InterruptHandler_HIGH();}
    }
    else if (LOW == RB4_SRC){
         if(RB4_InterruptHandler_LOW){
        RB4_InterruptHandler_LOW();}
    }
    else {}
}

void RB5_ISR(uint8 RB5_SRC){
    EXT_RBx_Interrupt_Flag_Clear() ;
    /* code */
    if(HIGH==RB5_SRC){
         if(RB5_InterruptHandler_HIGH){
        RB5_InterruptHandler_HIGH();}
    }
    else if (LOW == RB5_SRC){
         if(RB5_InterruptHandler_LOW){
        RB5_InterruptHandler_LOW();}
    }
    else {}
}
void RB6_ISR(uint8 RB6_SRC){
    EXT_RBx_Interrupt_Flag_Clear() ;
    /* code */
    if(HIGH==RB6_SRC){
         if(RB6_InterruptHandler_HIGH){
        RB6_InterruptHandler_HIGH();}
    }
    else if (LOW == RB6_SRC){
         if(RB6_InterruptHandler_LOW){
        RB6_InterruptHandler_LOW();}
    }
    else {}
}
void RB7_ISR(uint8 RB7_SRC){
    EXT_RBx_Interrupt_Flag_Clear() ;
    /* code */
    if(HIGH==RB7_SRC){
         if(RB7_InterruptHandler_HIGH){
        RB7_InterruptHandler_HIGH();}
    }
    else if (LOW == RB7_SRC){
         if(RB7_InterruptHandler_LOW){
        RB7_InterruptHandler_LOW();}
    }
    else {}
}


void INT0_ISR(void){
    EXT_INT0_Interrupt_Flag_Clear();
    /* code */
    if(INT0_InterruptHandler){
        INT0_InterruptHandler();
    }
}

void INT1_ISR(void){
    EXT_INT1_Interrupt_Flag_Clear();
    /* code */
    if(INT1_InterruptHandler){
        INT1_InterruptHandler();
    }
}

void INT2_ISR(void){
    EXT_INT2_Interrupt_Flag_Clear();
    /* code */
    if(INT2_InterruptHandler){
        INT2_InterruptHandler();
    }
}

STD_ReturnType Interrupt_INTx_Init(const Interrupt_INTx_t *int_obj){
    STD_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOK;
    }
    else{
        ret = Interrupt_INTx_Disable(int_obj);
        ret |= Interrupt_INTx_Clear_Flag(int_obj);
        ret |= Interrupt_INTx_Edge_Init(int_obj);
        #if INTERRUPT_PRIO_LEVEL_ENABLE==INTERRUPT_FEATURE_ENABLE
        ret |= Interrupt_INTx_Priority_Init(int_obj);
        #endif
        ret |= Interrupt_INTx_Pin_Init(int_obj);
        ret |= Interrupt_INTx_Handler(int_obj); //callback
        ret |= Interrupt_INTx_Enable(int_obj);
        
        
        
        
        
    }
    return ret;
}
STD_ReturnType Interrupt_INTx_DeInit(const Interrupt_INTx_t *int_obj){
    STD_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOK;
    }
    else{
        Interrupt_INTx_Disable(int_obj);
    }
    return ret;
}

STD_ReturnType Interrupt_RBx_Init(const Interrupt_RBx_t *int_obj){
    STD_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOK;
    }
    else{
        EXT_RBx_Interrupt_Disable();
        EXT_RBx_Interrupt_Flag_Clear();
        #if INTERRUPT_PRIO_LEVEL_ENABLE==INTERRUPT_FEATURE_ENABLE
                    INTERRUPT_PriorityEnable();
                if(INTERRUPT_PRIO_LOW == int_obj->Priority){
                    INTERRUPT_GlobalInterruptLowEnable();
                    EXT_RBx_PRIO_LOW();}
                else if(INTERRUPT_PRIO_HIGH == int_obj->Priority){
                    INTERRUPT_GlobalInterruptHighEnable();
                    EXT_RBx_PRIO_HIGH();}
                else{}
        #else
                INTERRUPT_GlobalInterruptEnable();
                INTERRUPT_PeripheralEnable();
        #endif
                ret = gpio_pin_init(&(int_obj->MCU_Pin));
                
                switch(int_obj->MCU_Pin.pin){
                case(pin4):
                    RB4_InterruptHandler_HIGH = int_obj->Interrupt_CallBack_HIGH;
                    RB4_InterruptHandler_LOW = int_obj->Interrupt_CallBack_LOW;
                break;
                case(pin5):
                    RB5_InterruptHandler_HIGH = int_obj->Interrupt_CallBack_HIGH;
                    RB5_InterruptHandler_LOW = int_obj->Interrupt_CallBack_LOW;
                break;
                case(pin6):
                    RB6_InterruptHandler_HIGH = int_obj->Interrupt_CallBack_HIGH;
                    RB6_InterruptHandler_LOW = int_obj->Interrupt_CallBack_LOW;
                break;
                case(pin7):
                    RB7_InterruptHandler_HIGH = int_obj->Interrupt_CallBack_HIGH;
                    RB7_InterruptHandler_LOW = int_obj->Interrupt_CallBack_LOW;
                break;
                default:
                    ret = E_NOK;
                    break;
                }
        EXT_RBx_Interrupt_Enable();
    }
    return ret;
}
STD_ReturnType Interrupt_RBx_DeInit(const Interrupt_RBx_t *int_obj){
    STD_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOK;
    }
    else{
        ret = EXT_RBx_Interrupt_Disable();
    }
    return ret;
}


static STD_ReturnType Interrupt_INTx_Enable(const Interrupt_INTx_t *int_obj){
    STD_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOK;
    }
    else{
        switch(int_obj->Source){
            case(INTERRUPT_EXT_INT0):
                #if INTERRUPT_PRIO_LEVEL_ENABLE==INTERRUPT_FEATURE_ENABLE
                    INTERRUPT_PriorityEnable();
                    INTERRUPT_GlobalInterruptHighEnable();
                #else
                INTERRUPT_GlobalInterruptEnable();
                INTERRUPT_PeripheralEnable();
                #endif
                EXT_INT0_Interrupt_Enable();
                break;
            case(INTERRUPT_EXT_INT1):
                #if INTERRUPT_PRIO_LEVEL_ENABLE==INTERRUPT_FEATURE_ENABLE
                    INTERRUPT_PriorityEnable();
                if(INTERRUPT_PRIO_LOW == int_obj->Priority){
                    INTERRUPT_GlobalInterruptLowEnable();}
                else if(INTERRUPT_PRIO_HIGH == int_obj->Priority){
                    INTERRUPT_GlobalInterruptHighEnable();}
                else{}
                #else
                INTERRUPT_GlobalInterruptEnable();
                INTERRUPT_PeripheralEnable();
                #endif
                EXT_INT1_Interrupt_Enable();
                break;
            case(INTERRUPT_EXT_INT2):
                #if INTERRUPT_PRIO_LEVEL_ENABLE==INTERRUPT_FEATURE_ENABLE
                    INTERRUPT_PriorityEnable();
                if(INTERRUPT_PRIO_LOW == int_obj->Priority){
                    INTERRUPT_GlobalInterruptLowEnable();}
                else if(INTERRUPT_PRIO_HIGH == int_obj->Priority){
                    INTERRUPT_GlobalInterruptHighEnable();}
                else{}
                #else
                INTERRUPT_GlobalInterruptEnable();
                INTERRUPT_PeripheralEnable();
                #endif
                EXT_INT2_Interrupt_Enable();
                break;
            default:
                ret = E_NOK;
                break;
        }
    }
    return ret;
}

static STD_ReturnType Interrupt_INTx_Disable(const Interrupt_INTx_t *int_obj){
    STD_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOK;
    }
    else{
        switch(int_obj->Source){
            case(INTERRUPT_EXT_INT0):
                EXT_INT0_Interrupt_Disable();
                break;
            case(INTERRUPT_EXT_INT1):
                EXT_INT1_Interrupt_Disable();
                break;
            case(INTERRUPT_EXT_INT2):
                EXT_INT2_Interrupt_Disable();
                break;
            default:
                ret = E_NOK;
                break;
        }
    }
    return ret;
}
static STD_ReturnType Interrupt_INTx_Edge_Init(const Interrupt_INTx_t *int_obj){
    STD_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOK;
    }
    else{
         switch(int_obj->Source){
            case(INTERRUPT_EXT_INT0):
                if(INTERRUPT_FALLING_EDGE == int_obj->Edge){
                    EXT_INT0_FallingEdge();}
                else if(INTERRUPT_RISING_EDGE == int_obj->Edge){
                    EXT_INT0_RisingEdge();}
                else{}
                break;
            case(INTERRUPT_EXT_INT1):
                if(INTERRUPT_FALLING_EDGE == int_obj->Edge){
                    EXT_INT1_FallingEdge(); }
                else if(INTERRUPT_RISING_EDGE == int_obj->Edge){
                    EXT_INT1_RisingEdge();}
                else{}
                break;
            case(INTERRUPT_EXT_INT2):
                if(INTERRUPT_FALLING_EDGE == int_obj->Edge){
                    EXT_INT2_FallingEdge();}
                else if(INTERRUPT_RISING_EDGE == int_obj->Edge){
                    EXT_INT2_RisingEdge();}
                else{}
                break;
            default:
                ret = E_NOK;
                break;
        }
        }
    
    return ret;
}

#if INTERRUPT_PRIO_LEVEL_ENABLE==INTERRUPT_FEATURE_ENABLE
static STD_ReturnType Interrupt_INTx_Priority_Init(const Interrupt_INTx_t *int_obj){
    STD_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOK;
    }
    else{
         switch(int_obj->Source){
            case(INTERRUPT_EXT_INT1):
                if(INTERRUPT_PRIO_LOW == int_obj->Priority){
                    EXT_INT1_PRIO_LOW();}
                else if(INTERRUPT_PRIO_HIGH == int_obj->Priority){
                    EXT_INT1_PRIO_HIGH();}
                else{}
                break;
            case(INTERRUPT_EXT_INT2):
                if(INTERRUPT_PRIO_LOW == int_obj->Priority){
                    EXT_INT2_PRIO_LOW();}
                else if(INTERRUPT_PRIO_HIGH == int_obj->Priority){
                    EXT_INT2_PRIO_HIGH();}
                else{}
                break;
            default:
                ret = E_NOK;
                break;
        }
    }
    return ret;
}
#endif

static STD_ReturnType Interrupt_INTx_Pin_Init(const Interrupt_INTx_t *int_obj){
    STD_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOK;
    }
    else{
        ret = gpio_pin_init(&(int_obj->MCU_Pin));
    }
    return ret;
}

static STD_ReturnType Interrupt_INTx_Clear_Flag(const Interrupt_INTx_t *int_obj){
    STD_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOK;
    }
    else{
            switch(int_obj->Source){
            case(INTERRUPT_EXT_INT0):
                EXT_INT0_Interrupt_Flag_Clear();
                break;
            case(INTERRUPT_EXT_INT1):
                EXT_INT1_Interrupt_Flag_Clear();
                break;
            case(INTERRUPT_EXT_INT2):
                EXT_INT2_Interrupt_Flag_Clear();
                break;
            default:
                ret = E_NOK;
                break;
        }
    }
    return ret;
}

static STD_ReturnType Interrupt_INT0_Handler(void (*INT_InterruptHandler) (void)){
    STD_ReturnType ret = E_OK;
    if(NULL == INT_InterruptHandler){
        ret = E_NOK;
    }
    else{
    INT0_InterruptHandler = INT_InterruptHandler;
    }
    return ret;
}

static STD_ReturnType Interrupt_INT1_Handler(void (*INT_InterruptHandler) (void)){
    STD_ReturnType ret = E_OK;
    if(NULL == INT_InterruptHandler){
        ret = E_NOK;
    }
    else{
        INT1_InterruptHandler = INT_InterruptHandler;
    }
    return ret;
}
static STD_ReturnType Interrupt_INT2_Handler(void (*INT_InterruptHandler) (void)){
    STD_ReturnType ret = E_OK;
    if(NULL == INT_InterruptHandler){
        ret = E_NOK;
    }
    else{
        INT2_InterruptHandler = INT_InterruptHandler;
    }
    return ret;
}
static STD_ReturnType Interrupt_INTx_Handler(const Interrupt_INTx_t *int_obj){
    STD_ReturnType ret = E_OK;
    if(NULL == int_obj){
        ret = E_NOK;
    }
    else{
        switch(int_obj->Source){
            case(INTERRUPT_EXT_INT0):
                ret = Interrupt_INT0_Handler(int_obj->Interrupt_CallBack);
                break;
            case(INTERRUPT_EXT_INT1):
                ret = Interrupt_INT1_Handler(int_obj->Interrupt_CallBack);
                break;
            case(INTERRUPT_EXT_INT2):
                ret = Interrupt_INT2_Handler(int_obj->Interrupt_CallBack);
                break;
            default:
                ret = E_NOK;
                break;
            }
    }
    return ret;
}