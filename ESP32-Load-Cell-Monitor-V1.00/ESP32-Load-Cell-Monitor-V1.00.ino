#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <HX711.h>
#include <SPI.h>
#include <SD.h>
#include <ESPmDNS.h>

const char* ssid = "Load_Cell";
const char* password = "LoadCell1234";

// Create an instance of the web server
AsyncWebServer server(80);

HX711 scale;

uint8_t dataPin = 25; // for esp32
uint8_t clockPin = 26; // for esp32

//Default Calibration Factor 100kg load cell
float calibrationFactor = -43188.00;

// SD card pins
const int SD_CS_PIN = 21;

// Declare the file to store weight data
File weightDataFile;
File dataFile;

// Variable to hold the current weight
float currentWeight = 0.0;

// Boolean flag to indicate if we are currently recording data
bool isRecording = false;

void setup() {

  Serial.begin(115200);

  IPAddress local_IP(192, 168, 1, 1);
  IPAddress gateway(192, 168, 1, 1);
  IPAddress subnet(255, 255, 255, 0);
  WiFi.softAPConfig(local_IP, gateway, subnet);
  WiFi.softAP(ssid, password);
  Serial.println("[+] WiFi access point created with SSID " + String(ssid));

    // Set up mDNS responder
  if (!MDNS.begin("loadcell")) {
    Serial.println("[!] Error setting up mDNS responder!");
  }
  Serial.println("[+] mDNS responder started with hostname 'loadcell.local'");

  Serial.println("Load Cell initializing...");
  scale.begin(dataPin, clockPin);
  scale.set_gain(128);
  delay(1000);
  initializeScale();

  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("Failed to initialize SD card!");
  } else {
    Serial.println("SD card initialized.");
  }

  // Serve a webpage at the root URL
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    // Open the file on the SD card
    File htmlFile = SD.open("/index.html");
    // Check if the file was opened successfully
    if (htmlFile) {
      // Read the contents of the file into a string
      String html = htmlFile.readString();
      // Close the file
      htmlFile.close();
      // Send the HTML to the client
      request->send(200, "text/html", html);
    } else {
      // Send an error message to the client
      request->send(404, "text/plain", "File not found");
    }
  });

// Handle the start recording button
server.on("/recordStart", HTTP_POST, [](AsyncWebServerRequest *request){
  Serial.println("Start recording");
  // Open the file on the SD card
  //dataFile = SD.open("/data.txt", FILE_WRITE);
  // Check if the file was opened successfully
    // Start recording by setting the record flag to true
    isRecording = true;
  // Redirect to the root URL
  request->redirect("/");
});

server.on("/recordStop", HTTP_POST, [](AsyncWebServerRequest *request){
  // Set the record flag to false
  isRecording = false;
  // Close the file if it's open
  if (dataFile) {
    dataFile.close();
  }
  // Redirect to the root URL
  request->redirect("/");
});

server.on("/getWeight", HTTP_GET, [](AsyncWebServerRequest *request){
  String response = String(currentWeight);
  request->send(200, "text/plain", response);
});

server.on("/tare", HTTP_POST, [](AsyncWebServerRequest *request){
  scale.tare();
  request->redirect("/");
});

server.on("/calibrate", HTTP_POST, [](AsyncWebServerRequest *request){
    
    // Reset the scale
    Serial.println("recalibrating...");
    scale.set_scale(1);

    if(request->hasParam("weight", true)){
        float calibrateWeight = request->getParam("weight", true)->value().toFloat();
        calibrationFactor = scale.get_units(20) / calibrateWeight;
        scale.set_scale(calibrationFactor);
        Serial.println("New Calibration Factor:");
        Serial.println(calibrationFactor);
        request->redirect("/");
    }
});

server.on("/start.png", HTTP_GET, [](AsyncWebServerRequest *request){
  File imageFile = SD.open("/start.png");
  if (imageFile) {
    request->send(SD, "/start.png", "image/png");
    imageFile.close();
  } else {
    request->send(404, "text/plain", "File not found");
  }
});

server.on("/stop.png", HTTP_GET, [](AsyncWebServerRequest *request){
  File imageFile = SD.open("/stop.png");
  if (imageFile) {
    request->send(SD, "/stop.png", "image/png");
    imageFile.close();
  } else {
    request->send(404, "text/plain", "File not found");
  }
});

  server.begin();
}

void loop() {

  currentWeight = scale.get_units(10);
  Serial.println(currentWeight);
  // Call the writeWeightToFile() function
  writeWeightToFile();

}

void writeWeightToFile() {
  Serial.println("isRecording: " + String(isRecording));
  // Check if recording is in progress
  if (isRecording) {
    // Open the file on the SD card
    File dataFile = SD.open("/data.txt", FILE_APPEND);
    // Check if the file was opened successfully
    if (dataFile) {
      Serial.println("Recording...");
      // Write the current weight to the file
      dataFile.println(String(currentWeight));
      // Close the file
     // dataFile.close();
    }
  }
}

void initializeScale(){
  scale.tare();
  Serial.println("Scale Zeroed");
  delay(1000);
  scale.set_scale(calibrationFactor);
  Serial.println("Scale Calibration Factor set to:  ");
  Serial.println(calibrationFactor);
}
