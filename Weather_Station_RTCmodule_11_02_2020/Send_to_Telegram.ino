/*void SendToTelegram()
{
   httpsClient.setFingerprint(fingerprint);
  httpsClient.setTimeout(15000);
  String TempIn = String(getTemperature());
  String TempOut = String(getTemperatureBME280());
  String Press = String(getPressureBME280()*0.0075006157584566);
  String Humi = String(getHumidityBME280());
      
 msg = "*Температура помещения:* " + TempIn + "*°C*%0A*Температура на улице:* " + TempOut + "*°C*%0A*Атмосферное давление:* " + Press + "*mmHg*%0A*Влажность воздуха:* " + Humi + "*%*";
 String Link = "/bot" + String(Config.TOKEN) +"/sendMessage?chat_id=" + String(Config.CHAT_ID) + "&parse_mode=Markdown&text=" + msg;
   Serial.print("HTTPS Connecting");
  int r=0; //retry counter
  while((!httpsClient.connect(host, httpsPort)) && (r < 30)){
      delay(100);
      Serial.print(".");
      r++;
  }
  if(r==30) {
    Serial.println("Connection failed");
  }
  else {
    Serial.println("Connected to web");
  
  Serial.print("requesting URL: ");
  Serial.println(host+Link);
 
  httpsClient.print(String("GET ") + Link + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +               
               "Connection: close\r\n\r\n");
 
  Serial.println("request sent");
                  
  while (httpsClient.connected()) {
    String line = httpsClient.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
 
  Serial.println("reply was:");
  Serial.println("==========");
  String line;
  while(httpsClient.available()){        
    line = httpsClient.readStringUntil('\n');  //Read Line by Line
    Serial.println(line); //Print response
  }
  Serial.println("==========");
  Serial.println("closing connection");
  }
}*/
