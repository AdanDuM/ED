################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Disco.cpp \
../src/Main.cpp \
../src/Pilha.cpp \
../src/TorresDeHanoi.cpp 

OBJS += \
./src/Disco.o \
./src/Main.o \
./src/Pilha.o \
./src/TorresDeHanoi.o 

CPP_DEPS += \
./src/Disco.d \
./src/Main.d \
./src/Pilha.d \
./src/TorresDeHanoi.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


