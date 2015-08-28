################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Logic/LogicDuckMove/Move.cpp 

OBJS += \
./Logic/LogicDuckMove/Move.o 

CPP_DEPS += \
./Logic/LogicDuckMove/Move.d 


# Each subdirectory must supply rules for building sources it contributes
Logic/LogicDuckMove/%.o: ../Logic/LogicDuckMove/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


