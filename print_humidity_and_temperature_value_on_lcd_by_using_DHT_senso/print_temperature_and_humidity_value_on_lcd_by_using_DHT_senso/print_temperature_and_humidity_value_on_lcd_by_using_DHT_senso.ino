/*Arduino IDE version: 1.8.3
Tested on: ARBD 1
Microcontroller: Atmega 328 p
written by: Anurag Aggarwal
Date: 06/110/2019*/

// include the DHT(humidity-temperature sensor) library
#include <EduIntro.h>

#include<LiquidCrystal.h>
LiquidCrystal lcd(4,5,0,1,2,3);      //pins connected to lcd(registor select, reset, D0, D1, D2, D3)

DHT11 dht11(D9);  // creating the object and connect sensor on pin 'D9'

int H;   // humidity readings are integers
int C;   // temperature C readings are integers
float F; // temperature F readings are returned in float format

void setup()
{
  lcd.begin(16,2);      //it start the lcd whose display is (16*2)
}

void loop()
{
  dht11.update();               //it update the value of temperature and humidity
  H = dht11.readHumidity();     // Reading the humidity value
  C = dht11.readCelsius();     	// Reading the temperature in Celsius degrees and store in the C variable
  F = dht11.readFahrenheit();  	// Reading the temperature in Fahrenheit degrees and store in the F variable
  

  // Print the collected data in a row on the Serial Monitor
  lcd.setCursor(0,0);           //set cursor of lcd to (column=0, row=0) coordinates
  lcd.print("Humidity ");
  lcd.print(H);                 //print humidity value of room on LCD
  delay(1000);

  lcd.setCursor(0,1);
  lcd.print("temperature ");
  lcd.print(C); 
  lcd.print(char(223)); 
  delay(1000);
  //Serial.print("temperature in Farenheit ");
  //Serial.println(F);

 // delay(1000);                // Wait one second before get another temperature reading
}
