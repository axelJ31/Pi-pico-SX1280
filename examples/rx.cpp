#include <stdio.h>
#include <iostream>
#include "pico/stdlib.h"

#include "SX1280.h"

using namespace std;

int16_t rssi = 0;
uint16_t pressure = 0;

int main() 
{
 stdio_init_all();

 SX1280 LT;

 if(LT.begin()) 
 {
  LT.setupLoRa();
  cout << "waiting for a message..." << endl;
 }
 else
 {
  while(1) cout << "failed in begin function" << endl;
 }

 while (1)
 {
  if(LT.checkIrqs())
  {
     LT.receiveSXBuffer(0,0);
     rssi = LT.readPacketRSSI();

     LT.startReadSXBuffer(0);
     LT.readSXBuffer(12);
     LT.endReadSXBuffer();
      
     pressure = LT.readUint16(0);
     cout << "pressure: " << pressure << endl;
     cout << "rssi : " << rssi << endl;
  }
 }
}
