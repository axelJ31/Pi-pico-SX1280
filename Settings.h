/*******************************************************************************************************
  Licensed under a MIT license displayed at the bottom of this document.
  Programs for raspberry pi pico

  This program is supplied as is, it is up to the user of the program to decide if the program is
  suitable for the intended purpose and free from errors.
*******************************************************************************************************/

//*******  Setup hardware pin definitions here ! ***************

//These are the pin definitions for one of my own boards and using an ebyte module,
//be sure to change the definitions to match your own setup. Some pins such as DIO2,
//DIO3, BUZZER may not be in used by this sketch so they do not need to be
//connected and should be included and be set to -1.
#define PIN_MISO 16
#define PIN_CS   -1
#define PIN_SCK  18
#define PIN_MOSI 19

#define SPI_PORT spi0

// Copyright of the author Stuart Robinson

#define NSS 26 //26
#define RFBUSY 2 //2
#define NRESET 0 //0
#define LED1 25 //25
#define DIO1 4 //4
#define DIO2 -1                 //not used 
#define DIO3 -1                 //not used
#define RX_EN 27    //27            //pin for RX enable, used on some SX1280 devices, set to -1 if not used
#define TX_EN 1               //pin for TX enable, used on some SX1280 devices, set to -1 if not used                        
#define BUZZER -1               //connect a buzzer here if wanted        

#define LORA_DEVICE DEVICE_SX1280               //we need to define the device we are using  

//LoRa Modem Parameters
#define Frequency 2445000000                     //frequency of transmissions
#define Offset 0                                 //offset frequency for calibration purposes  
#define Bandwidth LORA_BW_0800                   //LoRa bandwidth
#define SpreadingFactor LORA_SF7                 //LoRa spreading factor
#define CodeRate LORA_CR_4_5                     //LoRa coding rate

#define TXpower  0                            //power for transmissions in dBm

#define packet_delay 1000                        //mS delay between packets

#define RXBUFFER_SIZE 255                        //RX buffer size, not used in this program 

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
