#include <Stepper.h> // Library is required for the motor. 

const int stepsPerRevolution = 2048; // Number of steps per revolution

// Pins 8,9,10,11 (Left to right from the perspective of the IC)
const int pin1 = 8;
const int pin2 = 9;
const int pin3 = 10;
const int pin4 = 11; 

// Make an instance of the stepper class
Stepper myStepper = Stepper(stepsPerRevolution,pin1,pin3,pin2,pin4);

void setup() {
  myStepper.setSpeed(15);
  Serial.begin(9600);
}

// Main Program
void loop() {
  Serial.println("Rotating Clockwise");
  myStepper.step(stepsPerRevolution);
  delay(1000);
  
  Serial.println("Rotating Anticlockwise");
  myStepper.step(-stepsPerRevolution);
  delay(1000);
  
}
