#!/usr/bin/python
# Filename: InstrumentControl.py
version = '1.2'

#serial is a modified python serial module which disables the dtrState preventing
#resets when the serial session is closed.
#http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1274205532

#Code adapted from Dan Thompson and build-in Arduino examples
#http://danthompsonsblog.blogspot.com/2009/04/python-arduino-motor-shield-stepper.html
#and
#http://danthompsonsblog.blogspot.com/2008/09/easydriver-v31-tutorial.html

import serial
import time

print ('Loading InstrumentControl v'+ version)

def help():
	print('InstrumentControl.py currently supports:')
	print('Stepper Motor Control')

class StepperMotor:
    def __init__(self, StepperMotorAddress):
        self.StepperMotorAddress = StepperMotorAddress
        self.StepperMotor = serial.Serial(StepperMotorAddress, 115200, timeout=0.25)
        print("StepperMotor: Serial Communication Open" )
        time.sleep(1)
    def CloseSerial(self):
        #Close Serial Port
        self.StepperMotor.close()
        print( "StepperMotor: Serial Communication Closed"  )
        return
    def GetPosition(self):
        self.StepperMotor.write(bytes(chr(5)+chr(0)+chr(0), encoding='utf8'))
        time.sleep(1)
        StepperPosition=self.StepperMotor.readline().decode("utf-8")
        return StepperPosition

    def Girar(self, motor, a):
            self.StepperMotor.write(bytes(chr(120), encoding='utf8'))
            self.StepperMotor.write(bytes(chr(motor), encoding='utf8'))
            self.StepperMotor.write(bytes(chr(abs(a)), encoding='utf8'))
            self.StepperMotor.write(bytes(chr(abs(a)//a + 120), encoding='utf8'))


