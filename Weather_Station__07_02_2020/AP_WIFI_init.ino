void WiFi_init(){
  
 WiFi.mode(WIFI_STA);                                           //режим подключения в роутреру
 byte tries = 11;                                               //количество попыток
 WiFi.begin(String(Config.WIFI_SSID), String(Config.WIFI_PASSWORD));  
 while (--tries && WiFi.status() != WL_CONNECTED) 
      {
        delay(1000);
        Serial.print(".");
      }
 if (WiFi.status() != WL_CONNECTED)                              //если нет подключения к роутеру
      {
        Serial.println("");
        Serial.print("ESP strting AP-mode");
        WiFi.disconnect();
        WiFi.mode(WIFI_AP);                                      //поднять точку тоступа
        WiFi.softAP(String(Config.AP_SSID), String(Config.AP_PASSWORD));                           //имя, пароль, канал, видимость, количество одновременных подключений (1..8)
        Serial.println("");
        Serial.println("Run AP-mode");
        Serial.print("AP SSID: ");
        Serial.println(String(Config.AP_SSID));
        Serial.print("AP IP address: ");
        Serial.println(WiFi.softAPIP());
        Serial.println("WiFi MAC: " + String(WiFi.softAPmacAddress()));
        Config.SYNC_CLOCK = false;
        Config.SEND_TL = false; 
        Config.SEND_NM = false;
      }
  else
      {
        Serial.println("");
        Serial.print("Connected to ");
        Serial.println(String(Config.WIFI_SSID));
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
        Serial.println("WiFi MAC: " + String(WiFi.macAddress()));
      }
 }
