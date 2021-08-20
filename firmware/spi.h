/** Software SPI module.
 *  Provide software implementation of the SPI protocol for ATtiny13A.
 */

#pragma once

#ifndef __AVR_ATtiny13A__
#error MCU not suported.
#endif

#include <stdint.h>

/*! Initialize software SPI.
 *  Set MOSI, SCK and CS pins as outputs.
 */
void spi_init();

/*! Select device.
 *  Set CS to LOW.
 */
void spi_select();

/*! Wait for device readines.
 *  Wait for LOW on MISO.
 */
void spi_wait();

/*! Transfer and receive byte.
 */
uint8_t spi_xfer(uint8_t);

/*! Deselect device.
 *  Set CS to HIGH.
 */
void spi_deselect();
