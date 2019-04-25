#include <Stepper.h>

const int stepsPerRevolution = 512;

Stepper myStepper1(stepsPerRevolution, 8, 10, 9, 11);
Stepper myStepper2(stepsPerRevolution, 4, 6, 5, 7);

void setup() {
  // put your setup code here, to run once:
  myStepper1.setSpeed(60);
  myStepper2.setSpeed(60);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int command = 0;
  
  if(Serial.available() > 0){
    command = Serial.read();
  }

  switch(command){
    case '1'://Forward
      myStepper1.step(100);
      myStepper2.step(-100);
      break;
    case '2'://Back
      myStepper1.step(-100);
      myStepper2.step(100);
      break;
    case '3'://Left
      myStepper1.step(-100);
      myStepper2.step(-100);
      break;
    case '4'://Right
      myStepper1.step(100);
      myStepper2.step(100);
      break;
  }
}
