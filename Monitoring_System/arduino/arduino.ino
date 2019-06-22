//include the EduIntro library for dht(humidity-temperature sensor)
#include<EduIntro.h>

void setup() {
  Serial.begin(9600);
  pinMode(A7,OUTPUT);
}
int a,b;
int c,h;
DHT11 dht(D9);

void loop() {
  a=analogRead(A7);    //temp
  a=a*0.048;
  b=analogRead(A0);

  dht.update();
  delay(5);
  c= dht.readCelsius();
  h= dht.readHumidity();
  Serial.println(a);
  Serial.println(b);
  Serial.println(c);
  Serial.println(h);
  delay(1000);

}
