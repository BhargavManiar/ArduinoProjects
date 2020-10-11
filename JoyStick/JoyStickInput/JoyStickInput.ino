// Pin Connections

const int Switch_Pin = 2; // Digital 2 pin connected to output
const int X_pin = 0;      // Analogue 0 pin connected to X output
const int Y_pin = 1;      // Analogue 1 pin connected to Y output

bool outputType = false;  // Normal = false, CSV = true
void setup() {
  pinMode(Switch_Pin,INPUT);      // Configure Switch pin as input
  digitalWrite(Switch_Pin, HIGH); // Set the Switch pin as high 
  Serial.begin(115200);           // 12 Times the normal baud rate 
  if(outputType) {
    Serial.println("Switch, X Axis, Y Axis");
  }
}

void loop() {
  if(outputType) {
    CSVOutput();
  } else {
    regularOutput();
  }
}
void CSVOutput() {
  Serial.print(digitalRead(Switch_Pin));
  Serial.print(",");
  Serial.print(analogRead(X_pin));
  Serial.print(",");
  Serial.println(analogRead(Y_pin));
  delay(125);
}
void regularOutput() {
  Serial.print("Switch: ");
  Serial.print(digitalRead(Switch_Pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n");
  delay(500);
}
