#include <dht.h>


dht digitalSensor; // Object
int sensorPin = 5;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  float temperature = digitalSensor.temperature;
  float humidity = digitalSensor.humidity;
  
  Serial.print("The temperature is: ");
  Serial.println(temperature);

  Serial.print("The humidity is: ");
  Serial.println(humidity);
  delay(2000);
}
