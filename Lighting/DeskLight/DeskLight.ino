/* 
 Main LED Part WS2812B - LED
 
 Add Additional Comments Here
 PIN Out 

 WS2812B Strip
  Wires | Electronic | Arduino Nano
 --------------------|--------------
  White |    GND     |      GND
  Green |    Data    |      D2v
  Red   |    5v      |      5v
*/

/* Future Work 
 *------------------------
 * Document Functions []
 */
 
// _____________Libraries_____________
#include "FastLED.h"

//_____________Macros_____________
#define NUM_LEDS 14
#define DATA_PIN 4
#define TWO_HUNDRED_PI 628
#define MIN_BRIGHTNESS 64
#define MAX_BRIGHTNESS 255 
#define TRANSITION_DIM 5
#define BAUDRATE 9600

//_____________Variable Declarations_____________
CRGB leds[NUM_LEDS];        // Array to indicate LEDs in sequence

bool postTest = false;      // For testing the LEDs
bool serialMessages = true; // Serial Monitor
bool starting = true;       // To Prevent Looping

//_____________Setup_____________
void setup() { 
    FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
    if(serialMessages) {
      Serial.begin(BAUDRATE); 
    }
}

//_____________Main_____________
void loop()  {
  Serial.println("Starting Program");
  
  if(postTest == true) {
    colourTest();
    delay(5000);
    postTest = false;
    Serial.println("Exiting to main program");
  }

  if(starting == true) {
    turnOffLEDs();
    delay(2000);
    startUpLEDAnimation();
    dimLEDS();
    starting = false;
  }
}

//_____________LED Control_____________

// Reduces the brights to minimum brightness
void dimLEDS() {
  for(int i = MAX_BRIGHTNESS; i >= MIN_BRIGHTNESS; i--) {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(TRANSITION_DIM);
  }
}

// Turns on the lights sequentially
// @args: none
void startUpLEDAnimation() {
  turnOffLEDs();
  delay(2000);
  for(int ledElement = 0; ledElement < NUM_LEDS; ledElement ++) {
    leds[ledElement].r = 228;
    leds[ledElement].g = 52;
    leds[ledElement].b = 203;
    delay(50);
    FastLED.show();
  }
}

// Turns off all of the leds
// @args: none
void turnOffLEDs() {
    for(int i = 0; i < NUM_LEDS; i++) {
      leds[i].r = 0;
      leds[i].g = 0;
      leds[i].b = 0;
    }
    Serial.println("LEDs Off");
}

// Tests RGB LED components.
// @args: none
void colourTest() {
  
  Serial.println("Colour Test");
  turnOffLEDs();
  delay(100);
  
  // Blue LEDs
  Serial.println("Blue Test");
  for(int colour = 0; colour < 255; colour++ ) {
      for(int i = 0; i < NUM_LEDS; i++) {
        leds[i].b = colour; 
      }
      FastLED.show();
      delay(TRANSITION_DIM);
  }
  turnOffLEDs();
  delay(100);

  // Red LEDs
  Serial.println("Red Test");
  for(int colour = 0; colour < 255; colour++ ) {
      for(int i = 0; i < NUM_LEDS; i++) {
        leds[i].r = colour; 
      }
      FastLED.show();
      delay(TRANSITION_DIM);
      
  }
  turnOffLEDs();
  delay(100);
  
  // Green LEDs
  Serial.println("Green Test");
  for(int colour = 0; colour < 255; colour++ ) {
      for(int i = 0; i < NUM_LEDS; i++) {
        leds[i].g = colour; 
      }
      FastLED.show();
      delay(TRANSITION_DIM);      
  }
  turnOffLEDs();
  delay(100);

  // All LEDs (White)
  Serial.println("White Test");
  for(int colour = 0; colour < 255; colour++ ) {
      for(int i = 0; i < NUM_LEDS; i++) {
        leds[i].r = colour;
        leds[i].g = colour;
        leds[i].b = colour; 
      }
      FastLED.show();
      delay(TRANSITION_DIM);      
  }
  turnOffLEDs();
  delay(100);

  Serial.println("Colour Test Complete");
}
