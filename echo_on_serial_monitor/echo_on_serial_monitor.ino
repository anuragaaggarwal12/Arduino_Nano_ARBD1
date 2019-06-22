/*Arduino IDE version: 1.8.3
  Tested on: ARBD 1
  Microcontroller: Atmega 328 p
  written by: Anurag Aggarwal
  Date: 06/19/2019*/

void setup() 
{
  Serial.begin(9600);          //it start the serial monitor whose baud rate is 9600 bits/sec
}

char a;
void loop() 
{
  if(Serial.available())       //che ck if serial ois avaiblable
  {
  a=Serial.read();             //read the data passing from Serial Monitor  
  delay(10);                   //wait for 10 mili sec
  Serial.print(char(a+1));     //print character with increment of +1 tp previous character
  }
}
