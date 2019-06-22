/*Arduino IDE version: 1.8.3
Tested on: ARBD 1
Microcontroller: Atmega 328 p
written by: Anurag Aggarwal
Date: 06/12/2019*/


#define led 9        //D9 pin is connected to green led
#define pot A6       //A6 pin is connected to the potentiometer
int pot_value;

void setup() {
  pinMode(pot, INPUT);
  pinMode(led, OUTPUT);

}

void loop() {
  pot_value= analogRead(pot);
  pot_value= pot_value>>2;      //as our ADC is 10 bit and PWM is 8 bit so here we left shift the value of pot to convert it into 8 bit

  analogWrite(led, pot_value);     //glow led according to pot value
  
}

/*OR
 *  
 *   pot_val = map(analogRead(pot),0,1023,0,255);            //mapping is done
  
     analogWrite(led, pot_val);
 */
