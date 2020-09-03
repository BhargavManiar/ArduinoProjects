
// Pin configuration
int dot = 1; // For displaying segment "."
int a = 2;   // For displaying segment "a"
int b = 3;   // For displaying segment "b"
int c = 4;   // For displaying segment "c"
int d = 5;   // For displaying segment "d"
int e = 6;   // For displaying segment "e"
int f = 7;   // For displaying segment "f"
int g = 8;   // For displaying segment "g"

// Sets up all of the pins as output
void setup() {
  pinMode(a,OUTPUT);  // A
  pinMode(b,OUTPUT);  // B
  pinMode(c,OUTPUT);  // C
  pinMode(d,OUTPUT);  // D
  pinMode(e,OUTPUT);  // E
  pinMode(f,OUTPUT);  // F
  pinMode(g,OUTPUT);  // G
  pinMode(dot,OUTPUT);// Dot
  
  Serial.begin(9600);
}

// Turns off all LEDs
void turnOff() {
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  digitalWrite(dot,LOW);
}

// Turns on all LEDs
void turnOn() {
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(dot,HIGH);
}

// Activates LEDs to display number
void displayOutputNumber(int number) {
  turnOff(); // Turn all of the LEDs to a netural state
  switch(number) {
    case 0:
      digitalWrite(a, HIGH); 
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    case 1:
      digitalWrite(a, HIGH);
      digitalWrite(e, HIGH);
      break;
    case 2:
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(b, HIGH); 
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH); 
      break;
    case 3:
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH); 
      digitalWrite(b, HIGH); 
      digitalWrite(c, HIGH); 
      digitalWrite(d, HIGH);
      break;
    case 4:
      digitalWrite(a, HIGH); 
      digitalWrite(b, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(c, HIGH);
      break;
    case 5:
      digitalWrite(f, HIGH);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      break;
    case 6:
      digitalWrite(a, HIGH); 
      digitalWrite(b, HIGH); 
      digitalWrite(c, HIGH); 
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      break;
    case 7:
      digitalWrite(f, HIGH); 
      digitalWrite(g, HIGH); 
      digitalWrite(c, HIGH);
      break;
    case 8:
      digitalWrite(a, HIGH); 
      digitalWrite(b, HIGH); 
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    case 9:
      digitalWrite(a, HIGH); 
      digitalWrite(b, HIGH); 
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
      
    default: {
      break; 
    }
  }
  
}

// Activates LED to display dot in addition to any other LEDs active
void displayOutputDot() {
  digitalWrite(dot,HIGH);
}

// Tests all of the LEDs
void testLeds() {
  turnOn();
  delay(100);
  turnOff();
  delay(100);
}

// Iterates through numbers 0 to 9
void incrementNumbers() {
  for(int i = 0; i < 10; i++) {
    displayOutputNumber(i);
    delay(100); // Delay for persistance of vision reasons.
  }
}

// Main Loop
void loop() {
  testLeds();
  Serial.println("Test Complete");
  incrementNumbers();
  Serial.println("Increment Numbers Comlpete");
}
