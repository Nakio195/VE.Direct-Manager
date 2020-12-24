/*
 * VE_MPPT.cpp
 *
 *  Created on: 27 sept. 2020
 *      Author: TooT
 */

#include "VE_MPPT.h"

namespace VE_Manager
{

VE_MPPT::VE_MPPT(HardwareSerial &HWSerial, bool log, int logPeriod) : VEDirect(HWSerial)
{
	Serial.print("\tMPPT base code init... ");
	if(begin())
		Serial.println("OK");
	else
		Serial.println("Fail");

	MainBatteryVoltage = 0;
	PanelVoltage = 0;
	PanelPower = 0;
	BatteryCurrent = 0;
	LoadCurrent = 0;
	OutputState = false;
	RelayState = false;
	YieldTotal = 0;
	YieldToday = 0;
	MaxPowerToday = 0;
	YieldYesterday = 0;
	MaxPowerYesterday = 0;
	ErrorCode = 0;
	StateOfOperation = 0;
	Firmware = String("");
	ProductID = String("");
	DaySequence = 0;

	mEnableLog = log;
	mLogPeriod = logPeriod*60*1000;	// Period is in mn
	mLogTimer = 0;

	if(mEnableLog)
	{
		mFile = SD.open("MPPT.log", FILE_WRITE);
		if(mFile.availableForWrite())
		{
			mFile.println("Starting log");
			mFile.close();
		}
		else
			mEnableLog = false;
	}

}

void VE_MPPT::read()
{
	MainBatteryVoltage = VEDirect::read(VE_VOLTAGE)*0.001;
	PanelVoltage = VEDirect::read(VE_PANEL_VOLTAGE)*0.001;
	PanelPower = VEDirect::read(VE_PANEL_POWER);
	BatteryCurrent = VEDirect::read(VE_CURRENT)*0.001;
	LoadCurrent = VEDirect::read(VE_BATTERY_LOAD_CURRENT)*0.001;
	OutputState = VEDirect::read(VE_LOAD_STATE);
	RelayState = VEDirect::read(VE_RELAY_STATE);
	YieldTotal = VEDirect::read(VE_YIELD_TOTAL)*0.01;
	YieldToday = VEDirect::read(VE_YIELD_TODAY)*0.01;
	MaxPowerToday = VEDirect::read(VE_MAX_DAILY_POWER);
	YieldYesterday = VEDirect::read(VE_YIELD_YESTERDAY)*0.01;
	MaxPowerYesterday = VEDirect::read(VE_MAX_YESTERDAY_POWER);
	ErrorCode = VEDirect::read(VE_ERROR_CODE);
	StateOfOperation = VEDirect::read(VE_STATE_OF_OPERATION);
	Firmware = String(VEDirect::read(VE_FW));
	ProductID = String(VEDirect::read(VE_PID), HEX);
	DaySequence = VEDirect::read(VE_DAY_SEQUENCE_NUMBER);
}

void VE_MPPT::enableLog(uint32_t logPeriod)
{
	mEnableLog = true;
	mLogPeriod = logPeriod*60*1000;
}

void VE_MPPT::log(uint32_t dt)
{
	if(mEnableLog)
	{
		mLogTimer += dt;

		if(mLogTimer > mLogPeriod)
		{
			mFile = SD.open("MPPT.log", FILE_WRITE);
			mLogTimer = 0;

			if(mFile.availableForWrite())
			{
				Serial.println("Logging MPPT state...");
				mFile.print(MainBatteryVoltage, 2);
				mFile.print(",");
				mFile.print(PanelVoltage, 2);
				mFile.print(",");
				mFile.print(PanelPower, 2);
				mFile.print(",");
				mFile.print(BatteryCurrent, 2);
				mFile.print(",");
				mFile.print(LoadCurrent, 2);
				mFile.print(",");
				mFile.print(OutputState);
				mFile.print(",");
				mFile.print(RelayState);
				mFile.print(",");
				mFile.print(YieldTotal, 2);
				mFile.print(",");
				mFile.print(YieldToday, 2);
				mFile.print(",");
				mFile.print(MaxPowerToday);
				mFile.print(",");
				mFile.print(YieldYesterday, 2);
				mFile.print(",");
				mFile.print(MaxPowerYesterday);
				mFile.print(",");
				mFile.print(ErrorCode);
				mFile.print(",");
				mFile.print(StateOfOperation);
				mFile.print(",");
				mFile.print(Firmware);
				mFile.print(",");
				mFile.print(ProductID);
				mFile.print(",");
				mFile.println(DaySequence);

				mFile.close();
			}

			else
			{
				mEnableLog = false;
				Serial.println("SD unavailable stop logging");
			}
		}
	}
}

} /* namespace VE_Manager */
