#include "Arduino.h"
#include "VE_Manager/VE_MPPT.h"
#include "SPI.h"
#include "SD.h"

#define SERIAL_PAUSE_TIMEOUT 	uint32_t(30*1000)
#define SERIAL_PAUSE_AT_BOOT	uint32_t(30*1000)

using namespace VE_Manager;

VE_MPPT *MPPT;
File CurrentFile;

bool SerialPause_Boot = true;
bool SerialPause = true;
uint32_t SerialPause_Counter;

uint32_t previousTime = 0;

void setup()
{
	pinMode(13, OUTPUT);

	Serial.begin(19200);
	Serial1.begin(19200);
	//Serial.print("SD init... ");

	if (!SD.begin(49))
	{
	  //Serial.println("Fail");
	  return;
	}

	else
	{
		//Serial.println("OK");
	}

	CurrentFile = SD.open("datalog.log", FILE_WRITE);

	/*if(CurrentFile)
		//Serial.println("\tSD available for write");
	else
	{
		//Serial.println("\tSD not available for write...");
		while(1);
	}
*/
	CurrentFile.close();

	//Serial.println("MPPT init");

	//Serial.println("Starting");

	previousTime = millis();

}


void loop()
{

	int dt = millis() - previousTime;
	previousTime = millis();

	if(Serial.available())
	{
		SerialPause_Counter = 0;
		SerialPause = true;

		digitalWrite(13, HIGH);

		Serial1.write(Serial.read());
	}

	if(SerialPause)
	{
		SerialPause_Counter += dt;

		if(Serial1.available())
			Serial.write(Serial1.read());

		if(!SerialPause_Boot)
		{
			if(SerialPause_Counter > SERIAL_PAUSE_TIMEOUT)
			{
				SerialPause = false;
				digitalWrite(13, LOW);
			}
		}

		else
		{
			if(SerialPause_Counter > SERIAL_PAUSE_AT_BOOT)
			{
				SerialPause = false;
				SerialPause_Boot = false;
				digitalWrite(13, LOW);

				MPPT = new VE_MPPT(Serial1, true, 1);
				MPPT->enableLog(1);
			}
		}
	}


	if(!SerialPause)
	{
		MPPT->read();
		MPPT->log(dt);

		digitalWrite(13, HIGH);
		delay(100);
		digitalWrite(13, LOW);
	}

	delay(1);

}
