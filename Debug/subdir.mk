################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CircularBuffer.c \
../LMS.c \
../main.c 

OBJS += \
./CircularBuffer.obj \
./LMS.obj \
./main.obj 

C_DEPS += \
./CircularBuffer.pp \
./LMS.pp \
./main.pp 

C_DEPS__QUOTED += \
"CircularBuffer.pp" \
"LMS.pp" \
"main.pp" 

OBJS__QUOTED += \
"CircularBuffer.obj" \
"LMS.obj" \
"main.obj" 

C_SRCS__QUOTED += \
"../CircularBuffer.c" \
"../LMS.c" \
"../main.c" 


# Each subdirectory must supply rules for building sources it contributes
CircularBuffer.obj: ../CircularBuffer.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/home/lexa/CCS/ccsv5/tools/compiler/c6000/bin/cl6x" -mv6700 -g --include_path="/home/lexa/CCS/ccsv5/tools/compiler/c6000/include" --include_path="/home/lexa/CCS/ccsv5/xdais_7_20_00_07/packages/ti/xdais" --include_path="/home/lexa/CCS/ccsv5/xdctools_3_20_08_88/packages"  --diag_warning=225 --abi=coffabi --preproc_with_compile --preproc_dependency="CircularBuffer.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

LMS.obj: ../LMS.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/home/lexa/CCS/ccsv5/tools/compiler/c6000/bin/cl6x" -mv6700 -g --include_path="/home/lexa/CCS/ccsv5/tools/compiler/c6000/include" --include_path="/home/lexa/CCS/ccsv5/xdais_7_20_00_07/packages/ti/xdais" --include_path="/home/lexa/CCS/ccsv5/xdctools_3_20_08_88/packages"  --diag_warning=225 --abi=coffabi --preproc_with_compile --preproc_dependency="LMS.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/home/lexa/CCS/ccsv5/tools/compiler/c6000/bin/cl6x" -mv6700 -g --include_path="/home/lexa/CCS/ccsv5/tools/compiler/c6000/include" --include_path="/home/lexa/CCS/ccsv5/xdais_7_20_00_07/packages/ti/xdais" --include_path="/home/lexa/CCS/ccsv5/xdctools_3_20_08_88/packages"  --diag_warning=225 --abi=coffabi --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


