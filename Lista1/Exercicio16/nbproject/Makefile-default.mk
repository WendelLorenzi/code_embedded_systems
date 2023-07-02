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
FINAL_IMAGE=${DISTDIR}/Exercicio14.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Exercicio14.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=FreeRTOS/portable/heap_1.c FreeRTOS/portable/port.c FreeRTOS/serial/serial.c FreeRTOS/list.c FreeRTOS/tasks.c FreeRTOS/croutine.c FreeRTOS/queue.c FreeRTOS/event_groups.c newmain.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/FreeRTOS/portable/heap_1.p1 ${OBJECTDIR}/FreeRTOS/portable/port.p1 ${OBJECTDIR}/FreeRTOS/serial/serial.p1 ${OBJECTDIR}/FreeRTOS/list.p1 ${OBJECTDIR}/FreeRTOS/tasks.p1 ${OBJECTDIR}/FreeRTOS/croutine.p1 ${OBJECTDIR}/FreeRTOS/queue.p1 ${OBJECTDIR}/FreeRTOS/event_groups.p1 ${OBJECTDIR}/newmain.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/FreeRTOS/portable/heap_1.p1.d ${OBJECTDIR}/FreeRTOS/portable/port.p1.d ${OBJECTDIR}/FreeRTOS/serial/serial.p1.d ${OBJECTDIR}/FreeRTOS/list.p1.d ${OBJECTDIR}/FreeRTOS/tasks.p1.d ${OBJECTDIR}/FreeRTOS/croutine.p1.d ${OBJECTDIR}/FreeRTOS/queue.p1.d ${OBJECTDIR}/FreeRTOS/event_groups.p1.d ${OBJECTDIR}/newmain.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/FreeRTOS/portable/heap_1.p1 ${OBJECTDIR}/FreeRTOS/portable/port.p1 ${OBJECTDIR}/FreeRTOS/serial/serial.p1 ${OBJECTDIR}/FreeRTOS/list.p1 ${OBJECTDIR}/FreeRTOS/tasks.p1 ${OBJECTDIR}/FreeRTOS/croutine.p1 ${OBJECTDIR}/FreeRTOS/queue.p1 ${OBJECTDIR}/FreeRTOS/event_groups.p1 ${OBJECTDIR}/newmain.p1

