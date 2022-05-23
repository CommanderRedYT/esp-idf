#pragma once

#include <stdint.h>

void yield(void);

unsigned long micros();
void delayMicroseconds(uint32_t us);
