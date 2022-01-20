#include <Arduino.h>
int sensor; 

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(13, HIGH);
  sensor = analogRead(0);
  Serial.println(sensor);
  delay(100);dsad
}