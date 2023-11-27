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

#include "cripto.h"

// Función para encriptar/desencriptar usando el cifrado XOR
std::string cifradoXOR(const std::string& texto, const std::string& clave) {
    std::string resultado = texto;
    for (size_t i = 0; i < texto.length(); ++i) {
        resultado[i] = texto[i] ^ clave[i % clave.length()];
    }
    return resultado;
}

// Función para encriptar/desencriptar usando el cifrado de César
std::string cifradoCesar(const std::string& texto, int k) {
    std::string resultado = texto;
    for (char& c : resultado) {
        if (std::isalpha(c)) {
            char base = (std::isupper(c)) ? 'A' : 'a';
            c = (c - base + k + 26) % 26 + base;
        }
    }
    return resultado;
}

