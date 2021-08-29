#include "mcu.h"

#include <avr/interrupt.h>
#include <avr/power.h>
#include <avr/sleep.h>

void mcu_init() {
  clock_prescale_set(clock_div_1);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
}

void mcu_sleep() {
  sei();
  sleep_enable();
  sleep_cpu();
  sleep_disable();
  cli();
}
