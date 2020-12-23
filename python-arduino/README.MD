# Uso
Una vez cargado ArduinoStepperControl.ino al Arduino,

import InstrumentControl

Loading InstrumentControl v1.2

#Change 'COM5' to the Arduino COM port.

Stepper=InstrumentControl.StepperMotor('COM5')

StepperMotor: Serial Communication Open

#Hacer girar el motor 1 en 100 pasos

Stepper.Girar(120, 100)
