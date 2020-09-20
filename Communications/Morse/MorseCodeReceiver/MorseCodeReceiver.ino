int LDR = A0;
int baudrate = 9600;
int changeOfStateCounter = 0; // Hold the count of the change

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
  } else {            // Light
    currentState = true;
  }

 if(currentState != priorState) {
    
    if(currentState == false){
      // Value of changeOfStateCounter when the currentState changes
  
      // Dot - 1 Second On Time
      if(changeOfStateCounter >= 8 && changeOfStateCounter <= 10) {
        Serial.println(".");
      }
      
      // Bar - 3 Seconds On Time
      if(changeOfStateCounter >= 11 && changeOfStateCounter <= 20){
        Serial.println("-");
      }
  
      // Word Space - 7 Seconds On Time
      if(changeOfStateCounter >= 21 && changeOfStateCounter <= 42){
        Serial.print(" "); // Space
      }
      
      changeOfStateCounter = 0; // Reset the counter
      priorState = currentState; // Make the prior state the current one
      
    } else { // Counter at the same state
      changeOfStateCounter++;
    }
 }
  
  if(changeOfStateCounter > 100) { 
    changeOfStateCounter = 0;
    Serial.println("Seems that the transmission has finished");
  }

  delay(100);
}
