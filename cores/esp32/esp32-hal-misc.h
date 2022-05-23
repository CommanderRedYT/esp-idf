#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void yield(void);

unsigned long micros();
void delayMicroseconds(uint32_t us);

#ifdef __cplusplus
}
#endif
