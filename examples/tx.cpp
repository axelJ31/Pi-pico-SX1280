#include <stdio.h>
#include <iostream>
#include "pico/stdlib.h"

#include "SX1280.h"

using namespace std; 

int16_t rssi = 0;
uint16_t pressure = 1024;
int16_t altitude = -8;
float temperature = 24.6;

int main() 
{
 stdio_init_all();

 SX1280 LT;

 if(LT.begin()) 
 {
  LT.setupLoRa();
  cout << "Ready to communicate !" << endl;
 }
 else
 {
  while(1) cout << "failed in begin function" << endl;
 }

 LT.writeUint16(pressure, 0);
 LT.writeInt16(altitude, 2);
 LT.writeFloat(temperature, 4);

 LT.startWriteSXBuffer(0);
 LT.writeSXBuffer(8);
 LT.endWriteSXBuffer();
 LT.transmitSXBuffer(0, 8, 0);
 sleep_ms(50);

 while (1)
 {
   LT.writeUint16(pressure, 0);
   LT.writeInt16(altitude, 2);
   LT.writeFloat(temperature, 4);

   if(LT.isTXReady())
   {
    cout << "sending..." << endl;
    LT.startWriteSXBuffer(0);
    LT.writeSXBuffer(8);
    LT.endWriteSXBuffer();
    LT.transmitSXBuffer(0, 8, 0);
   }
 }
}
