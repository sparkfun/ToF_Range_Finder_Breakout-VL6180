/******************************************************************************
SFE_VL6180x.cpp
Library for VL6180x time of flight range finder.
Casey Kuhns @ SparkFun Electronics
10/29/2014
https://github.com/sparkfun/MS5803-14BA_Breakout

The VL6180x by ST micro is a time of flight range finder that
uses pulsed IR light to determine distances from object at close
range.  The average range of a sensor is between 0-200mm

In this file are the functions in the VL6180x class

Resources:
This library uses the Arduino Wire.h to complete I2C transactions.

Development environment specifics:
	IDE: Arduino 1.0.5
	Hardware Platform: Arduino Pro 3.3V/8MHz
	VL6180x Breakout Version: 1.0


This code is beerware. If you see me (or any other SparkFun employee) at the
local pub, and you've found our code helpful, please buy us a round!

Distributed as-is; no warranty is given.
******************************************************************************/

#include <Wire.h>
#include "SFE_VL6180X.h"

VL6180x::VL6180x(VL6180x_addr address)
// Initialize the Library
{
	Wire.begin(); // Arduino Wire library initializer
	address = address; //set interface used for communication
}

void VL6180x::reset(void)
// Reset device
{
	//TODO: RESET!
}

void VL6180x::getIdentification(VL6180xIdentification &identification)
//
{

}

void VL6180x::getSystemStatus(VL6180xSystemStatus &systemStatus)
//
{

}



uint8_t VL6180x::getDistance()
//
{

	return distance;
}
uint8_t VL6180x::getAmbientLight()
//
{
	
	return ambientLight;
}


uint8_t VL6180x::VL6180x_getRegister(uint16_t registerAddr)
//
{
	uint8_t data;
	Wire.beginTransmission( _i2caddress ); // Address set on class instantiation
	Wire.write((registerAddr >> 8) & 0xFF); //MSB of register address
	Wire.write(registerAddr & 0xFF); //LSB of register address
	Wire.endTransmission(); //Send address and register address bytes
	data = Wire.read(); //Read Data from selected register
	return data;
}
void VL6180x::VL6180x_setRegister(uint16_t registerAddr, uint8_t data)
//
{
	Wire.beginTransmission( _i2caddress ); // Address set on class instantiation
	Wire.write((registerAddr >> 8) & 0xFF); //MSB of register address
	Wire.write(registerAddr & 0xFF); //LSB of register address
	Wire.write(data); // Data/setting to be sent to device
	Wire.endTransmission(); //Send address and register address bytes
}

