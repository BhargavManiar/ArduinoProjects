
const int buzzerPin = 2; // Buzzer's positive end is connected to pin 2

void setup() {
  pinMode(buzzerPin, OUTPUT); // Set the buzzer as an output. 
}

void loop() {
  tone(buzzerPin, 1000);  // 1KHz signal to produce a sound
  delay(1000);            // Wait one second
  noTone(buzzerPin);      // Stop the signal
  delay(1000);            // Wait one second
}
