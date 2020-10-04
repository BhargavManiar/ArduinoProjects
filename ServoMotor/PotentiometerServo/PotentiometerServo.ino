#include <Servo.h>

Servo servoMotor; // Servo motor object
int servoPin = 5; // Servo motor pin 

int potentiometerPin = A0; // Potetiometer pin 
int potentiometerValue = 0; // Resistance value

int angle = 0; // The position of the servo arm


void setup() {
  servoMotor.attach(servoPin);
}

void loop() {
  potentiometerValue = analogRead(potentiometerPin); // Read the analogue pin
  angle = map(potentiometerValue, 0, 1023, 0, 180); // map input to numbers between 0 and 180

  servoMotor.write(angle); // Write the servo based on the mapped value
}
