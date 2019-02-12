
/****************************************************
 * This code starts monitoring the thermoresistors and relaying the temp info to the rpi
 * Written by Zachary Tomlinson for TejasDigital
 */

#include <Adafruit_MAX31865.h>

Adafruit_MAX31865 MAX_1 = Adafruit_MAX31865(10, 11, 12, 13);
Adafruit_MAX31865 MAX_2 = Adafruit_MAX31865(6, 7, 8, 9);

float TMP_1;
float TMP_2;

#define RREF 430.0

void setup() {
  Serial.begin(115200);                                         

  MAX_1.begin(MAX31865_3WIRE);                                    
  MAX_2.begin(MAX31865_2WIRE);
}


void loop() {
  TMP_1 = MAX_1.temperature(100, RREF);
  TMP_2 = MAX_2.temperature(100, RREF);
  Serial.print(TMP_1, BIN);
  Serial.print("|");
  Serial.println(TMP_2, BIN);

  delay(1000);
}
