#!/usr/bin/env python
# coding: utf-8

import serial 
import thingspeak
from time import sleep

mych=thingspeak.Channel(806491,api_key="Z7I1KDZEYOMNS6I8")     #(channel_id, api_key)

arduino=serial.Serial('COM3',9600)       #data is sent from controller to python

arduino.flushInput()
for i in range(10):
    sleep(1)                             #give delay of 1 mili sec
    a=int(arduino.readline()[:-2])
    b=int(arduino.readline()[:-2])
    c=int(arduino.readline()[:-2])
    
    data = {'field1':a,'field2':b,'field3':c}      #jason format
    print(data)
    up = mych.update(data)                

    #while channel is busy then wait and when channel is not busy update the value         
    while(up == '0'):
        up = mych.update(data)

arduino.close()                           #to close com3 port of arduino
