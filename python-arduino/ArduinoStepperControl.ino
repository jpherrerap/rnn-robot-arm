//ArduinoStepperControlv5.0
//2012-04-14 jdreyer
//Stepper motor control program
//Arduino will respond to ENQ character with the motor position 
//#define STEPPER_PIN_1 2
//#define STEPPER_PIN_2 3
//#define STEPPER_PIN_3 4
//#define STEPPER_PIN_4 5

int STEPPER_PIN_1=2;
int STEPPER_PIN_2=3;
int STEPPER_PIN_3=4;
int STEPPER_PIN_4=5;
int stepsToMoveNeg;
int StartByte;
int i;
int userInput[3];
int digitalVal;
int dir;
int steps;
int previous=0;
int val;
char direction;
int negVal;
int StepperPosition=0;
int byte1;
int byte2;
float Version=5.0;

int DirectionPin=8;
int StepPin=12;

void setup() {
   Serial.begin(115200);
   pinMode(13, OUTPUT); 
   pinMode(DirectionPin, OUTPUT);
   pinMode(StepPin, OUTPUT);
   pinMode(STEPPER_PIN_1, OUTPUT);
   pinMode(STEPPER_PIN_2, OUTPUT);
   pinMode(STEPPER_PIN_3, OUTPUT);
   pinMode(STEPPER_PIN_4, OUTPUT);
}

void loop()
{
  if (Serial.available() > 2) {
    StartByte = Serial.read();
    if (StartByte == 255) {
      for (i=0;i<2;i++) {
        userInput[i] = Serial.read();
      }
      byte1 = userInput[0];
      byte2 = userInput[1];
      val = (byte2<<8) | byte1;
      int stepsToMove = val-previous;
      
      if (stepsToMove > 0){
        //Move Forward 
        TurnMotorClockWise(stepsToMove);
      }
      if (stepsToMove < 0){
        TurnMotorCounterClockWise(stepsToMove*-1);
      }
      previous = val;
    }
    
    if (StartByte == 220) {
      for (i=0;i<2;i++) {
        userInput[i] = Serial.read();
      }
      byte1 = userInput[0];
      byte2 = userInput[1];
      val = (byte2<<8) | byte1;
      negVal = val * -1;
      int stepsToMove = negVal-previous;
      
      if (stepsToMove > 0){
        TurnMotorClockWise(stepsToMove);
      }
      if (stepsToMove < 0){
        TurnMotorCounterClockWise(stepsToMove*-1);
      }
      previous = negVal;
    }

    if (StartByte == 5) {
      Serial.print(StepperPosition);
    }
    
    if (StartByte == 118) {
      Serial.print(Version);
    }
    if (StartByte == 120) { // Esta parte es para hacer pruebas
      userInput[0] = Serial.read();
      userInput[1] = Serial.read();
      Serial.print(userInput[0]);
      Serial.print(userInput[1]);
      //TurnMotorCounterClockWise(100);
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

void TurnMotorClockWise(int steps)
{
  // Iterate for [steps] microsteps
  for (i = 0; i<steps; i++)       
  {
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  delay(2);

  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  delay(2);

  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  delay(2);

  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  delay(2);
  }
  StepperPosition=StepperPosition+steps;
}

void TurnMotorCounterClockWise(int steps)
{
  for (i = 0; i<steps; i++)       
  {
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  delay(2);
  
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  delay(2);
  
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  delay(2);
  
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  delay(2);
  }
  StepperPosition=StepperPosition-steps;
}
