################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Logic/LogicDucks/Duck.cpp \
../Logic/LogicDucks/DuckManager.cpp 

OBJS += \
./Logic/LogicDucks/Duck.o \
./Logic/LogicDucks/DuckManager.o 

CPP_DEPS += \
./Logic/LogicDucks/Duck.d \
./Logic/LogicDucks/DuckManager.d 


# Each subdirectory must supply rules for building sources it contributes
Logic/LogicDucks/%.o: ../Logic/LogicDucks/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


