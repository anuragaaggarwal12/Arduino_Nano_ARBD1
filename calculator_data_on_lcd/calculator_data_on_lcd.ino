/*Arduino IDE version: 1.8.3
Tested on: ARBD 1
Microcontroller: Atmega 328 p
written by: Anurag Aggarwal
Date: 06/17/2019*/

//include the library of lcd
#include<LiquidCrystal.h>

LiquidCrystal lcd(4, 5, 0, 1, 2, 3);     //pins connected to lcd(registor select, reset, D0, D1, D2, D3)

void col_on(int pattern);
int row_read();

//Patterns for different columns being high at different times
int pattern[4] = {8, 4, 2, 1};    //8 means 0b1000, 4 means 0b0100.....

char key[4][4] = {{'1', '2', '3', '+'}, {'4', '5', '6', '-'}, {'7', '8', '9', '*'}, {'c', '0', '=', '/'}};
int column[4] = {6, 7, 8, 9};     //D6, D7, D8, D9 pins are connected with column of keypad matrix
int row[4] = {10, 11, 12, 13};    //D10, D11, D12, D13 pins are connected with row of keypad matrix
long ctoi(char num[7], int num_count);

void setup()
{
  pinMode(6, OUTPUT);    //0th column pin of keyboard matrix
  pinMode(7, OUTPUT);    //1st column pin of keyboard matrix
  pinMode(8, OUTPUT);    //2nd column pin of keyboard matrix
  pinMode(9, OUTPUT);    //3rd column pin of keyboard matrix
  pinMode(10, INPUT);    //0th row pin of keyboard matrix
  pinMode(11, INPUT);    //1st row pin of keyboard matrix
  pinMode(12, INPUT);    //2nd row pin of keyboard matrix
  pinMode(13, INPUT);    //3rd row pin of keyboard matrix
  lcd.begin(16, 2);      //it start the lcd whose display is (16*2)
}
int a, b, c;
char num1[7] = {0}, op;
char num2[7];
int count = 0;


int vnum = 0;
int num1_count;
void loop() {
  for (int i = 0; i < 4; i++) {
    col_on(pattern[i]);      //Calling col_on function and passing patterns
    int j = row_read();      //Storing the values of the rows by reading value from the user
    if (j != 5) {            //Indicating that one of the keys has been pressed
      {
        if ((key[j][i] == '1') || (key[j][i] == '2') || (key[j][i] == '3') || (key[j][i] == '4') || (key[j][i] == '5') || (key[j][i] == '6') || (key[j][i] == '7') || (key[j][i] == '8') || (key[j][i] == '9') || (key[j][i] == '0')) {
          if (vnum == 0) {
            num1[count] = key[j][i];      //storing the first entered number
            lcd.print(key[j][i]);         //prrint the first number taken from user
            count++;
            if (count >= 7)
            {
              lcd.print("Maxm limit reached");
            }
          }
          if (vnum = 1)
          { num2[count] = key[j][i];          //Storing the second entered number
            Serial.print(key[j][i]);           //print the first number taken from user
            count++;
            if (count >= 7)
            {
              Serial.println("Maxm limit reached");
            }
          }
        }
        if ((key[j][i] == '+') || (key[j][i] == '-') || (key[j][i] == '*') || (key[j][i] == '/')) {
          if (vnum == 0) {
            op = key[j][i];                     //Store the operator
            lcd.print(key[j][i]);
            num1_count = count;                 //store first number
            count = 0;
            vnum = 1;
          } else {
            lcd.print("press equal to!!");
          }
        }
        else if (key[j][i] == 'c')
        {
          if (count > 0)
            count--;
        }
        else if (key[j][i] == '=')
        { lcd.print('=');                      //print '=' on the lcd screen
          switch (op)
          {
            case '+': lcd.setCursor(0, 1);     //set cursor of lcd to (column=0, row=1) coordinates
              lcd.print(ctoi(num1, num1_count) + ctoi(num2, count));
              lcd1();
              break;
            case '-': lcd.setCursor(0, 1);
              lcd.print(ctoi(num1, num1_count) - ctoi(num2, count));
              lcd1();
              break;
            case '*': lcd.setCursor(0, 1);
              lcd.print(ctoi(num1, num1_count)*ctoi(num2, count));
              lcd1();
              break;
            case '/': lcd.setCursor(0, 1);
              if (ctoi(num2, count) == 0)
              {
                lcd.print("inf");
              }
              else
                lcd.print(ctoi(num1, num1_count) / ctoi(num2, count));
              lcd1();
              break;
            default: lcd.setCursor(0, 1);
              lcd.print(ctoi(num1, num1_count));
              lcd1();


          }
          count = 0;
          vnum = 0;
        }

        if (vnum = 1)
        { num2[count] = key[j][i];
          Serial.print(key[j][i]);
          count++;
          if (count >= 7)
          {
            Serial.println("Maxm limit reached");
          }
        }
      }
    }

  }

  long ctoi(char num[7], int num1_count)
  {
    long temp = 1;
    long res = 0;
    for (int i = num1_count - 1; i >= 0; i--)
    {

      res = res + (temp * (num[i] - 48));
      temp = temp * 10;

    }
    return res;
  }

  void lcd1()
  {
    lcd.setCursor(0, 0);
    delay(2000);
    lcd.print("                ");
    lcd.setCursor(0, 0);
  }
  void col_on(int pattern)
  {
    digitalWrite(column[0], pattern == 8);  //high 0th column when the pattern is equal to 8(0b1000)
    digitalWrite(column[1], pattern == 4);  //high 1st column when the pattern is equal to 8(0b0100)
    digitalWrite(column[2], pattern == 2);  //high 2nd column when the pattern is equal to 8(0b0010)
    digitalWrite(column[3], pattern == 1);  //high 3rd column when the pattern is equal to 8(0b0001)
  }

  int row_read()
  {
    if (digitalRead(row[0]))            //it read the 0th pin of row of keypad matrix
    { while (digitalRead(row[0]));      //wait until another key is press
      return 0;
    }
    if (digitalRead(row[1]))            //it read the 1st pin of row of keypad matrix
    { while (digitalRead(row[1]));
      return 1;
    }
    if (digitalRead(row[2]))            //it read the 2nd pin of row of keypad matri
    { while (digitalRead(row[2]));
      return 2;
    }
    if (digitalRead(row[3]))
    { while (digitalRead(row[3]));      //it read the 3rd pin of row of keypad matrix
      {
        return 3;
      }

      return 5;                         //if key is not read and pressed then it return

    }

