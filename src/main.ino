/* Example sketch to control a 28BYJ-48 stepper motor with ULN2003 driver board and Arduino UNO. More info: https://www.makerguides.com */
// https://www.makerguides.com/28byj-48-stepper-motor-arduino-tutorial/
// Include the Arduino Stepper.h library:
#include <Stepper.h>

// Define analog pins to read from joystick
int analogX = 0;
int analogY = 1;
// Define variables to move steppers
int stpr1 = 0;
int stpr2 = 0;
// Dependig on the pin connected to the select button,
// define variable to read pin status
int inPin1 = 1;
int inPin0 = 0;
int selval1 = 0;
int selval0 = 0;


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
Stepper myStepper2 = Stepper(stepsPerRevolution, 10, 12, 11, 13);

//declare empty function to make compiler happy.
void zoomin();
void zoomout();

void setup() {
      // Set the speed to 5 rpm:
      myStepper0.setSpeed(10);
      myStepper1.setSpeed(10);
      myStepper2.setSpeed(10);
      // Declare pushbutton as input
      pinMode(inPin1, INPUT);
      pinMode(inPin0, INPUT);
      //pinMode(LED_BUILTIN, OUTPUT);
      // Begin Serial communication at a baud rate of 9600:
      Serial.begin(9600);
      Serial.println("Code: 28BJ48-ULN2003A v0.4");
}


void loop() {
      stpr1 = analogRead(analogX);
      stpr2 = analogRead(analogY);
      if (stpr1 < 200) {
            myStepper0.step(-100);
      } else { 
            myStepper0.step(0);
      } 
      if (stpr1 > 800) {
            myStepper0.step(100);
      } else { 
            myStepper0.step(0);
      } 
      if (stpr2 < 200) {
            myStepper1.step(-100);
      } else { 
            myStepper1.step(0);
      } 
      if (stpr2 > 800) {
            myStepper1.step(100);
      } else { 
            myStepper1.step(0);
      }
      selval1 = digitalRead(inPin1); 
      selval0 = digitalRead(inPin0); 
      if (selval1 == HIGH) {
            Serial.println("zoom stop");
      } else {
            Serial.println("zoom in");
            zoomin();
      }
      if (selval0 == HIGH) {
            Serial.println("zoom stop");
      } else {
            Serial.println("zoom out");
            zoomout();
      }
      delay(50);
}


void zoomin(){
      myStepper2.step(50);
}

void zoomout(){
      myStepper2.step(-50);
}
