#include <IRremote.h>

const int RECV_PIN = 7; // The pin that is connected to the reciever 
IRrecv irrecv(RECV_PIN);
decode_results results;
const int redPin = 10;  // Controls one LED
const int greenPin = 11;// Controls other LED

void setup() {
  irrecv.enableIRIn(); 
  irrecv.blink13(true);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  if(irrecv.decode(&results)) {
    
    switch(results.value) {
      case 0xFF38C7: // This is button 5 on the remote. 
        digitalWrite(redPin, HIGH);   // Turn the LED on
        delay(2000);  // Wait 2 seconds
    }

    switch(results.value) {
      case 0xFF5AA5:  // This is button 6
        digitalWrite(redPin, LOW);    // Turn the LED off
        delay(2000);
    }

    switch(results.value) {
      case 0xFF18E7: // This is button 2 on the remote. 
        digitalWrite(greenPin, HIGH); // Turn the LED on
        delay(2000);  // Wait 2 seconds
    }

    switch(results.value) {
      case 0xFF7A85: // This is button 3 on the remote
        digitalWrite(greenPin, LOW); // Turn the LED off
        delay(2000);      
    }

    irrecv.resume();
  }
}
