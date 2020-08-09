
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
    delay(quantise); // 1 Second
   } else if(len == 2) {
    delay(quantise*2); // 2 Second
   }
}

//__ Morse Code Base Syntax
void morseDot() {
  ledON();
  ledDelay(1); // 1 Second
  ledOFF();
  transitionDelay(); // 1 Second

  // Total delay: 2 Seconds
}

void morseBar() {
  ledON();
  ledDelay(2); // 2 Seconds
  ledOFF();
  transitionDelay(); // 1 Second

  // Total delay: 3 Seconds
}

void transitionDelay() {
  delay(quantise);
}


//__ MORSE LETTERS
void letterA() {
  morseDot();
  morseBar();

  // 5
}

void letterB() {
  morseBar();
  morseDot();
  morseDot();
  morseDot();

  // 9
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

  // 7
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
  letterB(); // -...
  letterA(); // .-
  letterG(); // --.
  // 21 SECONDS

  //Final string should be -....---.

  delay(20*quantise); //20 Seconds
}
