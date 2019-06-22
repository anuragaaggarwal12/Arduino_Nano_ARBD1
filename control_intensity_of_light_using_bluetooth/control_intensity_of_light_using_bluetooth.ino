/*Arduino IDE version: 1.8.3
  Tested on: ARBD 1
  Microcontroller: Atmega 328 p
  written by: Anurag Aggarwal
  Date: 06/18/2019*/

//include the library of bluetooth serial communication
#include <SoftwareSerial.h>

SoftwareSerial bt(12, 13);       //pins connected to bluetooth(RX, TX)

//to convert char into integer
int chartoint(char val[3]) {
  return 100 * (int(val[0]) - 48) + 10 * (int(val[1]) - 48) + (int(val[2]) - 48);
}
void led_on(int pin_no, int value)       //funtion is build
{ analogWrite(pin_no, value);
}

void setup() {
  pinMode(9, OUTPUT);           //D9 is connected with green led
  pinMode(10, OUTPUT);          //D10 is connected with blue led
  pinMode(11, OUTPUT);          //D11 is connected with red led
  bt.begin(9600);               //it start the serial communication of bluetooth whose baud rate is 9600 bits/sec
  Serial.begin(9600);           //it start the serial monitor whose baud rate is 9600 bits/sec
}

int value;
char temp;
void loop()
{
  if (bt.available())           //check if bluetooth is connected or not
  {
    temp = bt.read();           //read the data passing from bluetooth terminal
    if (temp == 'G')            //check if data sent from bluetooth terminal is equal to character 'G' which we defined
    {
      intensity_read(9);        //calling funtion of void intensity_read(int pin no)
    }
    if (temp == 'B')            //check if data sent from bluetooth terminal is equal to character 'B' which we defined
    { intensity_read(10);
    }
    else if (temp == 'R')       //check if data sent from bluetooth terminal is equal to character 'R' which we defined
    { intensity_read(11);
    }
  }
}
void intensity_read(int pin_no)       //function is built
{
  char val[3];

  delay(1);                            //delay of 1 mili volt is given so that it does not take any garbage value initially
  for (int i = 0; i < 3 ; i++) {
    val[i] = bt.read();                //eg--we give value from bluetooth like G010,B100
    delay(1);                          //delay of 1 mili volt is given so that it does not take any garbage value at last
  }
  int inten = chartoint(val);          //calling function of int chartoint(char val[3])
  value = map(inten, 0, 255, 0, 100);     //mapping value of 255 to 100 so if we give value =0 from bluetooth that led will off
                                          //and if we give value =100 from bluetooth that led will turn on with highest intensity

  led_on(pin_no, value);                  //calling function of void led_on(int pin_no,int value)
}
