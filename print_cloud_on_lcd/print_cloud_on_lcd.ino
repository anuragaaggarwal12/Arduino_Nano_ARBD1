/*Arduino IDE version: 1.8.3
  Tested on: ARBD 1
  Microcontroller: Atmega 328 p
  written by: Anurag Aggarwal
  Date: 06/18/2019*/

//include the library of lcd
#include<LiquidCrystal.h>

LiquidCrystal lcd(4,5,0,1,2,3);       //pins connected to lcd(registor select, reset, D0, D1, D2, D3)

byte top1[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte top2[] = {
  B11100,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte bottom[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte top_l[8] = {
  B00011,
  B00111,
  B00111,
  B01111,
  B01111,
  B11111,
  B11111,
  B11111
};

byte top_r[8] = {
  B11000,
  B11100,
  B11100,
  B11110,
  B11110,
  B11111,
  B11111,
  B11111
};

byte bottom_l[8] = {
  B11001,
  B11101,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte bottom_r[8] = {
  B10011,
  B10111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte bottom_ll[8] = {
  B00011,
  B00111,
  B01111,
  B01111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte bottom_rr[8] = {
  B11000,
  B11100,
  B11110,
  B11110,
  B11111,
  B11111,
  B11111,
  B11111
};
 
void setup() {
  lcd.begin(16, 2);          //it start the lcd whose display is (16*2)
 
  lcd.createChar(0, top1);   // create a new character
  lcd.createChar(1, top2);
  lcd.createChar(2, top_l);
  lcd.createChar(3, top_r);
  lcd.createChar(1, bottom);
  lcd.createChar(1, bottom);
  lcd.createChar(1, bottom);
  lcd.createChar(1, bottom);
  lcd.createChar(4, bottom_l);
  lcd.createChar(5, bottom_r);
  lcd.createChar(6, bottom_ll);
  lcd.createChar(7, bottom_rr);
   
  lcd.setCursor(6,0);        //set cursor of lcd to (column=6, row=1) coordinates
  lcd.write(byte(0));        //write the pattern store in byte 0

  lcd.setCursor(7,0);
  lcd.write(byte(1));

  lcd.setCursor(5,0);
  lcd.write(byte(2));

  lcd.setCursor(8,0);
  lcd.write(byte(3));
  
  lcd.setCursor(6,1);
  lcd.write(byte(1));

  lcd.setCursor(7,1);
  lcd.write(byte(1));

  lcd.setCursor(5,1);
  lcd.write(byte(1));

  lcd.setCursor(8,1);
  lcd.write(byte(1));

  lcd.setCursor(4,1);
  lcd.write(byte(4));

  lcd.setCursor(9,1);
  lcd.write(byte(5));

  lcd.setCursor(3,1);
  lcd.write(byte(6));

  lcd.setCursor(10,1);
  lcd.write(byte(7));
}

void loop() { }
