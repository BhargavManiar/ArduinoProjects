
int ledConnection = 8; // Led power is connected to port 8. 
int quantise = 1000; // 1 Second

void setup() {
  pinMode(ledConnection, OUTPUT);
}


//__ LED CONTROL
void ledON() {
  digitalWrite(ledConnection,HIGH);
}

void ledOFF() {
  digitalWrite(ledConnection,LOW);
}

void ledDelay(int len) {
   if(len == 1){
    delay(quantise);
   } else if(len == 2) {
    delay(quantise*2);
   }
}

//__ Morse Code Base Syntax
void morseDot() {
  ledON();
  ledDelay(1);
  ledOFF();
  transitionDelay();
}

void morseBar() {
  ledON();
  ledDelay(2);
  ledOFF();
  transitionDelay();
}

void transitionDelay() {
  delay(quantise);
}


//__ MORSE LETTERS
void letterA() {
  morseDot();
  morseBar();
}

void letterB() {
  morseBar();
  morseDot();
  morseDot();
  morseDot();
}

void letterC() {
  morseBar();
  morseDot();
  morseBar();
  morseDot();
}

void letterD() {
  morseBar();
  morseDot();
  morseDot();
}

void letterE() {
  morseDot();
}

void letterF() {
  morseDot();
  morseDot();
  morseBar();
  morseDot();
}

void letterG() {
  morseBar();
  morseBar();
  morseDot();
}

void letterH() {
  morseDot();
  morseDot();
  morseDot();
  morseDot();
}

void letterI() {
  morseDot();
  morseDot();
}

void letterJ() {
  morseDot();
  morseBar();
  morseBar();
  morseBar();
}


void loop() {
  letterB();
  letterA();
  letterG();
 
  letterB();
  letterA();
  letterG();

  delay(10*quantise);
}
