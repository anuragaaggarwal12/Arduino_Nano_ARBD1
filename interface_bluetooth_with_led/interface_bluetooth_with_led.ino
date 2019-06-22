/*Arduino IDE version: 1.8.3
  Tested on: ARBD 1
  Microcontroller: Atmega 328 p
  written by: Anurag Aggarwal
  Date: 06/15/2019*/

//include the library of bluetooth serial communication
#include <SoftwareSerial.h>

SoftwareSerial bt(12, 13);       //pins connected to bluetooth(RX, TX)

void setup()
{
  bt.begin(9600);                //it start the serial communication of bluetooth whose baud rate is 9600 bits/sec
  bt.println("Hello, world?");   //print hello world on bluetooth terminal

  pinMode(9,OUTPUT);             //D9 pin is connected to green led
  pinMode(10,OUTPUT);            //D10 pin is connected to blue led
  pinMode(11,OUTPUT);            //D11 pin is connected to red led
}

void loop() {        
  if (bt.available()) {          //check if bluetooth is connected or not
    char x=bt.read();            //read the data passing from bluetooth terminal
    
    if(x=='a')                   //check if data sent from bluetooth terminal is equal to character 'a' which we defined
    {
      x=map(analogRead(9),0,255,0,100);       //mapping value of 255 to 100 so if we give value =0 from bluetooth that led will off
                                               //and if we give value =100 from bluetooth that led will turn on with highest intensity
      analogWrite(9,HIGH);        //green led is on              
      analogWrite(10,LOW);        //blue red is off
      analogWrite(11,LOW);        //red led is off
    }

    else if(x=='b')
    {
      x=map(analogRead(10),0,255,0,100);
      analogWrite(9,LOW);
      analogWrite(10,HIGH);
      analogWrite(11,LOW);
    }

     else if(x=='c')
    {
      x=map(analogRead(11),0,255,0,100);
      analogWrite(9,LOW);
      analogWrite(10,LOW);
      analogWrite(11,HIGH);
    }

     else if(x=='d')
    {
      analogWrite(9,LOW);
      analogWrite(10,LOW);
      analogWrite(11,LOW);
    }
     
  }
}

