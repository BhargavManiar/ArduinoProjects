int motor = 9; // Motor connection point
int speedValue = 50; // Max value is 255

void setup() {
  pinMode(motor, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(speedValue >= 0 && speedValue <= 255) {
    analogWrite(motor,speedValue);
  }
}
