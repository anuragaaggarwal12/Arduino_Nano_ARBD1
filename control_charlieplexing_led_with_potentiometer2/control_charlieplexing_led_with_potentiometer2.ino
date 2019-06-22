/*Arduino IDE version: 1.8.3
  Tested on: ARBD 1
  Microcontroller: Atmega 328 p
  written by: Anurag Aggarwal
  Date: 06/13/2019*/

int pot_value;

void setup() {
  pinMode(A6, INPUT);         //A6 pin is connected to potentiometer

}

void loop()
{
  //here we map the value
  pot_value = map(analogRead(A6), 0, 1023, 0, 1000);

  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

  digitalWrite(A5, HIGH);
  digitalWrite(A4, LOW);
  delay(pot_value);         //as we increase pot value speed of charlieplexing start increasing

  pot_value = map(analogRead(A6), 0, 1023, 0, 1000);
  pinMode(A2, INPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, INPUT);
  pinMode(A5, OUTPUT);

  digitalWrite(A5, HIGH);
  digitalWrite(A3, LOW);
  delay(pot_value);

  pot_value = map(analogRead(A6), 0, 1023, 0, 1000);
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, OUTPUT);

  digitalWrite(A5, HIGH);
  digitalWrite(A2, LOW);
  delay(pot_value);

  pot_value = map(analogRead(A6), 0, 1023, 0, 1000);
  pinMode(A2, INPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, INPUT);

  digitalWrite(A4, HIGH);
  digitalWrite(A3, LOW);
  delay(pot_value);

  pot_value = map(analogRead(A6), 0, 1023, 0, 1000);
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, INPUT);

  digitalWrite(A4, HIGH);
  digitalWrite(A2, LOW);
  delay(pot_value);

  pot_value = map(analogRead(A6), 0, 1023, 0, 1000);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

  digitalWrite(A4, HIGH);
  digitalWrite(A5, LOW);
  delay(pot_value);

  pot_value = map(analogRead(A6), 0, 1023, 0, 1000);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

  digitalWrite(A3, HIGH);
  digitalWrite(A2, LOW);
  delay(pot_value);

  pot_value = map(analogRead(A6), 0, 1023, 0, 1000);
  pinMode(A2, INPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, INPUT);
  pinMode(A5, OUTPUT);

  digitalWrite(A3, HIGH);
  digitalWrite(A5, LOW);
  delay(pot_value);

  pot_value = map(analogRead(A6), 0, 1023, 0, 1000);
  pinMode(A2, INPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, INPUT);

  digitalWrite(A3, HIGH);
  digitalWrite(A4, LOW);
  delay(pot_value);

  pot_value = map(analogRead(A6), 0, 1023, 0, 1000);
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, OUTPUT);

  digitalWrite(A2, HIGH);
  digitalWrite(A5, LOW);
  delay(pot_value);

  pot_value = map(analogRead(A6), 0, 1023, 0, 1000);
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, INPUT);

  digitalWrite(A2, HIGH);
  digitalWrite(A4, LOW);
  delay(pot_value);

  pot_value = map(analogRead(A6), 0, 1023, 0, 1000);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

  digitalWrite(A2, HIGH);
  digitalWrite(A3, LOW);
  delay(pot_value);



}
