################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/EXTInterrupt/EXTInterrupt_Programme.c 

C_DEPS += \
./MCAL/EXTInterrupt/EXTInterrupt_Programme.d 

OBJS += \
./MCAL/EXTInterrupt/EXTInterrupt_Programme.o 


# Each subdirectory must supply rules for building sources it contributes
MCAL/EXTInterrupt/%.o: ../MCAL/EXTInterrupt/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


