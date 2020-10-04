#include <Servo.h> // Library for controlling the servo motor

Servo servoMotor; // Servo motor object
int servoPin = 5; // The pin the servo was connected to
int angle = 0;    // This is the angle from the start point

void setup() {
  servoMotor.attach(servoPin); // We can write to this pin.  
}

void loop() {
  servoMotor.write(0);    // Move the arm to the 0 degree position
  delay(1000);            // Wait one second
  
  servoMotor.write(90);   // Move the arm to the 90 degree position
  delay(1000);            // Wait one second

  servoMotor.write(180);  // Move the arm to the 180 degree position
  delay(2000);            // Wait two seconds

  
  
  
}
