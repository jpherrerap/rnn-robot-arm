//ArduinoStepperControlv5.0
//2012-04-14 jdreyer
//Stepper motor control program
//Arduino will respond to ENQ character with the motor position 
int stepsToMoveNeg;
int StartByte;
int i;
int userInput[3];
int a;
int steps;
char direction;

int StepperPosition=0;
int mot;
int motornum;
int motor1[4]={2, 3, 4, 5};
int motor2[4]={6, 7, 8, 9};
int motor3[4]={10, 11, 12, 13};
int* motors[3]={motor1, motor2, motor3};
int sgn;

int StepPin=12;

void setup() {
   Serial.begin(115200);
   pinMode(13, OUTPUT); 
   pinMode(StepPin, OUTPUT);
   pinMode(motor1[0], OUTPUT);
   pinMode(motor1[1], OUTPUT);
   pinMode(motor1[2], OUTPUT);
   pinMode(motor1[3], OUTPUT);
  
   pinMode(motor2[0], OUTPUT);
   pinMode(motor2[1], OUTPUT);
   pinMode(motor2[2], OUTPUT);
   pinMode(motor2[3], OUTPUT);
  
   pinMode(motor3[0], OUTPUT);
   pinMode(motor3[1], OUTPUT);
   pinMode(motor3[2], OUTPUT);
   pinMode(motor3[3], OUTPUT);
}

void loop()
{
  if (Serial.available() > 2) {
    StartByte = Serial.read();
    if (StartByte == 5) {
      Serial.print(StepperPosition);
    }

    if (StartByte == 120) {
      userInput[0] = Serial.read();
      userInput[1] = Serial.read();
      userInput[2] = Serial.read();
      sgn=userInput[2];
      motornum=userInput[0]-120;
      a=userInput[1];
      MotorOff( motors[(motornum+1) % 3]);
      MotorOff( motors[(motornum+2) % 3]);
      Serial.print(sgn);
      if (StartByte==119) { // Signo negativo
        TurnMotorCounterClockWise(a, motors[motornum]);
        MotorOff( motors[motornum] );
      }
      if (StartByte == 121) { // Signo positivo
        TurnMotorClockWise(a, motors[motornum]);
        MotorOff( motors[motornum] );
      }
    }
  }
}

void FlashLED(int time)
{
  digitalWrite(13, HIGH);   // set the LED on
  delay(time);              // wait for time
  digitalWrite(13, LOW);    // set the LED off
  delay(10);              
}

void TurnMotorClockWise(int steps, int motor[])
{
  // Iterate for [steps] microsteps
  for (i = 0; i<steps; i++)       
  {
  digitalWrite(motor[0], HIGH);
  digitalWrite(motor[1], LOW);
  digitalWrite(motor[2], LOW);
  digitalWrite(motor[3], LOW);
  delay(2);

  digitalWrite(motor[0], LOW);
  digitalWrite(motor[1], HIGH);
  digitalWrite(motor[2], LOW);
  digitalWrite(motor[3], LOW);
  delay(2);

  digitalWrite(motor[0], LOW);
  digitalWrite(motor[1], LOW);
  digitalWrite(motor[2], HIGH);
  digitalWrite(motor[3], LOW);
  delay(2);

  digitalWrite(motor[0], LOW);
  digitalWrite(motor[1], LOW);
  digitalWrite(motor[2], LOW);
  digitalWrite(motor[3], HIGH);
  delay(2);
  }
  StepperPosition=StepperPosition+steps;
}

void TurnMotorCounterClockWise(int steps, int motor[])
{
  for (i = 0; i<steps; i++)       
  {
  digitalWrite(motor[0], LOW);
  digitalWrite(motor[1], LOW);
  digitalWrite(motor[2], LOW);
  digitalWrite(motor[3], HIGH);
  delay(2);
  
  digitalWrite(motor[0], LOW);
  digitalWrite(motor[1], LOW);
  digitalWrite(motor[2], HIGH);
  digitalWrite(motor[3], LOW);
  delay(2);
  
  digitalWrite(motor[0], LOW);
  digitalWrite(motor[1], HIGH);
  digitalWrite(motor[2], LOW);
  digitalWrite(motor[3], LOW);
  delay(2);
  
  digitalWrite(motor[0], HIGH);
  digitalWrite(motor[1], LOW);
  digitalWrite(motor[2], LOW);
  digitalWrite(motor[3], LOW);
  delay(2);
  }
  StepperPosition=StepperPosition-steps;
}

void MotorOff(int motor[])
{
  digitalWrite(motor[0], LOW);
  digitalWrite(motor[1], LOW);
  digitalWrite(motor[2], LOW);
  digitalWrite(motor[3], LOW);
}
