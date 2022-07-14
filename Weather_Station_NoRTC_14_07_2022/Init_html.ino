void Init_html() {
  server.on ( "/", HTTP_Main );                                       //Гдавная страница
  server.on ( "/settings_WiFi_AP", HTTP_Settings_WIFI_AP );           //страница с настройками wifi/ap
  server.on ( "/settings_NM_Tel", HTTP_Settings_NM_Tel );             //страница с настройками narodmon и telegram
  server.on ( "/settings_Clock", HTTP_SettingsClock );                //страница с настройками часов
  server.on ( "/settings_Light", HTTP_SettingsLight );                //страница настройки яркости
  server.on ( "/save", HTTP_handleSave );                             //запись данных в память устройства
  server.on ( "/reboot", HTTP_handleReboot );                         //перезагрузка
  httpUpdater.setup(&server);                                         //обновления через web-интерфейс  http://{local_IP}/update

  server.begin();
}
