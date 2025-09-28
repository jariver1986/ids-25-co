#ifndef ERRORES_H
#define ERRORES_H

#define Alerta(mensaje) RegistrarMensaje(ALERTA, _FUNCTION_, __LINE__, mensaje)

typedef enum gravedad_e {
    ERROR,       //!< Mensaje de error
    ALERTA,      //!< Mensaje de alerta
    INFORMACION, //!< Mensaje de informacion
    DEPURACION,  //!< Mensaje de depuracion
} gravedad_t;

/**
 * @brief Funcion para registrar un mensaje en la bitacora de errores del sistema
 *
 * @param gravedad  Nivel de gravedad del mensaje registrado
 * @param funcion   Funcion que realiza el registro del mensaje
 * @param linea     Linea del codigo fuente en la que se llama al registro del mensaje
 * @param mensaje   Cadena de caracteres con el mensaje que se desea registrar
 */
void RegistrarMensaje(gravedad_t gravedad, const char * funcion, int linea, const char * mensaje);

#endif
