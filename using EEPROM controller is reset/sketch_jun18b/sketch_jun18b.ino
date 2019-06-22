/*Arduino IDE version: 1.8.3
Tested on: ARBD 1
Microcontroller: Atmega 328 p
written by: Anurag Aggarwal
Date: 06/110/2019*/

// include the DHT(humidity-temperature sensor) library
#include <EEPROM.h>

// start reading from the first byte (address 0) of the EEPROM
int address;
byte value;             // here value is stored in byte 0b11111111

void setup() {
  // initialize serial and wait for port to open:
  pinMode(9,OUTPUT);                  //D9 led is connected to green led
  Serial.begin(9600);                 //it start the serial monitor whose baud rate is 9600 bits/sec
  value = EEPROM.read(address);       //when controller is ON then the value is store and when it is reset
                                         //EX-OR of this value is performed by using EEPROM memory
  digitalWrite(9,value);
  EEPROM.write(address,value^255);    //EX-OR operation is take place
}

void loop() {
}

