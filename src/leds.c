#include "leds.h"
#include <stdbool.h>
#include "errores.h"

#define ALL_LED_OFF       0x0000
#define ALL_LED_ON        0xFFFF
#define FIRST_BIT         1
#define LED_TO_BIT_OFFSET 1

static uint16_t * puerto = 0;

static uint16_t LedToMask(int led) {
    return FIRST_BIT << (led - LED_TO_BIT_OFFSET);
}

void LedsInitDriver(uint16_t * puerto_virtual) {
    puerto = puerto_virtual; // <— ¡asigna el puntero global!
    *puerto = ALL_LED_OFF;   // todos apagados
}

void LedsTurnOn(int led) {
    if (led < 1 || led > 16) {
        RegistrarMensaje(ALERTA, __FUNCTION__, __LINE__, "El led no es valido");
        return;
    }
    *puerto |= LedToMask(led);
}

void LedsTurnOff(int led) {
    *puerto &= ~LedToMask(led);
}

void LedsTurnOnAll(void) { // <-- agregar
    *puerto = ALL_LED_ON;
}

// leds.c
void LedsTurnOffAll(void) { // <-- nuevo
    *puerto = ALL_LED_OFF;  // pone los 16 bits en 0
}
