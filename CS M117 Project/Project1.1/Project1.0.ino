#include "AFMotor.h"

AF_DCMotor motor1(3, MOTOR34_64KHZ);
AF_DCMotor motor2(4, MOTOR34_64KHZ);

const int buzzer = 7;
const int led1   = 8;
const int led2   = 9;
const int led3   = 10;
const int led4   = 11;
int command;

void setup() {
  Serial.begin(9600);
  Serial.flush();
  pinMode(buzzer, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
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
      noTone(buzzer);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      //Serial.print("Inside Case 0\n");
      break;
    case '1'://Forward
      motor1.setSpeed(255);
      motor1.run(BACKWARD);
      motor2.setSpeed(236);
      motor2.run(BACKWARD);
      //Serial.print("Inside Case 1\n");
      break;
    case '2'://Back
      motor1.setSpeed(255);
      motor1.run(FORWARD);
      motor2.setSpeed(236);
      motor2.run(FORWARD);
      //Serial.print("Inside Case 2\n");
      break;
    case '3'://Left
      motor1.setSpeed(98);
      motor1.run(BACKWARD);
      motor2.setSpeed(98);
      motor2.run(FORWARD);
      //Serial.print("Inside Case 3\n");
      break;
    case '4'://Right
      motor1.setSpeed(98);
      motor1.run(FORWARD);
      motor2.setSpeed(98);
      motor2.run(BACKWARD);
      //Serial.print("Inside Case 4\n");
      break;
    case '5'://Sound
      tone(buzzer, 1000);
      //Serial.print("Inside Case 5\n");
      break;
    case '6'://Lights
      digitalWrite(led1, HIGH);
      digitalWrite(led3, HIGH);
      delay(100);
      digitalWrite(led1, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led4, HIGH);
      delay(100);
      digitalWrite(led2, LOW);
      digitalWrite(led4, LOW);
      //Serial.print("Inside Case 6\n");
      break;
  }
}
