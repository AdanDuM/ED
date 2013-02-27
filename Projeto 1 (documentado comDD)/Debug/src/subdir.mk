################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Caixa.cpp \
../src/CaixaEspecial.cpp \
../src/Cliente.cpp \
../src/ElementoDaListaCircular.cpp \
../src/ElementoDeFila.cpp \
../src/ListaCircular.cpp \
../src/Main.cpp \
../src/Supermercado.cpp 

OBJS += \
./src/Caixa.o \
./src/CaixaEspecial.o \
./src/Cliente.o \
./src/ElementoDaListaCircular.o \
./src/ElementoDeFila.o \
./src/ListaCircular.o \
./src/Main.o \
./src/Supermercado.o 

CPP_DEPS += \
./src/Caixa.d \
./src/CaixaEspecial.d \
./src/Cliente.d \
./src/ElementoDaListaCircular.d \
./src/ElementoDeFila.d \
./src/ListaCircular.d \
./src/Main.d \
./src/Supermercado.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


