#pragma once
#include <boost/asio.hpp>

class SimpleSerial
{
	public:
		SimpleSerial(std::string port, unsigned int baud_rate) : io(), serial(io,port)
		{
			serial.set_option(boost::asio::serial_port_base::baud_rate(baud_rate));
		}

		void writeLine(std::string s)
		{
			boost::asio::write(serial,boost::asio::buffer(s.c_str(), s.size()));
		}

	private:
		boost::asio::io_service io;
		boost::asio::serial_port serial;
};

