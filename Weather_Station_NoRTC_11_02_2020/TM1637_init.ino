void TM1637_init()
{
  tm1637.init();                                      //Инициализация модуля TM1637
  //Установка яркости индикатора
  /*
     BRIGHT_DARKEST = 0 Тёмный
     BRIGHT_TYPICAL = 2 Средний
     BRIGHTEST = 7      Яркий
  */
  tm1637.set(Config.LIGHT);                         //Выбор яркости свечения индикатора  
}
