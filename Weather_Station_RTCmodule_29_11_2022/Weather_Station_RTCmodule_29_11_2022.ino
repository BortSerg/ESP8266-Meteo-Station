#include <ArduinoOTA.h>
#include <OneWire.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>
#include <DallasTemperature.h>
#include "sntp.h"
#include <BME280I2C.h>
#include <Wire.h>
#include <time.h>
#include <TM1637.h>
#include <EEPROM.h>
// #include <WiFiClientSecure.h>              // для отправки в Telegram

BME280I2C::Settings settings(
    BME280::OSR_X1,
    BME280::OSR_X1,
    BME280::OSR_X1,
    BME280::Mode_Forced,
    BME280::StandbyTime_1000ms,
    BME280::Filter_Off,
    BME280::SpiEnable_False,
    BME280I2C::I2CAddr_0x76);
BME280I2C bme(settings);

// I2C pins                                 //Wemos ESP8266
#define SDA_pin 4 // D2 pin
#define SCL_pin 5 // D1 pin

// инициализация oneWire и DS18B20
#define ONE_WIRE_BUS D4          // вывод к которому подключен DS18B20 он же GPIO1
#define TEMPERATURE_PRECISION 12 // точность бит. Если глючит или врет, уменьшить с 12 до 9

//  инициализация и установка адреся RTC
#define DS1307_I2C_ADDRESS 0x68

// определение пинов для вывода на индикаор ТМ1637
#define CLK D6
#define DIO D5

bool bme_find = false;
bool ds18b20_find = false;

// Создаём объект класса TM1637, в качестве параметров передаём номера пинов подключения
TM1637 tm1637(CLK, DIO);
bool changeClock = false;
bool notChangeClock = false;

int NumberOfDevices; // сколько датчиков DS18B20 в системе.

// Переменные для часов
// uint32 Time;                              //время в UNIX формате
String timefull;        // время в формате dayweek month day 00:00:00 year
byte hours;             // часы
byte minutes;           // минуты
byte seconds;           // секунды
byte dayOfWeek;         // день недели
byte dayOfMonth;        // число месяца
byte month;             // месяц
byte year;              // год
byte sinc_count = 0;    // счечик попыток синхронизации часов
bool point_flag = true; // флаг для мигания разделителем при отображении часов
bool sync_clock = true; // флаг на разрешение синхронизации часов с сервером

// Переменные для таймингов
unsigned long previousMillis_TM1637 = 0;
unsigned long previousMillis_NM = 0;
unsigned long previousMillis_TL = 0;
unsigned long sync_previousMillis = 0;
unsigned long currentMillis = 0;
unsigned long clock_tick = 0;
unsigned long interval_TM1637 = 10000;  // интервал через который происходит смена значений на индикаторе
unsigned long interval_sync = 43200000; // интервал синхронизации часов
byte count = 0;                         // счетчик смены значений на индикаторе
bool send_NM = true;                    // разрешение на отправку данных Narodmon.ru
unsigned long interval_NM = 300000;     // интервал отправки данных на Narodmon.ru
// bool          send_TL = true;               //разрешение на отправку данных Telegram
// unsigned long interval_TL = 300000;         //интервал отправки данных на Telegram

ESP8266HTTPUpdateServer httpUpdater;
ESP8266WebServer server(80);

WiFiClient client; // для отправки данных на narodmon.ru
// WiFiClientSecure httpsClient;               //для отправки даных в Telegram

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);

// const uint16_t httpsPort = 443;             // порт Telegram bot
// const char* host = "api.telegram.org";      // хост Telegram bot
// SHA1 finger print of certificate use web browser to view and copy
// const char fingerprint[] PROGMEM = "bb dc 45 2a 07 e3 4a 71 33 40 32 da be 81 f7 72 6f 4a 2b 6b";
// String token = "";                          //api token
// String chat_id = "";                        //id чата с ботом
// String msg = "Start";                       //переменная для хранения сообщения которое будет отправленно в Telegram bot

