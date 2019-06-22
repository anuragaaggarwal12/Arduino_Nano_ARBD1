/*Arduino IDE version: 1.8.3
Tested on: ARBD 1
Microcontroller: Atmega 328 p
written by: Anurag Aggarwal
Date: 06/20/2019*/

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

int pattern[4]={8,4,2,1};      //here 8 means 0b1000, 4 means 0b0100,.....
int key[4][4]={{1,2,3,10},{4,5,6,11},{7,8,9,12},{14,0,15,13}};  //buttons on keypad matrix is in integer format
int column[4]={6,7,8,9};       //D6, D7, D8, D9 pins are connected with column of keypad matrix
int row[4]={10,11,12,13};      //D10, D11, D12, D13 pins are connected with row of keypad matrix

void loop()
{
  for(int i=0;i<=3;i++)
  {
    col_on(pattern[i]);        //Calling col_on function and passing patterns
    int j=row_read();          //Storing the values of the rows reading value from the user
    if(j!=6)                   //Indicating that one of the keys has been pressed
    {
      Serial.println(key[j][i]);    //print the value of key enter by user(row, column)
    }
  }
}  

int row_read(){
  if(digitalRead(row[0]))         //it read the 0th pin of row of keypad matrix
 { while(digitalRead(row[0]));       //wait until another key is press
    return 0;
 }
  if(digitalRead(row[1]))         //it read the 1st pin of row of keypad matrix
  {while(digitalRead(row[1]));
    return 1;
  }
  if(digitalRead(row[2]))         //it read the 2nd pin of row of keypad matri
  {while(digitalRead(row[2]));
    return 2;
  }
  if(digitalRead(row[3]))
  {while(digitalRead(row[3]));    //it read the 3rd pin of row of keypad matrix
  {
    return 3;
  }
  
    return 6;                     //if key is not read and pressed then it return
  
}

void col_on(int pattern)
{
  digitalWrite(column[0],pattern==8);     //high 0th column when the pattern is equal to 8(0b1000)
  digitalWrite(column[1],pattern==4);     //high 1st column when the pattern is equal to 8(0b0100)
  digitalWrite(column[2],pattern==2);     //high 2nd column when the pattern is equal to 8(0b0010)
  digitalWrite(column[3],pattern==1);     //high 3rd column when the pattern is equal to 8(0b0001)
}



