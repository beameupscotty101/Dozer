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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/RoachFSMProject.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/RoachFSMProject.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=C:/CMPE118/src/AD.c C:/CMPE118/src/BOARD.c C:/CMPE118/src/ES_Framework.c C:/CMPE118/src/pwm.c C:/CMPE118/src/serial.c RoachMain.c RoachFSM.c ../../../../CMPE118/src/IO_Ports.c ../../../../CMPE118/src/RC_Servo.c ../dozer.X/Dozer.c DozerFrameworkEvents.c TapeSensorService.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/331920610/AD.o ${OBJECTDIR}/_ext/331920610/BOARD.o ${OBJECTDIR}/_ext/331920610/ES_Framework.o ${OBJECTDIR}/_ext/331920610/pwm.o ${OBJECTDIR}/_ext/331920610/serial.o ${OBJECTDIR}/RoachMain.o ${OBJECTDIR}/RoachFSM.o ${OBJECTDIR}/_ext/443050350/IO_Ports.o ${OBJECTDIR}/_ext/443050350/RC_Servo.o ${OBJECTDIR}/_ext/169173975/Dozer.o ${OBJECTDIR}/DozerFrameworkEvents.o ${OBJECTDIR}/TapeSensorService.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/331920610/AD.o.d ${OBJECTDIR}/_ext/331920610/BOARD.o.d ${OBJECTDIR}/_ext/331920610/ES_Framework.o.d ${OBJECTDIR}/_ext/331920610/pwm.o.d ${OBJECTDIR}/_ext/331920610/serial.o.d ${OBJECTDIR}/RoachMain.o.d ${OBJECTDIR}/RoachFSM.o.d ${OBJECTDIR}/_ext/443050350/IO_Ports.o.d ${OBJECTDIR}/_ext/443050350/RC_Servo.o.d ${OBJECTDIR}/_ext/169173975/Dozer.o.d ${OBJECTDIR}/DozerFrameworkEvents.o.d ${OBJECTDIR}/TapeSensorService.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/331920610/AD.o ${OBJECTDIR}/_ext/331920610/BOARD.o ${OBJECTDIR}/_ext/331920610/ES_Framework.o ${OBJECTDIR}/_ext/331920610/pwm.o ${OBJECTDIR}/_ext/331920610/serial.o ${OBJECTDIR}/RoachMain.o ${OBJECTDIR}/RoachFSM.o ${OBJECTDIR}/_ext/443050350/IO_Ports.o ${OBJECTDIR}/_ext/443050350/RC_Servo.o ${OBJECTDIR}/_ext/169173975/Dozer.o ${OBJECTDIR}/DozerFrameworkEvents.o ${OBJECTDIR}/TapeSensorService.o

# Source Files
SOURCEFILES=C:/CMPE118/src/AD.c C:/CMPE118/src/BOARD.c C:/CMPE118/src/ES_Framework.c C:/CMPE118/src/pwm.c C:/CMPE118/src/serial.c RoachMain.c RoachFSM.c ../../../../CMPE118/src/IO_Ports.c ../../../../CMPE118/src/RC_Servo.c ../dozer.X/Dozer.c DozerFrameworkEvents.c TapeSensorService.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/RoachFSMProject.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX320F128H
MP_LINKER_FILE_OPTION=
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
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/331920610/AD.o: C:/CMPE118/src/AD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/AD.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/AD.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/AD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/331920610/AD.o.d" -o ${OBJECTDIR}/_ext/331920610/AD.o C:/CMPE118/src/AD.c   
	
${OBJECTDIR}/_ext/331920610/BOARD.o: C:/CMPE118/src/BOARD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/BOARD.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/BOARD.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/BOARD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/331920610/BOARD.o.d" -o ${OBJECTDIR}/_ext/331920610/BOARD.o C:/CMPE118/src/BOARD.c   
	
${OBJECTDIR}/_ext/331920610/ES_Framework.o: C:/CMPE118/src/ES_Framework.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/ES_Framework.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/ES_Framework.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/ES_Framework.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/331920610/ES_Framework.o.d" -o ${OBJECTDIR}/_ext/331920610/ES_Framework.o C:/CMPE118/src/ES_Framework.c   
	
