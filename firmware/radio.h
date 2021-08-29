#pragma once

#include <stdint.h>

void radio_init();
void radio_wake();
void radio_calibrate();
void radio_send(uint8_t[RADIO_PKTLEN]);
void radio_sleep();
