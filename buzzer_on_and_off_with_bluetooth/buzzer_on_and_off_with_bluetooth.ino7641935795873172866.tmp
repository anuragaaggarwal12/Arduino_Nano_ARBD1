/*Arduino IDE version: 1.8.3
Tested on: ARBD 1
Microcontroller: Atmega 328 p
written by: Anurag Aggarwal
Date: 06/17/2019*/

//include the library of bluetooth serial communication
#include <SoftwareSerial.h>

SoftwareSerial bt(12, 13);                //pins connected to bluetooth(RX, TX)

void setup() {
  // set the data rate for the SoftwareSerial port
  bt.begin(9600);                //it start the serial communication of bluetooth whose baud rate is 9600 bits/sec
  bt.println("Hello, world?");   //print hello world on bluetooth terminal

  pinMode(6, OUTPUT);            //D6 pin is connected to buzzer
  Serial.begin(9600);            //it start the serial monitor whose baud rate is 9600 bits/sec
 
}

char str[9] = "buzzer ON";       //here we make a string of 9 characters
char a[10]="buzzer off";         //here we make a string of 10 characters
int count1 = 0;
int count2 = 0;

void loop()
{
  if (bt.available())           //check if bluetooth is connected or not
  {
    char temp = bt.read();      //read the string passing from bluetooth terminal
    
    if (temp == str[count1])    //check if data sent from bluetooth terminal is equal to string which we defined 
    {count1++;
    }
    else
    { count1 = 0;
    }
    if (count1 == 9)             //check if count1 value is 9
    {
      count1 = 0;
      digitalWrite(6, HIGH);     //D6 pin is high and buzzer is ON
    }
   
    if ((temp == a[count2]))     //check if data sent from bluetooth terminal is equal to string which we defined
    { count2++;
    }
    else
    { count2 = 0;
    }
    if(count2==10)               //check if count1 value is 10
    {
      count2 = 0;                //make the value of count 0
      digitalWrite(6,LOW);       //D6 pin is ls low and buzzer is turn OFF
    }
    
  }
}