${OBJECTDIR}/_ext/331920610/pwm.o: C:/CMPE118/src/pwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/pwm.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/pwm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/331920610/pwm.o.d" -o ${OBJECTDIR}/_ext/331920610/pwm.o C:/CMPE118/src/pwm.c   
	
${OBJECTDIR}/_ext/331920610/serial.o: C:/CMPE118/src/serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/serial.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/serial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/331920610/serial.o.d" -o ${OBJECTDIR}/_ext/331920610/serial.o C:/CMPE118/src/serial.c   
	
${OBJECTDIR}/RoachMain.o: RoachMain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/RoachMain.o.d 
	@${RM} ${OBJECTDIR}/RoachMain.o 
	@${FIXDEPS} "${OBJECTDIR}/RoachMain.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/RoachMain.o.d" -o ${OBJECTDIR}/RoachMain.o RoachMain.c   
	
${OBJECTDIR}/RoachFSM.o: RoachFSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/RoachFSM.o.d 
	@${RM} ${OBJECTDIR}/RoachFSM.o 
	@${FIXDEPS} "${OBJECTDIR}/RoachFSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/RoachFSM.o.d" -o ${OBJECTDIR}/RoachFSM.o RoachFSM.c   
	
${OBJECTDIR}/_ext/443050350/IO_Ports.o: ../../../../CMPE118/src/IO_Ports.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/443050350 
	@${RM} ${OBJECTDIR}/_ext/443050350/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/_ext/443050350/IO_Ports.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/443050350/IO_Ports.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/443050350/IO_Ports.o.d" -o ${OBJECTDIR}/_ext/443050350/IO_Ports.o ../../../../CMPE118/src/IO_Ports.c   
	
${OBJECTDIR}/_ext/443050350/RC_Servo.o: ../../../../CMPE118/src/RC_Servo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/443050350 
	@${RM} ${OBJECTDIR}/_ext/443050350/RC_Servo.o.d 
	@${RM} ${OBJECTDIR}/_ext/443050350/RC_Servo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/443050350/RC_Servo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/443050350/RC_Servo.o.d" -o ${OBJECTDIR}/_ext/443050350/RC_Servo.o ../../../../CMPE118/src/RC_Servo.c   
	
${OBJECTDIR}/_ext/169173975/Dozer.o: ../dozer.X/Dozer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/169173975 
	@${RM} ${OBJECTDIR}/_ext/169173975/Dozer.o.d 
	@${RM} ${OBJECTDIR}/_ext/169173975/Dozer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/169173975/Dozer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/169173975/Dozer.o.d" -o ${OBJECTDIR}/_ext/169173975/Dozer.o ../dozer.X/Dozer.c   
	
${OBJECTDIR}/DozerFrameworkEvents.o: DozerFrameworkEvents.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/DozerFrameworkEvents.o.d 
	@${RM} ${OBJECTDIR}/DozerFrameworkEvents.o 
	@${FIXDEPS} "${OBJECTDIR}/DozerFrameworkEvents.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/DozerFrameworkEvents.o.d" -o ${OBJECTDIR}/DozerFrameworkEvents.o DozerFrameworkEvents.c   
	
${OBJECTDIR}/TapeSensorService.o: TapeSensorService.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/TapeSensorService.o.d 
	@${RM} ${OBJECTDIR}/TapeSensorService.o 
	@${FIXDEPS} "${OBJECTDIR}/TapeSensorService.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/TapeSensorService.o.d" -o ${OBJECTDIR}/TapeSensorService.o TapeSensorService.c   
	
else
${OBJECTDIR}/_ext/331920610/AD.o: C:/CMPE118/src/AD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/AD.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/AD.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/AD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/331920610/AD.o.d" -o ${OBJECTDIR}/_ext/331920610/AD.o C:/CMPE118/src/AD.c   
	
${OBJECTDIR}/_ext/331920610/BOARD.o: C:/CMPE118/src/BOARD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/BOARD.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/BOARD.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/BOARD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/331920610/BOARD.o.d" -o ${OBJECTDIR}/_ext/331920610/BOARD.o C:/CMPE118/src/BOARD.c   
	
