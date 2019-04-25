#include "AFMotor.h"

AF_DCMotor motor1(3, MOTOR34_64KHZ);
AF_DCMotor motor2(4, MOTOR34_64KHZ);

int command;

void setup() {
  Serial.begin(9600);
  Serial.flush();
  command = 0;
}

void loop() {
  if(Serial.available() > 0){
    command = Serial.read();
  }

  switch(command){
    case '0':
      motor1.setSpeed(0);
      motor2.setSpeed(0);
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      delay(10);
    case '1'://Forward
      motor1.setSpeed(255);
      motor1.run(BACKWARD);
      motor2.setSpeed(236);
      motor2.run(BACKWARD);
      break;
    case '2'://Back
      motor1.setSpeed(255);
      motor1.run(FORWARD);
      motor2.setSpeed(236);
      motor2.run(FORWARD);
      break;
    case '3'://Left
      motor1.setSpeed(98);
      motor1.run(BACKWARD);
      motor2.setSpeed(98);
      motor2.run(FORWARD);
      break;
    case '4'://Right
      motor1.setSpeed(98);
      motor1.run(FORWARD);
      motor2.setSpeed(98);
      motor2.run(BACKWARD);
      break;
  }
}
