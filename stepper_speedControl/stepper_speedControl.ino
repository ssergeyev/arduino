#include <Stepper.h>
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
unsigned long t,t1;
boolean dir=true;
int mstep=2;

Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
int stepCount = 0;  // number of steps the motor has taken

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorReading = analogRead(A0);
  int motorSpeed = map(sensorReading, 0, 1023, 0, 300);
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    //myStepper.step(stepsPerRevolution / 100);
    myStepper.step(mstep);
  }  
  t=millis();
  if (t-t1>=2000){
    t1=t;
    Serial.println(motorSpeed);
    if(mstep==2){mstep = -2;} else {mstep = 2;}
  }  
}
