/*Arduino IDE version: 1.8.3
Tested on: ARBD 1
Microcontroller: Atmega 328 p
written by: Anurag Aggarwal
Date: 05/07/2019*/

//include the library of bluetooth serial communication
#include <SoftwareSerial.h>

SoftwareSerial bt(12, 13);      //pins connected to bluetooth(RX, TX)
void setup() {
  // set the data rate for the SoftwareSerial port
  bt.begin(9600);                  //it start the serial communication of bluetooth whose baud rate is 9600 bits/sec
  Serial.begin(9600);
  pinMode(2, OUTPUT);       //D2 pin is connected with relay
  pinMode(3, OUTPUT);       //D3 pin is connected with buzzer
  pinMode(9,OUTPUT);        //D9 pin is connected with red led
  pinMode(10,OUTPUT);       //D10 pin is connected with green led
  pinMode(11,OUTPUT);       //D11 pin is connected with blue led
}
char x;
int val;
void loop()
{
  if (bt.available() > 1)     //check if bluetooth has more than 1 byte to available
  {
    x = bt.read();        //read which x is glow
    val = int(bt.read());   //read what value is send corresponding to that x
  }
  if(x == 'R') analogWrite(9,val);
  if(x == 'G') analogWrite(10,val);
  if(x == 'B') analogWrite(11,val);
  
  if(x == 'A')                  //to off all the led from mit app inventor
  {
    analogWrite(9,val);         //through mit app inventor we sent value 0 when it read text='A'       
    analogWrite(10,val);
    analogWrite(11,val);
  }
   // by using on and off button in mit aap inventor
  if(x == 'O')     
      digitalWrite(2,HIGH);     //relay is On
  if(x == 'F') 
      digitalWrite(2,LOW);      //relay is off
  if(x == 'Y')       
      digitalWrite(3,HIGH);     //buzzer is on
  if(x == 'Z') 
      digitalWrite(3,LOW);      //buzer is off
  
}
