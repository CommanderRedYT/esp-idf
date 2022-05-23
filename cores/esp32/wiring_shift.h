#pragma once

#define LSBFIRST 0
#define MSBFIRST 1

#include <stdint.h>

uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder);
void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);
