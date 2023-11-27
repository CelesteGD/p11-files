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

#include "rotate.h"

void PrintProgramPurpose() {
  std::cout << "Rota las vocales en minúscula que encuentre en el fichero que se le pase como parámetro por línea de comandos"; 
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
      std::cerr << "Uso: " << argv[0] << " <nombre_de_archivo>" << std::endl;
      return 1; // Código de error
  }

  // Abrir el archivo de entrada
  std::ifstream archivoEntrada(argv[1]);
  if (!archivoEntrada.is_open()) {
      std::cerr << "No se pudo abrir el archivo de entrada: " << argv[1] << std::endl;
      return 1; // Código de error
  }

  // Crear un nombre para el archivo de salida
  std::string nombreArchivoSalida = std::string(argv[1]) + "_rotado.txt";

  // Abrir el archivo de salida
  std::ofstream archivoSalida(nombreArchivoSalida);
  if (!archivoSalida.is_open()) {
      std::cerr << "No se pudo abrir el archivo de salida: " << nombreArchivoSalida << std::endl;
      return 1; // Código de error
  }

  std::string linea;

  // Leer cada línea del archivo de entrada
  while (std::getline(archivoEntrada, linea)) {
      std::string lineaRotada = rotarVocalesEnPalabra(linea);
      archivoSalida << lineaRotada << '\n';
  }

  // Cerrar archivos
  archivoEntrada.close();
  archivoSalida.close();

  std::cout << "Rotación completada. Resultado en: " << nombreArchivoSalida << std::endl;

  return 0;
}



