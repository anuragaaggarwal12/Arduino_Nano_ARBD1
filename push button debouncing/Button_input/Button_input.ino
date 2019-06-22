/*Arduino IDE version: 1.8.3
  Tested on: ARBD 1
  Microcontroller: Atmega 328 p
  written by: Anurag Aggarwal
  Date: 05/30/2019*/

int current, previous;

void setup() {
  pinMode(9, OUTPUT);       //D9 is connected to green led
  pinMode(A1, INPUT);       //A1 pin is connected to navi_button
}

void loop() 
{
  previous = digitalRead(A1);     //read navi_button value
  if (previous == LOW) {
    delay(5);                     //5 mili sec delay is given to remove bouncing time
    current = digitalRead(A1);    //read navi_button value after skipping bouncing time
    if (previous == current)      //if both condition is equal then it high the output
    {
      digitalWrite(9, HIGH);      //now green led will glow when navi_button is pressed
    }
  }
}
