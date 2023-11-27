/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Celeste González Díaz
 * @date 27 Nov 2023
 * @contact alu0101648361@ull.edu.es
 * @brief functions that we will use in our main
 */

#include "filesAtoZ.h"

// Función para obtener el nombre del archivo de salida para una letra
std::string obtenerNombreArchivo(char letra) {
    return std::string(1, letra) + ".txt";
}
