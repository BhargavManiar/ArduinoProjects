#include <dht.h>

dht digitalSensor; // Object
int sensorPin = 5;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int chk = digitalSensor.read11(sensorPin);
  
  int temperature = digitalSensor.temperature;
  int humidity = digitalSensor.humidity;

  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");

  Serial.print("Humidity is: ");
  Serial.print(humidity);
  Serial.println("%");

  Serial.println("_______________");
  Serial.println("");
  
  delay(10000);
}
