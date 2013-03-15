################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/LED.c" \
"../Sources/MCG.c" \
"../Sources/MCU_init.c" \
"../Sources/Puertos.c" \
"../Sources/UART.c" \
"../Sources/main.c" \
"../Sources/sa_mtb.c" \

C_SRCS += \
../Sources/LED.c \
../Sources/MCG.c \
../Sources/MCU_init.c \
../Sources/Puertos.c \
../Sources/UART.c \
../Sources/main.c \
../Sources/sa_mtb.c \

OBJS += \
./Sources/LED_c.obj \
./Sources/MCG_c.obj \
./Sources/MCU_init_c.obj \
./Sources/Puertos_c.obj \
./Sources/UART_c.obj \
./Sources/main_c.obj \
./Sources/sa_mtb_c.obj \

C_DEPS += \
./Sources/LED.d \
./Sources/MCG.d \
./Sources/MCU_init.d \
./Sources/Puertos.d \
./Sources/UART.d \
./Sources/main.d \
./Sources/sa_mtb.d \

OBJS_QUOTED += \
"./Sources/LED_c.obj" \
"./Sources/MCG_c.obj" \
"./Sources/MCU_init_c.obj" \
"./Sources/Puertos_c.obj" \
"./Sources/UART_c.obj" \
"./Sources/main_c.obj" \
"./Sources/sa_mtb_c.obj" \

C_DEPS_QUOTED += \
"./Sources/LED.d" \
"./Sources/MCG.d" \
"./Sources/MCU_init.d" \
"./Sources/Puertos.d" \
"./Sources/UART.d" \
"./Sources/main.d" \
"./Sources/sa_mtb.d" \

OBJS_OS_FORMAT += \
./Sources/LED_c.obj \
./Sources/MCG_c.obj \
./Sources/MCU_init_c.obj \
./Sources/Puertos_c.obj \
./Sources/UART_c.obj \
./Sources/main_c.obj \
./Sources/sa_mtb_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/LED_c.obj: ../Sources/LED.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/LED.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/LED_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/MCG_c.obj: ../Sources/MCG.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/MCG.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/MCG_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/MCU_init_c.obj: ../Sources/MCU_init.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/MCU_init.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/MCU_init_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Puertos_c.obj: ../Sources/Puertos.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Puertos.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/Puertos_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/UART_c.obj: ../Sources/UART.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/UART.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/UART_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/main_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/sa_mtb_c.obj: ../Sources/sa_mtb.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/sa_mtb.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/sa_mtb_c.obj"
	@echo 'Finished building: $<'
	@echo ' '


