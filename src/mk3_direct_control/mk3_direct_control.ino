#include <Stepper.h>

#define ZERO_RANGE 20

Stepper motor_b(200, 2, 4, 3, 5);
Stepper motor_v(200, 6, 8, 7, 9);
Stepper motor_h(200, 10, 12, 11, 13);

int RPM[3] = {0, 0, 0};

void setup() {
  Serial.begin(9600);
}

void loop() {
  int Speed = analogRead(A0);
  int Speed1 = analogRead(A1);
  int Speed2 = analogRead(A2);
  RPM[0] = map(Speed, 0, 1023, -100, 100);
  RPM[1] = map(Speed1, 0, 1023, -100, 100);
  RPM[2] = map(Speed2, 0, 1023, -100, 100);

  moveMotor(1);
  moveMotor(2);
  moveMotor(3);
}

void moveMotor(int motor) {
  int rpm = RPM[motor - 1];
  if (motor == 1) {
    if (rpm >= ZERO_RANGE) {
      motor_b.step(1);
      motor_b.setSpeed(rpm);
      delay(1);
    }
    else if (rpm <= -ZERO_RANGE) {
      motor_b.step(-1);
      motor_b.setSpeed(-rpm);
      delay(1);
    }
    else {
      stopMotor(motor);
    }
  }
  else if (motor == 2) {
    if (rpm >= ZERO_RANGE) {
      motor_v.step(1);
      motor_v.setSpeed(rpm);
      delay(1);
    }
    else if (rpm <= -ZERO_RANGE) {
      motor_v.step(-1);
      motor_v.setSpeed(-rpm);
      delay(1);
    }
    else {
      stopMotor(motor);
    }
  }
  else if (motor == 3) {
    if (rpm >= ZERO_RANGE) {
      motor_h.step(1);
      motor_h.setSpeed(rpm);
      delay(1);
    }
    else if (rpm <= -ZERO_RANGE) {
      motor_h.step(-1);
      motor_h.setSpeed(-rpm);
      delay(1);
    }
    else {
      stopMotor(motor);
    }
  }

}

void stopMotor(int motor) {
  if (motor == 1) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  if (motor == 2) {
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }
  if (motor == 3) {
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
}
