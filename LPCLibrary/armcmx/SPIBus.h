/*
 * Copyright (c) 2010 by Cristian Maglie <c.maglie@bug.st>
 * SPI Master library for arduino.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */

#ifndef _SPIBUS_H_
#define _SPIBUS_H_

#include <stdio.h>
#include <stdint.h>
//#include <Arduino.h>
//#include <avr/pgmspace.h>
#include "armcmx.h"

#include "spi.h"


class SPIBus {
	SPIDef * port;
	GPIOPin sck, miso, mosi, nss;
	
public:
	SPIBus(SPIDef * port, 
		GPIOPin sckpin, GPIOPin misopin, GPIOPin mosipin, GPIOPin nsspin) : 
		sck(sckpin), miso(misopin), mosi(mosipin), nss(nsspin)  {}

  // SPI Configuration methods

//  inline static void attachInterrupt();
//  inline static void detachInterrupt(); // Default

  void begin(); // Default
  void end();

	inline uint16 transfer(uint16 _data) {
    return SPI_transfer(port, _data);
	}

	inline void setBitOrder(uint16_t bitOrder) {
		//SPI_setBitOrder(port, bitOrder);
	}

	inline void setDataMode(uint16_t mode) {
		//SPI_setDataMode(port, mode);
	}

	inline void setClockDivider(uint16_t rate) {	
		// spi_setClockDivier(port, rate);
	}
	
	inline void setMode(uint16 clkdiv, uint16 cpol, uint16 cpha, uint16 msbfirst) {
		//SPI_setMode(port, clkdiv, cpol, cpha, msbfirst);
	}
	
};

//sextern SPI SPIBus1();

/*
void SPIClass::attachInterrupt() {
  SPCR |= _BV(SPIE);
}

void SPIClass::detachInterrupt() {
  SPCR &= ~_BV(SPIE);
}
*/

#endif
