void Dalas18B20()
{
  DS18B20.begin(); // Запуск DS18B20
  DeviceAddress tempDeviceAddress;
  NumberOfDevices = DS18B20.getDeviceCount(); // количество датчиков DS18B20 в системе .
  if (NumberOfDevices > 0)
    ds18b20_find = true;
  Serial.print("Found ");
  Serial.print(NumberOfDevices, DEC);
  Serial.println(" DS18B20 devices.");
  Serial.print("Parasite power is: ");
  if (DS18B20.isParasitePowerMode())
    Serial.println("ON");
  else
    Serial.println("OFF");

  String buf;
  for (int i = 0; i < NumberOfDevices; i++)
  {
    if (DS18B20.getAddress(tempDeviceAddress, i))
      DS18B20.setResolution(tempDeviceAddress, TEMPERATURE_PRECISION);
    Serial.print("Device #" + String(i) + " - ");
    for (uint8_t i = 0; i < 8; i++)
    {
      if (tempDeviceAddress[i] < 16)
        buf = buf + "0"; // адрес датчика в буфер
      buf = buf + String(tempDeviceAddress[i], HEX);
    }
    Serial.print(buf);
    Serial.println(" = Ok");
    buf = "";
  }
}
