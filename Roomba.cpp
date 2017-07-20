#include "Roomba.h"

bool Roomba::openOI()
{
	if(debugMode)
		std::cout << "Opening OI: ";
	std::string opcodes = "";
	opcodes += (char)0x80;
	opcodes += (char)0x00; //zero data bytes

	try
	{
		if(debugMode)
			std::cout << "SUCCESS" << std::endl;
		serialPort.writeLine(opcodes);
		if(outFile.is_open())
			outFile << opcodes;
		return true;
	} catch (boost::system::system_error e)
	{
		if(debugMode)
			std::cout << "FAIL" << std::endl;
		std::cerr << "Failed to write string: " << opcodes << std::endl;
		std::cerr << "Stack trace: " << e.what() << std::endl;
		return false;
	}
}

bool Roomba::setMode(ModeType m)
{
	if(debugMode)
		std::cout << "Changing mode to " << m << ": ";
	std::string opcodes = "";
	opcodes += (m == FULL) ? (char)0x84 : (char)0x83;
	opcodes += (char)0x00; //zero data bytes

	try
	{
		if(debugMode)
			std::cout << "SUCCESS" << std::endl;
		serialPort.writeLine(opcodes);
		if(outFile.is_open())
			outFile << opcodes;
		return true;
	} catch (boost::system::system_error e)
	{
		if(debugMode)
			std::cout << "FAIL" << std::endl;
		std::cerr << "Failed to write string: " << opcodes << std::endl;
		std::cerr << "Stack trace: " << e.what() << std::endl;
		return false;
	}
}

bool Roomba::setLED(bool playBtn, bool advBtn, unsigned char color, unsigned char intensity)
{
	if(debugMode)
		std::cout << "Changing LED status: ";
	std::string opcodes = "";
	opcodes += (char)0x8B; //LED opcode

	//Data byte 1 (controls states of play and adv buttons)
	//8's bit controls adv button state, 2's bit controls play btn
	
	if(playBtn && advBtn)
		opcodes += (char)0x0F;
	else if(playBtn)
		opcodes += (char)0x02;
	else if(advBtn)
		opcodes += (char)0x08;
	else
		opcodes += (char)0x10;

	opcodes += color;
	opcodes += intensity;

	try
	{
		if(debugMode)
			std::cout << "SUCCESS" << std::endl;
		serialPort.writeLine(opcodes);
		if(outFile.is_open())
			outFile << opcodes;
		return true;
	} catch (boost::system::system_error e)
	{
		if(debugMode)
			std::cout << "FAIL" << std::endl;
		std::cerr << "Failed to write string: " << opcodes << std::endl;
		std::cerr << "Stack trace: " << e.what() << std::endl;
		return false;
	}
}

bool Roomba::drive(unsigned char vel_hi, unsigned char vel_lo, unsigned char rad_hi, unsigned char rad_lo)
{
	if(debugMode)
		std::cout << "Drive: ";
	std::string opcodes = "";
	opcodes += (char)0x89; //drive (controlled) opcode
	opcodes += vel_hi;
	opcodes += vel_lo;
	opcodes += rad_hi;
	opcodes += rad_lo;

	try
	{
		if(debugMode)
			std::cout << "SUCCESS" << std::endl;
		serialPort.writeLine(opcodes);
		if(outFile.is_open())
			outFile << opcodes;
		return true;
	} catch (boost::system::system_error e)
	{
		if(debugMode)
			std::cout << "FAIL" << std::endl;
		std::cerr << "Failed to write string: " << opcodes << std::endl;
		std::cerr << "Stack trace: " << e.what() << std::endl;
		return false;
	}
}

bool Roomba::driveDirect(unsigned char right_hi, unsigned char right_lo, unsigned char left_hi, unsigned char left_lo)
{
	if(debugMode)
		std::cout << "Drive direct: ";
	std::string opcodes = "";
	opcodes += (char)0x91; //drive direct opcode

	//four bytes of data representing two signed numbers (2's complement)
	opcodes += right_hi;
	opcodes += right_lo;
	opcodes += left_hi;
	opcodes += left_lo;

	try
	{
		if(debugMode)
			std::cout << "SUCCESS" << std::endl;
		serialPort.writeLine(opcodes);
		if(outFile.is_open())
			outFile << opcodes;
		return true;
	} catch (boost::system::system_error e)
	{
		if(debugMode)
			std::cout << "FAIL" << std::endl;
		std::cerr << "Failed to write string: " << opcodes << std::endl;
		std::cerr << "Stack trace: " << e.what() << std::endl;
		return false;
	}
}

bool Roomba::waitTime(unsigned char time)
{
	if(debugMode)
		std::cout << "Waiting for time: ";
	std::string opcodes = "";
	opcodes += 0x9B; //wait time opcode
	opcodes += time; //wait time in tenths of a second

	try
	{
		if(debugMode)
			std::cout << "SUCCESS" << std::endl;
		serialPort.writeLine(opcodes);
		if(outFile.is_open())
			outFile << opcodes;
		return true;
	} catch (boost::system::system_error e)
	{
		if(debugMode)
			std::cout << "FAIL" << std::endl;
		std::cerr << "Failed to write string: " << opcodes << std::endl;
		std::cerr << "Stack trace: " << e.what() << std::endl;
		return false;
	}
}

bool Roomba::waitAng(unsigned char ang_hi, unsigned char ang_lo)
{
	if(debugMode)
		std::cout << "Wait angle: ";
	std::string opcodes = "";
	opcodes += (char)0x9D;
	opcodes += ang_hi;
	opcodes += ang_lo;

	try
	{
		if(debugMode)
			std::cout << "SUCCESS" << std::endl;
		serialPort.writeLine(opcodes);
		if(outFile.is_open())
			outFile << opcodes;
		return true;
	} catch (boost::system::system_error e)
	{
		if(debugMode)
			std::cout << "FAIL" << std::endl;
		std::cerr << "Failed to write string: " << opcodes << std::endl;
		std::cerr << "Stack trace: " << e.what() << std::endl;
		return false;
	}
}

