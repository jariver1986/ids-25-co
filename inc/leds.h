// src/leds.h
#ifndef LEDS_H
#define LEDS_H

#include <stdint.h>

#define LED_OFF 0
#define LED_ON  1

void LedsInitDriver(uint16_t * puerto_virtual);
void LedsTurnOn(int led);
void LedsTurnOff(int led);
void LedsTurnOnAll(void);
void LedsTurnOffAll(void);
int LedsConsultarEstado(int led);
int LedsConsultarLedOn(int led);
int LedsConsultarLedOff(int led);

#endif
