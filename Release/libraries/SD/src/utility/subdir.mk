################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src\utility\Sd2Card.cpp \
C:\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src\utility\SdFile.cpp \
C:\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src\utility\SdVolume.cpp 

LINK_OBJ += \
.\libraries\SD\src\utility\Sd2Card.cpp.o \
.\libraries\SD\src\utility\SdFile.cpp.o \
.\libraries\SD\src\utility\SdVolume.cpp.o 

CPP_DEPS += \
.\libraries\SD\src\utility\Sd2Card.cpp.d \
.\libraries\SD\src\utility\SdFile.cpp.d \
.\libraries\SD\src\utility\SdVolume.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\SD\src\utility\Sd2Card.cpp.o: C:\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src\utility\Sd2Card.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.2\cores\arduino" -I"C:\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.2\variants\mega" -I"C:\Users\TooT\Documents\Arduino\libraries\VictronVEDirectArduino\src" -I"C:\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src" -I"C:\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.2\libraries\SPI\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\SD\src\utility\SdFile.cpp.o: C:\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src\utility\SdFile.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.2\cores\arduino" -I"C:\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.2\variants\mega" -I"C:\Users\TooT\Documents\Arduino\libraries\VictronVEDirectArduino\src" -I"C:\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src" -I"C:\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.2\libraries\SPI\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\SD\src\utility\SdVolume.cpp.o: C:\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src\utility\SdVolume.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Sloeber\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"C:\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.2\cores\arduino" -I"C:\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.2\variants\mega" -I"C:\Users\TooT\Documents\Arduino\libraries\VictronVEDirectArduino\src" -I"C:\Sloeber\arduinoPlugin\libraries\SD\1.2.4\src" -I"C:\Sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.8.2\libraries\SPI\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


