#include "cc1101.h"
#include "mcu.h"
#include "radio.h"
#include "sensor.h"
#include "spi.h"
#include "watchdog.h"

struct __attribute__((packed, scalar_storage_order("big-endian"))) {
  uint8_t uuid[16];
  uint32_t counter;
  uint8_t state;
} packet = {.uuid = (uint8_t[]){PACKET_UUID}, .counter = 0};

int main() {
  mcu_init();
  watchdog_init();
  sensor_init();
  spi_init();
  cc1101_init();
  radio_init();

  do {
    radio_sleep();
    watchdog_arm();
    mcu_sleep();
    radio_wake();
    radio_calibrate();
    packet.counter++;
    packet.state = sensor_state();
    radio_send((uint8_t *)&packet);
  } while (1);
}

_Static_assert(sizeof packet == RADIO_PKTLEN);
