################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../main.cpp 

CPP_DEPS += \
./main.pp 

OBJS += \
./main.obj 

CPP_DEPS__QUOTED += \
"main.pp" 

OBJS__QUOTED += \
"main.obj" 

CPP_SRCS__QUOTED += \
"../main.cpp" 


# Each subdirectory must supply rules for building sources it contributes
main.obj: ../main.cpp $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/home/lexa/CCS/ccsv5/tools/compiler/c6000/bin/cl6x" -mv6700 -g -O2 --include_path="/home/lexa/CCS/ccsv5/tools/compiler/c6000/include"  --diag_warning=225 --abi=coffabi --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


