/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Celeste González Díaz
 * @date 27 Nov 2023
 * @contact alu0101648361@ull.edu.es
 * @brief main function of our program
 */

#include "read-DFA.h"

void PrintProgramPurpose() {
  std::cout << "Escriba un programa read_DFA.cc que lea un fichero de texto input.dfa " 
	    << "que contiene la especificación de un DFA e imprima en pantalla las características del mismo.";
}

bool CheckCorrectParameters(const int argc, char *argv[], const int kCorrectNumber) {
  if (argc != kCorrectNumber) {
    std::cout << "This program has been executed with a wrong number of parameters" << std::endl << std::endl;
    std::cout << "This program should be called" << argv[0] << std::endl;
    return false;
  }
  return true;
}

int main(int argc, char* argv[]) {
  PrintProgramPurpose();
  // Verificar si se proporciona un nombre de archivo como argumento
  if (argc != 2) {
      std::cerr << "Uso: " << argv[0] << " <input.dfa>" << std::endl;
      return 1; // Código de error
  }

  // Abrir el archivo de entrada
  std::ifstream archivoEntrada(argv[1]);
  if (!archivoEntrada.is_open()) {
      std::cerr << "No se pudo abrir el archivo de entrada: " << argv[1] << std::endl;
      return 1; // Código de error
  }

  // Leer el número total de estados del DFA
  unsigned int numEstados;
  archivoEntrada >> numEstados;

  // Leer el estado de arranque del DFA
  unsigned int estadoArranque;
  archivoEntrada >> estadoArranque;

  // Leer la información de cada estado
  std::vector<Estado> estados(numEstados);
  std::set<unsigned int> estadosAceptacion;

  for (unsigned int i = 0; i < numEstados; ++i) {
      Estado& estado = estados[i];
      estado.id = i;

  // Leer si es un estado de aceptación
  int esAceptacion;
  archivoEntrada >> esAceptacion;
  estado.aceptacion = (esAceptacion == 1);

  // Leer el número de transiciones
  unsigned int numTransiciones;
  archivoEntrada >> numTransiciones;

  // Leer las transiciones
  for (unsigned int j = 0; j < numTransiciones; ++j) {
    char simbolo;
    unsigned int estadoDestino;
    archivoEntrada >> simbolo >> estadoDestino;
    estado.transiciones[simbolo] = estadoDestino;
  }

  // Si el estado es de aceptación, añadirlo al conjunto de estados de aceptación
  if (estado.aceptacion) {
    estadosAceptacion.insert(i);
  }
}

  // Cerrar el archivo de entrada
  archivoEntrada.close();

  // Imprimir las características del DFA
  std::cout << "|Q| = " << numEstados << "\n";
  std::cout << "q0 = " << estadoArranque << "\n";
  imprimirConjuntoAceptacion(estadosAceptacion);

  // Imprimir la función de transición
  for (const Estado& estado : estados) {
      for (const auto& transicion : estado.transiciones) {
          std::cout << "delta(" << estado.id << ", " << transicion.first << ") = " << transicion.second << "\n";
      }
  }

  return 0;
}

