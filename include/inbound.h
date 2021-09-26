#ifndef INBOUND_H
#define INBOUND_H

#include <Arduino.h>
#include "button.h"

/* Constants */
#define INBOUND_RESISTANCE_DEBUG // Enables serial printing for resistance
#define INBOUND_BUTTON_DEBUG     // Enables serial printing for button

#define TOLERANCE_PERCENT 10.f   // Button matching tolerance (in %)
#define RESISTANCE_WIRE_A_PIN 0  // Analogue input pin on Arduino
#define RESISTANCE_WIRE_B_PIN 1  // Analogue input pin on Arduino
#define RESISTANCE_KNOWN 10000.f // The known resistor value in Ohms

/* Variables */
extern float VOLTS_IN; // Vcc (+5 Volts)

/* Functions */
void readButton(button *btn);
float readResistance(byte pin);
int detectButton(byte pin, float currentResistance);
boolean isButtonPressed(float resistanceDefinition, float currentResistance);
void printButton(button *btn);

#endif