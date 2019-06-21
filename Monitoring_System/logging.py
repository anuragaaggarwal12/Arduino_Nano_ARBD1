#!/usr/bin/env python
# coding: utf-8

import serial 
import thingspeak
from time import sleep

mych=thingspeak.Channel(806491,api_key="Z7I1KDZEYOMNS6I8")

arduino=serial.Serial('COM3',9600)

arduino.flushInput()
for i in range(10):
    sleep(1)
    a=int(arduino.readline()[:-2])
    b=int(arduino.readline()[:-2])
    c=int(arduino.readline()[:-2])
    d=int(arduino.readline()[:-2])
    data = {'field1':a,'field2':b,'field3':c,'field4':d}
    print(data)
    up = mych.update(data)      #jason format
    while(up == '0'):
        up = mych.update({'field1':a,'field2':b,'field3':c,'field4':d})

arduino.close()     #to close com3 port of arduino
