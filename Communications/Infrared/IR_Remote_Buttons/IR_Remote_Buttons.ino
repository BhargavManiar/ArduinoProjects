#include <IRremote.h>

const int RECV_PIN = 7; // The pin that is connected to the reciever 
IRrecv irrecv(RECV_PIN);
decode_results results;

unsigned long keyValue = 0;

void setup() {
  irrecv.enableIRIn();
  irrecv.blink13(true);
  Serial.begin(9600);
}

void loop() {
  if(irrecv.decode(&results)) {

    if(results.value == 0xFFFFFFFF) {
      results.value = keyValue;
    }

    switch(results.value) {
      case 0xFFA25D:
        Serial.println("Power On/Off");
        break;
      case 0xFF629D:
        Serial.println("Volume +");
        break;
      case 0xFFE21D:
        Serial.println("Func/ Stop");
        break;
      case 0xFF22DD:
        Serial.println("Rewind");
        break;
      case 0xFF02FD:
        Serial.println("Play/Pause");
        break;
      case 0xFFC23D:
        Serial.println("Fast Forward");
        break;
      case 0xFFE01F:
        Serial.println("Down");
        break;
      case 0xFFA857:
        Serial.println("Volume -");
        break;
      case 0xFF906F:
        Serial.println("Up");
        break;
      case 0xFF6897:
        Serial.println("0");
        break;
      case 0xFF9867:
        Serial.println("EQ");
        break;
      case 0xFFB04F:
        Serial.println("ST/Recpt");
        break;
      case 0xFF30CF:
        Serial.println("1");
        break;
      case 0xFF18E7:
        Serial.println("2");
        break;
      case 0xFF7A85:
        Serial.println("3");
        break;
      case 0xFF10EF:
        Serial.println("4");
        break;
      case 0xFF38C7:
        Serial.println("5");
        break;
      case 0xFF5AA5:
        Serial.println("6");
        break;
      case 0xFF42BD:
        Serial.println("7");
        break;
      case 0xFF4AB5:
        Serial.println("8");
        break;
      case 0xFF52AD:
        Serial.println("9");
        break;
    }
    
    keyValue = results.value;
    irrecv.resume();
  }
}
