################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../external/gtest/gtest-all.cc 

CC_DEPS += \
./external/gtest/gtest-all.d 

OBJS += \
./external/gtest/gtest-all.o 


# Each subdirectory must supply rules for building sources it contributes
external/gtest/%.o: ../external/gtest/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/Users/jackbranch/eclipse-workspace/C++Kata/external" -I"/Users/jackbranch/eclipse-workspace/C++Kata/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


