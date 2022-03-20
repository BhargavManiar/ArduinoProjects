int Relay = 2; 

void setup() {
  Serial.begin(115200);
  pinMode(Relay,OUTPUT);
}

void loop() {
  digitalWrite(Relay, HIGH);
  delay(500);
  digitalWrite(Relay, LOW);
  delay(500);
  
}
