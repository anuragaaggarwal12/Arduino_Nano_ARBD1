/*Arduino IDE version: 1.8.3
Tested on: ARBD 1
Microcontroller: Atmega 328 p
written by: Anurag Aggarwal
Date: 06/20/2019*/

void setup() {
  // put your setup code here, to run once:

}

void loop() {
//12 pins of charlieplexing led are connected with 4 pins
  pinMode(A2,INPUT);       //A2 pin is taken as input to give high impedence
  pinMode(A3,INPUT);       //A3 pin is taken as input to give high impedence
  pinMode(A4,OUTPUT);      //between 2 pins we can connect only 2 led
  pinMode(A5,OUTPUT);

  digitalWrite(A5,HIGH);   //out of 2 led, we give high to 1 led so it will glow
  digitalWrite(A4, LOW);
  delay(1000);             // wait for 1 sec

  pinMode(A2,INPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,INPUT);
  pinMode(A5,OUTPUT);

  digitalWrite(A5,HIGH);
  digitalWrite(A3, LOW);
  delay(1000);

  pinMode(A2,OUTPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,OUTPUT);

  digitalWrite(A5,HIGH);
  digitalWrite(A2, LOW);
  delay(1000);

  pinMode(A2,INPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,INPUT);

  digitalWrite(A4,HIGH);
  digitalWrite(A3, LOW);
  delay(1000);

  pinMode(A2,OUTPUT);
  pinMode(A3,INPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,INPUT);

  digitalWrite(A4,HIGH);
  digitalWrite(A2, LOW);
  delay(1000);

  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);

  digitalWrite(A4,HIGH);
  digitalWrite(A5, LOW);
  delay(1000);

  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);

  digitalWrite(A3,HIGH);
  digitalWrite(A2, LOW);
  delay(1000);

  pinMode(A2,INPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,INPUT);
  pinMode(A5,OUTPUT);

  digitalWrite(A3,HIGH);
  digitalWrite(A5, LOW);
  delay(1000);

  pinMode(A2,INPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,INPUT);

  digitalWrite(A3,HIGH);
  digitalWrite(A4, LOW);
  delay(1000);

  pinMode(A2,OUTPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,OUTPUT);

  digitalWrite(A2,HIGH);
  digitalWrite(A5, LOW);
  delay(1000);

  pinMode(A2,OUTPUT);
  pinMode(A3,INPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,INPUT);

  digitalWrite(A2,HIGH);
  digitalWrite(A4, LOW);
  delay(1000);

  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);

  digitalWrite(A2,HIGH);
  digitalWrite(A3, LOW);
  delay(1000);

  
  

}
