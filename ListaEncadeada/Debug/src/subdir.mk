################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CabecaDeLista.cpp \
../src/ElementoDeLista.cpp \
../src/InfoLista.cpp \
../src/Main.cpp 

OBJS += \
./src/CabecaDeLista.o \
./src/ElementoDeLista.o \
./src/InfoLista.o \
./src/Main.o 

CPP_DEPS += \
./src/CabecaDeLista.d \
./src/ElementoDeLista.d \
./src/InfoLista.d \
./src/Main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


