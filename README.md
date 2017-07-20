# iRoomba
A general purpose library that utilizes Boost c++ to send serial data to an iRobot Create 1. 

# Library Description

SimpleSerial.h -- An implementation of Boost's asio compiled library. I found this online, and edited it slightly for my purposes.

Roomba.h / Roomba.cpp -- Roomba class. Utilizes SimpleSerial class to send corresponding opcodes to iCreate 1.

runner.cpp -- An example program created using the above library. Drives iRobot iCreate 1 with arrow keys and alternates the power LED.
