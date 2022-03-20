#include <Servo.h>

Servo servoMotor; 
int servoPin = 5; // Pin connected to the servo motor
int velocity = 0;   // Includes direction and speed

void setup() {
  servoMotor.attach(servoPin);
  Serial.begin(9600);
}

void loop() {

  servoMotor.write(85); // 0 to 89 Full speed to slow speed one direction
  
  delay(2000);
  Serial.println("Waiting");
  
  servoMotor.write(90); // Stop

  delay(2000);
  Serial.println("Waiting");

  servoMotor.write(100); // 91 to 180 slow to full speed in the other direction.

  delay(2000);
  Serial.println("Waiting");

}
