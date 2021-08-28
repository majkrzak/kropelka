#include "cc1101.h"
#include "radio.h"
#include "spi.h"
#include <util/delay.h>

int main() {
  spi_init();
  cc1101_init();
  radio_init();

  do {
    for (int i = 0; i < 50; i++)
      _delay_ms(100);
    radio_calibrate();
    radio_send((uint8_t[]){'t', 'e', 's', 't'});
  } while (1);
  return 0;
}
