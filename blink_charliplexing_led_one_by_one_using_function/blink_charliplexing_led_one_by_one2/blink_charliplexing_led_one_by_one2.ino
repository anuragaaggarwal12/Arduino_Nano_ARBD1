/*Arduino IDE version: 1.8.3
Tested on: ARBD 1
Microcontroller: Atmega 328 p
written by: Anurag Aggarwal
Date: 06/12/2019*/

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  int patterns[12]={2201,2021,221,2012,212,2210,122,2120,2102,1220,1202,1022};   //here we make array to glow different led
  for(int i=0;i<12;i++)       //runs loop 12 times as we have 12 charlieplexing led
  {
    cpl(patterns[i]);         //calling function of void cpl(int pattern)
    delay(1000);              //// wait for 1 sec
  }
   
}
void cpl(int pattern)
{
  Serial.println(pattern/1000);             //for printing the no. at thousand place
  Serial.println((pattern/100)%10);         //for printing the no. at hundred place
  Serial.println((pattern/10)%10);          //for printing the no. at tens place
  Serial.println(pattern%10);               //for printing the no. at ones place
  if((pattern/1000==1)||(pattern/1000==0))  //check if the no. at particular pin is 0,1 or z
  {
    pinMode(A2,OUTPUT);                     //if the no. is 0 or 1 then assign it as Output
    digitalWrite(A2,pattern/1000);
  }
  else
  pinMode(A2,INPUT);                        //if the no. is z then assign it as Input
  if(((pattern/100)%10==1)||((pattern/100)%10==0))
  {
    pinMode(A3,OUTPUT);
    digitalWrite(A3,(pattern/100)%10);
  }
  else
  pinMode(A3,INPUT);
  if(((pattern/10)%10==1)||((pattern/10)%10==0))
  {
    pinMode(A4,OUTPUT);
    digitalWrite(A4,(pattern/10)%10);
  }
  else
  pinMode(A4,INPUT);
  if(((pattern)%10==1)||((pattern)%10==0))
  {
    pinMode(A5,OUTPUT);
    digitalWrite(A5,(pattern)%10);
  }
  else
  pinMode(A5,INPUT);
  
}
