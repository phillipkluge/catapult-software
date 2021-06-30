/*
 * SETUP AND WIRING INSTRUCTIONS ARE INCLUDED IN THE SETUP.md FILE
 * REVISED 2021/06/29
 */
#include <LiquidCrystal.h>
#include <Stepper.h>

#define trigPin 13
#define echoPin 12

const int stepsPerRevolution = 360;

Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // (rs, enable, d4, d5, d6, d7) // Creating the lcd display object

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
 * Prints distance to the display, also makes a determination based on the user set max distance
 * if the object is in range
 */
bool print_detect(long distance, int maxdist, String prefix) {
  bool detectobj = true;

  lcd.print(prefix + "000");
  
  if (distance > maxdist) {  // If the distance is outside the user's range
    detectobj = false;
  }
  
  if (distance >= 10 && distance < 100) { // if the distancee is a two digit number
    lcd.setCursor(7,0);
    lcd.print(distance);
  }
  else if (distance >= 100 && distance < 450) { // if the distance is a three digit number
    lcd.setCursor(6,0);
    lcd.print(distance);
  }
  else if (distance >= 450 || distance <= 0) { // if the distance is out of sensor bounds
    detectobj = false;
  }
  else { // If the distance is a single digit number
    lcd.setCursor(8, 0);
    lcd.print(distance);
  }

  lcd.setCursor(10,0);
  lcd.print("cm");
  lcd.setCursor(0,1);
  lcd.print("MaxDist: ");
  lcd.print(maxdist);
  lcd.print("cm");
  delay(10);
  lcd.setCursor(0,0);
  
  return detectobj;
}

/*
 * Function to setup the project, sets pinout and motor speed
 */
void setup() {
  myStepper.setSpeed(36);
  lcd.begin(16,2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

/*
 * The main function that loops similar to a while loop as long as the Arduino has power
 */
void loop() {
  long distance; // the current distance the sensor finds
  bool detectobj; // if an object has been found

  // CONFIGURE THESE VARIABLES TO YOUR LIKING
  int maxdist = 30; // the maximum distance the sensor will detect an object (in cm, with a max of 450)
  int steps = 12; // number of steps the motor will take for every sensor check (out of 2048 for full rotation)

  // step the motor, calculate distance, and print to screen
  myStepper.step(steps);
  distance = calculate();
  detectobj = print_detect(distance, maxdist, "Dist: ");

  // if an object was detected, stop the motor as long as it sees the object
  if (detectobj) {
    while (true) {
      distance = calculate();
      detectobj = print_detect(distance, maxdist, "STOP: ");

      if (detectobj == false) {
        break;
      }
    }
  }
}
