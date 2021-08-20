#include "cc1101.h"

#include "spi.h"

uint8_t cc1101_strobe(uint8_t addr) {
  spi_select();
  spi_wait();
  uint8_t ret = spi_xfer(addr);
  spi_deselect();
  return ret;
}

uint8_t cc1101_write(uint8_t addr, uint8_t data) {
  spi_select();
  spi_wait();
  uint8_t ret = spi_xfer(addr);
  spi_xfer(data);
  spi_deselect();
  return ret;
}

uint8_t cc1101_burst_write(uint8_t addr, uint8_t *data, size_t size) {
  spi_select();
  spi_wait();
  uint8_t ret = spi_xfer(addr | 0x40);
  while (size--)
    spi_xfer(*(data++));
  spi_deselect();
  return ret;
}
