# ESP8266-Meteo-Station

Personal weather station on ESP8266 v11_02_2020.
1. Added the ability to update firmware via the web interface of the weather station. 
   You must go to the address http: // {IP Address} / update and specify *.bin firmware file
2. Now there are 2 firmware in the project. With and without an RTC module. 
   In firmware without an RTC module, time is counted using the ESP8266 itself.


Personal weather station on ESP8266 v07_02_2020.

Fix some bugs:
1. Fix display on the indicator of negative temperatures
2. Fix changes the background color of the main web page at low temperatures
3. Adding a button to adjust the brightness of the indicators on the main web page
4. Decrease in manipulations at the first firmware of the device. Now you need to uncomment part of the code, flash, comment out and flash it again.
