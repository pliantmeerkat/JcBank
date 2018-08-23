################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/db/dbProcessor.cpp 

OBJS += \
./src/db/dbProcessor.o 

CPP_DEPS += \
./src/db/dbProcessor.d 


# Each subdirectory must supply rules for building sources it contributes
src/db/%.o: ../src/db/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/Users/jackbranch/eclipse-workspace/C++Kata/external" -I"/Users/jackbranch/eclipse-workspace/C++Kata/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


