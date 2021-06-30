/*
Made for the 28BYJ-48 stepper motor
Contact me on discord: PhillipJK#8190
*/

#include <Stepper.h>

const int stepsPerRevolution = 360;

// initialize the stepper library on pins 8 through 11 (IN1-IN4 on driver board):
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11); // initializing a stepper motor object

void setup() {
  myStepper.setSpeed(64);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution
  Serial.println("moving");
  myStepper.step(2048);
  delay(5000); // delay for 5 seconds (5000ms)
}
