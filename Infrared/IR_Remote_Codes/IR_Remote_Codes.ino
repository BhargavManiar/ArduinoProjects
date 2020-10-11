#include <IRremote.h>

const int RECEIVER_PIN = 7; 

IRrecv receiver(RECEIVER_PIN); // This is an object for the IRreceiver
decode_results results; // This is a results object

void setup() {
  Serial.begin(9600); // We need this to print information out
  receiver.enableIRIn();
  receiver.blink13(true); // The built in LED will blink when a signal is sent
}

void loop() {

  // Decode the received signal 
  if(receiver.decode(&results)) {
    Serial.println(results.value, HEX); // Print out the value
    receiver.resume();                  // Reset receiver
  }

}
