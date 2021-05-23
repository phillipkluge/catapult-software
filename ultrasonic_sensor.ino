/*
 HC-SR04 Ping distance sensor
 VCC to arduino 5v GND to arduino GND
 Echo to Arduino pin 13 Trig to Arduino pin 12
 Red POS to Arduino pin 11
 Green POS to Arduino pin 10
 */
#include <LiquidCrystal.h>

#define trigPin 13
#define echoPin 12

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // (rs, enable, d4, d5, d6, d7)

void setup() {
  lcd.begin(16,2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // setup and calculations
  long duration, distance;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  // changing led statuses
  if (distance >= 450 || distance <= 0) {  // This is where the LED On/Off happens
    lcd.print("Dist: N/A");
    delay(750);
    lcd.clear();
  }
  else {
    lcd.print("Dist: ");
    lcd.print(distance);
    lcd.print("cm");
    delay(750);
    lcd.clear();
  }
}
