#include <Arduino.h>
int LEDgreen = 3;        // Grün Pin 3
int LEDred = 5;         // Rot Pin 5
int LEDblue = 6;       // Blau Pin 6
int t = 1000;           // Pause 1 sec.
int brightness1a = 150; // Helligkeit Grün
int brightness1b = 200; // Helligkeit Rot
int brightness1c = 250; // Helligkeit Blau 
int dark = 0;           // Helligkeit ganz unten
int sensor;             
int rowCount = 500;
int rowNumber = 0;

void setup()
{
  pinMode(LEDgreen, OUTPUT);
  pinMode(LEDblue, OUTPUT);
  pinMode(LEDred, OUTPUT);
  Serial.begin(9600);
  while (!Serial)
    ;
  Serial.println("1 für Grün, 2 für Rot, 3 für Blau");
}

void loop()
{
  if (Serial.available())
  {
    analogWrite(LEDgreen, dark);
    analogWrite(LEDred, dark);
    analogWrite(LEDblue, dark);

    int state = Serial.parseInt();
    if (state == 1)
    {
      analogWrite(LEDgreen, brightness1a); // Grün on
      delay(t);
      Serial.println("Grün an!");
    }

    if (state == 2)
    {
      analogWrite(LEDred, brightness1b); // Rot on
      delay(t);
      Serial.println("Rot an!");
    }

    if (state == 3)
    {
      analogWrite(LEDblue, brightness1c); // Blau on
      delay(t);
      Serial.println("Grün an!");
    }
    sensor = analogRead(0);
    // Serial.println(sensor);

    if (rowNumber < rowCount)
    {
      Serial.print(++rowNumber);
      Serial.print('\t');
      Serial.println(sensor); //Sensorwert Ausgabe
    }
    delay(100);
  }
}