${OBJECTDIR}/_ext/331920610/ES_Framework.o: C:/CMPE118/src/ES_Framework.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/ES_Framework.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/ES_Framework.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/ES_Framework.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/331920610/ES_Framework.o.d" -o ${OBJECTDIR}/_ext/331920610/ES_Framework.o C:/CMPE118/src/ES_Framework.c   
	
${OBJECTDIR}/_ext/331920610/pwm.o: C:/CMPE118/src/pwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/pwm.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/pwm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/331920610/pwm.o.d" -o ${OBJECTDIR}/_ext/331920610/pwm.o C:/CMPE118/src/pwm.c   
	
${OBJECTDIR}/_ext/331920610/serial.o: C:/CMPE118/src/serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/331920610 
	@${RM} ${OBJECTDIR}/_ext/331920610/serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/serial.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/serial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/331920610/serial.o.d" -o ${OBJECTDIR}/_ext/331920610/serial.o C:/CMPE118/src/serial.c   
	
${OBJECTDIR}/RoachMain.o: RoachMain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/RoachMain.o.d 
	@${RM} ${OBJECTDIR}/RoachMain.o 
	@${FIXDEPS} "${OBJECTDIR}/RoachMain.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/RoachMain.o.d" -o ${OBJECTDIR}/RoachMain.o RoachMain.c   
	
${OBJECTDIR}/RoachFSM.o: RoachFSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/RoachFSM.o.d 
	@${RM} ${OBJECTDIR}/RoachFSM.o 
	@${FIXDEPS} "${OBJECTDIR}/RoachFSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/RoachFSM.o.d" -o ${OBJECTDIR}/RoachFSM.o RoachFSM.c   
	
${OBJECTDIR}/_ext/443050350/IO_Ports.o: ../../../../CMPE118/src/IO_Ports.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/443050350 
	@${RM} ${OBJECTDIR}/_ext/443050350/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/_ext/443050350/IO_Ports.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/443050350/IO_Ports.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/443050350/IO_Ports.o.d" -o ${OBJECTDIR}/_ext/443050350/IO_Ports.o ../../../../CMPE118/src/IO_Ports.c   
	
${OBJECTDIR}/_ext/443050350/RC_Servo.o: ../../../../CMPE118/src/RC_Servo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/443050350 
	@${RM} ${OBJECTDIR}/_ext/443050350/RC_Servo.o.d 
	@${RM} ${OBJECTDIR}/_ext/443050350/RC_Servo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/443050350/RC_Servo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/443050350/RC_Servo.o.d" -o ${OBJECTDIR}/_ext/443050350/RC_Servo.o ../../../../CMPE118/src/RC_Servo.c   
	
${OBJECTDIR}/_ext/169173975/Dozer.o: ../dozer.X/Dozer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/169173975 
	@${RM} ${OBJECTDIR}/_ext/169173975/Dozer.o.d 
	@${RM} ${OBJECTDIR}/_ext/169173975/Dozer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/169173975/Dozer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/169173975/Dozer.o.d" -o ${OBJECTDIR}/_ext/169173975/Dozer.o ../dozer.X/Dozer.c   
	
${OBJECTDIR}/DozerFrameworkEvents.o: DozerFrameworkEvents.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/DozerFrameworkEvents.o.d 
	@${RM} ${OBJECTDIR}/DozerFrameworkEvents.o 
	@${FIXDEPS} "${OBJECTDIR}/DozerFrameworkEvents.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/DozerFrameworkEvents.o.d" -o ${OBJECTDIR}/DozerFrameworkEvents.o DozerFrameworkEvents.c   
	
${OBJECTDIR}/TapeSensorService.o: TapeSensorService.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/TapeSensorService.o.d 
	@${RM} ${OBJECTDIR}/TapeSensorService.o 
	@${FIXDEPS} "${OBJECTDIR}/TapeSensorService.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/TapeSensorService.o.d" -o ${OBJECTDIR}/TapeSensorService.o TapeSensorService.c   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/RoachFSMProject.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/RoachFSMProject.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}           -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/RoachFSMProject.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/RoachFSMProject.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/RoachFSMProject.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
