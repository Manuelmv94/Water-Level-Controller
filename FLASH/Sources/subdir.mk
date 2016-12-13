################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/ADC.c" \
"../Sources/MTIM.c" \
"../Sources/TimersManager.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/ADC.c \
../Sources/MTIM.c \
../Sources/TimersManager.c \
../Sources/main.c \

OBJS += \
./Sources/ADC_c.obj \
./Sources/MTIM_c.obj \
./Sources/TimersManager_c.obj \
./Sources/main_c.obj \

OBJS_QUOTED += \
"./Sources/ADC_c.obj" \
"./Sources/MTIM_c.obj" \
"./Sources/TimersManager_c.obj" \
"./Sources/main_c.obj" \

C_DEPS += \
./Sources/ADC_c.d \
./Sources/MTIM_c.d \
./Sources/TimersManager_c.d \
./Sources/main_c.d \

C_DEPS_QUOTED += \
"./Sources/ADC_c.d" \
"./Sources/MTIM_c.d" \
"./Sources/TimersManager_c.d" \
"./Sources/main_c.d" \

OBJS_OS_FORMAT += \
./Sources/ADC_c.obj \
./Sources/MTIM_c.obj \
./Sources/TimersManager_c.obj \
./Sources/main_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/ADC_c.obj: ../Sources/ADC.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/ADC.args" -ObjN="Sources/ADC_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/MTIM_c.obj: ../Sources/MTIM.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/MTIM.args" -ObjN="Sources/MTIM_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/TimersManager_c.obj: ../Sources/TimersManager.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/TimersManager.args" -ObjN="Sources/TimersManager_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/main.args" -ObjN="Sources/main_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


