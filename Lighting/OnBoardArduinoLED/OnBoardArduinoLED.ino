void setup() {
  // Setup the led built into the Arduino board
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN,HIGH); // Turn on the LED
  delay(1000);                    // Wait 1 second
  digitalWrite(LED_BUILTIN,LOW);  // Turn off the LED
  delay(1000);                    // Wait 1 second
}
