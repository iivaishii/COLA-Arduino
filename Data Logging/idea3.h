/*
COLA Arduino
Data Logging code (USB)
*/

#ifndef Idea_3_h
#define Idea_3_h

#include <SoftwareSerial.h>
#include "IMU.h"
#include "GPS_I2C.h"


void setup()
{
  SoftwareSerial mySerial(15, 14); // Rx, Tx (GPS Sensor)
  SoftwareSerial mySerial1(17, 16); // Rx, Tx (IMU Sensor)

  mySerial.begin(115200); // Initialize UART with baud rate of 115200 bps
  mySerial1.begin(115200);
}

void loop()
{
  for (int i = 0; i < 4; i++)
    {
      result[i] = Wire.read();
    }
  if (mySerial.available())
  { //GPS Section
    byte gps_data_rcvd = mySerial.read();   // Read one byte from serial buffer and save to data_rcvd
    mySerial.write(gps_data_rcvd);
    
    long latitude = gps_location(long latitude);
    long longitude = gps_location(long longitude);
    long altitude = gps_location(long altitude);
  }

  if (mySerial1.available())
  { //IMU Section
    byte imu_data_rcvd = mySerial1.read();
    mySerial1.write(imu_data_rcvd);
  }
}


#endif