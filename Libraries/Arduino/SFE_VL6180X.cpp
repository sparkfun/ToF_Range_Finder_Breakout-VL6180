/******************************************************************************
MS5803_I2C.cpp
Library for MS5803 pressure sensor.
Casey Kuhns @ SparkFun Electronics
6/26/2014
https://github.com/sparkfun/MS5803-14BA_Breakout

The MS58XX MS57XX and MS56XX by Measurement Specialties is a low cost I2C pressure
sensor.  This sensor can be used in weather stations and for altitude
estimations. It can also be used underwater for water depth measurements. 

In this file are the functions in the MS5803 class

Resources:
This library uses the Arduino Wire.h to complete I2C transactions.

Development environment specifics:
	IDE: Arduino 1.0.5
	Hardware Platform: Arduino Pro 3.3V/8MHz
	MS5803 Breakout Version: 1.0


This code is beerware. If you see me (or any other SparkFun employee) at the
local pub, and you've found our code helpful, please buy us a round!

Distributed as-is; no warranty is given.
******************************************************************************/

#include <Wire.h>

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

