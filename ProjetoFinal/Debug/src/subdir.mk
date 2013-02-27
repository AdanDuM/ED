################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ArvoreB.cpp \
../src/Dados.cpp \
../src/Main.cpp \
../src/Nodo.cpp 

OBJS += \
./src/ArvoreB.o \
./src/Dados.o \
./src/Main.o \
./src/Nodo.o 

CPP_DEPS += \
./src/ArvoreB.d \
./src/Dados.d \
./src/Main.d \
./src/Nodo.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


