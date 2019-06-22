/*Arduino IDE version: 1.8.3
Tested on: ARBD 1
Microcontroller: Atmega 328 p
written by: Anurag Aggarwal
Date: 06/16/2019*/

//include the library of bluetooth serial communication
#include <SoftwareSerial.h>

SoftwareSerial bt(12, 13);      //pins connected to bluetooth(RX, TX)


void setup() {
  // set the data rate for the SoftwareSerial port
  bt.begin(9600);                  //it start the serial communication of bluetooth whose baud rate is 9600 bits/sec
  bt.println("Hello, world?");     //print hello world on bluetooth terminal

  pinMode(6, OUTPUT);     //D6 pin is connected to buzzer

}
/*void loop()
  {
  if (bt.available())          //check if bluetooth is connected or not
  {
    if(bt.read()=='a')         //check if data sent from bluetooth terminal is equal to character which we defined 
    {
      digitalWrite(6,HIGH);    //D6 pin is high and buzzer is ON
    }
    else
    {
      digitalWrite(6,LOW);     //D6 pin is ls low and buzzer is turn OFF
    }

  }

  }*/
char str[6] = "buzzer";
int count = 0;
int state = LOW;          //initially state is 0

void loop()
{
  if (bt.available())     //check if bluetooth is connected or not
  {
    if (bt.read() == str[count])     //check if data sent from bluetooth terminal is equal to string which we defined 
    {
      count++;            //increment the value of count by 1
    }
    else
    {
      count = 0;          //make the value of count 0
    }
    if (count == 5)
    {
      //1st time when we sent 'buzzer' from bluetooth then buzzer will on and 2nd time when we sent 'buzzer' from bluetooth then buzzer will off
      state=!state;     
    }
    digitalWrite(6, state);
  }
}



