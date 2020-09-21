#include <Stepper.h> // Library is required for the motor. 

const int stepsPerRevolution = 2038; // Number of steps per revolution

// Pins 8,9,10,11 (Left to right from the perspective of the IC)
const int pin1 = 8;
const int pin2 = 9;
const int pin3 = 10;
const int pin4 = 11; 

// Make an instance of the stepper class
Stepper myStepper = Stepper(stepsPerRevolution,pin1,pin2,pin3,pin4);

// Main Program
void loop() {
  myStepper.setSpeed(100);
  myStepper.step(stepPerRevolution);
  delay(1000); // Wait one second

  myStepper.setSpeed(700);
  myStepper.step(-stepPerRevolution);
  delay(1000);
  
}
