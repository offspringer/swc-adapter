#include <Arduino.h>
#include "inbound.h"

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  button detectedButton;
  readButton(&detectedButton);
  printButton(&detectedButton);
  delay(1000);
}