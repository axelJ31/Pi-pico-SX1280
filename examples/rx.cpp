/*
  Copyright 2022 - Juaneda Axel
  Licensed under a MIT license displayed at the bottom of this document.
*/


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


/*
  MIT license
  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
  documentation files (the "Software"), to deal in the Software without restriction, including without limitation
  the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
  and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
  The above copyright notice and this permission notice shall be included in all copies or substantial portions
  of the Software.
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
  TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  DEALINGS IN THE SOFTWARE.
*/
