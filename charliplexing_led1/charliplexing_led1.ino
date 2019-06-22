/*Arduino IDE version: 1.8.3
Tested on: ARBD 1
Microcontroller: Atmega 328 p
written by: Anurag Aggarwal
Date: 06/10/2019*/

void setup() {
  // put your setup code here, to run once:

}

void loop() {
 //between 2 pins we can connect only 2 led
  pinMode(A2,OUTPUT);       //for blinking led between A2 and A3 pins
  pinMode(A3,OUTPUT);
  pinMode(A4,INPUT);        //A2 pin is taken as input to give high impedence
  pinMode(A5,INPUT);        //A3 pin is taken as input to give high impedence

  digitalWrite(A4,LOW);
  digitalWrite(A5,HIGH);    //out of 2 led, we give high to 1 led so it will glow


 /* pinMode(A2,INPUT);    //for blinking led between A4 and A5 pins
  pinMode(A3,INPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);

  digitalWrite(A4,LOW);
  digitalWrite(A5,HIGH); */


  /*pinMode(A2,OUTPUT);    //for blinking led between A2 and A5 pins
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,OUTPUT);

  digitalWrite(A2,LOW);
  digitalWrite(A5,HIGH); */


  
  

}
