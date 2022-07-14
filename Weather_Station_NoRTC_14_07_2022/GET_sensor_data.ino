//=================Получение тепературы с датчика DS18B20=================
float getTemperature() // 1-Wire ds18b20
{
  float temp;
  byte count = 0;
  do
  {
    DS18B20.requestTemperatures();
    temp = DS18B20.getTempCByIndex(0);
    delay(100);
    count++;
  } while ((temp <= (-50.0) || temp >= 85.0) & count <= 5);
  return temp;
}

//=================Получение тепературы c датчика BME280=================
float getTemperatureBME280()
{
  float temp;
  byte count = 0;
  do
  {
    temp = bme.temp();
    delay(100);
    count++;
  } while ((temp <= (-40.0) || temp >= 85.0) & count <= 5);
  return temp;
}

//=================Получение давления с датчика BME280===================
float getPressureBME280()
{
  float pres;
  byte count = 0;
  do
  {
    pres = bme.pres();
    delay(100);
    count++;
  } while ((pres <= 30000.0 || pres >= 110000.0) & count <= 5); //приделы в паскалях
  return pres;
}

//=================Получение влажности с датчика BME280==================
float getHumidityBME280()
{
  float hum;
  byte count = 0;
  do
  {
    hum = bme.hum();
    delay(100);
    count++;
  } while ((hum < 0.0 || hum > 100.0) & count <= 5);

  return hum;
}

//=================Функция вывода на ндикатор температуры в комнате=================
void getTM1637TemperatureRoom() //
{
  int temp = getTemperatureBME280(); //временная локальная переменная
  tm1637.display(0, 30);             //  t
  tm1637.display(1, 35);             //
  tm1637.display(2, 20);             //  i
  tm1637.display(3, 26);             //  n
  delay(600);
  tm1637.display(0, 30);        //  t
  tm1637.display(1, temp / 10); //  temp
  tm1637.display(2, temp % 10); //  temp
  tm1637.display(3, 36);        //  degree
}

//=================Функция вывода на ндикатор температуры на улице=================
void getTM1637TemperatureOut() //
{
  int temp = getTemperature(); //временная локальная переменная
  tm1637.display(0, 30);       //  t
  tm1637.display(1, 27);       //  o
  tm1637.display(2, 32);       //  u
  tm1637.display(3, 30);       //  t
  delay(600);

  if (temp <= -10)
  {
    tm1637.display(0, 34);             // -
    tm1637.display(1, abs(temp) / 10); // temp
    tm1637.display(2, abs(temp) % 10); // temp
    tm1637.display(3, 36);             // degree
  }

  if ((temp > -10) & (temp < 0))
  {
    tm1637.display(0, 30);             // t
    tm1637.display(1, 34);             // -
    tm1637.display(2, abs(temp) % 10); // temp
    tm1637.display(3, 36);             // degree
  }

  if ((temp >= 0) & (temp < 10))
  {
    tm1637.display(0, 30);        // t
    tm1637.display(1, 35);        // NULL
    tm1637.display(2, temp % 10); // temp
    tm1637.display(3, 36);        // degree
  }

  if (temp >= 10)
  {
    tm1637.display(0, 30);        //  t
    tm1637.display(1, temp / 10); //  temp
    tm1637.display(2, temp % 10); //  temp
    tm1637.display(3, 36);        //  degree
  }
}

//=================Функция вывода на ндикатор атмосферного давления=================
void getTM1637Pressure() //
{
  int temp = getPressureBME280() * 0.0075006157584566; //временная локальная переменная и перевод из паскалей в мм.рт.ст.

  tm1637.display(0, 28);                //  P
  tm1637.display(1, (temp / 100) % 10); //  presure
  tm1637.display(2, (temp / 10) % 10);  //  presure
  tm1637.display(3, (temp % 10));       //  presure
}

//=================Функция вывода на ндикатор влажности воздуха=====================
void getTM1637Humidity() //
{
  int temp = getHumidityBME280(); //временная локальная переменная

  if (temp <= 0)
  {
    tm1637.display(0, 17); //  H
    tm1637.display(1, 35); //  NULL
    tm1637.display(2, 0);  //  0
    tm1637.display(3, 37); //  _
  }
  if (temp >= 100)
  {
    tm1637.display(0, 17); //  H
    tm1637.display(1, 1);  //  1
    tm1637.display(2, 0);  //  0
    tm1637.display(3, 0);  //  0
  }
  else
  {
    tm1637.display(0, 17);        //  H
    tm1637.display(1, temp / 10); //  hum
    tm1637.display(2, temp % 10); //  hum
    tm1637.display(3, 37);        //  _
  }
}
