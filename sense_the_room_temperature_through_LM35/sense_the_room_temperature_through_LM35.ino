/*Arduino IDE version: 1.8.3
Tested on: ARBD 1
Microcontroller: Atmega 328 p
written by: Anurag Aggarwal
Date: 06/01/2019*/

int temp_value;
float temperature ;
void setup() 
{
  Serial.begin(9600);          //it start the serial monitor whose baud rate is 9600 bits/sec
  pinMode(A7, INPUT);          //A7 pin is connected to Lm35 temperature sensor
}

void loop() {

  temp_value = analogRead(A7);
  temp_value = (temp_value) * 0.48 ;    //convert mili volt into temperature in degree Celcius
  Serial.print("temperature=");
  Serial.println(temp_value);           //print the temperature value on serial monitor
  delay(1000);                          //wait for 1 sec

}
