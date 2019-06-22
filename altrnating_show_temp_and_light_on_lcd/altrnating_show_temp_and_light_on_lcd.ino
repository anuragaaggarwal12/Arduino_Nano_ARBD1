/*Arduino IDE version: 1.8.3
Tested on: ARBD 1
Microcontroller: Atmega 328 p
written by: Anurag Aggarwal
Date: 06/16/2019*/

//include the library of LCD
#include<LiquidCrystal.h>

LiquidCrystal lcd(4,5,0,1,2,3);       //pins connected to lcd(registor select, reset, D0, D1, D2, D3)


void setup() {
  pinMode(A1,INPUT);    //A1 pin is connected to navi button
  pinMode(A0,INPUT);    //A0 pin is connected to ldr sensor
  pinMode(A7,INPUT);    //A7 pin is connected to Lm35 temperature sensor 

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);     //it start the lcd whose display is (16*2)
}
int light_value;
int temp_value;
int navi;
int state=0;

void loop() 
{ 
  navi=analogRead(A1);
  light_value=analogRead(A0);
  temp_value=analogRead(A7);
  temp_value=temp_value*0.048;     //convert voltage in mili volt into temperature in degree celcius

  
  if(navi==0)
  {
    if(state=!state)         
    {
      lcd.clear();              //it clear the lcd means previous command is erase now
      lcd.setCursor(0,0);       //set cursor of lcd to(column=0, row=0) coordinates
      lcd.print("light=");
      lcd.print(light_value);   //print the value of light which was taken by sensor
      delay(1000);              // wait for 1 sec
    }
    else
    {
      lcd.clear();
      lcd.setCursor(0,1);      //set cursor of lcd to(column=0, row=0) coordinates
      lcd.print("temperature=");
      lcd.print(temp_value);   //print the value of temperature which was taken by sensor
      delay(1000);
    }
  }
 
}
