# Uso
Una vez cargado ArduinoStepperControl.ino al Arduino,
>>> import InstrumentControl
Loading InstrumentControl v1.2
#Change 'COM5' to the Arduino COM port.
>>> Stepper=InstrumentControl.StepperMotor('COM5')
StepperMotor: Serial Communication Open
#Get the version of ArduinoStepperControl software
>>> Stepper.GetVersion()
'5.00'
#Set position of motor
>>> Stepper.SetPosition(1,1,2000)
2000
#Ask Arduino for motor position
>>> Stepper.GetPosition()
'2000'