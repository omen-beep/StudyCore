#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/MPLABXProjects.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/MPLABXProjects.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECU_Layer/ECU_7SEG/ECU_7SEG.c ECU_Layer/ECU_BUTTON/ECU_BUTTON.c ECU_Layer/ECU_DC_MOTOR/ECU_DC_MOTOR.c ECU_Layer/ECU_KEYPAD/ECU_KEYPAD.c ECU_Layer/ECU_LCD/ECU_LCD.c ECU_Layer/ECU_LED/ECU_LED.c ECU_Layer/ECU_RELAY/ECU_RELAY.c ECU_Layer/ECU_LAYER_INIT/ECU_LAYER_INIT.c MCAL_Layer/GPIO/HAL_GPIO.c MCAL_Layer/MCAL_ADC/MCAL_ADC.c MCAL_Layer/MCAL_CCP1/MCAL_CCP1.c MCAL_Layer/MCAL_EEPROM/MCAL_EEPROM.c MCAL_Layer/MCAL_I2C/MCAL_I2C.c MCAL_Layer/MCAL_Interrupts/MCAL_Interrupt_Manager.c MCAL_Layer/MCAL_Interrupts/MCAL_Internal_Interrupt.c MCAL_Layer/MCAL_Interrupts/MCAL_External_Interrupt.c MCAL_Layer/MCAL_TIMER/MCAL_TIMER.c MCAL_Layer/MCAL_TIMER2/MCAL_TIMER2.c MCAL_Layer/MCAL_TIMER3/MCAL_TIMER3.c MCAL_Layer/MCAL_USART/MCAL_USART.c MCAL_Layer/TIMER1/TIMER1.c MCAL_Layer/Device_Config.c application.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU_Layer/ECU_7SEG/ECU_7SEG.p1 ${OBJECTDIR}/ECU_Layer/ECU_BUTTON/ECU_BUTTON.p1 ${OBJECTDIR}/ECU_Layer/ECU_DC_MOTOR/ECU_DC_MOTOR.p1 ${OBJECTDIR}/ECU_Layer/ECU_KEYPAD/ECU_KEYPAD.p1 ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1 ${OBJECTDIR}/ECU_Layer/ECU_LED/ECU_LED.p1 ${OBJECTDIR}/ECU_Layer/ECU_RELAY/ECU_RELAY.p1 ${OBJECTDIR}/ECU_Layer/ECU_LAYER_INIT/ECU_LAYER_INIT.p1 ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1 ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/MCAL_ADC.p1 ${OBJECTDIR}/MCAL_Layer/MCAL_CCP1/MCAL_CCP1.p1 ${OBJECTDIR}/MCAL_Layer/MCAL_EEPROM/MCAL_EEPROM.p1 ${OBJECTDIR}/MCAL_Layer/MCAL_I2C/MCAL_I2C.p1 ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Interrupt_Manager.p1 ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Internal_Interrupt.p1 ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_External_Interrupt.p1 ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER/MCAL_TIMER.p1 ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER2/MCAL_TIMER2.p1 ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER3/MCAL_TIMER3.p1 ${OBJECTDIR}/MCAL_Layer/MCAL_USART/MCAL_USART.p1 ${OBJECTDIR}/MCAL_Layer/TIMER1/TIMER1.p1 ${OBJECTDIR}/MCAL_Layer/Device_Config.p1 ${OBJECTDIR}/application.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU_Layer/ECU_7SEG/ECU_7SEG.p1.d ${OBJECTDIR}/ECU_Layer/ECU_BUTTON/ECU_BUTTON.p1.d ${OBJECTDIR}/ECU_Layer/ECU_DC_MOTOR/ECU_DC_MOTOR.p1.d ${OBJECTDIR}/ECU_Layer/ECU_KEYPAD/ECU_KEYPAD.p1.d ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1.d ${OBJECTDIR}/ECU_Layer/ECU_LED/ECU_LED.p1.d ${OBJECTDIR}/ECU_Layer/ECU_RELAY/ECU_RELAY.p1.d ${OBJECTDIR}/ECU_Layer/ECU_LAYER_INIT/ECU_LAYER_INIT.p1.d ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1.d ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/MCAL_ADC.p1.d ${OBJECTDIR}/MCAL_Layer/MCAL_CCP1/MCAL_CCP1.p1.d ${OBJECTDIR}/MCAL_Layer/MCAL_EEPROM/MCAL_EEPROM.p1.d ${OBJECTDIR}/MCAL_Layer/MCAL_I2C/MCAL_I2C.p1.d ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Interrupt_Manager.p1.d ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Internal_Interrupt.p1.d ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_External_Interrupt.p1.d ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER/MCAL_TIMER.p1.d ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER2/MCAL_TIMER2.p1.d ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER3/MCAL_TIMER3.p1.d ${OBJECTDIR}/MCAL_Layer/MCAL_USART/MCAL_USART.p1.d ${OBJECTDIR}/MCAL_Layer/TIMER1/TIMER1.p1.d ${OBJECTDIR}/MCAL_Layer/Device_Config.p1.d ${OBJECTDIR}/application.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU_Layer/ECU_7SEG/ECU_7SEG.p1 ${OBJECTDIR}/ECU_Layer/ECU_BUTTON/ECU_BUTTON.p1 ${OBJECTDIR}/ECU_Layer/ECU_DC_MOTOR/ECU_DC_MOTOR.p1 ${OBJECTDIR}/ECU_Layer/ECU_KEYPAD/ECU_KEYPAD.p1 ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1 ${OBJECTDIR}/ECU_Layer/ECU_LED/ECU_LED.p1 ${OBJECTDIR}/ECU_Layer/ECU_RELAY/ECU_RELAY.p1 ${OBJECTDIR}/ECU_Layer/ECU_LAYER_INIT/ECU_LAYER_INIT.p1 ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1 ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/MCAL_ADC.p1 ${OBJECTDIR}/MCAL_Layer/MCAL_CCP1/MCAL_CCP1.p1 ${OBJECTDIR}/MCAL_Layer/MCAL_EEPROM/MCAL_EEPROM.p1 ${OBJECTDIR}/MCAL_Layer/MCAL_I2C/MCAL_I2C.p1 ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Interrupt_Manager.p1 ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Internal_Interrupt.p1 ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_External_Interrupt.p1 ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER/MCAL_TIMER.p1 ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER2/MCAL_TIMER2.p1 ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER3/MCAL_TIMER3.p1 ${OBJECTDIR}/MCAL_Layer/MCAL_USART/MCAL_USART.p1 ${OBJECTDIR}/MCAL_Layer/TIMER1/TIMER1.p1 ${OBJECTDIR}/MCAL_Layer/Device_Config.p1 ${OBJECTDIR}/application.p1

