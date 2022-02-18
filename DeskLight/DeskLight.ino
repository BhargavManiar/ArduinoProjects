/* 
 Main LED Part WS2812B - LED
 
 Add Additional Comments Here
 PIN Out 

 WWS2812B Strip
  Wires | Electronic | Arduino Nano
 --------------------|--------------
  White |    GND     |      GND
  Green |    Data    |      D2
  Red   |    5v      |      5v
 
*/

/* Future Work 
 *------------------------
 * Lower CLK Speed    []
 * Document Functions []
 */
// _____________Libraries_____________
#include "FastLED.h"
#include <avr/sleep.h>

//_____________Macros_____________
#define NUM_LEDS 14
#define DATA_PIN 2
#define TWO_HUNDRED_PI 628
#define MIN_BRIGHTNESS 128
#define MAX_BRIGHTNESS 255 
#define TRANSITION_DIM 2

//_____________Variable Declarations_____________
CRGB leds[NUM_LEDS];              // Array to indicate LEDs in sequence

int element = 0;                  // An element is an led defined by a sequential number
int last_element = 0;             // The very last element initialised in the method

bool postTest = false;            // For testing the LEDs
bool enableSerialMessages = false;// Serial Monitor

//_____________Setup_____________
void setup()
{ 
    FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS); //delay for LED before turning on.
    if(enableSerialMessages) {
      Serial.begin(9600);  // Sets up the serial baud = 9600  
    }
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
}

//_____________Main_____________
void loop() 
{
  if(postTest == true)
  {
    colourTest();
    postTest = false;
    delay(1000);
    Serial.println("Exiting to main program");
  }
  startUpLEDAnimation();
  dimLEDS();
  sleep_mode();
}

//_____________LED Control_____________

// Reduces the brights to minimum brightness
void dimLEDS() 
{
  for(int i = MAX_BRIGHTNESS; i >= MIN_BRIGHTNESS; i--)
  {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(TRANSITION_DIM);
  }
}

// Turns on the lights sequentially
// @args: none
void startUpLEDAnimation() 
{
      for(int i=0; i<TWO_HUNDRED_PI; i++)
      {
        element = round((NUM_LEDS-1)/2*(sin(i/100.0)+1));
        FastLED.show();
        if(element < last_element)
        {
            leds[element].r = i;
            leds[element].b = i;
            
            delay(10); // Start Up Delay
            FastLED.show();
        }
        last_element = element;
      }
}

// Turns off all of the leds
// @args: none
void turnOffLEDs() {
    Serial.println("Switching Off LEDs");
    for(int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CRGB::Black; // Turns off LEDs
    }
    Serial.println("LEDs Off");
}

// Tests RGB LED components.
// @args: none
void colourTest()
{
  
  Serial.println("Colour Test");
  turnOffLEDs();
  delay(100);
  
  // Blue LEDs
  for(int colour = 0; colour < 255; colour++ )
  {
      for(int i = 0; i < NUM_LEDS; i++)
      {
        leds[i].b = colour; 
      }
      FastLED.show();
      delay(TRANSITION_DIM);
  }
  turnOffLEDs();
  delay(100);

  // Red LEDs
  for(int colour = 0; colour < 255; colour++ )
  {
      for(int i = 0; i < NUM_LEDS; i++)
      {
        leds[i].r = colour; 
      }
      FastLED.show();
      delay(TRANSITION_DIM);
      
  }
  turnOffLEDs();
  delay(100);
  
  // Green LEDs
  for(int colour = 0; colour < 255; colour++ )
  {
      for(int i = 0; i < NUM_LEDS; i++)
      {
        leds[i].g = colour; 
      }
      FastLED.show();
      delay(TRANSITION_DIM);      
  }
  turnOffLEDs();
  delay(100);

  // Green LEDs
  for(int colour = 0; colour < 255; colour++ )
  {
      for(int i = 0; i < NUM_LEDS; i++)
      {
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