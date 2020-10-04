#include <Servo.h> // Library for controlling the servo motor

Servo servoMotor; // Servo motor object
int servoPin = 5; // The pin the servo was connected to
int angle = 0;    // This is the angle from the start point

void setup() {
  servoMotor.attach(servoPin); // We can write to this pin.  
}
