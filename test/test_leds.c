/*
prender un led y verificar que no cambia el resto
prender un led y apagarlo cualquiera
prender mas de un led, apagar uno y verificar que el resto siguen sin cambiod
prender un led y apagarlo en ambos extremos
inciar el driver y revisar que todos los leds esten apagados
prender todos los leds
prender y apagar todos los leds
prender algunos leds mas de una vez y verificar que sigue prendido
apagar algunos leds mas de una vez y verificar que siguen apagados
prender algunos leds, despues prender todos y comprobar que todos los leds quedan prendidos
prender todos, apagar algunos, apagar todos y comprobar que todos los leds quedan apagados
consultar el estado de un led encendido y comprobar que es correcto
consultar el estado de un led apagado y comprobar que es correcto
tratar de manipular un led fuera de rango y comprobar que se genera un error
*/

#include "unity.h"
#include "leds.h"
void setUp(void) {
}

void tearDown(void) {
}

/* void test_inicial(void) {
    TEST_FAIL_MESSAGE("Arrancamos...");
} */

void test_al_iniciar_todos_los_leds_estan_apagados(void) {
    uint16_t puerto_virtual = 0xFFFF; // mock

    LedsInitDriver(&puerto_virtual);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}