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

/** \file led.c
 ** \brief Implementación del módulo LED genérico.
 **
 ** Este archivo implementa el control de un LED usando callbacks de GPIO provistos por el usuario.
 ** Es independiente de plataforma (STM32, AVR, POSIX GPIO, etc.).
 **
 ** \addtogroup led
 ** @{ */

/* === Headers files inclusions =============================================================== */
#include "led.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */
static const led_cfg_t * s_cfg = 0;
static bool s_led_on = false; /* Estado lógico del LED (true = encendido) */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */
bool led_init(const led_cfg_t * cfg) {
    if (!cfg || !cfg->write || !cfg->read) {
        return false;
    }
    s_cfg = cfg;
    /* Inicialmente lo apagamos de forma lógica */
    s_led_on = false;
    /* Aplicar al pin físico según sea activo-bajo o activo-alto */
    if (s_cfg->active_low) {
        s_cfg->write(1, s_cfg->ctx); /* activo-bajo: 1 = apagado */
    } else {
        s_cfg->write(0, s_cfg->ctx); /* activo-alto: 0 = apagado */
    }
    return true;
}

void led_on(void) {
    if (!s_cfg)
        return;
    s_led_on = true;
    if (s_cfg->active_low) {
        s_cfg->write(0, s_cfg->ctx); /* activo-bajo: 0 = encendido */
    } else {
        s_cfg->write(1, s_cfg->ctx); /* activo-alto: 1 = encendido */
    }
}

void led_off(void) {
    if (!s_cfg)
        return;
    s_led_on = false;
    if (s_cfg->active_low) {
        s_cfg->write(1, s_cfg->ctx); /* activo-bajo: 1 = apagado */
    } else {
        s_cfg->write(0, s_cfg->ctx); /* activo-alto: 0 = apagado */
    }
}

void led_toggle(void) {
    if (!s_cfg)
        return;
    if (s_led_on) {
        led_off();
    } else {
        led_on();
    }
}

bool led_is_on(void) {
    if (!s_cfg)
        return false;
    /* Devolvemos el estado lógico que ofrece la API del módulo,
       no el nivel eléctrico directamente. */
    return s_led_on;
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
