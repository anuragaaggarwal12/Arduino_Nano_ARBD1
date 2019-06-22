/*Arduino IDE version: 1.8.3
  Tested on: ARBD 1
  Microcontroller: Atmega 328 p
  written by: Anurag Aggarwal
  Date: 06/13/2019*/
  
//include the library of bluetooth serial communication
#include <SoftwareSerial.h>

SoftwareSerial bt(12, 13);          //pins connected to bluetooth(RX, TX)

void setup() 
{
  Serial.begin(9600);                //it start the serial monitor whose baud rate is 9600 bits/sec
  Serial.println("Goodnight ");      //print goodnight on serial monitor

  // set the data rate for the SoftwareSerial port
  bt.begin(9600);                    //it start the serial communication of bluetooth whose baud rate is 9600 bits/sec
  bt.println("Hello, world?");       //print hello world on bluetooth terminal
}

void loop() { // run over and over
  if (bt.available()) {           //check if bluetooth is connected or not
    Serial.write(bt.read());      //print value from bluetooth_terminal to serial_monitor
  }
  if (Serial.available()) {       //check if serial monitor is connected or not
    bt.write(Serial.read());      //print value from serial_monitor to bluetooth_terminal
  }
}

