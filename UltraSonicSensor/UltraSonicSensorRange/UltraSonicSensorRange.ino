
// Pins
const int triggerPin = 10;
const int echoPin = 9;

// Variables
float duration, distance; 

void setup() {
  pinMode(triggerPin, OUTPUT);  // To send the pulses
  pinMode(echoPin, INPUT);      // To recieve the pulses
  Serial.begin(9600);
}


// Main loop
void loop () {
  
  digitalWrite(triggerPin, LOW); // TX OFF
  delayMicroseconds(2);          // Wait two miliseconds
  digitalWrite(triggerPin, HIGH);// TX ON
  delayMicroseconds(10);         // Wait ten miliseconds
  digitalWrite(triggerPin, LOW); // TX OFF

  duration = pulseIn(echoPin, HIGH);  // Duration in milliseconds
  // distance = (speed) * (duration * 10^-3)
  // using distance = speed * time
  distance = (duration * 0.034) / 2;
  
  Serial.print("Distance: ");
  Serial.println(distance);
  
  delay(100);
}
