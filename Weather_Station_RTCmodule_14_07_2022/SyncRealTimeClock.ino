void SyncRealTimeClock() {                                      //Функция инхронизации времени с NTP сервером
  
  SNTP_server_set();
  //SNTP_server_set();
  label:
  //Time = sntp_get_current_timestamp();                        // получаем дату в UNIX формате
  timefull = sntp_get_real_time(sntp_get_current_timestamp());  // получаем дату в виде dayweek month day 00:00:00 YYYY
  delay(1000);
  Serial.println(timefull);
  String DOW, MON;
  byte  n = 0;
  byte hh = 0;
  byte mm = 0;
  byte ss = 0;
  byte delta = 0;
  n =  timefull.indexOf(' ');                                   // ищем индекс первого вхождения 'пробела' в строке. это разделитель дня недели и месяца
  DOW = timefull.substring(n-3,n);                              // берем подстроку в которую запишутся три символа до 'пробела' (день недели)
    if (DOW == "Mon") dayOfWeek = 1;                            // определяем номер дня недели
    if (DOW == "Tue") dayOfWeek = 2;
    if (DOW == "Wed") dayOfWeek = 3;
    if (DOW == "Thu") dayOfWeek = 4; 
    if (DOW == "Fri") dayOfWeek = 5; 
    if (DOW == "Sat") dayOfWeek = 6; 
    if (DOW == "Sun") dayOfWeek = 7; 
  
  MON = timefull.substring(n+1, n+4);                           // берем подстроку в которую запишутся три символа после 'пробела' (месяц)
    if (MON == "Jan") month = 1;                                // определяем номер месяца
    if (MON == "Feb") month = 2;
    if (MON == "Mar") month = 3;
    if (MON == "Apr") month = 4; 
    if (MON == "May") month = 5; 
    if (MON == "Jun") month = 6; 
    if (MON == "Jul") month = 7;
    if (MON == "Aug") month = 8; 
    if (MON == "Sep") month = 9; 
    if (MON == "Oct") month = 10; 
    if (MON == "Nov") month = 11;
    if (MON == "Dec") month = 12;

  dayOfMonth = timefull.substring(n+5, n+7).toInt();            // берем подстроку в которую запишется число месяца
  n = timefull.indexOf(':');                                    // ищем индекс первого вхождения ":" в строке. это разделитель часов и минут
  hh = timefull.substring(n - 2, n).toInt();                    // берем подстроку в которую запишутся два символа до : (часы) и конвертируем в число
  mm = timefull.substring(n+1, n+3).toInt();                    // берем подстроку в которую запишутся два символа после : (мнуты) и конвертируем в число
  
  n = timefull.lastIndexOf(':');                                // ищем индекс последнего вхождения ":" в строке. это разделитель минут и секунд                     
  ss = timefull.substring(n+1, n+3).toInt();                    // берем подстроку в которую запишутся два символа после : (скунды) и конвертируем в число
  
  n = timefull.length();                                        // получаем длину строки
  year = timefull.substring(n-3, n).toInt();                    // берем подстроку в которую запишутся два последих символа строки (год) и конвертируем в число
  
  sinc_count++;
  while (hours == 8 & minutes == 0 & sinc_count < 20)           // 20 попыток синхронизации времени (если неуданая, то получает время 08 часов 00 минут)
        {
          goto label;
        }
  Serial.println("Попыток связи с NTP " + String(sinc_count) + "\n");

  sinc_count = 0;      
  
  getTimeDs1307(&seconds, &minutes, &hours);                    //получим время из DS1307
  delta = minutes - mm;
  Serial.println("NTP:    "+String(hh)+":"+String(mm)+":"+String(ss)+ " GMT="+String(Config.GMT));
  Serial.println("DS1307: "+ String(hours)+":"+String(minutes)+":"+String(seconds));
  if (hours != hh | abs(delta)>=1 )                             //сравним часы и минуты с данными NTP
    {
      hours   = hh;
      minutes = mm;
      seconds = ss;
      setDateDs1307(seconds, minutes, hours, dayOfWeek, dayOfMonth, month, year);
      Serial.println("Время DS1307 синхронизировано с NTP.\n");
      changeClock = true;
    }
  else
    { 
      Serial.println("Синхронизировать нет необходимости. Разница времени метеостанции и NTP сервера меньше 1 минуты");
      notChangeClock = true;
    }
}


//=================Функция вывода на ндикатор часов=================================
void viewTime()
{
  getTimeDs1307(&seconds, &minutes, &hours);                   // закоментировать еси нет RTC модуля и счет будет идти с помощью самой ESP8266
  tm1637.point(point_flag);
  tm1637.display(0, hours / 10); 
  tm1637.display(1, hours % 10); 
  tm1637.display(2, minutes / 10); 
  tm1637.display(3, minutes % 10);
  point_flag = !point_flag;
}

/*
void clock_()                                                   //функция отсчета времени для часов если использовать <Ticker.h> и нет RTC модуля
{                                                               //раскоментировать функцию и закоментировать строку 84
  seconds++;
  if (seconds>59)
      {
        seconds = 0;
        minutes++;
        if (minutes > 59)
            {
              minutes = 0;
              hours++;
              if(hours > 23) 
                 {
                    hours = 0;
                 }
            }
      }
}
 */
