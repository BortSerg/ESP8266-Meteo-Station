# ESP8266-Meteo-Station
v14_07_2022.
1. Add auto load default settings in first start meteo station after firmware download.
2. Set DS18B20 outdoor sensor; BME280 room sensor.
3. Fix bug in 7-segment display light.
 
v11_02_2020.
1. Added the ability to update firmware via the web interface of the weather station. 
   You must go to the address http: // {IP Address} / update and specify *.bin firmware file.
2. Now there are 2 firmware in the project. With and without an RTC module. 
   In firmware without an RTC module, time is counted using the ESP8266 itself.


v07_02_2020.
Fix some bugs:
1. Fix display on the indicator of negative temperatures.
2. Fix changes the background color of the main web page at low temperatures.
3. Adding a button to adjust the brightness of the indicators on the main web page.
4. Decrease in manipulations at the first firmware of the device. Now you need to uncomment part of the code, flash, comment out and flash it again.
