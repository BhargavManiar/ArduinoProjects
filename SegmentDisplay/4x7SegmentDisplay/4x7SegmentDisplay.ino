
// Pin configuration
const int a = 2;    // For displaying segment "a"
const int b = 3;    // For displaying segment "b"
const int c = 4;    // For displaying segment "c"
const int d = 5;    // For displaying segment "d"
const int e = 6;    // For displaying segment "e"
const int f = 7;    // For displaying segment "f"
const int g = 8;    // For displaying segment "g"

const int dot = 9;  // For displaying segment "."

const int digitOne = 10;     // For displaying digit 1
const int digitTwo = 11;     // For displaying digit 2
const int digitThree = 12;  // For displaying digit 3
const int digitFour = 13;   // For displaying digit 4

boolean test = true;  // Test leds
boolean dotLedStatus = true;   // Dot led

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
  
  pinMode(digitOne,OUTPUT);   // 1
  pinMode(digitTwo,OUTPUT);   // 2
  pinMode(digitThree,OUTPUT); // 3
  pinMode(digitFour,OUTPUT);  // 4
  
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
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      break;
    case 1:
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      break;
    case 2:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(g, HIGH); 
      digitalWrite(e, HIGH);
      digitalWrite(d, HIGH); 
      break;
    case 3:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH); 
      digitalWrite(g, HIGH); 
      digitalWrite(c, HIGH); 
      digitalWrite(d, HIGH);
      break;
    case 4:
      digitalWrite(f, HIGH); 
      digitalWrite(g, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      break;
    case 5:
      digitalWrite(a, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      break;
    case 6:
      digitalWrite(a, HIGH); 
      digitalWrite(f, HIGH); 
      digitalWrite(g, HIGH); 
      digitalWrite(e, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      break;
    case 7:
      digitalWrite(a, HIGH); 
      digitalWrite(b, HIGH); 
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

void displayDigit(int number) {
  
  digitalWrite(digitOne,  HIGH);
  digitalWrite(digitTwo,  HIGH);
  digitalWrite(digitThree,HIGH);
  digitalWrite(digitFour, HIGH);
  switch(number) {
    case 1:
      digitalWrite(digitOne,  LOW);

    case 2:

      digitalWrite(digitTwo,  LOW);

    case 3:

      digitalWrite(digitThree,LOW);

    case 4:

      digitalWrite(digitFour, LOW);
      
    default: {
      break; 
    }
  }
}

// Activates LED to display dot in addition to any other LEDs active
void displayOutputDot(boolean state) {
  if (state == true) {
    digitalWrite(dot,HIGH); 
    Serial.println("Dot on");
  } else if (state == false) {
    digitalWrite(dot,LOW);
    Serial.println("Dot off");
  }
  
}

// Turns all the leds on then off.
boolean startUpTest(boolean yes) {
  if(yes == true) {
    displayOutputNumber(1);
    displayOutputNumber(2);
    displayOutputNumber(3);
    displayOutputNumber(4);
    turnOn();
    delay(1000);
    turnOff();
    return false;
  }
}

// Main Loop
void loop() {
    int x = 500;
    displayDigit(1);
    displayOutputNumber(1);

    delay(100);
    
}
