# ESP32-WiFi-Load-Cell-Monitor
This is a Load Cell Monitor designed using an ESP32, allowing wireless viewing through a hosted webpage stored on the SD card. Load cell data can also be logged using an SD card. 
<br/>
<br/>
This project is perfect for hobbyists and professionals looking to monitor weight or load changes wirelessly!
<br/>
<br/>
🚧 This page is under construction <br/>
<br/>
Future roadmap: <br/>
•  Improve Error Handling<br/>
•  Load SSID and Password from config.txt<br/>
•  restructure/clean up code<br/>
<h2>⚙️ Features</h2>
•  Display current weight<br/>
•  Tare Scale<br/>
•  Calibrate Scale with user input for weight<br/>
•  Host access point and webpage with custom domain from SD card<br/>
<br/>
<img src="https://github.com/JoshMH-91/ESP32-WiFi-Load-Cell-Monitor/assets/138040193/2d799443-ecbb-4e89-ad3e-3e7dfad93a9a" length="50%" width="50%">
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
•  <b>3v3</b> wire to <b>3v</b> on ESP32<br/>
•  <b>GND</b> wire to <b>ground</b> on ESP32<br/>
•  <b>CS</b> wire to <b>pin 21</b> on ESP32<br/>
•  <b>MOSI</b> wire to <b>pin 23</b> on ESP32<br/>
•  <b>CLK</b> wire to <b>pin 18</b> on ESP32<br/>
•  <b>MISO</b> wire to <b>pin 19</b> on ESP32<br/>
<br/>
<b><u>HX711</u></b><br/>
•  <b>VDD</b> wire to <b>3v</b> on ESP32<br/>
•  <b>VCC</b> wire to <b>3v</b> on ESP32<br/>
•  <b>DAT</b> wire to <b>pin 25</b> on ESP32<br/>
•  <b>CLK</b> wire to <b>pin 26</b> ESP32<br/>
•  <b>GND</b> wire to <b>ground</b> on ESP32<br/>
<br/>
<img src="https://github.com/JoshMH-91/ESP32-WiFi-Load-Cell-Monitor/assets/138040193/f2935c7d-2c23-4556-ae32-02b65b569bdd">
<br/>
2️⃣ Copy files in SD folder to your SD card.
<br/>
<br/>
3️⃣ Open provided .ino file in your Arduino IDE download/install the required libraries and upload the code to the board
<br/>
<br/>
Default Domain:  <code>loadcell.local</code><br/>
Default SSID:  <code>Load_Cell</code><br/>
Default Password:  <code>LoadCell1234</code><br/>
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
<img src="https://github.com/JoshMH-91/ESP32-WiFi-Load-Cell-Monitor/assets/138040193/b09c8023-8616-46d8-8be7-6815376f478c" length="50%" width="50%">
<br/><br/>
<a href="https://www.buymeacoffee.com/JoshMH91" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/default-yellow.png" alt="Buy Me A Coffee" height="50" width="200"></a>




