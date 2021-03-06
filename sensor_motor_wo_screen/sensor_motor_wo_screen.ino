/*
 * SETUP AND WIRING INSTRUCTIONS ARE INCLUDED IN THE SETUP.txt FILE
 * REVISED 2021/06/29
 */
#include <Stepper.h>

#define trigPin 13
#define echoPin 12

const int stepsPerRevolution = 360;

Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

/*
 * Function to calculate the distance from the parameters of the sensor
 */
long calculate() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  return distance;
}

/*
 * Makes a determination based on the user set max distance
 * if the object is in range
 */
bool detect(long distance, int maxdist) {
  bool detectobj = true;
  
  if ((distance > maxdist) || (distance >= 450 || distance <= 0)) {  // If the distance is outside the user's range OR the sensor's range
    detectobj = false; // no object has been detected
  }
  
  return detectobj;
}

/*
 * Function to setup the project, sets pinout and motor speed
 */
void setup() {
  myStepper.setSpeed(36);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

/*
 * The main function that loops similar to a while loop as long as the Arduino has power
 */
void loop() {
  long distance; // the current distance the sensor finds
  bool detectobj = true; // if an object has been found

  // CONFIGURE THESE VARIABLES TO YOUR LIKING
  int maxdist = 30; // the maximum distance the sensor will detect an object (in cm, with a max of 450)
  int steps = 12; // number of steps the motor will take for every sensor check (out of 2048 for full rotation)

  distance = calculate(); // finds the distance to the nearest object

  detectobj = detect(distance, maxdist); // finds if there is an object within the set distance

  // if there is no object detected, spin the base of the catapult further
  if (!detectobj) {
    myStepper.step(steps);
  }
}
