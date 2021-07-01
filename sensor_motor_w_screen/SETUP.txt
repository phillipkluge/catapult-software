PURPOSE:
	To continually turn the catapult base until the sensor detects an object within a certain number of centimeters (set by the user)

SETUP:
- For the Screen and Sensor:

	1. Get a breadboard and the Arduino, connect the Arduino 5V to a "+" rail on the breadboard and Arduino GND to a "-" rail using cables.
		*This will act as power and ground for all other components
	2. Attach the screen to the breadboard
	3. Attach the sensor to the breadboard
	4. Attach a 10k Potentiometer to the breadboard (used to control the backlight of the screen)
	5. Attach the following from the sensor to the Arduino:
		- The Sensor VCC connect to the Arduino 5V (as setup in step 1)
		- The Sensor GND connect to the Arduino GND (as setup in step 1)
		- The Sensor Trig connect to the Arduino Board Digital I/O 13
		- The Sensor Echo connect to the Arduino Board Digital I/O 12
	6. Attach the following from the screen to Arduino:
		- LCD VSS pin to Arduino GND (as setup in step 1)
		- LCD VDD pin to Arduino 5V (as setup in step 1)
		- LCD RS pin to digital pin 1
		- LCD RW pin to Arduino GND (as setup in step 1)
		- LCD Enable pin to digital pin 2
		- LCD D4 pin to digital pin 4
		- LCD D5 pin to digital pin 5
		- LCD D6 pin to digital pin 6
		- LCD D7 pin to digital pin 7
		- LCD VO pin to 10k Potentiometer center pin
		- The 10k Potentiometer's other legs connect to +5V and GND
		- For the backlight of the display, pin 15 (A) and 16 (K) of the LCD connect to 5V and GND
			Use a 220 Ohm resistor when connecting pin 15 to 5V for best results

- For the Stepper Motor:

	7. Make sure you have the motor AND driver from the kit. (As well as the Arduino of course)
	8. Connect IN1, IN2, IN3, and IN4 from the driver to pins 8, 9, 10, 11 on the Arduino respectively
	9. Connect 5V power and GND from the driver to the breadboard (as set up in step 1)
	10. Finally, connect the stepper motor to the driver

11. Plug it in and upload the code provided, you can mess with parameters as you see fit
	*If you need any help just contact me on discord: @PhillipJK#8190 or email: kluge@ualberta.ca


REFERENCE(S):
	- https://www.instructables.com/Arduino-Ultrasonic-Sensor-HC-SR04-With-LCD-Display/
