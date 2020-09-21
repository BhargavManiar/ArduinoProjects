
// Pins
const int triggerPin = 9;
const int echoPin = 10;

// Variables
float duration, distance; 

void setup() {
  pinMode(triggerPin, OUTPUT);  // To send the pulses
  pinMode(echoPin, INPUT);      // To recieve the pulses
  Serial.begin(9600);
}


// Main loop
void loop () {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*0.0343)/2; 
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
}
