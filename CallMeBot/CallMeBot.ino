#include <WiFi.h>    
#include <HTTPClient.h>
#include <UrlEncode.h>

//const char* ssid = "VM6641029";
//const char* password = "Fp3vbqmcswmf";

const char* ssid = "EE-Hub-r6Nu";
const char* password = "SCONE-jog-ever";

String phoneNumber = "+447887385356";
String apiKey = "7828616";

void sendMessage(String message) {
  // Data to send with HTTP POST
  String url = "https://api.callmebot.com/whatsapp.php?phone=" + phoneNumber + "&apikey=" + apiKey + "&text=" + urlEncode(message);    
  HTTPClient http;
  http.begin(url);

  http.addHeader("Content-Type", "application/x-www-form-urlencoded"); // Specify content-type header
  
  // Send HTTP POST request
  int httpResponseCode = http.POST(url);
  if (httpResponseCode == 200) {
    Serial.print("Message sent successfully");
  }
  else {
    Serial.println("Error sending the message");
    Serial.print("HTTP response code: ");
    Serial.println(httpResponseCode);
  }

  http.end(); // Free resources
}

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  sendMessage("Hello from ESP32!");   // Send Message to WhatsAPP
}

void loop() { 
}
