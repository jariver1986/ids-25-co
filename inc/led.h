/************************************************************************************************
Copyright (c) 2025, <tu nombre>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

#ifndef LED_H
#define LED_H

/** \file led.h
 ** \brief API pública para control de un LED genérico.
 **
 ** Este archivo declara la interfaz de un módulo LED independiente de plataforma.
 ** Permite inicializar el LED con funciones de bajo nivel (GPIO) provistas por el usuario
 ** y controlar su estado (encender, apagar, alternar, consultar).
 **
 ** \addtogroup led Módulo LED
 ** \brief Control genérico de LED (on/off/toggle).
 ** @{ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Headers files inclusions ================================================================ */
#include <stdbool.h> /* bool */
#include <stdint.h>  /* tipos estándar */

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */
/** \brief Función de escritura de GPIO.
 *
 * Debe escribir 0/1 en el pin físico del LED.
 * \param level 0 = nivel bajo, 1 = nivel alto.
 * \param ctx   Puntero opaco provisto por el usuario (por ejemplo, puerto/pin).
 */
typedef void (*led_write_fn)(int level, void * ctx);

/** \brief Función de lectura de GPIO.
 *
 * Debe devolver el nivel lógico actual del pin (0/1).
 * \param ctx   Puntero opaco provisto por el usuario (por ejemplo, puerto/pin).
 * \return int  0 = bajo, 1 = alto.
 */
typedef int (*led_read_fn)(void * ctx);

/** \brief Configuración de inicialización del módulo LED. */
typedef struct {
    led_write_fn write; /**< Callback para escribir el pin. */
    led_read_fn read;   /**< Callback para leer el pin. */
    void * ctx;         /**< Contexto opaco para callbacks (ej. puerto/pin). */
    bool active_low;    /**< true si el LED es activo-bajo; false si activo-alto. */
} led_cfg_t;

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */
/** \brief Inicializa el módulo LED con callbacks de GPIO y configuración de actividad.
 *
 * Debe llamarse antes de cualquier otra función del módulo.
 * \param cfg Puntero a la configuración. No se copia; debe permanecer válida.
 * \return true si la configuración es válida; false en caso contrario.
 */
bool led_init(const led_cfg_t * cfg);

/** \brief Enciende el LED (según active_low/active_high). */
void led_on(void);

/** \brief Apaga el LED (según active_low/active_high). */
void led_off(void);

/** \brief Alterna el estado del LED. */
void led_toggle(void);

/** \brief Indica si el LED está encendido lógicamente.
 * \return true si encendido; false si apagado.
 */
bool led_is_on(void);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} End of module definition for doxygen */

#endif /* LED_H */
