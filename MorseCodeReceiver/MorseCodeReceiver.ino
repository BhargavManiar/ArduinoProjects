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
    
  if(currentState == false)
    // Value of changeOfStateCounter when the currentState changes
    if(changeOfStateCounter == 9 || changeOfStateCounter == 10 || changeOfStateCounter == 11 || changeOfStateCounter == 8) {
      Serial.println(".");
    }
    if(changeOfStateCounter == 19 || changeOfStateCounter == 20 || changeOfStateCounter == 21 || changeOfStateCounter == 18){
      Serial.println("-");
    }
    changeOfStateCounter = 0; // Reset the counter
    priorState = currentState; // Make the prior state the current one
  }
  else { // Counter at the same state
    changeOfStateCounter++;
  }
  
  if(changeOfStateCounter > 100) { 
    changeOfStateCounter = 0;
    Serial.println("Seems that the transmission has finished");
  }

  delay(100);
}
