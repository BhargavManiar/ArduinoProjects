
// Pin configuration
int dot = 1; // For displaying segment "."
int a = 2;   // For displaying segment "a"
int b = 3;   // For displaying segment "b"
int c = 4;   // For displaying segment "c"
int d = 5;   // For displaying segment "d"
int e = 6;   // For displaying segment "e"
int f = 7;   // For displaying segment "f"
int g = 8;   // For displaying segment "g"

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

void loop() {
  

}
