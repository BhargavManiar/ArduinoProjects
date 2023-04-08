#include <SPI.h>              //Library for using SPI Communication 
#include <mcp2515.h>          //Library for using CAN Communication
#include <LiquidCrystal.h>    //Library for using LCD display
const int rs = 3, en = 4, d4 = 5, d5 = 6, d6 = 7, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  //Define LCD display pins RS,E,D4,D5,D6,D7
struct can_frame canMsg;
MCP2515 mcp2515(10);                 // SPI CS Pin 10

void setup() {
  lcd.begin(16, 2);                  //Sets LCD as 16x2 type
  lcd.setCursor(0, 0);               //Display Welcome Message
  lcd.print("CIRCUIT DIGEST");
  lcd.setCursor(0, 1);
  lcd.print("CAN ARDUINO");
  delay(3000);
  lcd.clear();
  SPI.begin();                       //Begins SPI communication
  Serial.begin(9600);                //Begins Serial Communication at 9600 baudrate

  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ); //Sets CAN at speed 500KBPS and Clock 8MHz
  mcp2515.setNormalMode();                  //Sets CAN at normal mode
}

void loop()
{
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) // To receive data (Poll Read)
  {
    int temperature = canMsg.data[0];
    int pitch = canMsg.data[1];
    int roll = canMsg.data[2];
    int X = canMsg.data[3];
    int Y = canMsg.data[4];
    int Z = canMsg.data[5];

    Serial.println();
    Serial.print("Temperature: ");  Serial.println(temperature);
    Serial.print("Pitch: ");        Serial.println(pitch);
    Serial.print("Roll: ");         Serial.println(roll);
    Serial.print("Gyro X: ");       Serial.println(X);
    Serial.print("Gyro Y: ");       Serial.println(Y);
    Serial.print("Gyro Z: ");       Serial.println(Z);

    delay(5000);
  }
}
