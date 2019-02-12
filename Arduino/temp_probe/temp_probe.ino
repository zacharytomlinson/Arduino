const int temperaturePin = 13;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  float voltage, deg_C, deg_F;

  voltage = getVoltage(temperaturePin);

  deg_C = (voltage - 0.5) * 100.0;

  deg_F = deg_C * (9.0/5.0) + 32.0;

  Serial.print("voltage: ");
  Serial.print(voltage);
  Serial.print("  deg C: ");
  Serial.print(deg_C);
  Serial.print("  deg F: ");
  Serial.println(deg_F);

  delay(1000);
}

float getVoltage(int pin)
{
  return (analogRead(pin) * 0.004882814);
}
