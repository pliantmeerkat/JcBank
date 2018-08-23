################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../tests/authenticationTest.cpp \
../tests/bankAccountTest.cpp \
../tests/dbProcessorTest.cpp \
../tests/paymentProcessorTest.cpp \
../tests/transactionTest.cpp 

OBJS += \
./tests/authenticationTest.o \
./tests/bankAccountTest.o \
./tests/dbProcessorTest.o \
./tests/paymentProcessorTest.o \
./tests/transactionTest.o 

CPP_DEPS += \
./tests/authenticationTest.d \
./tests/bankAccountTest.d \
./tests/dbProcessorTest.d \
./tests/paymentProcessorTest.d \
./tests/transactionTest.d 


# Each subdirectory must supply rules for building sources it contributes
tests/%.o: ../tests/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/Users/jackbranch/eclipse-workspace/C++Kata/db" -I"/Users/jackbranch/eclipse-workspace/C++Kata/external" -I"/Users/jackbranch/eclipse-workspace/C++Kata/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


