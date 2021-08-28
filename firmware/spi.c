#include "spi.h"

#include <avr/io.h>
#include <util/delay.h>

#define DELAY 20

void spi_init() {
  DDRB |= 1 << PB0;
  DDRB |= 1 << PB2;
  DDRB |= 1 << PB4;
  DDRB &= ~(1 << PB1);
}

void spi_select() {
  PORTB &= ~(1 << PB4);
  _delay_ms(DELAY);
}

void spi_wait() {
  while (PORTB & (1 << PB1))
    ;
}

uint8_t spi_xfer(uint8_t in) {
  uint8_t out = 0;
  for (int8_t i = 7; i >= 0; --i) {
    // Write bit
    if ((in >> i) & 1) {
      PORTB |= (1 << PB0);
    } else {
      PORTB &= ~(1 << PB0);
    }
    _delay_ms(DELAY);
    // Read bit
    out |= (PINB >> PB0) & 1;
    // tick the clock
    PORTB |= (1 << PB2);
    _delay_ms(DELAY);
    PORTB &= ~(1 << PB2);
  }
  return out;
}

void spi_deselect() {
  PORTB |= (1 << PB4);
  _delay_ms(DELAY);
}
