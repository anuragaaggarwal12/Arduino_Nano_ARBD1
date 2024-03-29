/*Arduino IDE version: 1.8.3
Tested on: ARBD 1
Microcontroller: Atmega 328 p
written by: Anurag Aggarwal
Date: 06/21/2019*/

//include the EduIntro library for dht(humidity-temperature sensor)
#include<EduIntro.h>

void setup() {
  Serial.begin(9600);       //it start the lcd whose display is (16*2)
  pinMode(A0,INPUT);        //A0 pin is connected to ldr sensor
}

int a;
int b,h;
DHT11 dht(D9);              // creating the object and connect sensor on pin 'D9'

void loop() {
  a=analogRead(A0);         //A0 pin is connected to ldr sensor

  dht.update();             //it update the value of temperature and humidity
  delay(5);                 //wait for some mili sec for stabling the data
  t= dht.readCelsius();     // Reading the temperature in Celsius degrees and store in the C variable
  h= dht.readHumidity();    // Reading the humidity value
  Serial.println(a);        //print value of ldr on serial monitor
  Serial.println(t);
  Serial.println(h);
  delay(1000);              // Wait one second

}
