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

#include "read-DFA.h"

// Estructura para representar un estado del DFA
struct Estado {
    unsigned int id;
    bool aceptacion;
    std::map<char, unsigned int> transiciones;
};

// Función para imprimir el conjunto de estados de aceptación
void imprimirConjuntoAceptacion(const std::set<unsigned int>& conjunto) {
    std::cout << "F = {";
    for (auto estado : conjunto) {
        std::cout << estado << (estado == *conjunto.rbegin() ? "}\n" : ", ");
    }
}

