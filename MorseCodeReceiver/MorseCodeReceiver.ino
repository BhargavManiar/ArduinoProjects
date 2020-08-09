int LDR = A0;
int baudrate = 9600;
int counterOne = 0; // The time the led is on 
int counterTwo = 0; // The time the led is off
bool high = false;

void setup() {
  pinMode(LDR, INPUT);
  Serial.begin(baudrate);  
}

void loop() {
  
  int LDR_out = analogRead(LDR);
  
  if(LDR_out >= 1000) { // Dark 
    counterOne ++;
    Serial.print("LED Off Counter One: ");
    Serial.println(counterOne);
    counterTwo = 0;
    
  } else {            // Light
    counterTwo ++;
    Serial.print("LED On Counter Two: ");
    Serial.println(counterTwo); 
    counterOne = 0;
    
  }
  
  if(counterTwo >= 50) {
    counterTwo = 0;
    Serial.println("Seems that the transmission has finished");
  }
  
  if(counterOne >= 50) {
    counterOne = 0;
    Serial.println("Seems that the transmission has finished");
  }
  delay(100);
}
