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

#include "rotate.h"

// Función para rotar una vocal en minúscula
char rotarVocal(char vocal) {
  switch (vocal) {
      case 'a': return 'e';
      case 'e': return 'i';
      case 'i': return 'o';
      case 'o': return 'u';
      case 'u': return 'a';
      default: return vocal;
  }
}

// Función para rotar las vocales en una palabra
std::string rotarVocalesEnPalabra(const std::string& palabra) {
  std::string palabraRotada = palabra;
  for (char& c : palabraRotada) {
      if (std::islower(c) && (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) {
          c = rotarVocal(c);
      }
  }
  return palabraRotada;
}

