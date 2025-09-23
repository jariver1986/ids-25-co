// src/leds.h
#ifndef LEDS_H
#define LEDS_H

#include <stdint.h>

void LedsInitDriver(uint16_t * puerto_virtual);
void LedsTurnOn(int led);
void LedsTurnOff(int led);
void LedsTurnOnAll(void);
void LedsTurnOffAll(void);

#endif
