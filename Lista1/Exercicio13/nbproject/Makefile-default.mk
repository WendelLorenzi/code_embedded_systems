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
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/lista2_exercicio14_1.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/lista2_exercicio14_1.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
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
SOURCEFILES_QUOTED_IF_SPACED=FreeRTOS/portable/heap_1.c FreeRTOS/portable/port.c FreeRTOS/serial/serial.c FreeRTOS/list.c FreeRTOS/tasks.c FreeRTOS/croutine.c FreeRTOS/queue.c newmain.c FreeRTOS/event_groups.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/FreeRTOS/portable/heap_1.o ${OBJECTDIR}/FreeRTOS/portable/port.o ${OBJECTDIR}/FreeRTOS/serial/serial.o ${OBJECTDIR}/FreeRTOS/list.o ${OBJECTDIR}/FreeRTOS/tasks.o ${OBJECTDIR}/FreeRTOS/croutine.o ${OBJECTDIR}/FreeRTOS/queue.o ${OBJECTDIR}/newmain.o ${OBJECTDIR}/FreeRTOS/event_groups.o
POSSIBLE_DEPFILES=${OBJECTDIR}/FreeRTOS/portable/heap_1.o.d ${OBJECTDIR}/FreeRTOS/portable/port.o.d ${OBJECTDIR}/FreeRTOS/serial/serial.o.d ${OBJECTDIR}/FreeRTOS/list.o.d ${OBJECTDIR}/FreeRTOS/tasks.o.d ${OBJECTDIR}/FreeRTOS/croutine.o.d ${OBJECTDIR}/FreeRTOS/queue.o.d ${OBJECTDIR}/newmain.o.d ${OBJECTDIR}/FreeRTOS/event_groups.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/FreeRTOS/portable/heap_1.o ${OBJECTDIR}/FreeRTOS/portable/port.o ${OBJECTDIR}/FreeRTOS/serial/serial.o ${OBJECTDIR}/FreeRTOS/list.o ${OBJECTDIR}/FreeRTOS/tasks.o ${OBJECTDIR}/FreeRTOS/croutine.o ${OBJECTDIR}/FreeRTOS/queue.o ${OBJECTDIR}/newmain.o ${OBJECTDIR}/FreeRTOS/event_groups.o

