#include <LiquidCrystal.h>

/* initialise the library by associating any needed LCD interface pin
with the arduino pin number it is connected to */
 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);           // set up the LCD's number of columns and rows:
  lcd.print("Hello, World!"); // Print a message to the LCD.
}

void loop() {
  lcd.noDisplay();  // Turn off the display:
  delay(500);
  lcd.display();    // Turn on the display:
  delay(500);
}
