#include "button.h"

/* Variables */

// Indexed button resistance values {SOURCE, SEEK_UP, SEEK_DOWN, VOLUME_UP, VOLUME_DOWN, PICK_UP, HANG_UP}
float INPUT_BUTTON_RESISTANCES[TOTAL_BUTTONS] = {1000.f, 109.f, 330.f, 109.f, 0.f, 330.f, 0.f};

// Indexed button wires {SOURCE, SEEK_UP, SEEK_DOWN, VOLUME_UP, VOLUME_DOWN, PICK_UP, HANG_UP}
float INPUT_BUTTON_WIRES[TOTAL_BUTTONS] = {WIRE_A, WIRE_B, WIRE_B, WIRE_A, WIRE_A, WIRE_A, WIRE_B};