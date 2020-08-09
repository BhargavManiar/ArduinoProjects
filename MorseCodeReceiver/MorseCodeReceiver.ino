int LDR = A0;
int baudrate = 9600;
int counterOne = 0; // The time the led is on 
int counterTwo = 0; // The time the led is off

bool currentState;
bool priorState;


void setup() {
  pinMode(LDR, INPUT);
  Serial.begin(baudrate);  
}

void loop() {
  
  int LDR_out = analogRead(LDR);
  
  if(LDR_out >= 1000) { // Dark 
    currentState = false;
    
    counterOne ++;
    Serial.print("LED Off Counter One: ");
    Serial.println(counterOne);
    counterTwo = 0;
    
  } else {            // Light
    currentState = true;
    
    counterTwo ++;
    Serial.print("LED On Counter Two: ");
    Serial.println(counterTwo); 
    counterOne = 0;
  }

  if(currentState != priorState)
  {
    Serial.println("Change");
    priorState = currentState;
    // Add print of counter two here 
  }
  
  if(counterTwo >= 50 || counterOne >= 50) {
    counterTwo = 0;
    counterOne = 0;
    Serial.println("Seems that the transmission has finished");
  }
  
  delay(100);
}
