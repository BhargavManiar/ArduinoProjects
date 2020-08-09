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
  
  if(LDR_out >= 1000) {
    high = true; 
    Serial.println("High");
    
  } else {
    high = false;; 
    Serial.println("Low");
  }

  if(high == true) {
    counterOne ++;
    Serial.println(counterOne);
    counterTwo = 0; 
  } else {
    counterTwo ++;
    Serial.println(counterTwo); 
    counterOne = 0;
  }

  if(counterTwo == 1000) {
    counterTwo = 0;
  }
  
  if(counterOne == 1000) {
    counterOne = 0;
  }
}
