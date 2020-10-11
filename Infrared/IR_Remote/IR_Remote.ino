#include <IRremote.h>

const int RECV_PIN = 7; // The pin that is connected to the reciever 
IRrecv irrecv(RECV_PIN):
decode_results results;
const int redPin = 10;  // Controls one LED
const int greenPin = 11;// Controls other LED

void setup() {
  irrecv.enableIRIN(); 
  irrecv.blink13(true);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  
}
