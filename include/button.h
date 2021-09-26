#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

/* Define button type */
struct button
{
    byte button;
    byte wire;
    float resistance;
    float resistanceDefinition;
};
typedef struct button Button;

/* Constants */
#define TOTAL_BUTTONS 7      // Total buttons on the steering wheel
#define BUTTON_NONE -1       // When no button is pressed
#define BUTTON_SOURCE 0      // Index corresponding to the SOURCE button resistance (blue)
#define BUTTON_SEEK_UP 1     // Index corresponding to the SEEK_UP button resistance (white)
#define BUTTON_SEEK_DOWN 2   // Index corresponding to the SEEK_DOWN button resistance (white)
#define BUTTON_VOLUME_UP 3   // Index corresponding to the VOLUME_UP button resistance (blue)
#define BUTTON_VOLUME_DOWN 4 // Index corresponding to the VOLUME_DOWN button resistance (blue)
#define BUTTON_PICK_UP 5     // Index corresponding to the PICK_UP button resistance (blue)
#define BUTTON_HANG_UP 6     // Index corresponding to the HANG_UP button resistance (white)

#define WIRE_A 0 // Primary wire from SWC (STRG SW A, pin 6 of Nissan J502 connector)
#define WIRE_B 1 // Secondary wire from SWC (STRG SW B, pin 16 of Nissan J502 connector)

/* Variables */

// Indexed button resistance values {SOURCE, SEEK_UP, SEEK_DOWN, VOLUME_UP, VOLUME_DOWN, PICK_UP, HANG_UP}
extern float INPUT_BUTTON_RESISTANCES[TOTAL_BUTTONS];

// Indexed button wires {SOURCE, SEEK_UP, SEEK_DOWN, VOLUME_UP, VOLUME_DOWN, PICK_UP, HANG_UP}
extern float INPUT_BUTTON_WIRES[TOTAL_BUTTONS];

#endif