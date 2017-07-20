#include "stdafx.h"
#include "Roomba.h"
#include <iostream>
#include <string>
#include <time.h>

int main()
{
	using namespace std;

	Roomba r("COM1", 57600);
	r.debugOff();
	r.openOI();
	r.setMode(FULL);

	time_t startTime = time(NULL);
	unsigned char color = 0;
	while(true)
	{
		r.setLED(true, true, color, 255);
		SHORT upKeyState = GetAsyncKeyState(VK_UP);
		SHORT downKeyState = GetAsyncKeyState(VK_DOWN);
		SHORT rightKeyState = GetAsyncKeyState(VK_RIGHT);
		SHORT leftKeyState = GetAsyncKeyState(VK_LEFT);
		SHORT spaceKeyState = GetAsyncKeyState(VK_SPACE);

		if((1 << 15) & upKeyState)
			r.driveDirect(0x01, 0x00, 0x01, 0x00);
		else if((1 << 15) & downKeyState)
			r.driveDirect(0xFE, 0xFF, 0xFE, 0xFF);
		else if((1 << 15) & rightKeyState)
			 r.drive(0x01, 0x00, 0xFF, 0xFF); //turn right
		else if((1 << 15) & leftKeyState)
			r.drive(0x01, 0x00, 0x00, 0x00); //turn left
		else if((1 << 15) & spaceKeyState)
			break;
		else
			r.drive(0x00, 0x00, 0x00, 0x00); //stop

		time_t timeDiff = time(NULL) - startTime;
		if(timeDiff % 5 == 0)
			color = (color == 0) ? 255:0; //toggle power color
	}
	
	return 0;
}