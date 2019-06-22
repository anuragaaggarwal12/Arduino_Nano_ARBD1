/*Arduino IDE version: 1.8.3
  Tested on: ARBD 1
  Microcontroller: Atmega 328 p
  written by: Anurag Aggarwal
  Date: 06/14/2019*/

//include the library of bluetooth serial communication
#include <SoftwareSerial.h>

SoftwareSerial bt(12,13);       //pins connected to bluetooth(RX, TX)

void setup() {
  pinMode(A0,INPUT);            //A0 pin is connected to ldr sensor
  pinMode(A7,INPUT);            //A0 pin is connected to Lm35 temperature sensor

  bt.begin(9600);               //it start the serial communication of bluetooth whose baud rate is 9600 bits/sec
  
}
int light;
int temp_value;
void loop() {
  light=analogRead(A0);
  temp_value=analogRead(A7);
  temp_value=temp_value*0.048;     //convert voltage in mili volt to temperature in degree celcius

  bt.println(light);               //print value of light on bluetooth terminal
  delay(1000);                     //wait for 1 sec
  bt.println(temp_value);          //print value of temperature value on bluetooth terminal
  delay(1000);                     //wait for 1 sec

}
