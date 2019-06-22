/*Arduino IDE version: 1.8.3
Tested on: ARBD 1
Microcontroller: Atmega 328 p
written by: Anurag Aggarwal
Date: 06/15/2019*/

//include the library of lcd
#include<LiquidCrystal.h>

//include the library of bluetooth serial communication
#include <SoftwareSerial.h>

LiquidCrystal lcd(4,5,0,1,2,3);     //pins connected to lcd(registor select, reset, D0, D1, D2, D3)
SoftwareSerial bt(12, 13);          //pins connected to bluetooth(RX, TX)

void setup() {
  lcd.begin(16,2);                  //it start the lcd whose display is (16*2)
  lcd.print("Goodnight moon!");
  delay(2000);                      //wait for 2 sec
  lcd.clear();                      //it clear the lcd means previous command is erase from lcd
  

  // set the data rate for the SoftwareSerial port
  bt.begin(9600);                  //it start the serial communication of bluetooth whose baud rate is 9600 bits/sec
  bt.println("Hello, world?");     //print hello world on bluetooth terminal

  
}
int c=0;
int r=0;
void loop()
{
  if (bt.available())           //check if bluetooth is connected or not
  {
    lcd.write(bt.read());       //data sent from bluetooth is start writing on LCD
    c++;

    if (( c>=15)&&(r==0))
    {
      lcd.setCursor(0,1);       //set cursor of lcd to (column=0, row=1) coordinates
      r++;c=0;
    }
    else if((c>=15)&&(r==1))    //if there is no space on lcd
    {
      c=0;
      r=0;
      lcd.clear();               //it clear the lcd means previous command is erase from lcd
    }
  }
  
}

