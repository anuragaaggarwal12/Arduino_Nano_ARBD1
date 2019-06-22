/*Arduino IDE version: 1.8.3
Tested on: ARBD 1
Microcontroller: Atmega 328 p
written by: Anurag Aggarwal
Date: 06/14/2019*/

void setup() {

  pinMode(6,OUTPUT);     //0th column pin of keyboard matrix
  pinMode(7,OUTPUT);     //1st column pin of keyboard matrix
  pinMode(8,OUTPUT);     //2nd column pin of keyboard matrix
  pinMode(9,OUTPUT);     //3rd column pin of keyboard matrix
  pinMode(10,INPUT);     //0th row pin of keyboard matrix
  pinMode(11,INPUT);     //1st row pin of keyboard matrix
  pinMode(12,INPUT);     //2nd row pin of keyboard matrix
  pinMode(13,INPUT);     //3rd row pin of keyboard matrix
  Serial.begin(9600);    //it start the serial monitor whose baud rate is 9600 bits/sec
}
int row[4];

void loop() {
  digitalWrite(6,HIGH);     //D6 pin is connected to 0th column which is high
  digitalWrite(7,LOW);      //D7 pin is connected to 0th column which is low
  digitalWrite(8,LOW);      //D8 pin is connected to 0th column which is low
  digitalWrite(9,LOW);      //D9 pin is connected to 0th column which is low
  row[0]=digitalRead(10);   //D10 pin is connected to 0th row  
  row[1]=digitalRead(11);   //D11 pin is connected to 1st row
  row[2]=digitalRead(12);   //D12 pin is connected to 2nd row
  row[3]=digitalRead(13);   //D13 pin is connected to 3rd row

  if(row[0]==HIGH)          //if 0th row is high
  {
    Serial.println("key 1 is pressed");   //print on serial monitor
    while(digitalRead(10)==HIGH);         ////wait until another key is press
  }
  else if(row[1]==HIGH)
  {
    Serial.println("key 4 is pressed"); 
    while(digitalRead(11)==HIGH);
  }
  else if(row[2]==HIGH)
  {
    Serial.println("key 7 is pressed"); 
    while(digitalRead(12)==HIGH);
  }
  else if(row[3]==HIGH)
  {
    Serial.println("key * is pressed"); 
    while(digitalRead(13)==HIGH);
  }

  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  row[0]=digitalRead(10);
  row[1]=digitalRead(11);
  row[2]=digitalRead(12);
  row[3]=digitalRead(13);

  if(row[0]==HIGH)
  {
    Serial.println("key 2 is pressed"); 
    while(digitalRead(10)==HIGH);
  }
  else if(row[1]==HIGH)
  {
    Serial.println("key 5 is pressed"); 
    while(digitalRead(11)==HIGH);
  }
  else if(row[2]==HIGH)
  {
    Serial.println("key 8 is pressed"); 
    while(digitalRead(12)==HIGH);
  }
  else if(row[3]==HIGH)
  {
    Serial.println("key 0 is pressed"); 
    while(digitalRead(13)==HIGH);
  }

  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  row[0]=digitalRead(10);
  row[1]=digitalRead(11);
  row[2]=digitalRead(12);
  row[3]=digitalRead(13);

  if(row[0]==HIGH)
  {
    Serial.println("key 3 is pressed"); 
    while(digitalRead(10)==HIGH);
  }
  else if(row[1]==HIGH)
  {
    Serial.println("key 6 is pressed"); 
    while(digitalRead(11)==HIGH);
  }
  else if(row[2]==HIGH)
  {
    Serial.println("key 9 is pressed"); 
    while(digitalRead(12)==HIGH);
  }
  else if(row[3]==HIGH)
  {
    Serial.println("key # is pressed"); 
    while(digitalRead(13)==HIGH);
  }

  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  row[0]=digitalRead(10);
  row[1]=digitalRead(11);
  row[2]=digitalRead(12);
  row[3]=digitalRead(13);

  if(row[0]==HIGH)
  {
    Serial.println("key A is pressed");
    while(digitalRead(10)==HIGH);
  }
  else if(row[1]==HIGH)
  {
    Serial.println("key B is pressed"); 
    while(digitalRead(11)==HIGH);
  }
  else if(row[2]==HIGH)
  {
    Serial.println("key C is pressed");
    while(digitalRead(12)==HIGH); 
  }
  else if(row[3]==HIGH)
  {
    Serial.println("key D is pressed");
    while(digitalRead(13)==HIGH); 
  }

}