# Source Files
SOURCEFILES=ECU_Layer/ECU_7SEG/ECU_7SEG.c ECU_Layer/ECU_BUTTON/ECU_BUTTON.c ECU_Layer/ECU_DC_MOTOR/ECU_DC_MOTOR.c ECU_Layer/ECU_KEYPAD/ECU_KEYPAD.c ECU_Layer/ECU_LCD/ECU_LCD.c ECU_Layer/ECU_LED/ECU_LED.c ECU_Layer/ECU_RELAY/ECU_RELAY.c ECU_Layer/ECU_LAYER_INIT/ECU_LAYER_INIT.c MCAL_Layer/GPIO/HAL_GPIO.c MCAL_Layer/MCAL_ADC/MCAL_ADC.c MCAL_Layer/MCAL_CCP1/MCAL_CCP1.c MCAL_Layer/MCAL_EEPROM/MCAL_EEPROM.c MCAL_Layer/MCAL_I2C/MCAL_I2C.c MCAL_Layer/MCAL_Interrupts/MCAL_Interrupt_Manager.c MCAL_Layer/MCAL_Interrupts/MCAL_Internal_Interrupt.c MCAL_Layer/MCAL_Interrupts/MCAL_External_Interrupt.c MCAL_Layer/MCAL_TIMER/MCAL_TIMER.c MCAL_Layer/MCAL_TIMER2/MCAL_TIMER2.c MCAL_Layer/MCAL_TIMER3/MCAL_TIMER3.c MCAL_Layer/MCAL_USART/MCAL_USART.c MCAL_Layer/TIMER1/TIMER1.c MCAL_Layer/Device_Config.c application.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/MPLABXProjects.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU_Layer/ECU_7SEG/ECU_7SEG.p1: ECU_Layer/ECU_7SEG/ECU_7SEG.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ECU_7SEG" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_7SEG/ECU_7SEG.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_7SEG/ECU_7SEG.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ECU_7SEG/ECU_7SEG.p1 ECU_Layer/ECU_7SEG/ECU_7SEG.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_7SEG/ECU_7SEG.d ${OBJECTDIR}/ECU_Layer/ECU_7SEG/ECU_7SEG.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_7SEG/ECU_7SEG.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ECU_BUTTON/ECU_BUTTON.p1: ECU_Layer/ECU_BUTTON/ECU_BUTTON.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ECU_BUTTON" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_BUTTON/ECU_BUTTON.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_BUTTON/ECU_BUTTON.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ECU_BUTTON/ECU_BUTTON.p1 ECU_Layer/ECU_BUTTON/ECU_BUTTON.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_BUTTON/ECU_BUTTON.d ${OBJECTDIR}/ECU_Layer/ECU_BUTTON/ECU_BUTTON.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_BUTTON/ECU_BUTTON.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ECU_DC_MOTOR/ECU_DC_MOTOR.p1: ECU_Layer/ECU_DC_MOTOR/ECU_DC_MOTOR.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ECU_DC_MOTOR" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_DC_MOTOR/ECU_DC_MOTOR.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_DC_MOTOR/ECU_DC_MOTOR.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ECU_DC_MOTOR/ECU_DC_MOTOR.p1 ECU_Layer/ECU_DC_MOTOR/ECU_DC_MOTOR.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_DC_MOTOR/ECU_DC_MOTOR.d ${OBJECTDIR}/ECU_Layer/ECU_DC_MOTOR/ECU_DC_MOTOR.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_DC_MOTOR/ECU_DC_MOTOR.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ECU_KEYPAD/ECU_KEYPAD.p1: ECU_Layer/ECU_KEYPAD/ECU_KEYPAD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ECU_KEYPAD" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_KEYPAD/ECU_KEYPAD.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_KEYPAD/ECU_KEYPAD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ECU_KEYPAD/ECU_KEYPAD.p1 ECU_Layer/ECU_KEYPAD/ECU_KEYPAD.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_KEYPAD/ECU_KEYPAD.d ${OBJECTDIR}/ECU_Layer/ECU_KEYPAD/ECU_KEYPAD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_KEYPAD/ECU_KEYPAD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1: ECU_Layer/ECU_LCD/ECU_LCD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ECU_LCD" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1 ECU_Layer/ECU_LCD/ECU_LCD.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.d ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ECU_LED/ECU_LED.p1: ECU_Layer/ECU_LED/ECU_LED.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ECU_LED" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_LED/ECU_LED.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_LED/ECU_LED.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ECU_LED/ECU_LED.p1 ECU_Layer/ECU_LED/ECU_LED.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_LED/ECU_LED.d ${OBJECTDIR}/ECU_Layer/ECU_LED/ECU_LED.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_LED/ECU_LED.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ECU_RELAY/ECU_RELAY.p1: ECU_Layer/ECU_RELAY/ECU_RELAY.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ECU_RELAY" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_RELAY/ECU_RELAY.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_RELAY/ECU_RELAY.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ECU_RELAY/ECU_RELAY.p1 ECU_Layer/ECU_RELAY/ECU_RELAY.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_RELAY/ECU_RELAY.d ${OBJECTDIR}/ECU_Layer/ECU_RELAY/ECU_RELAY.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_RELAY/ECU_RELAY.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ECU_LAYER_INIT/ECU_LAYER_INIT.p1: ECU_Layer/ECU_LAYER_INIT/ECU_LAYER_INIT.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ECU_LAYER_INIT" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_LAYER_INIT/ECU_LAYER_INIT.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_LAYER_INIT/ECU_LAYER_INIT.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ECU_LAYER_INIT/ECU_LAYER_INIT.p1 ECU_Layer/ECU_LAYER_INIT/ECU_LAYER_INIT.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_LAYER_INIT/ECU_LAYER_INIT.d ${OBJECTDIR}/ECU_Layer/ECU_LAYER_INIT/ECU_LAYER_INIT.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_LAYER_INIT/ECU_LAYER_INIT.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1: MCAL_Layer/GPIO/HAL_GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1 MCAL_Layer/GPIO/HAL_GPIO.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.d ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/MCAL_ADC/MCAL_ADC.p1: MCAL_Layer/MCAL_ADC/MCAL_ADC.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/MCAL_ADC" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/MCAL_ADC.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/MCAL_ADC.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/MCAL_ADC.p1 MCAL_Layer/MCAL_ADC/MCAL_ADC.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/MCAL_ADC.d ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/MCAL_ADC.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/MCAL_ADC.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/MCAL_CCP1/MCAL_CCP1.p1: MCAL_Layer/MCAL_CCP1/MCAL_CCP1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/MCAL_CCP1" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_CCP1/MCAL_CCP1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_CCP1/MCAL_CCP1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/MCAL_CCP1/MCAL_CCP1.p1 MCAL_Layer/MCAL_CCP1/MCAL_CCP1.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/MCAL_CCP1/MCAL_CCP1.d ${OBJECTDIR}/MCAL_Layer/MCAL_CCP1/MCAL_CCP1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/MCAL_CCP1/MCAL_CCP1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/MCAL_EEPROM/MCAL_EEPROM.p1: MCAL_Layer/MCAL_EEPROM/MCAL_EEPROM.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/MCAL_EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_EEPROM/MCAL_EEPROM.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_EEPROM/MCAL_EEPROM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/MCAL_EEPROM/MCAL_EEPROM.p1 MCAL_Layer/MCAL_EEPROM/MCAL_EEPROM.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/MCAL_EEPROM/MCAL_EEPROM.d ${OBJECTDIR}/MCAL_Layer/MCAL_EEPROM/MCAL_EEPROM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/MCAL_EEPROM/MCAL_EEPROM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/MCAL_I2C/MCAL_I2C.p1: MCAL_Layer/MCAL_I2C/MCAL_I2C.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/MCAL_I2C" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_I2C/MCAL_I2C.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_I2C/MCAL_I2C.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/MCAL_I2C/MCAL_I2C.p1 MCAL_Layer/MCAL_I2C/MCAL_I2C.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/MCAL_I2C/MCAL_I2C.d ${OBJECTDIR}/MCAL_Layer/MCAL_I2C/MCAL_I2C.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/MCAL_I2C/MCAL_I2C.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Interrupt_Manager.p1: MCAL_Layer/MCAL_Interrupts/MCAL_Interrupt_Manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Interrupt_Manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Interrupt_Manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Interrupt_Manager.p1 MCAL_Layer/MCAL_Interrupts/MCAL_Interrupt_Manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Interrupt_Manager.d ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Interrupt_Manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Interrupt_Manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Internal_Interrupt.p1: MCAL_Layer/MCAL_Interrupts/MCAL_Internal_Interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Internal_Interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Internal_Interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Internal_Interrupt.p1 MCAL_Layer/MCAL_Interrupts/MCAL_Internal_Interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Internal_Interrupt.d ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Internal_Interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Internal_Interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_External_Interrupt.p1: MCAL_Layer/MCAL_Interrupts/MCAL_External_Interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_External_Interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_External_Interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_External_Interrupt.p1 MCAL_Layer/MCAL_Interrupts/MCAL_External_Interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_External_Interrupt.d ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_External_Interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_External_Interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/MCAL_TIMER/MCAL_TIMER.p1: MCAL_Layer/MCAL_TIMER/MCAL_TIMER.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/MCAL_TIMER" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER/MCAL_TIMER.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER/MCAL_TIMER.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER/MCAL_TIMER.p1 MCAL_Layer/MCAL_TIMER/MCAL_TIMER.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER/MCAL_TIMER.d ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER/MCAL_TIMER.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER/MCAL_TIMER.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/MCAL_TIMER2/MCAL_TIMER2.p1: MCAL_Layer/MCAL_TIMER2/MCAL_TIMER2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/MCAL_TIMER2" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER2/MCAL_TIMER2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER2/MCAL_TIMER2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER2/MCAL_TIMER2.p1 MCAL_Layer/MCAL_TIMER2/MCAL_TIMER2.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER2/MCAL_TIMER2.d ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER2/MCAL_TIMER2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER2/MCAL_TIMER2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/MCAL_TIMER3/MCAL_TIMER3.p1: MCAL_Layer/MCAL_TIMER3/MCAL_TIMER3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/MCAL_TIMER3" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER3/MCAL_TIMER3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER3/MCAL_TIMER3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER3/MCAL_TIMER3.p1 MCAL_Layer/MCAL_TIMER3/MCAL_TIMER3.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER3/MCAL_TIMER3.d ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER3/MCAL_TIMER3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER3/MCAL_TIMER3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/MCAL_USART/MCAL_USART.p1: MCAL_Layer/MCAL_USART/MCAL_USART.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/MCAL_USART" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_USART/MCAL_USART.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_USART/MCAL_USART.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/MCAL_USART/MCAL_USART.p1 MCAL_Layer/MCAL_USART/MCAL_USART.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/MCAL_USART/MCAL_USART.d ${OBJECTDIR}/MCAL_Layer/MCAL_USART/MCAL_USART.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/MCAL_USART/MCAL_USART.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/TIMER1/TIMER1.p1: MCAL_Layer/TIMER1/TIMER1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/TIMER1" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/TIMER1/TIMER1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/TIMER1/TIMER1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/TIMER1/TIMER1.p1 MCAL_Layer/TIMER1/TIMER1.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/TIMER1/TIMER1.d ${OBJECTDIR}/MCAL_Layer/TIMER1/TIMER1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/TIMER1/TIMER1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Device_Config.p1: MCAL_Layer/Device_Config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Device_Config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Device_Config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Device_Config.p1 MCAL_Layer/Device_Config.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Device_Config.d ${OBJECTDIR}/MCAL_Layer/Device_Config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Device_Config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU_Layer/ECU_7SEG/ECU_7SEG.p1: ECU_Layer/ECU_7SEG/ECU_7SEG.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ECU_7SEG" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_7SEG/ECU_7SEG.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_7SEG/ECU_7SEG.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ECU_7SEG/ECU_7SEG.p1 ECU_Layer/ECU_7SEG/ECU_7SEG.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_7SEG/ECU_7SEG.d ${OBJECTDIR}/ECU_Layer/ECU_7SEG/ECU_7SEG.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_7SEG/ECU_7SEG.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ECU_BUTTON/ECU_BUTTON.p1: ECU_Layer/ECU_BUTTON/ECU_BUTTON.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ECU_BUTTON" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_BUTTON/ECU_BUTTON.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_BUTTON/ECU_BUTTON.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ECU_BUTTON/ECU_BUTTON.p1 ECU_Layer/ECU_BUTTON/ECU_BUTTON.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_BUTTON/ECU_BUTTON.d ${OBJECTDIR}/ECU_Layer/ECU_BUTTON/ECU_BUTTON.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_BUTTON/ECU_BUTTON.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ECU_DC_MOTOR/ECU_DC_MOTOR.p1: ECU_Layer/ECU_DC_MOTOR/ECU_DC_MOTOR.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ECU_DC_MOTOR" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_DC_MOTOR/ECU_DC_MOTOR.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_DC_MOTOR/ECU_DC_MOTOR.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ECU_DC_MOTOR/ECU_DC_MOTOR.p1 ECU_Layer/ECU_DC_MOTOR/ECU_DC_MOTOR.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_DC_MOTOR/ECU_DC_MOTOR.d ${OBJECTDIR}/ECU_Layer/ECU_DC_MOTOR/ECU_DC_MOTOR.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_DC_MOTOR/ECU_DC_MOTOR.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ECU_KEYPAD/ECU_KEYPAD.p1: ECU_Layer/ECU_KEYPAD/ECU_KEYPAD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ECU_KEYPAD" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_KEYPAD/ECU_KEYPAD.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_KEYPAD/ECU_KEYPAD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ECU_KEYPAD/ECU_KEYPAD.p1 ECU_Layer/ECU_KEYPAD/ECU_KEYPAD.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_KEYPAD/ECU_KEYPAD.d ${OBJECTDIR}/ECU_Layer/ECU_KEYPAD/ECU_KEYPAD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_KEYPAD/ECU_KEYPAD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1: ECU_Layer/ECU_LCD/ECU_LCD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ECU_LCD" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1 ECU_Layer/ECU_LCD/ECU_LCD.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.d ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_LCD/ECU_LCD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ECU_LED/ECU_LED.p1: ECU_Layer/ECU_LED/ECU_LED.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ECU_LED" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_LED/ECU_LED.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_LED/ECU_LED.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ECU_LED/ECU_LED.p1 ECU_Layer/ECU_LED/ECU_LED.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_LED/ECU_LED.d ${OBJECTDIR}/ECU_Layer/ECU_LED/ECU_LED.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_LED/ECU_LED.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ECU_RELAY/ECU_RELAY.p1: ECU_Layer/ECU_RELAY/ECU_RELAY.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ECU_RELAY" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_RELAY/ECU_RELAY.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_RELAY/ECU_RELAY.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ECU_RELAY/ECU_RELAY.p1 ECU_Layer/ECU_RELAY/ECU_RELAY.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_RELAY/ECU_RELAY.d ${OBJECTDIR}/ECU_Layer/ECU_RELAY/ECU_RELAY.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_RELAY/ECU_RELAY.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ECU_LAYER_INIT/ECU_LAYER_INIT.p1: ECU_Layer/ECU_LAYER_INIT/ECU_LAYER_INIT.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ECU_LAYER_INIT" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_LAYER_INIT/ECU_LAYER_INIT.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ECU_LAYER_INIT/ECU_LAYER_INIT.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ECU_LAYER_INIT/ECU_LAYER_INIT.p1 ECU_Layer/ECU_LAYER_INIT/ECU_LAYER_INIT.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ECU_LAYER_INIT/ECU_LAYER_INIT.d ${OBJECTDIR}/ECU_Layer/ECU_LAYER_INIT/ECU_LAYER_INIT.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ECU_LAYER_INIT/ECU_LAYER_INIT.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1: MCAL_Layer/GPIO/HAL_GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1 MCAL_Layer/GPIO/HAL_GPIO.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.d ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/GPIO/HAL_GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/MCAL_ADC/MCAL_ADC.p1: MCAL_Layer/MCAL_ADC/MCAL_ADC.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/MCAL_ADC" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/MCAL_ADC.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/MCAL_ADC.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/MCAL_ADC.p1 MCAL_Layer/MCAL_ADC/MCAL_ADC.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/MCAL_ADC.d ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/MCAL_ADC.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/MCAL_ADC/MCAL_ADC.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/MCAL_CCP1/MCAL_CCP1.p1: MCAL_Layer/MCAL_CCP1/MCAL_CCP1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/MCAL_CCP1" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_CCP1/MCAL_CCP1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_CCP1/MCAL_CCP1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/MCAL_CCP1/MCAL_CCP1.p1 MCAL_Layer/MCAL_CCP1/MCAL_CCP1.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/MCAL_CCP1/MCAL_CCP1.d ${OBJECTDIR}/MCAL_Layer/MCAL_CCP1/MCAL_CCP1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/MCAL_CCP1/MCAL_CCP1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/MCAL_EEPROM/MCAL_EEPROM.p1: MCAL_Layer/MCAL_EEPROM/MCAL_EEPROM.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/MCAL_EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_EEPROM/MCAL_EEPROM.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_EEPROM/MCAL_EEPROM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/MCAL_EEPROM/MCAL_EEPROM.p1 MCAL_Layer/MCAL_EEPROM/MCAL_EEPROM.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/MCAL_EEPROM/MCAL_EEPROM.d ${OBJECTDIR}/MCAL_Layer/MCAL_EEPROM/MCAL_EEPROM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/MCAL_EEPROM/MCAL_EEPROM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/MCAL_I2C/MCAL_I2C.p1: MCAL_Layer/MCAL_I2C/MCAL_I2C.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/MCAL_I2C" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_I2C/MCAL_I2C.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_I2C/MCAL_I2C.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/MCAL_I2C/MCAL_I2C.p1 MCAL_Layer/MCAL_I2C/MCAL_I2C.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/MCAL_I2C/MCAL_I2C.d ${OBJECTDIR}/MCAL_Layer/MCAL_I2C/MCAL_I2C.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/MCAL_I2C/MCAL_I2C.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Interrupt_Manager.p1: MCAL_Layer/MCAL_Interrupts/MCAL_Interrupt_Manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Interrupt_Manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Interrupt_Manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Interrupt_Manager.p1 MCAL_Layer/MCAL_Interrupts/MCAL_Interrupt_Manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Interrupt_Manager.d ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Interrupt_Manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Interrupt_Manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Internal_Interrupt.p1: MCAL_Layer/MCAL_Interrupts/MCAL_Internal_Interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Internal_Interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Internal_Interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Internal_Interrupt.p1 MCAL_Layer/MCAL_Interrupts/MCAL_Internal_Interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Internal_Interrupt.d ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Internal_Interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_Internal_Interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_External_Interrupt.p1: MCAL_Layer/MCAL_Interrupts/MCAL_External_Interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_External_Interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_External_Interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_External_Interrupt.p1 MCAL_Layer/MCAL_Interrupts/MCAL_External_Interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_External_Interrupt.d ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_External_Interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/MCAL_Interrupts/MCAL_External_Interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/MCAL_TIMER/MCAL_TIMER.p1: MCAL_Layer/MCAL_TIMER/MCAL_TIMER.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/MCAL_TIMER" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER/MCAL_TIMER.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER/MCAL_TIMER.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER/MCAL_TIMER.p1 MCAL_Layer/MCAL_TIMER/MCAL_TIMER.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER/MCAL_TIMER.d ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER/MCAL_TIMER.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER/MCAL_TIMER.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/MCAL_TIMER2/MCAL_TIMER2.p1: MCAL_Layer/MCAL_TIMER2/MCAL_TIMER2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/MCAL_TIMER2" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER2/MCAL_TIMER2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER2/MCAL_TIMER2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER2/MCAL_TIMER2.p1 MCAL_Layer/MCAL_TIMER2/MCAL_TIMER2.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER2/MCAL_TIMER2.d ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER2/MCAL_TIMER2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER2/MCAL_TIMER2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/MCAL_TIMER3/MCAL_TIMER3.p1: MCAL_Layer/MCAL_TIMER3/MCAL_TIMER3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/MCAL_TIMER3" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER3/MCAL_TIMER3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER3/MCAL_TIMER3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER3/MCAL_TIMER3.p1 MCAL_Layer/MCAL_TIMER3/MCAL_TIMER3.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER3/MCAL_TIMER3.d ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER3/MCAL_TIMER3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/MCAL_TIMER3/MCAL_TIMER3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/MCAL_USART/MCAL_USART.p1: MCAL_Layer/MCAL_USART/MCAL_USART.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/MCAL_USART" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_USART/MCAL_USART.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/MCAL_USART/MCAL_USART.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/MCAL_USART/MCAL_USART.p1 MCAL_Layer/MCAL_USART/MCAL_USART.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/MCAL_USART/MCAL_USART.d ${OBJECTDIR}/MCAL_Layer/MCAL_USART/MCAL_USART.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/MCAL_USART/MCAL_USART.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/TIMER1/TIMER1.p1: MCAL_Layer/TIMER1/TIMER1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/TIMER1" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/TIMER1/TIMER1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/TIMER1/TIMER1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/TIMER1/TIMER1.p1 MCAL_Layer/TIMER1/TIMER1.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/TIMER1/TIMER1.d ${OBJECTDIR}/MCAL_Layer/TIMER1/TIMER1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/TIMER1/TIMER1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Device_Config.p1: MCAL_Layer/Device_Config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Device_Config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Device_Config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Device_Config.p1 MCAL_Layer/Device_Config.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Device_Config.d ${OBJECTDIR}/MCAL_Layer/Device_Config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Device_Config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/MPLABXProjects.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/MPLABXProjects.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/MPLABXProjects.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/MPLABXProjects.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/MPLABXProjects.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/MPLABXProjects.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/MPLABXProjects.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
