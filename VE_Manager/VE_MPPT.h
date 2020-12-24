/*
 * VE_MPPT.h
 *
 *  Created on: 27 sept. 2020
 *      Author: TooT
 */

#ifndef VE_MPPT_H_
#define VE_MPPT_H_

#include "Arduino.h"
#include "VEDirect.h"
#include "SPI.h"
#include "SD.h"

namespace VE_Manager
{

	class VE_MPPT : public VEDirect
	{
		public:
			VE_MPPT(HardwareSerial &HWSerial, bool log = false, int logPeriod = 1);
			void read();
			void enableLog(uint32_t logPeriod);
			void log(uint32_t dt);

		public:
			float MainBatteryVoltage;
			float PanelVoltage;
			float PanelPower;
			float BatteryCurrent;
			float LoadCurrent;
			bool OutputState;
			bool RelayState;
			float YieldTotal;
			float YieldToday;
			float MaxPowerToday;
			float YieldYesterday;
			float MaxPowerYesterday;
			int ErrorCode;
			int StateOfOperation;
			String Firmware;
			String ProductID;
			int DaySequence;

		private:
			bool mEnableLog;
			File mFile;

			uint64_t mLogTimer;
			uint64_t mLogPeriod;
	};

}

#endif /* VE_MPPT_H_ */
