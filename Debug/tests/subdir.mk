################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../tests/bankAccountTest.cpp \
../tests/paymentProcessorTest.cpp \
../tests/transactionTest.cpp 

OBJS += \
./tests/bankAccountTest.o \
./tests/paymentProcessorTest.o \
./tests/transactionTest.o 

CPP_DEPS += \
./tests/bankAccountTest.d \
./tests/paymentProcessorTest.d \
./tests/transactionTest.d 


# Each subdirectory must supply rules for building sources it contributes
tests/%.o: ../tests/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/Users/jackbranch/eclipse-workspace/C++Kata/external" -I"/Users/jackbranch/eclipse-workspace/C++Kata/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


