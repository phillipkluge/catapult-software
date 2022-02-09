# EIC Catapult Project:
A place to store all code needed for the EIC catapult project.
All the hardware used in this project was acquired from [this link](https://www.amazon.ca/Elegoo-Project-Starter-Tutorial-Arduino/dp/B01D8KOZF4/ref=sr_1_5?dchild=1&keywords=elegoo+uno&qid=1622936663&sr=8-5):

# Description of Included Files:

### For stepper_motor.ino:

* Moves the stepper motor around one revolution every 5 seconds.
* Setup based on the diagram at [arduino.cc](https://create.arduino.cc/projecthub/debanshudas23/getting-started-with-stepper-motor-28byj-48-3de8c9)

### For ultrasonic_sensor.ino:

* Uses the display to show the distance of the nearest object to the ultransonic sensor.
* The sensor has a maximum range of 4.50m, anything greater than that and it can not accurately calculate the distance.
* To see a setup of the electronics, see the image labelled "ultrasonic-sensor-image.jpg." I am working on getting a proper diagram drawn up.

### For sensor_motor_w_screen:

* Continually turns the motor for the base of the catapult until the sensor finds an object within a certain number of centimers (default: 30)
* Stops turning once an object has been found
* Outputs object distance and max distance to the display
* Wiring instructions and reference pics are included in the folder

### For sensor_motor_wo_screen:

* Identical to the code that includes the screen, just with it disabled so there is no need to wire that up
* This makes it easier to wire, but harder to see what is happening and to debug it if there are any problems

# Contact Info
### If you need to contact me for any reason, do so over:
* Discord: @PhillipJK#8190
* Email: phillipjkluge@gmail.com
