
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

void loop() {
  

}