struct ESP_Config // структура для хранения настроек метеостанции в EEPROM памяти. Переменные структуры записаны большими буквами, для их отличия от других глобальных переменных
{
  char MUSOR[16] = {}; // В начале сектора EEPROM содержатся какие-то данные ESP, запись туда важных данных нежелательна
  // Наименование в режиме клиента
  char WIFI_SSID[32] = {}; // имя сети
  char WIFI_PASSWORD[32] = {};
  // Параметры подключения в режиме точки доступа
  char AP_SSID[32] = {}; // имя точки доступа
  char AP_PASSWORD[32] = {};
  // Настройки часов
  int GMT = 0;               // часовой пояс
  bool SYNC_CLOCK = 0;       // разрешение на синхронизацию
  uint8_t INTERVAL_SYNC = 0; // интервал синхронизации часов
  // Настройки отправки данных на narodmon.ru
  bool SEND_NM = 0;        // разрешение на отправку данных Narodmon
  uint8_t INTERVAL_NM = 0; // интервал отправки данных
  // Настройки отправки сообщений в Telegram
  bool SEND_TL = 0;        // разрешение на отправку данных Telegram
  uint8_t INTERVAL_TL = 0; // интервал отправки данных
  char CHAT_ID[16] = {};   // Уникальный ID  чата
  char TOKEN[64] = {};     // API Token
  byte LIGHT = 0;          // Яркость 7-сегментного индикатора
  byte CONTROLL_VALUE = 0; // Контрольное значение = 88. Используется для определения загрузки дефолтных настроек при первом запуске
} Config;

void setup()
{
  Serial.begin(115200);
  Serial.println("");
  Serial.println("Soft ver. 29.11.2022");
  Serial.println("");
  EEPROM.begin(sizeof(Config)); // инициализация EEPROM памяти в размере = размеру структуры Config
  Serial.println("Инициализированно " + String(sizeof(Config)) + " byte EEPROM памяти");

  OTA_Update(); // подключение обновления по воздуху

  Read_Config(); // xтение конфига из EEPROM памяти конфигураций

  if (Config.CONTROLL_VALUE != 88) // проверка считаных с памяти данных. Если контрольное значение не верно, то записать дефолтные настройки
  {
    String ssid = "WiFiName";
    String pass = "";
    String ap_ssid = "ESP8266";
    String ap_pass = "";
    strcpy(Config.WIFI_SSID, ssid.c_str());
    strcpy(Config.WIFI_PASSWORD, pass.c_str());
    strcpy(Config.AP_SSID, ap_ssid.c_str());
    strcpy(Config.AP_PASSWORD, ap_pass.c_str());
    Config.SEND_NM = 5;
    Config.GMT = 0;
    Config.SYNC_CLOCK = 1;
    Config.INTERVAL_NM = 5;
    Config.INTERVAL_SYNC = 12;
    Config.LIGHT = 2;
    Config.CONTROLL_VALUE = 88;
    save_Config();
  }

  TM1637_init(); // Инициализация модуля TM1637

  SNTP_server_set(); // установка таймзоны и sntp серверов

  WiFi_init(); // подключение к сети и синхронизация часов/поднятие точки доступа

  Dalas18B20(); // поиск и инициализация датчиков DS18B20

  BME(); // поиск и инициализация датчика BME/BMP

  Init_html(); // инициализация HTML страниц сервера

  Serial.println("Temperature web server started!\n");

  IP_address_run(); // вывод IP адреса

  if (Config.SYNC_CLOCK == true & WiFi.status() == WL_CONNECTED)
    SyncRealTimeClock();
}

void loop()
{
  server.handleClient();
  ArduinoOTA.handle();

  currentMillis = millis();
  if (currentMillis - previousMillis_TM1637 > interval_TM1637)
  {
    previousMillis_TM1637 = currentMillis;
    count++;
    if (count > 4)
      count = 0;
  }

  if (currentMillis - sync_previousMillis > interval_sync) // тайминг синхронизации часов с сервером
  {
    sync_previousMillis = currentMillis;
    if (Config.SYNC_CLOCK == true)
      SyncRealTimeClock();
  }

  if (currentMillis - sync_previousMillis > interval_NM) // тайминг синхронизации часов с сервером
  {
    sync_previousMillis = currentMillis;
    if (Config.SEND_NM == true)
      SendToNM();
  }

  switch (count)
  {
  case 0: // вывод часов
  {
    if (currentMillis - clock_tick > 1000)
    {
      clock_tick = currentMillis;
      viewTime();
    }
    break;
  }

  case 1: // вывод температыру на улице
  {
    tm1637.point(false);
    if (ds18b20_find)
      getTM1637TemperatureOut();
    else
      count++;
    break;
  }

  case 2: // вывод температурыd в комнате
  {
    if (bme_find)
      getTM1637TemperatureRoom();
    else
      count++;
    break;
  }

  case 3: // вывод атмосферного давлния
  {
    if (bme_find)
      getTM1637Pressure();
    else
      count++;
    break;
  }

  case 4: // вывод влажности в комнате
  {
    if (bme_find)
      getTM1637Humidity();
    else
      count = 0;
    break;
  }
  }
  yield();
}
