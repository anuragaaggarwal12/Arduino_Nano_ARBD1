/*Arduino IDE version: 1.8.3
Tested on: ARBD 1
Microcontroller: Atmega 328 p
written by: Anurag Aggarwal
Date: 06/07/2019*/

#define led1 9
#define led2 10
#define led3 11

void setup() {
  pinMode(led1, OUTPUT);      //led1 is connected with green led
  pinMode(led2, OUTPUT);      //led2 is connected with blue led
  pinMode(led3, OUTPUT);      //led3 is connected with red led

}

void loop() {
  digitalWrite(led1, HIGH);    //green led will turn on
  delay(100);                  //wait for 100 mili sec
  digitalWrite(led2, HIGH);    //blue led will turn on
  delay(200);                  //wait for 200 mili sec
  digitalWrite(led3, HIGH);    //red led will turn on
  delay(300);                  //wait for 200 mili sec
  digitalWrite(led1, LOW);     //green led will turn off
  delay(1000);                 //wait for 1 sec
  digitalWrite(led2, LOW);     //blue led will turn off
  delay(1000);                 //wait for 1 sec
  digitalWrite(led3, LOW);     //red led will turn off
  delay(1000);                 //wait for 1 sec

}
