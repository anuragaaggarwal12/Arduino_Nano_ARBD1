/*Arduino IDE version: 1.8.3
Tested on: ARBD 1
Microcontroller: Atmega 328 p
written by: Anurag Aggarwal
Date: 06/16/2019*/

void setup()
{
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

int pattern[4] = {8, 4, 2, 1};       //here 8 means 0b1000, 4 means 0b0100,.....
int key[4][4] = {{1, 2, 3, 10}, {4, 5, 6, 11}, {7, 8, 9, 12}, {14, 0, 15, 13}};    //buttons on keypad matrix is in integer format
int column[4] = {6, 7, 8, 9};        //D6, D7, D8, D9 pins are connected with column of keypad matrix
int row[4] = {10, 11, 12, 13};       //D10, D11, D12, D13 pins are connected with row of keypad matrix

void loop()
{
  for (int i = 0; i <= 3; i++)
  {
    col_on(pattern[i]);        //Calling col_on function and passing patterns
    int j=row_read();          //Storing the values of the rows reading value from the user
    if(j!=6)                   //Indicating that one of the keys has been pressed
    {
      if (key[j][i] == 1)      //if 1st key is preesed
      {
       //12 pins of charlieplexing led are connected with 4 pins
        pinMode(A2,INPUT);       //A2 pin is taken as input to give high impedence
        pinMode(A3,INPUT);       //A3 pin is taken as input to give high impedence
        pinMode(A4,OUTPUT);      //between 2 pins we can connect only 2 led
        pinMode(A5,OUTPUT);
      
        digitalWrite(A5,HIGH);   //out of 2 led, we give high to 1 led so it will glow
        digitalWrite(A4, LOW);
        delay(1000);             // wait for 1 sec
      }
      else if (key[j][i] == 2)
      {
        pinMode(A2, INPUT);
        pinMode(A3, OUTPUT);
        pinMode(A4, INPUT);
        pinMode(A5, OUTPUT);

        digitalWrite(A5, HIGH);
        digitalWrite(A3, LOW);
        delay(1000);
      }
      else if (key[j][i] == 3)
      {
        pinMode(A2, OUTPUT);
        pinMode(A3, INPUT);
        pinMode(A4, INPUT);
        pinMode(A5, OUTPUT);

        digitalWrite(A5, HIGH);
        digitalWrite(A2, LOW);
        delay(1000);
      }
      else if (key[j][i] == 4)
      {
        pinMode(A2, INPUT);
        pinMode(A3, OUTPUT);
        pinMode(A4, OUTPUT);
        pinMode(A5, INPUT);

        digitalWrite(A4, HIGH);
        digitalWrite(A3, LOW);
        delay(1000);
      }
      else if (key[j][i] == 5)
      {
        pinMode(A2, OUTPUT);
        pinMode(A3, INPUT);
        pinMode(A4, OUTPUT);
        pinMode(A5, INPUT);

        digitalWrite(A4, HIGH);
        digitalWrite(A2, LOW);
        delay(1000);
      }
      else if (key[j][i] == 6)
      {
        pinMode(A2, INPUT);
        pinMode(A3, INPUT);
        pinMode(A4, OUTPUT);
        pinMode(A5, OUTPUT);

        digitalWrite(A4, HIGH);
        digitalWrite(A5, LOW);
        delay(1000);
      }
      else if (key[j][i] == 7)
      {
        pinMode(A2, OUTPUT);
        pinMode(A3, OUTPUT);
        pinMode(A4, INPUT);
        pinMode(A5, INPUT);

        digitalWrite(A3, HIGH);
        digitalWrite(A2, LOW);
        delay(1000);
      }
      else if (key[j][i] == 8)
      {
        pinMode(A2, INPUT);
        pinMode(A3, OUTPUT);
        pinMode(A4, INPUT);
        pinMode(A5, OUTPUT);

        digitalWrite(A3, HIGH);
        digitalWrite(A5, LOW);
        delay(1000);
      }
      else if (key[j][i] == 9)
      {
        pinMode(A2, INPUT);
        pinMode(A3, OUTPUT);
        pinMode(A4, OUTPUT);
        pinMode(A5, INPUT);

        digitalWrite(A3, HIGH);
        digitalWrite(A4, LOW);
        delay(1000);
      }
      else if (key[j][i] == 10)
      {
        pinMode(A2, OUTPUT);
        pinMode(A3, INPUT);
        pinMode(A4, INPUT);
        pinMode(A5, OUTPUT);

        digitalWrite(A2, HIGH);
        digitalWrite(A5, LOW);
        delay(1000);
      }
      else if (key[j][i] == 11)
      {
        pinMode(A2, OUTPUT);
        pinMode(A3, INPUT);
        pinMode(A4, OUTPUT);
        pinMode(A5, INPUT);

        digitalWrite(A2, HIGH);
        digitalWrite(A4, LOW);
        delay(1000);
      }
      else if (key[j][i] == 12)
      {
        pinMode(A2, OUTPUT);
        pinMode(A3, OUTPUT);
        pinMode(A4, INPUT);
        pinMode(A5, INPUT);

        digitalWrite(A2, HIGH);
        digitalWrite(A3, LOW);
        delay(1000);
      }
    }
  }
}

int row_read() {
  if (digitalRead(row[0]))
  { while (digitalRead(row[0]));
    return 0;
  }
  if (digitalRead(row[1]))
  { while (digitalRead(row[1]));
    return 1;
  }
  if (digitalRead(row[2]))
  { while (digitalRead(row[2]));
    return 2;
  }
  if (digitalRead(row[3]))
  { while (digitalRead(row[3]));
    return 3;
  }

  return 6;

}

void col_on(int pattern)
{
  digitalWrite(column[0], pattern == 8);
  digitalWrite(column[1], pattern == 4);
  digitalWrite(column[2], pattern == 2);
  digitalWrite(column[3], pattern == 1);
}




