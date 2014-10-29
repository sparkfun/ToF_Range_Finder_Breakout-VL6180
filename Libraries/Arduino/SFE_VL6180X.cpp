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



#define CONT 8

#define VL6180X_ADDRESS 0x29

void setup() {
  // put your setup code here, to run once:
  pinMode(CONT, OUTPUT);
  digitalWrite(CONT, HIGH);

  Serial.begin(9600);
  
  Wire.begin();
  
  delay(100);
  
  Wire.beginTransmission(VL6180X_ADDRESS);
  Wire.write(0x00);
  Wire.write(0x06);
//  Wire.write(data);                     // Put data in Tx buffer
  Wire.endTransmission();               // Send the Tx buffer
  
  Wire.requestFrom(VL6180X_ADDRESS, 1);
    byte data = Wire.read();
    Serial.println(data, HEX);

}

void loop() {
  // put your main code here, to run repeatedly: 
  
}

