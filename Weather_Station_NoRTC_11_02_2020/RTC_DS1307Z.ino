byte decToBcd(byte val)
{
  return ( (val/10*16) + (val%10) );
}

byte bcdToDec(byte val)               //функция преобразования в десятичную систему
{
  return ( (val/16*10) + (val%16) );
}

void setDateDs1307(byte seconds,        // 0-59        //передача параметров в RTC
                   byte minutes,        // 0-59
                   byte hours,          // 1-23
                   byte dayOfWeek,     // 1-7
                   byte dayOfMonth,    // 1-28/29/30/31
                   byte month,         // 1-12
                   byte year)          // 0-99
{
   Wire.beginTransmission(DS1307_I2C_ADDRESS);
   Wire.write(0);
   Wire.write(decToBcd(seconds));    
   Wire.write(decToBcd(minutes));
   Wire.write(decToBcd(hours));     
   Wire.write(decToBcd(dayOfWeek));
   Wire.write(decToBcd(dayOfMonth));
   Wire.write(decToBcd(month));
   Wire.write(decToBcd(year));
   Wire.endTransmission();
   Serial.println("Время DS1307 установлено");
}

void setTimeDs1307(byte seconds, byte minutes, byte hours)
{
   Wire.beginTransmission(DS1307_I2C_ADDRESS);
   Wire.write(0);
   Wire.write(decToBcd(seconds));    
   Wire.write(decToBcd(minutes));
   Wire.write(decToBcd(hours));     
   Wire.endTransmission();
   Serial.println("Время DS1307 установлено");
}
void getDateDs1307(byte *seconds, byte *minutes, byte *hours, byte *dayOfWeek, byte *dayOfMonth, byte *month, byte *year) //полное получение данных из  RTC
{
        Wire.beginTransmission(DS1307_I2C_ADDRESS);
        Wire.write(0);
        Wire.endTransmission();
      
        Wire.requestFrom(DS1307_I2C_ADDRESS, 7);
      
        *seconds     = bcdToDec(Wire.read() & 0x7f);
        *minutes     = bcdToDec(Wire.read());
        *hours       = bcdToDec(Wire.read() & 0x3f); 
        *dayOfWeek  = bcdToDec(Wire.read());
        *dayOfMonth = bcdToDec(Wire.read());
        *month      = bcdToDec(Wire.read());
        *year       = bcdToDec(Wire.read());
}

void getTimeDs1307(byte *seconds, byte *minutes, byte *hours)                  //получение только врмени из RTC
{
        Wire.beginTransmission(DS1307_I2C_ADDRESS);
        Wire.write(0);
        Wire.endTransmission();
      
        Wire.requestFrom(DS1307_I2C_ADDRESS, 3);
      
        *seconds     = bcdToDec(Wire.read() & 0x7f);
        *minutes     = bcdToDec(Wire.read());
        *hours       = bcdToDec(Wire.read() & 0x3f); 
}
