# ESP32-WiFi-Load-Cell-Monitor
Load Cell Monitor designed using an ESP32, allowing wireless viewing through a hosted webpage stored on SD card.  Load cell data can also be logged using an SD card.
<br/><br/>
🚧 This page is under construction<br/>
<h2>📋 Material:</h2>
•  ESP32 Board (I used <a href="https://www.amazon.com/AITRIP-Development-Microcontroller-Integrated-Amplifiers/dp/B0B19KRPRC/ref=sr_1_5?crid=2V78DRIQ2YHNC&keywords=airtip+esp32+usb+c&qid=1687975641&sprefix=airtip+esp32+usb%2Caps%2C130&sr=8-5">ESP-WROOM-32</a>) <br/>
•  Load Cell (I used <a href="https://www.amazon.com/Portable-High-Precision-Pressure-Tension-Weighing/dp/B077YHNNCP/ref=sr_1_10?crid=2D2NQGT8I60AP&keywords=arduino+load+cell+s+beam&qid=1687975736&sprefix=arduino+load+cell+s+beam%2Caps%2C116&sr=8-10">S-Beam Load Cell</a>)<br/>
•  HX711 Board (I used <a href="https://www.amazon.com/SparkFun-Load-Cell-Amplifier-HX711/dp/B079LVMC6X/ref=sr_1_3?crid=2LGIDV7QPOFLD&keywords=hx711&qid=1687975811&sprefix=hx71%2Caps%2C129&sr=8-3">SparkFun HX711 - Load Cell Amplifier</a>)<br/>
•  Mirco SD Card Reader (I used this <a href="https://www.amazon.com/UMLIFE-Interface-Conversion-Compatible-Raspberry/dp/B0989SM146/ref=sr_1_4?crid=17GH67ZH9OQ3M&keywords=arduino+micro+sd+reader&qid=1687975929&sprefix=arduino+micro+sd+reade%2Caps%2C126&sr=8-4">SD Card Reader</a>)<br/>
•  Mirco SD Card<br/>
•  Power Supply (can be used with 🔋 battery for mobile load cell)<br/>
<br />
<h2>📄 Instructions:</h2>
1️⃣ Wire ESP32
<br/>
<br/>
<b><u>SD Card</u></b><br/>
•  <span style="color:red">3v3 wire</span> to 3v ESP32<br/>
•  GND wire to ground on ESP32<br/>
•  CS wire to _ on ESP32<br/>
•  MOSI wire to _ on ESP32<br/>
•  CLK wire to _ on ESP32<br/>
•  MISO wire to _ on ESP32<br/>
<br/>
<b><u>HX711</u></b><br/>
•  <br/>
<br/>

2️⃣ Open provided .ino file in your Arduino IDE download the required libraries and upload the code to the board
<br/>

3️⃣ Copy files in SD folder to your SD card.
<br/>
<br/>
⭐ Icons used in project created by <a href="https://dryicons.com">DryIcons.com</a>
<br/>
<br/>
<h2>📚 Required Libraries</h2>
•  WiFi, <code>#include  &lt;WiFi.h &gt;</code></br>
•  <a href="https://github.com/me-no-dev/AsyncTCP.git">AsyncTCP</a>, <code>#include &lt;AsyncTCP.h &gt;</code></br>
•  <a href="https://github.com/me-no-dev/ESPAsyncWebServer.git">ESPAsyncWebServer</a>, <code>#include &lt;ESPAsyncWebServer.h &gt;</code></br>
•  HX711, <code>#include &lt;HX711.h &gt;</code></br>
•  SPI, <code>#include &lt;SPI.h &gt;</code></br>
•  SD, <code>#include &lt;SD.h &gt;</code></br>
•  ESPmDNS, <code>#include &lt;ESPmDNS.H &gt;</code></br>
<br/>
<h2>📈 Example Data Ouput</h2>
This is an example of a chart created with the raw data recorded on the SD card:
<br/>
<img src="https://github.com/JoshMH-91/ESP32-WiFi-Load-Cell-Monitor/assets/138040193/1fb20cde-3cae-4abf-a05e-feec42eb2ddb)" width="40%" height="40%">





