#include "cc1101.h"
#include "mcu.h"
#include "radio.h"
#include "spi.h"
#include "watchdog.h"
#include <util/delay.h>

int main() {
  mcu_init();
  watchdog_init();
  spi_init();
  cc1101_init();
  radio_init();

  do {
    radio_sleep();
    watchdog_arm();
    mcu_sleep();
    radio_wake();
    radio_calibrate();
    radio_send((uint8_t[]){'t', 'e', 's', 't'});
  } while (1);
}
