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

  // Move the arm continously from 0 to 180 degree positions.
  
  for(angle = 0; angle <= 180; angle += 1) { // Increment position by 1 degree
    servoMotor.write(angle);
    delay(15);  // Wait a short period of time
  }

  // Move the arm continously from 180 to 0 degree positions.
  
  for(angle = 180; angle >= 0; angle -= 1) { // Increment position by 1 degree
    servoMotor.write(angle);
    delay(15);  // Wait a short period of time
  }

  delay(2000);

  for(angle = 0; angle <=360; angle ++) { // Increment position by 1 degree
    servoMotor.write(angle);
    delay(15);
  }
  
}
