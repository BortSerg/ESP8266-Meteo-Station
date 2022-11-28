void Read_Config(void){                                   //чтение конфига из EEPROM памяти
   size_t sz1 = sizeof(Config);
   for( int i=0; i<sz1; i++ ){
       uint8_t c = EEPROM.read(i);
       *((uint8_t*)&Config + i) = c; 
    }  
   
        interval_sync = Config.INTERVAL_SYNC * 3600000; //3600000ms в одном часе
        interval_NM   = Config.INTERVAL_NM * 60000;     //60000ms в одной минуте
//        interval_TL   = Config.INTERVAL_TL * 60000;     //60000ms в одной минуте
}
