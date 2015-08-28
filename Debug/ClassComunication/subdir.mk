################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ClassComunication/Facade.cpp \
../ClassComunication/Observer.cpp 

OBJS += \
./ClassComunication/Facade.o \
./ClassComunication/Observer.o 

CPP_DEPS += \
./ClassComunication/Facade.d \
./ClassComunication/Observer.d 


# Each subdirectory must supply rules for building sources it contributes
ClassComunication/%.o: ../ClassComunication/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


