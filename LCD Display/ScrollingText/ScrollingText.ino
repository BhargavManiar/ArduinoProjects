#include <LiquidCrystal.h>//Library for LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //LCD pins at which it is attached to the Arudino

void setup()
{
  lcd.begin(16, 2);             //LCD order
  lcd.print("Welcome Bhargav"); //prints on LCD
  lcd.setCursor(0,1);           //Setting the cursor on LCD
  delay(1000);//delay of 1 second
  
}

void loop()
{
  int timeDelay = 100;
  /*
  for(int PositionCount=0;PositionCount<13; PositionCount++)//loop for scrolling the LCD text
  {
    lcd.scrollDisplayLeft();//builtin command to scroll left the text
    delay(timeDelay);// delay of 150 msec
  }
  */
 
  for(int PositionCount=0; PositionCount<29; PositionCount++)
  {
    delay(125);
    lcd.scrollDisplayRight(); //builtin command to scroll right the text
    delay(125);
  }

}
