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

#include "vowels-and-consonants.h"

// Función para contar el número de vocales en una palabra
int contarVocales(const std::string& palabra) {
    int contador = 0;
    for (char c : palabra) {
        if (std::tolower(c) == 'a' || std::tolower(c) == 'e' || std::tolower(c) == 'i' || std::tolower(c) == 'o' || std::tolower(c) == 'u') {
            contador++;
        }
    }
    return contador;
}

// Función para contar el número de consonantes en una palabra
int contarConsonantes(const std::string& palabra) {
    int contador = 0;
    for (char c : palabra) {
        if (std::isalpha(c) && !std::tolower(c) == 'a' && !std::tolower(c) == 'e' && !std::tolower(c) == 'i' && !std::tolower(c) == 'o' && !std::tolower(c) == 'u') {
            contador++;
        }
    }
    return contador;
}

