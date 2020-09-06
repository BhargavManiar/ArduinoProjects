
int ledConnection = 13; // Led power is connected to port 13. 
int quantise = 1000;    // 1 Second
int baudrate = 9600;

void setup() {
  pinMode(ledConnection, OUTPUT);
  Serial.begin(baudrate);
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

void Dot() { // Total delay: 1 Seconds
  ledON();
  ledDelay(1); // 1 Second
  ledOFF();
}

void Bar() {  // Total delay: 3 Seconds
  ledON();
  ledDelay(3); // 3 Seconds
  ledOFF();
}

void spaceBetweenLetters() { // Total delay: 3 Seconds
  ledDelay(3); // 3 Seconds
}

void spaceBetweenWords() { // Total delay: 7 Seconds
  ledDelay(7); // 7 Seconds
}


//__ MORSE LETTERS
void letterA() {
  Dot();
  Bar();
}

void letterB() {
  Bar();
  Dot();
  Dot();
  Dot();
}

void letterC() {
  Bar();
  Dot();
  Bar();
  Dot();
}

void letterD() {
  Bar();
  Dot();
  Dot();
}

void letterE() {
  Dot();
}

void letterF() {
  Dot();
  Dot();
  Bar();
  Dot();
}

void letterG() {
  Bar();
  Bar();
  Dot();
}

void letterH() {
  Dot();
  Dot();
  Dot();
  Dot();
}

void letterI() {
  Dot();
  Dot();
}

void letterJ() {
  Dot();
  Bar();
  Bar();
  Bar();
}

void letterK(){
  Bar();
  Dot();
  Bar();
}

void letterL(){
  Dot();
  Bar();
  Dot();
  Dot();
}

void letterM(){
  Bar();
  Bar();
}

void letterN(){
  Bar();
  Dot(); 
}

void letterO(){
  Bar();
  Bar();
  Bar();
}

void letterP(){
  Dot();
  Bar();
  Bar();
  Dot();
}

void letterQ(){
  Bar();
  Bar();
  Dot();
  Bar();
}

void letterR(){
  Dot();
  Bar();
  Dot();
}

void letterS(){
  Dot();
  Dot();
  Dot();
}

void letterT(){
  Bar();
}

void letterU(){
  Dot();
  Dot();
  Bar();
}

void letterV(){
  Dot();
  Dot();
  Dot();
  Bar();
}

void letterW(){
  Dot();
  Bar();
  Bar();
}

void letterX(){
  Bar();
  Dot();
  Dot();
  Bar();
}

void letterY(){
  Bar();
  Dot();
  Bar();
  Bar();
}

void letterZ(){
  Bar();
  Bar();
  Dot();
  Dot();
}


//__ MORSE NUMBERS
void one() {
  Dot();
  Bar();
  Bar();
  Bar();
  Bar();
}

void two() {
  Dot();
  Dot();
  Bar();
  Bar();
  Bar();
}

void three() {
  Dot();
  Dot();
  Dot();
  Bar();
  Bar();
}

void four() {
  Dot();
  Dot();
  Dot();
  Dot();
  Bar();
}

void five() {
  Dot();
  Dot();
  Dot();
  Dot();
  Dot();
}

void six() {
  Bar();
  Dot();
  Dot();
  Dot();
  Dot();  
}

void seven() {
  Bar();
  Bar();
  Dot();
  Dot();
  Dot();
}

void eight() {
  Bar();
  Bar();
  Bar();
  Dot();
  Dot();
}

void nine() {
  Bar();
  Bar();
  Bar();
  Bar();
  Dot();
}

void zero() {
  Bar();
  Bar();
  Bar();
  Bar();
  Bar();
}

void loop() {
  ledDelay(10);
  letterB();
  letterH();
  letterA();
  letterR();
  letterG();
  letterA();
  letterV();
  ledDelay(10);
}
