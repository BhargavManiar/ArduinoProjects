int LDRval = A0;
int led = 12;
bool debug = 1;


void setup() {
  // put your setup code here, to run once:
  
  pinMode(A0, INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  int ldr = analogRead(LDRval);
  
  if(debug) // if debug is set to 1 the values of resistnance of the ldr will show
  {
    Serial.print(ldr); // Print out the resistance value. 
    Serial.print("\n"); // Print out a new line
  } 

  if(ldr > 1000) // If the room is darkl
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
  delay(500);
  
}
  
