# ESP32-Load-Cell-Monitor
Load Cell Monitor designed using an ESP32, allowing wireless viewing on your phone through a hosted webpage.  Load cell data can also be logged using an SD card.
<br/><br/>
🚧 This page is under construction<br/>
<h2>📋 Material:</h2>
•  ESP32 Board (I used <a href="https://www.amazon.com/AITRIP-Development-Microcontroller-Integrated-Amplifiers/dp/B0B19KRPRC/ref=sr_1_5?crid=2V78DRIQ2YHNC&keywords=airtip+esp32+usb+c&qid=1687975641&sprefix=airtip+esp32+usb%2Caps%2C130&sr=8-5">ESP-WROOM-32</a>) <br/>
•  Load Cell (I used <a href="https://www.amazon.com/Portable-High-Precision-Pressure-Tension-Weighing/dp/B077YHNNCP/ref=sr_1_10?crid=2D2NQGT8I60AP&keywords=arduino+load+cell+s+beam&qid=1687975736&sprefix=arduino+load+cell+s+beam%2Caps%2C116&sr=8-10">S-Beam Load Cell</a>)<br/>
•  HX711 Board (I used <a href="https://www.amazon.com/SparkFun-Load-Cell-Amplifier-HX711/dp/B079LVMC6X/ref=sr_1_3?crid=2LGIDV7QPOFLD&keywords=hx711&qid=1687975811&sprefix=hx71%2Caps%2C129&sr=8-3">SparkFun HX711 - Load Cell Amplifier</a>)<br/>
•  Mirco SD Card Reader (I used this <a href="https://www.amazon.com/UMLIFE-Interface-Conversion-Compatible-Raspberry/dp/B0989SM146/ref=sr_1_4?crid=17GH67ZH9OQ3M&keywords=arduino+micro+sd+reader&qid=1687975929&sprefix=arduino+micro+sd+reade%2Caps%2C126&sr=8-4">SD Card Reader</a>)<br/>
•  Mirco SD Card<br/>
•  Power Supply <br/>
<br />
<h2>📄 Instructions:</h2>
1️⃣ Wire ESP32
<br/>
<br/>
<b><u>SD Card</u></b><br/>
•  3v3 wire to 3v ESP32<br/>
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

