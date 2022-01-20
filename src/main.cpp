#include <Arduino.h>
int LEDblue = 3;        // Blue on Pin 3
int LEDred = 5;         // Red on Pin 5
int LEDgreen = 6;       // Green on Pin 6
int t = 1000;           // Break 1 sec.
int brightness1a = 150; // Set blues brightness on a Value
int brightness1b = 200; // Set rot brightness on a Value
int brightness1c = 250; // Set green brightness on a Value
int dark = 0;           // Set brightness on 0
int sensor;

void setup()
{
  pinMode(LEDblue, OUTPUT);
  pinMode(LEDgreen, OUTPUT);
  pinMode(LEDred, OUTPUT);
  Serial.begin(9600);
  while (!Serial)
    ;
  Serial.println("1 for blue, 2 for red, 3 for green");
}

void loop()
{
  if (Serial.available())
  {
    analogWrite(LEDblue, dark);
    analogWrite(LEDred, dark);
    analogWrite(LEDgreen, dark);

    int state = Serial.parseInt();
    if (state == 1)
    {
      analogWrite(LEDblue, brightness1a); // blue on
      delay(t);
      Serial.println("Command completed BlueLED turned ON");
    }

    if (state == 2)
    {
      analogWrite(LEDred, brightness1b); // red on
      delay(t);
      Serial.println("Command completed RedLED turned ON");
    }

    if (state == 3)
    {
      analogWrite(LEDgreen, brightness1c); //green on
      delay(t);
      Serial.println("Command completed GreenLED turned ON");
    }
    sensor = analogRead(0);
    Serial.println(sensor);
    delay(100);
  }
}
