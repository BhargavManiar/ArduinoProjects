int motor = 3; 

void setup() {
  pinMode(motor,OUTPUT);
}

void loop() {
  digitalWrite(motor, HIGH);  // Start Motor
  delay(10000);               // Wait 10 seconds
  digitalWrite(motor,LOW);    // Stop Motor
  delay(10000);               // Wait 10 seconds
}
