#include <Arduino.h>

static float zadnje;
static float srednja0;
static float br0;
static float srednja1;
static float br1;

void setup() { 
  Serial.begin(9600);
  zadnje = 0;
}

float analogTomVolt(float analog){
  float volt = 1000 * analog * 5 / 1023;
  return volt;
}

float analogToTemp(){
  float temp = (analogRead(5) * (5000 / 1024.0)) / 10;
  return temp;
}

void loop() {
  float time = millis() / 1000;
  float Cell0 = analogRead(A0); 
  float Cell1 = analogRead(A1); 
  
  if (time >= zadnje + 60){
    Serial.print(time);
    Serial.print(" - 0: ");
    Serial.print(srednja0 / br0);
    Serial.print(" - 1: ");
    Serial.print(srednja1 / br1);
    Serial.print(" - Temperatura: ");
    Serial.println(analogToTemp());
    zadnje += 60;
    br0 = 0;
    srednja0 = 0;
    br1 = 0;
    srednja1 = 0;
  } else {
    srednja0 += analogTomVolt(Cell0);
    br0 += 1;
    srednja1 += analogTomVolt(Cell1);
    br1 += 1;
  }
  delay(3000);
}