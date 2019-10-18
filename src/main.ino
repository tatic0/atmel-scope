/* Example sketch to control a 28BYJ-48 stepper motor with ULN2003 driver board and Arduino UNO. More info: https://www.makerguides.com */
// https://www.makerguides.com/28byj-48-stepper-motor-arduino-tutorial/
// Include the Arduino Stepper.h library:
#include <Stepper.h>

// Define variables to read from joystick
int analogX = 0;
int analogY = 0;
// Define variables to move steppers
int stpr1 = 0;
int stpr2 = 0;

// Define number of steps per rotation:
const int stepsPerRevolution = 2048;

// Wiring:
// Pin 8 to IN1 on the ULN2003 driver
// Pin 9 to IN2 on the ULN2003 driver
// Pin 10 to IN3 on the ULN2003 driver
// Pin 11 to IN4 on the ULN2003 driver
// Create stepper object called 'myStepper', note the pin order:
Stepper myStepper0 = Stepper(stepsPerRevolution, 6, 8, 7, 9);
Stepper myStepper1 = Stepper(stepsPerRevolution, 2, 4, 3, 5);


void setup() {
      // Set the speed to 5 rpm:
      myStepper0.setSpeed(10);
      myStepper1.setSpeed(10);
      
      // Begin Serial communication at a baud rate of 9600:
      Serial.begin(9600);
      Serial.println("Code: 28BJ48-ULN2003A v0.2");
}


void loop() {
      // Step one revolution in one direction:
      Serial.println("clockwise");
      myStepper0.step(stepsPerRevolution);
      delay(500);
      myStepper1.step(stepsPerRevolution);
      delay(500);
      
      // Step one revolution in the other direction:
      Serial.println("counterclockwise");
      myStepper0.step(-stepsPerRevolution);
      delay(500);
      myStepper1.step(-stepsPerRevolution);
      delay(500);
}
