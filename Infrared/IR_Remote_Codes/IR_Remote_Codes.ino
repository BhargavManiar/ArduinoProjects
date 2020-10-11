#include <IRremote.h>

const int RECEIVER_PIN = 2; 

IRrecv receiver(RECEIVER_PIN); // This is an object for the IRreceiver
decode_results results; // This is a results object

void setup() {
  receiver.enableIRIn();
  receiver.blink13(true); // The built in LED will blink when a signal is sent
  Serial.begin(9600); // We need this to print information out
}
