#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "SimpleSerial.h"

enum ModeType
{
	FULL, SAFE
};

class Roomba
{
	public:

		Roomba(std::string portName, unsigned int baudRate) : serialPort(portName, baudRate), outFile("debug.kek")
		{
			debugMode = true;
			if(debugMode)
			{
				std::cout << "New roomba object created." << std::endl;
				std::cout << "\tPORT: " << portName << std::endl;
				std::cout << "\tBAUD: " << baudRate << std::endl;
			}
		}

		bool openOI();
		bool setMode(ModeType m);
		bool setLED(bool playBtn, bool advBtn, unsigned char color, unsigned char intensity);
		bool driveDirect(unsigned char right_hi, unsigned char right_lo, unsigned char left_hi, unsigned char left_lo);
		bool drive(unsigned char vel_hi, unsigned char vel_lo, unsigned char rad_hi, unsigned char rad_lo);
		bool waitTime(unsigned char time);
		bool waitAng(unsigned char ang_hi, unsigned char ang_lo);
		void debugOff(){outFile.close(); debugMode = false;}
	private:
		bool debugMode;
		SimpleSerial serialPort;
		std::ofstream outFile;

};

