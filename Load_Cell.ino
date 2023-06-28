#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <Arduino.h>
#include <HX711.h>
#include <Wire.h>

const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";

HX711 scale;

uint8_t dataPin  = 19;//for esp32
uint8_t clockPin = 18;//for esp32

AsyncWebServer server(80);

String readWeight(){
  float weight = scale.get_units(10);
  Serial.printlnl(weight);
  return String(weight);
}

void setup() {
  
  Serial.begin(115200);
  scale.begin(dataPin, clockPin);
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
