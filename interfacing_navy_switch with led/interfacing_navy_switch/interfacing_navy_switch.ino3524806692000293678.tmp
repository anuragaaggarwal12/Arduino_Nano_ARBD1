#define navi_b A1
#define led1 9
#define led2 10
#define led3 11

int current, ledstate= 0;

void setup() {                //run 1 time only
  pinMode(navi_b, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {                 //run many time
  
  current= analogRead(navi_b);
  if(current <= 100)
  {
    if(ledstate == 1){            // we can also write here
      ledstate = 0;                  //ledstate=!ledstate
    }
    else {
      ledstate = 1;
    }
    digitalWrite(led1,ledstate);
    while(analogRead(navi_b) <= 100);
  }

  if((current>= 450) && (current <= 550)) 
  {
    if(ledstate== 1)
    {
      ledstate= 0;
    }
    else{
      ledstate= 1;
    }
    digitalWrite(led2,ledstate);
    while((analogRead(navi_b)>= 450) && (analogRead(navi_b) <=550));
  }
  
    if((current>= 670) && (current <= 700))
  {
    if(ledstate== 1)
    {
      ledstate= 0;
    }
    else{
      ledstate= 1;
    }
    digitalWrite(led3,ledstate);
     while((analogRead(navi_b)>= 670) && (analogRead(navi_b) <=700));
  } 
  if((current>=760)&&(current<=780))
  {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  }
}
  
