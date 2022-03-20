// LED Colours
const int red = 10;
const int yellow = 12;
const int green = 11;

// Delay for transitions between lights
const int waitTime = 5000; 

// For reducing electronic issues
bool setupComplete = false;

void setup() {
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  Serial.print("\nSetup Complete");
}

void trafficLightAlgorithm() {
  digitalWrite(red, HIGH);
  delay(waitTime);
  digitalWrite(red, LOW);
  
  digitalWrite(yellow, HIGH);
  delay(waitTime);
  digitalWrite(yellow, LOW);

  digitalWrite(green, HIGH);
  delay(waitTime);
  digitalWrite(green, LOW);

  digitalWrite(yellow, HIGH);
  delay(waitTime);
  digitalWrite(yellow, LOW);
}

void setupLights() {
  digitalWrite(red,LOW);
  digitalWrite(yellow,LOW);
  digitalWrite(green,LOW);
  setupComplete = true;
  Serial.println("LED's Set to Low");
}

void loop() {
  
  if(setupComplete == true) {
    trafficLightAlgorithm();
  } else {
    setupLights();
  }
}
