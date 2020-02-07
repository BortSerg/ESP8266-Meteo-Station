void SendToNM(){
  if (WiFi.status() == WL_CONNECTED)
  {
    
      DS18B20.requestTemperatures();              // Команда на замер температуры.
      //long rssi = WiFi.RSSI();                    // переменная уровня сигнала WI-FI
      //float vdd33 = ESP.getVcc() / 1000.0 ;       // напряжение питания
      //vdd33 = vdd33 + 0.3;
      delay(1000);                                // Задержка для того чтобы датчик успел провести замер.
      
      DeviceAddress tempDeviceAddress;            // Переменная для получения адреса датчика
      String buf;                                 // Буфер для отправки на NarodMon
      buf = "#" + WiFi.macAddress() + "\r\n";
      buf.replace(":", "");                       //формируем заголовок удаляет ":" в данных, например в МАС адресе

      DS18B20.getAddress(tempDeviceAddress, 0);   // Получаем уникальный адрес датчика
      buf = buf + "#";
      for (uint8_t i = 0; i < 8; i++)
      {
        if (tempDeviceAddress[i] < 16) buf = buf + "0";  // адрес датчика в буфер
        buf = buf + String(tempDeviceAddress[i], HEX);
      }
      
      String TempIn = String(getTemperature());
      String TempOut = String(getTemperatureBME280());
      String Press = String(getPressureBME280()*0.0075006157584566);
      String Humi = String(getHumidityBME280());
       
      buf = buf + "#" + TempIn + "\r\n";        //температура DS18B20
      buf = buf + "#BME280T";
      buf = buf + "#" + TempOut + "\r\n";       //температура BME280
      buf = buf + "#BME280P";
      buf = buf + "#" + Press + "\r\n";         //давление BME280
      buf = buf + "#BME280H";
      buf = buf + "#" + Humi + "\r\n";          //влажность BME280

      /*DS18B20.getAddress(tempDeviceAddress, 1); // Получаем уникальный адрес датчика
        buf = buf + "#";
        for (uint8_t i = 0; i < 8; i++)
        {
        if (tempDeviceAddress[i] < 16) buf = buf + "0";  // адрес датчика 2 в буфер
        buf = buf + String(tempDeviceAddress[i], HEX);
        }
        buf = buf + "#" + String(getTemperature()) + "\r\n";              //температура DS18B20 2
      */
      buf = buf + "##\r\n"; // закрываем пакет

      //WiFiClient client;
      client.connect("narodmon.ru", 8283);                            //Подключаемся
      client.print(buf);                                              // И отправляем данные
      Serial.println("============");
      Serial.println("Data sendet to NarodMon");
      Serial.println(buf);                                            //Что отправили на narodmon.ru вывети в консоль
      Serial.println("============\n");
     
      /*
      Serial.println("DS18B20_T1: " + String(getTemperature()) + " °C");
      Serial.println("BME280_T: " + String(getTemperatureBME280()) + " °C");
      Serial.println("BME280_P: " + String(getPressureBME280() * 0.0075006157584566) + " mmHg");
      Serial.println("BME280_H: " + String(getHumidityBME280()) + " %");
      */
   }
  
}
