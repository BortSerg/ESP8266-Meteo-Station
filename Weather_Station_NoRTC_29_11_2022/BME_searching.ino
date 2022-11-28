void BME()
{
  //===================BME280 searching======================
  Wire.begin(SDA_pin, SCL_pin);
  byte count = 0;
  while (!bme.begin() & count < 5)
  {
    Serial.println("Could not find BME280I2C sensor!");
    delay(1000);
    count++;
  }

  if (bme.begin())
  {
    bme_find = true;
    // bme.chipID(); // Deprecated. See chipModel().
    switch (bme.chipModel())
    {
    case BME280::ChipModel_BME280:
      Serial.println("Found BME280 sensor! Success.");
      break;
    case BME280::ChipModel_BMP280:
      Serial.println("Found BMP280 sensor! No Humidity available.");
      break;
    default:
      Serial.println("Found UNKNOWN sensor! Error!");
    }
    // Change some settings before using.
    settings.tempOSR = BME280::OSR_X4;
    bme.setSettings(settings);
  }
}