# Source Files
SOURCEFILES=FreeRTOS/portable/heap_1.c FreeRTOS/portable/port.c FreeRTOS/serial/serial.c FreeRTOS/list.c FreeRTOS/tasks.c FreeRTOS/croutine.c FreeRTOS/queue.c newmain.c FreeRTOS/event_groups.c



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/lista2_exercicio14_1.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4550
MP_PROCESSOR_OPTION_LD=18f4550
MP_LINKER_DEBUG_OPTION=  -u_DEBUGSTACK
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/FreeRTOS/portable/heap_1.o: FreeRTOS/portable/heap_1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FreeRTOS/portable" 
	@${RM} ${OBJECTDIR}/FreeRTOS/portable/heap_1.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/portable/heap_1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/include" -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/portable" -I"/home/sybreon/MPLABXProjects/RTOSC18.X" -ms -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/FreeRTOS/portable/heap_1.o   FreeRTOS/portable/heap_1.c 
	@${DEP_GEN} -d ${OBJECTDIR}/FreeRTOS/portable/heap_1.o 
	@${FIXDEPS} "${OBJECTDIR}/FreeRTOS/portable/heap_1.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/FreeRTOS/portable/port.o: FreeRTOS/portable/port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FreeRTOS/portable" 
	@${RM} ${OBJECTDIR}/FreeRTOS/portable/port.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/portable/port.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/include" -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/portable" -I"/home/sybreon/MPLABXProjects/RTOSC18.X" -ms -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/FreeRTOS/portable/port.o   FreeRTOS/portable/port.c 
	@${DEP_GEN} -d ${OBJECTDIR}/FreeRTOS/portable/port.o 
	@${FIXDEPS} "${OBJECTDIR}/FreeRTOS/portable/port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/FreeRTOS/serial/serial.o: FreeRTOS/serial/serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FreeRTOS/serial" 
	@${RM} ${OBJECTDIR}/FreeRTOS/serial/serial.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/serial/serial.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/include" -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/portable" -I"/home/sybreon/MPLABXProjects/RTOSC18.X" -ms -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/FreeRTOS/serial/serial.o   FreeRTOS/serial/serial.c 
	@${DEP_GEN} -d ${OBJECTDIR}/FreeRTOS/serial/serial.o 
	@${FIXDEPS} "${OBJECTDIR}/FreeRTOS/serial/serial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/FreeRTOS/list.o: FreeRTOS/list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/list.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/list.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/include" -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/portable" -I"/home/sybreon/MPLABXProjects/RTOSC18.X" -ms -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/FreeRTOS/list.o   FreeRTOS/list.c 
	@${DEP_GEN} -d ${OBJECTDIR}/FreeRTOS/list.o 
	@${FIXDEPS} "${OBJECTDIR}/FreeRTOS/list.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/FreeRTOS/tasks.o: FreeRTOS/tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/tasks.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/tasks.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/include" -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/portable" -I"/home/sybreon/MPLABXProjects/RTOSC18.X" -ms -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/FreeRTOS/tasks.o   FreeRTOS/tasks.c 
	@${DEP_GEN} -d ${OBJECTDIR}/FreeRTOS/tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/FreeRTOS/tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/FreeRTOS/croutine.o: FreeRTOS/croutine.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/croutine.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/croutine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/include" -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/portable" -I"/home/sybreon/MPLABXProjects/RTOSC18.X" -ms -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/FreeRTOS/croutine.o   FreeRTOS/croutine.c 
	@${DEP_GEN} -d ${OBJECTDIR}/FreeRTOS/croutine.o 
	@${FIXDEPS} "${OBJECTDIR}/FreeRTOS/croutine.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/FreeRTOS/queue.o: FreeRTOS/queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/queue.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/queue.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/include" -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/portable" -I"/home/sybreon/MPLABXProjects/RTOSC18.X" -ms -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/FreeRTOS/queue.o   FreeRTOS/queue.c 
	@${DEP_GEN} -d ${OBJECTDIR}/FreeRTOS/queue.o 
	@${FIXDEPS} "${OBJECTDIR}/FreeRTOS/queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/newmain.o: newmain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/newmain.o.d 
	@${RM} ${OBJECTDIR}/newmain.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/include" -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/portable" -I"/home/sybreon/MPLABXProjects/RTOSC18.X" -ms -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/newmain.o   newmain.c 
	@${DEP_GEN} -d ${OBJECTDIR}/newmain.o 
	@${FIXDEPS} "${OBJECTDIR}/newmain.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/FreeRTOS/event_groups.o: FreeRTOS/event_groups.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/event_groups.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/event_groups.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/include" -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/portable" -I"/home/sybreon/MPLABXProjects/RTOSC18.X" -ms -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/FreeRTOS/event_groups.o   FreeRTOS/event_groups.c 
	@${DEP_GEN} -d ${OBJECTDIR}/FreeRTOS/event_groups.o 
	@${FIXDEPS} "${OBJECTDIR}/FreeRTOS/event_groups.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/FreeRTOS/portable/heap_1.o: FreeRTOS/portable/heap_1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FreeRTOS/portable" 
	@${RM} ${OBJECTDIR}/FreeRTOS/portable/heap_1.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/portable/heap_1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/include" -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/portable" -I"/home/sybreon/MPLABXProjects/RTOSC18.X" -ms -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/FreeRTOS/portable/heap_1.o   FreeRTOS/portable/heap_1.c 
	@${DEP_GEN} -d ${OBJECTDIR}/FreeRTOS/portable/heap_1.o 
	@${FIXDEPS} "${OBJECTDIR}/FreeRTOS/portable/heap_1.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/FreeRTOS/portable/port.o: FreeRTOS/portable/port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FreeRTOS/portable" 
	@${RM} ${OBJECTDIR}/FreeRTOS/portable/port.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/portable/port.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/include" -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/portable" -I"/home/sybreon/MPLABXProjects/RTOSC18.X" -ms -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/FreeRTOS/portable/port.o   FreeRTOS/portable/port.c 
	@${DEP_GEN} -d ${OBJECTDIR}/FreeRTOS/portable/port.o 
	@${FIXDEPS} "${OBJECTDIR}/FreeRTOS/portable/port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/FreeRTOS/serial/serial.o: FreeRTOS/serial/serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FreeRTOS/serial" 
	@${RM} ${OBJECTDIR}/FreeRTOS/serial/serial.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/serial/serial.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/include" -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/portable" -I"/home/sybreon/MPLABXProjects/RTOSC18.X" -ms -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/FreeRTOS/serial/serial.o   FreeRTOS/serial/serial.c 
	@${DEP_GEN} -d ${OBJECTDIR}/FreeRTOS/serial/serial.o 
	@${FIXDEPS} "${OBJECTDIR}/FreeRTOS/serial/serial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/FreeRTOS/list.o: FreeRTOS/list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/list.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/list.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/include" -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/portable" -I"/home/sybreon/MPLABXProjects/RTOSC18.X" -ms -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/FreeRTOS/list.o   FreeRTOS/list.c 
	@${DEP_GEN} -d ${OBJECTDIR}/FreeRTOS/list.o 
	@${FIXDEPS} "${OBJECTDIR}/FreeRTOS/list.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/FreeRTOS/tasks.o: FreeRTOS/tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/tasks.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/tasks.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/include" -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/portable" -I"/home/sybreon/MPLABXProjects/RTOSC18.X" -ms -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/FreeRTOS/tasks.o   FreeRTOS/tasks.c 
	@${DEP_GEN} -d ${OBJECTDIR}/FreeRTOS/tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/FreeRTOS/tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/FreeRTOS/croutine.o: FreeRTOS/croutine.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/croutine.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/croutine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/include" -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/portable" -I"/home/sybreon/MPLABXProjects/RTOSC18.X" -ms -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/FreeRTOS/croutine.o   FreeRTOS/croutine.c 
	@${DEP_GEN} -d ${OBJECTDIR}/FreeRTOS/croutine.o 
	@${FIXDEPS} "${OBJECTDIR}/FreeRTOS/croutine.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/FreeRTOS/queue.o: FreeRTOS/queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/queue.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/queue.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/include" -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/portable" -I"/home/sybreon/MPLABXProjects/RTOSC18.X" -ms -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/FreeRTOS/queue.o   FreeRTOS/queue.c 
	@${DEP_GEN} -d ${OBJECTDIR}/FreeRTOS/queue.o 
	@${FIXDEPS} "${OBJECTDIR}/FreeRTOS/queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/newmain.o: newmain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/newmain.o.d 
	@${RM} ${OBJECTDIR}/newmain.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/include" -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/portable" -I"/home/sybreon/MPLABXProjects/RTOSC18.X" -ms -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/newmain.o   newmain.c 
	@${DEP_GEN} -d ${OBJECTDIR}/newmain.o 
	@${FIXDEPS} "${OBJECTDIR}/newmain.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/FreeRTOS/event_groups.o: FreeRTOS/event_groups.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/event_groups.o.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/event_groups.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/include" -I"/home/sybreon/MPLABXProjects/RTOSC18.X/FreeRTOS/portable" -I"/home/sybreon/MPLABXProjects/RTOSC18.X" -ms -oa- -Ls -o-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/FreeRTOS/event_groups.o   FreeRTOS/event_groups.c 
	@${DEP_GEN} -d ${OBJECTDIR}/FreeRTOS/event_groups.o 
	@${FIXDEPS} "${OBJECTDIR}/FreeRTOS/event_groups.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/lista2_exercicio14_1.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    18f8722_g.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "18f8722_g.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_SIMULATOR=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/lista2_exercicio14_1.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/lista2_exercicio14_1.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   18f8722_g.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "18f8722_g.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/lista2_exercicio14_1.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
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