# Source Files
SOURCEFILES=FreeRTOS/portable/heap_1.c FreeRTOS/portable/port.c FreeRTOS/serial/serial.c FreeRTOS/list.c FreeRTOS/tasks.c FreeRTOS/croutine.c FreeRTOS/queue.c FreeRTOS/event_groups.c newmain.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Exercicio14.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4550
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/FreeRTOS/portable/heap_1.p1: FreeRTOS/portable/heap_1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/FreeRTOS/portable" 
	@${RM} ${OBJECTDIR}/FreeRTOS/portable/heap_1.p1.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/portable/heap_1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/FreeRTOS/portable/heap_1.p1 FreeRTOS/portable/heap_1.c 
	@-${MV} ${OBJECTDIR}/FreeRTOS/portable/heap_1.d ${OBJECTDIR}/FreeRTOS/portable/heap_1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/FreeRTOS/portable/heap_1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/FreeRTOS/portable/port.p1: FreeRTOS/portable/port.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/FreeRTOS/portable" 
	@${RM} ${OBJECTDIR}/FreeRTOS/portable/port.p1.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/portable/port.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/FreeRTOS/portable/port.p1 FreeRTOS/portable/port.c 
	@-${MV} ${OBJECTDIR}/FreeRTOS/portable/port.d ${OBJECTDIR}/FreeRTOS/portable/port.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/FreeRTOS/portable/port.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/FreeRTOS/serial/serial.p1: FreeRTOS/serial/serial.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/FreeRTOS/serial" 
	@${RM} ${OBJECTDIR}/FreeRTOS/serial/serial.p1.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/serial/serial.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/FreeRTOS/serial/serial.p1 FreeRTOS/serial/serial.c 
	@-${MV} ${OBJECTDIR}/FreeRTOS/serial/serial.d ${OBJECTDIR}/FreeRTOS/serial/serial.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/FreeRTOS/serial/serial.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/FreeRTOS/list.p1: FreeRTOS/list.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/list.p1.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/list.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/FreeRTOS/list.p1 FreeRTOS/list.c 
	@-${MV} ${OBJECTDIR}/FreeRTOS/list.d ${OBJECTDIR}/FreeRTOS/list.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/FreeRTOS/list.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/FreeRTOS/tasks.p1: FreeRTOS/tasks.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/tasks.p1.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/tasks.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/FreeRTOS/tasks.p1 FreeRTOS/tasks.c 
	@-${MV} ${OBJECTDIR}/FreeRTOS/tasks.d ${OBJECTDIR}/FreeRTOS/tasks.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/FreeRTOS/tasks.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/FreeRTOS/croutine.p1: FreeRTOS/croutine.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/croutine.p1.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/croutine.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/FreeRTOS/croutine.p1 FreeRTOS/croutine.c 
	@-${MV} ${OBJECTDIR}/FreeRTOS/croutine.d ${OBJECTDIR}/FreeRTOS/croutine.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/FreeRTOS/croutine.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/FreeRTOS/queue.p1: FreeRTOS/queue.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/queue.p1.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/queue.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/FreeRTOS/queue.p1 FreeRTOS/queue.c 
	@-${MV} ${OBJECTDIR}/FreeRTOS/queue.d ${OBJECTDIR}/FreeRTOS/queue.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/FreeRTOS/queue.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/FreeRTOS/event_groups.p1: FreeRTOS/event_groups.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/event_groups.p1.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/event_groups.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/FreeRTOS/event_groups.p1 FreeRTOS/event_groups.c 
	@-${MV} ${OBJECTDIR}/FreeRTOS/event_groups.d ${OBJECTDIR}/FreeRTOS/event_groups.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/FreeRTOS/event_groups.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/newmain.p1: newmain.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/newmain.p1.d 
	@${RM} ${OBJECTDIR}/newmain.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/newmain.p1 newmain.c 
	@-${MV} ${OBJECTDIR}/newmain.d ${OBJECTDIR}/newmain.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/newmain.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/FreeRTOS/portable/heap_1.p1: FreeRTOS/portable/heap_1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/FreeRTOS/portable" 
	@${RM} ${OBJECTDIR}/FreeRTOS/portable/heap_1.p1.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/portable/heap_1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/FreeRTOS/portable/heap_1.p1 FreeRTOS/portable/heap_1.c 
	@-${MV} ${OBJECTDIR}/FreeRTOS/portable/heap_1.d ${OBJECTDIR}/FreeRTOS/portable/heap_1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/FreeRTOS/portable/heap_1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/FreeRTOS/portable/port.p1: FreeRTOS/portable/port.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/FreeRTOS/portable" 
	@${RM} ${OBJECTDIR}/FreeRTOS/portable/port.p1.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/portable/port.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/FreeRTOS/portable/port.p1 FreeRTOS/portable/port.c 
	@-${MV} ${OBJECTDIR}/FreeRTOS/portable/port.d ${OBJECTDIR}/FreeRTOS/portable/port.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/FreeRTOS/portable/port.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/FreeRTOS/serial/serial.p1: FreeRTOS/serial/serial.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/FreeRTOS/serial" 
	@${RM} ${OBJECTDIR}/FreeRTOS/serial/serial.p1.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/serial/serial.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/FreeRTOS/serial/serial.p1 FreeRTOS/serial/serial.c 
	@-${MV} ${OBJECTDIR}/FreeRTOS/serial/serial.d ${OBJECTDIR}/FreeRTOS/serial/serial.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/FreeRTOS/serial/serial.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/FreeRTOS/list.p1: FreeRTOS/list.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/list.p1.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/list.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/FreeRTOS/list.p1 FreeRTOS/list.c 
	@-${MV} ${OBJECTDIR}/FreeRTOS/list.d ${OBJECTDIR}/FreeRTOS/list.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/FreeRTOS/list.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/FreeRTOS/tasks.p1: FreeRTOS/tasks.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/tasks.p1.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/tasks.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/FreeRTOS/tasks.p1 FreeRTOS/tasks.c 
	@-${MV} ${OBJECTDIR}/FreeRTOS/tasks.d ${OBJECTDIR}/FreeRTOS/tasks.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/FreeRTOS/tasks.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/FreeRTOS/croutine.p1: FreeRTOS/croutine.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/croutine.p1.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/croutine.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/FreeRTOS/croutine.p1 FreeRTOS/croutine.c 
	@-${MV} ${OBJECTDIR}/FreeRTOS/croutine.d ${OBJECTDIR}/FreeRTOS/croutine.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/FreeRTOS/croutine.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/FreeRTOS/queue.p1: FreeRTOS/queue.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/queue.p1.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/queue.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/FreeRTOS/queue.p1 FreeRTOS/queue.c 
	@-${MV} ${OBJECTDIR}/FreeRTOS/queue.d ${OBJECTDIR}/FreeRTOS/queue.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/FreeRTOS/queue.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/FreeRTOS/event_groups.p1: FreeRTOS/event_groups.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/FreeRTOS" 
	@${RM} ${OBJECTDIR}/FreeRTOS/event_groups.p1.d 
	@${RM} ${OBJECTDIR}/FreeRTOS/event_groups.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/FreeRTOS/event_groups.p1 FreeRTOS/event_groups.c 
	@-${MV} ${OBJECTDIR}/FreeRTOS/event_groups.d ${OBJECTDIR}/FreeRTOS/event_groups.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/FreeRTOS/event_groups.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/newmain.p1: newmain.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/newmain.p1.d 
	@${RM} ${OBJECTDIR}/newmain.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/newmain.p1 newmain.c 
	@-${MV} ${OBJECTDIR}/newmain.d ${OBJECTDIR}/newmain.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/newmain.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
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
${DISTDIR}/Exercicio14.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    18f8722_g.lkr
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Exercicio14.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Exercicio14.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/Exercicio14.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/Exercicio14.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   18f8722_g.lkr
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Exercicio14.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Exercicio14.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
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
