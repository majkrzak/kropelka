#include "mcu.h"

#include <avr/interrupt.h>
#include <avr/power.h>
#include <avr/sleep.h>
#include <avr/wdt.h>

ISR(WDT_vect) {}

static void watchdog_init() { WDTCR = 1 << WDP3 | 1 << WDP0; }

static void watchdog_arm() {
  wdt_reset();
  WDTCR |= 1 << WDE;
  WDTCR |= 1 << WDTIE;
}

void mcu_init() {
  clock_prescale_set(clock_div_1);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  watchdog_init();
}

void mcu_sleep() {
  sei();
  watchdog_arm();
  sleep_enable();
  sleep_cpu();
  sleep_disable();
  cli();
}
