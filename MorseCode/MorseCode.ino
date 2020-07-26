
int  ledConnection = 8; // Led power is connected to port 8. 
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
    delay(quantise*2)
   }
}

//__ Morse Code Base Syntax
void morseDot() {
  ledON();
  ledDelay(1);
  ledOFF();
}

void morseBar() {
  ledON():
  ledDelay(2);
  ledOFF():
}


//__ LETTERS
void letterA() {
  morseDot();
  morseBar();
}

void letterB() {
  
}

void letterC() {
  
}

void letterD() {
  
}

void letterE() {
  
}

void letterF() {
  
}

void letterG() {
  
}

void letterH {
  
}

void letterI {
  
}

void letterJ {
  
}


void loop() {
  letterA();
  delay(10000);
}
