#include "inbound.h"

/* Variables */
float VOLTS_IN = 5.f; // Vcc (+5 Volts)

/* Functions */
void readButton(button *btn)
{
  float currentResistance = 0.f;
  int currentButton = BUTTON_NONE;

  // try to read from primary wire
  currentResistance = readResistance(RESISTANCE_WIRE_A_PIN);
  currentButton = detectButton(RESISTANCE_WIRE_A_PIN, currentResistance);
  if (currentButton == BUTTON_NONE)
  {
    // if nothing is detected, try from secondary wire
    currentResistance = readResistance(RESISTANCE_WIRE_B_PIN);
    currentButton = detectButton(RESISTANCE_WIRE_B_PIN, currentResistance);
  }

  btn->button = currentButton;
  if (currentButton != BUTTON_NONE)
  {
    btn->wire = INPUT_BUTTON_WIRES[currentButton];
    btn->resistance = currentResistance;
    btn->resistanceDefinition = INPUT_BUTTON_RESISTANCES[currentButton];
  }
}

// Reads the resistance
float readResistance(byte pin)
{
  int rawVolts = analogRead(pin);                                           // Read raw analogue value (0-1023)
  float voltsOut = (VOLTS_IN / 1024.f) * float(rawVolts);                   // Convert to voltage (at point between resistors)
  float currentResistance = RESISTANCE_KNOWN * ((VOLTS_IN / voltsOut) - 1); // Calculate the resistance

#ifdef INBOUND_RESISTANCE_DEBUG
  Serial.print("Voltage: ");
  Serial.print(voltsOut);
  Serial.print(", Resistance: ");
  Serial.println(currentResistance);
#endif

  return currentResistance;
}

// Detects which button is currently pressed.
int detectButton(byte pin, float currentResistance)
{
  int currentButton = BUTTON_NONE;

  for (int i = 0; i < TOTAL_BUTTONS; i++)
  {
    // If we aren't analyzing the correct wire for the button, skip it
    if (pin != INPUT_BUTTON_WIRES[i])
      continue;

    // Otherwise, proceed to the check whether the resistance value corresponds to the button
    if (isButtonPressed(INPUT_BUTTON_RESISTANCES[i], currentResistance))
    {
      currentButton = i;
      break;
    }
  }

  return currentButton;
}

// Determines if the current resistance is within tolerance
boolean isButtonPressed(float resistanceDefinition, float currentResistance)
{
  float decimalPercent = TOLERANCE_PERCENT / 100.f;
  float highRange = resistanceDefinition * (1.f + decimalPercent);
  float lowRange = resistanceDefinition * (1.f - decimalPercent);
  return lowRange <= currentResistance && currentResistance <= highRange;
}

// Prints the current button (if DEBUG is enabled)
void printButton(button *btn)
{
#ifdef INBOUND_BUTTON_DEBUG
  Serial.print("Button: ");

  switch (btn->button)
  {
  case BUTTON_SOURCE:
    Serial.print("SOURCE");
    break;
  case BUTTON_SEEK_UP:
    Serial.print("SEEK_UP");
    break;
  case BUTTON_SEEK_DOWN:
    Serial.print("SEEK_DOWN");
    break;
  case BUTTON_VOLUME_UP:
    Serial.print("VOLUME_UP");
    break;
  case BUTTON_VOLUME_DOWN:
    Serial.print("VOLUME_DOWN");
    break;
  case BUTTON_PICK_UP:
    Serial.print("PICK_UP");
    break;
  case BUTTON_HANG_UP:
    Serial.print("HANG_UP");
    break;
  default:
    Serial.println("NONE");
  }

  if (btn->button != BUTTON_NONE)
  {
    Serial.print(", Wire: ");
    switch (btn->wire)
    {
    case WIRE_A:
      Serial.print("A");
      break;
    case WIRE_B:
      Serial.print("B");
      break;
    }

    Serial.print(", Resistance: ");
    Serial.print(btn->resistance);

    Serial.print(", Resistance definition: ");
    Serial.println(btn->resistanceDefinition);
  }
#endif
}