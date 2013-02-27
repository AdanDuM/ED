################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ElementoFila.cpp \
../src/ElementoLista.cpp \
../src/Fila.cpp \
../src/InfoLista.cpp \
../src/ListaDupla.cpp \
../src/Main.cpp 

OBJS += \
./src/ElementoFila.o \
./src/ElementoLista.o \
./src/Fila.o \
./src/InfoLista.o \
./src/ListaDupla.o \
./src/Main.o 

CPP_DEPS += \
./src/ElementoFila.d \
./src/ElementoLista.d \
./src/Fila.d \
./src/InfoLista.d \
./src/ListaDupla.d \
./src/Main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


