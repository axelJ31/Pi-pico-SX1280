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
uint16_t pressure = 1024;
int16_t altitude = -8;
float temperature = 24.6;

int main()
{
    stdio_init_all();

    SX1280 LT;

    if (LT.begin())
    {
        LT.setupLoRa();
        cout << "Ready to communicate !" << endl;
    }
    else
    {
        while (1)
            cout << "failed in begin function" << endl;
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

        if (LT.isTXReady())
        {
            cout << "sending..." << endl;
            LT.startWriteSXBuffer(0);
            LT.writeSXBuffer(8);
            LT.endWriteSXBuffer();
            LT.transmitSXBuffer(0, 8, 0);
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
