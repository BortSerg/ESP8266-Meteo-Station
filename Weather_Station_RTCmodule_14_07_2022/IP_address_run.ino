void IP_address_run()                                           //бегущая строка выводит IP адрес
{
  String IP_ADDRESS;                                            //строка для получения IP адреса
  int8_t banner_IP[18]={};                                         //массив хранения IP адреса для бегущей строки

  if (WiFi.status() == WL_CONNECTED)                            //если подключена к роутеру
      IP_ADDRESS = WiFi.localIP().toString();
  else                                                          //если режим точки доступа
      IP_ADDRESS = WiFi.softAPIP().toString();
  
  banner_IP[0] = 0x30;    //I
  banner_IP[1] = 0x73;    //P
  banner_IP[2] = 0x00;    //
  
  for (int i=0; i<IP_ADDRESS.length()+3;i++)
  {
    if (IP_ADDRESS[i] == '0') banner_IP[i+3] = 0x3f;
    if (IP_ADDRESS[i] == '1') banner_IP[i+3] = 0x06;
    if (IP_ADDRESS[i] == '2') banner_IP[i+3] = 0x5b;
    if (IP_ADDRESS[i] == '3') banner_IP[i+3] = 0x4f;
    if (IP_ADDRESS[i] == '4') banner_IP[i+3] = 0x66;
    if (IP_ADDRESS[i] == '5') banner_IP[i+3] = 0x6d;
    if (IP_ADDRESS[i] == '6') banner_IP[i+3] = 0x7d;
    if (IP_ADDRESS[i] == '7') banner_IP[i+3] = 0x07;
    if (IP_ADDRESS[i] == '8') banner_IP[i+3] = 0x7f;
    if (IP_ADDRESS[i] == '9') banner_IP[i+3] = 0x6f;
    if (IP_ADDRESS[i] == '.') banner_IP[i+3] = 0x08;
  }
  tm1637.runningString(banner_IP, sizeof(banner_IP), 500);
}
