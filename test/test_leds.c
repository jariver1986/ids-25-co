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
agregar prueba para forzar los rangos
*/

#include "unity.h"
#include "leds.h"
#include "stdint.h"
#include "mock_errores.h"

static uint16_t puerto_virtual;

void setUp(void) {
    LedsInitDriver(&puerto_virtual);
}

void tearDown(void) {
}

// Iniciar el driver y verificar que todos los leds esten apagados
void test_al_iniciar_todos_los_leds_estan_apagados(void) {
    uint16_t puerto_virtual = 0xFFFF; // mock

    LedsInitDriver(&puerto_virtual);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}
// prender un led y verificar que no cambia el resto
void test_prender_un_led_y_verificar_que_no_cambia_el_resto(void) {
    // uint16_t puerto_virtual; // la funcion actual ya lo deja definido con un estado

    // LedsInitDriver(&puerto_virtual);
    LedsTurnOn(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 2, puerto_virtual); // o puede escribirse 0x0004 a 1<<2
}

// prender un led cualquiera y apagarlo
void test_prender_un_led_cualquiera_y_apagarlo(void) {
    // uint16_t puerto_virtual;

    // LedsInitDriver(&puerto_virtual);
    LedsTurnOn(5);
    LedsTurnOff(5);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

// prender mas de un led, apagar uno y verificar que el resto siguen sin cambios
void test_prender_mas_de_un_led_apagar_uno_y_verificar_que_el_resto_siguen_sin_cambios(void) {
    LedsTurnOn(3);
    LedsTurnOn(5);
    LedsTurnOff(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 4, puerto_virtual);
}

// tratar de manipular un led fuera de rango y comprobar que se genera un error
void test_tratar_de_apagar_un_led_fuera_de_rango_y_comprobar_que_se_genera_un_error(void) {
    // RegistrarMensaje_Expect(ALERTA, "LedsTurnOn", 0, "EL LED no es valido");
    // RegistrarMensaje_IgnoreArg_linea();
    RegistrarMensaje_ExpectAnyArgs();

    LedsTurnOn(0);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
    RegistrarMensaje_ExpectAnyArgs();
    LedsTurnOn(17);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

void test_tratar_de_encender_un_led_fuera_de_rango_y_comprobar_que_se_genera_un_error(void) {
    // RegistrarMensaje_Expect(ALERTA, "LedsTurnOn", 0, "EL LED no es valido");
    // RegistrarMensaje_IgnoreArg_linea();
    RegistrarMensaje_ExpectAnyArgs();

    LedsTurnOn(0);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
    RegistrarMensaje_ExpectAnyArgs();
    LedsTurnOn(17);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

void test_prender_todos_los_leds_luego_de_cambios_previos(void) {
    RegistrarMensaje_ExpectAnyArgs();
    LedsTurnOn(3);
    LedsTurnOn(7);
    LedsTurnOff(3);
    // estado aquí es solo LED7 encendido
    LedsTurnOnAll();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, puerto_virtual);
}

void apagar_todos_los_leds(void) { // <-- nuevo test
    // Prepara un estado con varios encendidos
    LedsTurnOn(1);
    LedsTurnOn(8);
    LedsTurnOn(16);

    // Acción
    LedsTurnOffAll();

    // Verificación
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

void prender_todos_y_luego_apagar_todos(void) {

    RegistrarMensaje_ExpectAnyArgs();
    RegistrarMensaje_ExpectAnyArgs();

    LedsTurnOnAll();
    LedsTurnOffAll();

    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

void test_consultar_led_encendido(void) {
    LedsTurnOn(5);
    TEST_ASSERT_EQUAL(LED_ON, LedsConsultarEstado(5));
    TEST_ASSERT_TRUE(LedsConsultarLedOn(5));
    TEST_ASSERT_FALSE(LedsConsultarLedOff(5));
}

void test_consultar_led_apagado(void) {
    LedsTurnOff(5);
    TEST_ASSERT_EQUAL(LED_OFF, LedsConsultarEstado(5));
    TEST_ASSERT_TRUE(LedsConsultarLedOff(5));
    TEST_ASSERT_FALSE(LedsConsultarLedOn(5));
}