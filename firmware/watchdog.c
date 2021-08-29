#include "watchdog.h"

#include <avr/interrupt.h>
#include <avr/wdt.h>

ISR(WDT_vect) {}

void watchdog_init() { WDTCR = 1 << WDP3 | 1 << WDP0; }

void watchdog_arm() {
  wdt_reset();
  WDTCR |= 1 << WDE;
  WDTCR |= 1 << WDTIE;
}
