################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/bankAccount.cpp \
../src/main.cpp \
../src/paymentProcessor.cpp \
../src/transaction.cpp 

OBJS += \
./src/bankAccount.o \
./src/main.o \
./src/paymentProcessor.o \
./src/transaction.o 

CPP_DEPS += \
./src/bankAccount.d \
./src/main.d \
./src/paymentProcessor.d \
./src/transaction.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/Users/jackbranch/eclipse-workspace/C++Kata/external" -I"/Users/jackbranch/eclipse-workspace/C++Kata/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


