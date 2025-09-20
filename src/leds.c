#include "leds.h"
#include <stdbool.h>
static uint16_t * puerto = 0;
void LedsInitDriver(uint16_t * puerto_virtual) {
    puerto = puerto_virtual; // <— ¡asigna el puntero global!
    *puerto = 0x0000;        // todos apagados
}

void LedsTurnOn(int led) {
    *puerto = 1 << 2;
}