
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
    delay(quantise*len); // 1 Second * len
}

//__ Morse Code Base Syntax

void morseDot() { // Total delay: 2 Seconds
  ledON();
  ledDelay(1); // 1 Second
  ledOFF();
  ledDelay(1); // 1 Second
}

void morseBar() {  // Total delay: 4 Seconds
  ledON();
  ledDelay(2); // 2 Seconds
  ledOFF();
  ledDelay(2); // 2 Seconds
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
  morseBar();
  morseBar();
  morseBar();

  ledOFF();
  delay(20*quantise); //20 Seconds
}
