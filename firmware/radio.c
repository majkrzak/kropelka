#include "radio.h"

#include "cc1101.h"

static void _wait_idle() {
  while (cc1101_strobe(CC1101_SNOP) & 0b01110000)
    ;
}

void radio_init() {
  cc1101_strobe(CC1101_SRES);
  _wait_idle();
  cc1101_burst_write(CC1101_FREQ, (uint8_t[]){RADIO_FREQ}, 3);
  cc1101_burst_write(
      CC1101_MDMCFG,
      (uint8_t[]){
          RADIO_CHANBW_E << 6 | RADIO_CHANBW_M << 4 | RADIO_DRATE_E,
          RADIO_DRATE_M,
          (0b011 << 4) | 1 << 3 |
              011, // MOD_FORMAT: ASK/OOK, MC, SYNC_MODE:16/16
          (0b100 << 4) | RADIO_CHANSPC_E, // NUM_PREAMBLE:4, CHANSPC_E (default)
          RADIO_CHANSPC_M,
      },
      5);
  cc1101_burst_write(CC1101_PKTCTRL,
                     (uint8_t[]){
                         0,               // tx only, no address
                         (1 << 2) | 0b00, // CRC_EN:1, LENGTH_CONFIG: fixed
                     },
                     2);
  cc1101_write(CC1101_PKTLEN, RADIO_PKTLEN);
  cc1101_burst_write(CC1101_SYNC, (uint8_t[]){0xAB, 0xBA}, 2);
  cc1101_write(CC1101_FREND0, (0x01 << 4) | 1);
}

void radio_wake() {
  _wait_idle();
  cc1101_burst_write(CC1101_PATABLE, (uint8_t[]){0x00, 0x12}, 2);
}

void radio_calibrate() {
  cc1101_strobe(CC1101_SCAL);
  _wait_idle();
}

void radio_send(uint8_t data[RADIO_PKTLEN]) {
  cc1101_burst_write(CC1101_FIFO, data, RADIO_PKTLEN);
  cc1101_strobe(CC1101_STX);
  _wait_idle();
}

void radio_sleep() { cc1101_strobe(CC1101_SPWD); }
