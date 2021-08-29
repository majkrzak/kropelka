#include "sensor.h"

#include <avr/io.h>

void sensor_init() {
  DDRB &= 1 << PB3;
  PORTB |= 1 << PB3;
}

bool sensor_state() { return (PINB & 1 << PB3) ? true : false; }
