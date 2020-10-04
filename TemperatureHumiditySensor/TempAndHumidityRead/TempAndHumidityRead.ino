#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

DHT digitalSensor; // Object
int sensorPin = 5;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  float temperature = digitalSensor.readTemperature;
  float humidity = digitalSensor.readHumidity;
  
  Serial.println("The temperature is: ");
  Serial.print(temperature);

  Serial.println("The humidity is: ");
  Serial.print(humidity);
}
