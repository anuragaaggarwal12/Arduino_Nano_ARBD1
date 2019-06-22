/*Arduino IDE version: 1.8.3
  Tested on: ARBD 1
  Microcontroller: Atmega 328 p
  written by: Anurag Aggarwal
  Date: 06/14/2019*/

int pot_value;

void setup() {
  pinMode(A6, INPUT);           //A6 pin is connected to potentiometer
}

void loop() {

  pot_value = analogRead(A6);
  pot_value = pot_value >> 2;   //as our ADC is 10 bit and PWM is 8 bit so here we left shift the value of pot to convert it into 8 bit

  if (pot_value <= 20)
  {
    pinMode(A2, INPUT);        //A2 pin is taken as input to give high impedence
    pinMode(A3, INPUT);        //A3 pin is taken as input to give high impedence
    pinMode(A4, OUTPUT);       //between 2 pins we can connect only 2 led
    pinMode(A5, OUTPUT);

    digitalWrite(A5, HIGH);    //out of 2 led, we give high to 1 led so it will glow
    digitalWrite(A4, LOW);
    delay(1000);               // wait for 1 sec
  }

  if ((pot_value > 20) && (pot_value <= 40))
  {
    pinMode(A2, INPUT);
    pinMode(A3, OUTPUT);
    pinMode(A4, INPUT);
    pinMode(A5, OUTPUT);

    digitalWrite(A5, HIGH);
    digitalWrite(A3, LOW);
    delay(1000);
  }

  if ((pot_value > 40) && (pot_value <= 60))
  {
    pinMode(A2, OUTPUT);
    pinMode(A3, INPUT);
    pinMode(A4, INPUT);
    pinMode(A5, OUTPUT);

    digitalWrite(A5, HIGH);
    digitalWrite(A2, LOW);
    delay(1000);
  }

  if ((pot_value > 60) && (pot_value <= 80))
  {
    pinMode(A2, INPUT);
    pinMode(A3, OUTPUT);
    pinMode(A4, OUTPUT);
    pinMode(A5, INPUT);

    digitalWrite(A4, HIGH);
    digitalWrite(A3, LOW);
    delay(1000);
  }

  if ((pot_value > 80) && (pot_value <= 100))
  {
    pinMode(A2, OUTPUT);
    pinMode(A3, INPUT);
    pinMode(A4, OUTPUT);
    pinMode(A5, INPUT);

    digitalWrite(A4, HIGH);
    digitalWrite(A2, LOW);
    delay(1000);
  }

  if ((pot_value > 100) && (pot_value <= 120))
  {
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    pinMode(A4, OUTPUT);
    pinMode(A5, OUTPUT);

    digitalWrite(A4, HIGH);
    digitalWrite(A5, LOW);
    delay(1000);
  }

  if ((pot_value > 120) && (pot_value <= 140))
  {
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
    pinMode(A4, INPUT);
    pinMode(A5, INPUT);

    digitalWrite(A3, HIGH);
    digitalWrite(A2, LOW);
    delay(1000);
  }

  if ((pot_value > 140) && (pot_value <= 160))
  {
    pinMode(A2, INPUT);
    pinMode(A3, OUTPUT);
    pinMode(A4, INPUT);
    pinMode(A5, OUTPUT);

    digitalWrite(A3, HIGH);
    digitalWrite(A5, LOW);
    delay(1000);
  }

  if ((pot_value > 160) && (pot_value <= 180))
  {
    pinMode(A2, INPUT);
    pinMode(A3, OUTPUT);
    pinMode(A4, OUTPUT);
    pinMode(A5, INPUT);

    digitalWrite(A3, HIGH);
    digitalWrite(A4, LOW);
    delay(1000);
  }

  if ((pot_value > 180) && (pot_value <= 200))
  {
    pinMode(A2, OUTPUT);
    pinMode(A3, INPUT);
    pinMode(A4, INPUT);
    pinMode(A5, OUTPUT);

    digitalWrite(A2, HIGH);
    digitalWrite(A5, LOW);
    delay(1000);
  }

  if ((pot_value > 200) && (pot_value <= 220))
  {
    pinMode(A2, OUTPUT);
    pinMode(A3, INPUT);
    pinMode(A4, OUTPUT);
    pinMode(A5, INPUT);

    digitalWrite(A2, HIGH);
    digitalWrite(A4, LOW);
    delay(1000);
  }

  if ((pot_value > 220) && (pot_value <= 240))
  {
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
    pinMode(A4, INPUT);
    pinMode(A5, INPUT);

    digitalWrite(A2, HIGH);
    digitalWrite(A3, LOW);
    delay(1000);
  }

  if ((pot_value > 240) && (pot_value <= 255))
  {
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);
    digitalWrite(A4, LOW);
    digitalWrite(A3, LOW);
  }

}
