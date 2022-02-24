/*
  Copyright 2022 - Juaneda Axel
  Licensed under a MIT license displayed at the bottom of this document.
  
  This code was adapted from the library of Stuart Robinson https://github.com/StuartsProjects/SX12XX-LoRa
*/


#ifndef SX1280_H // include guard
#define SX1280_H

#include <stdio.h>
#include <iostream>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/spi.h"
#include "hardware/clocks.h"

#include "Settings.h"
#include "SX1280_Def.h"

using namespace std;

class SX1280
{
 public :
    SX1280();

    void setupLoRa();
    bool begin();

    void setMode(uint8_t modeconfig);
    void setRegulatorMode(uint8_t mode);
    void setPacketType(uint8_t packettype);
    void setRfFrequency(uint32_t frequency, int32_t offset);
    void setBufferBaseAddress(uint8_t txBaseAddress, uint8_t rxBaseAddress);
    void setModulationParams(uint8_t modParam1, uint8_t modParam2, uint8_t  modParam3);
    void setPacketParams(uint8_t packetParam1, uint8_t  packetParam2, uint8_t packetParam3, uint8_t packetParam4, uint8_t packetParam5, uint8_t packetParam6, uint8_t packetParam7);
    void setDioIrqParams(uint16_t irqMask, uint16_t dio1Mask, uint16_t dio2Mask, uint16_t dio3Mask );
    void setHighSensitivity();
    void setTxParams(uint8_t RampTime);

    void resetDevice();

    uint8_t receiveSXBuffer(uint8_t startaddr, uint16_t timeout);
    void startReadSXBuffer(uint8_t ptr);
    uint8_t readBufferChar(char *rxbuffer);

    int16_t readPacketRSSI();
    int8_t readPacketSNR();

    void readSXBuffer(uint8_t size);
    void getSXBuffer(uint8_t *destination, uint8_t size);

    uint8_t endReadSXBuffer();

    bool isTXReady();
    void startWriteSXBuffer(uint8_t ptr);
    void writeSXBuffer(uint8_t size);
    void endWriteSXBuffer();
    void transmitSXBuffer(uint8_t startaddr, uint8_t length, uint16_t timeout);

    bool checkIrqs();

    void writeUint8(uint8_t u8, uint8_t addr);
    uint8_t readUint8(uint8_t addr);

    void writeUint16(uint16_t u16, uint8_t startaddr);
    uint16_t readUint16(uint8_t startaddr);

    void writeInt8(int8_t i8, uint8_t addr);
    int8_t readInt8(uint8_t addr);

    void writeInt16(int16_t i16, uint8_t startaddr);
    int16_t readInt16(uint8_t startaddr);

    void writeFloat(float fl, uint8_t startaddr);
    float readFloat(uint8_t startaddr);
    
    void writeChar(char c, uint8_t addr);
    char readChar(uint8_t addr);

    #ifdef DEBUG
    uint8_t getTXBuffer(uint8_t addr);
    #endif

    ~SX1280();

 private :
    void checkBusy();
    bool checkDevice();

    void writeRegister(uint16_t address, uint8_t value);
    void readRegisters(uint16_t address, uint8_t *buffer, uint16_t size);
    uint8_t readRegister(uint16_t address);
    void writeRegisters(uint16_t address, uint8_t *buffer, uint16_t size);

    void readCommand(uint8_t Opcode, uint8_t *buffer, uint16_t size);
    void writeCommand(uint8_t Opcode, uint8_t *buffer, uint16_t size);

    void setTx(uint16_t timeout);
    void txEnable();

    void setRx(uint16_t timeout);
    void rxEnable();

    void clearIrqStatus(uint16_t irqMask);
    uint16_t readIrqStatus();

    uint8_t RXPacketL, periodBase = PERIODBASE_01_MS;
    uint8_t rxBuffer[RXBUFFER_SIZE], txBuffer[RXBUFFER_SIZE];
    bool rxtxpinmode;
    bool waitIrq = false;
};

#endif


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
