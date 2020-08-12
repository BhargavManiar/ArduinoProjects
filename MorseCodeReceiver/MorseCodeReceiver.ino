int LDR = A0;
int baudrate = 9600;
int counterOne = 0; // The time the led is on 
int counterTwo = 0; // The time the led is off
int changeOfStateCounter = 0; // Hold the count of the change

bool currentState;
bool priorState;
bool restartLoop; 


void setup() {
  pinMode(LDR, INPUT);
  Serial.begin(baudrate);  
}

void loop() {
  
  int LDR_out = analogRead(LDR);
  
  if(LDR_out >= 1000) { // Dark 
    currentState = false;
    counterOne ++;
    counterTwo = 0; 
  } else {            // Light
    currentState = true;
    counterTwo ++;
    counterOne = 0;
  }

  if(currentState != priorState) {
    priorState = currentState;

    if(changeOfStateCounter == 9){
      Serial.print(".");
    }
    if(changeOfStateCounter == 19){
      Serial.print("-");
    }
    changeOfStateCounter = 0; // Reset the counter
  }
  else { // Counter at the same state
    changeOfStateCounter++;
  }
  
  if(changeOfStateCounter > 200) { 
    changeOfStateCounter = 0;
    Serial.println("Seems that the transmission has finished");
  }

  delay(100);
}
