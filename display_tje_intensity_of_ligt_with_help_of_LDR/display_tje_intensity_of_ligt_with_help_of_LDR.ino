/*Arduino IDE version: 1.8.3
Tested on: ARBD 1
Microcontroller: Atmega 328 p
written by: Anurag Aggarwal
Date: 06/2/2019*/

int ldr_value;

void setup() {
  
  Serial.begin(9600);        //it start the serial monitor whose baud rate is 9600 bits/sec
  pinMode(A0,INPUT);         //A0 pin is connected to ldr sensor
  pinMode(9,OUTPUT);         //D9 pin is connected to green led
}

void loop() 
{
  ldr_value= map(analogRead(A0),0,1100,0,255);     //mapping is done to covert ldr value(0-1100) to light intensity value(0-255)
  digitalWrite(9,ldr_value);     //glolw led according to the intensity of light of room
}

  
  /*OR
   * 
   * if(ldr_value>=1000)
  {
    digitalWrite(led, HIGH);
  }
  else 
  {
    digitalWrite(led, LOW);
  }
   * 
   */
  
