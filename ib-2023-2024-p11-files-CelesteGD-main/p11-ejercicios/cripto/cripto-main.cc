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

#include "cripto.h"

void PrintProgramPurpose() {
  std::cout << "Su finalidad es encriptar y/o desencriptar ficheros de texto.";
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
  // Verificar si se proporcionan suficientes argumentos
  if (argc != 6) {
      std::cerr << "Modo de uso: " << argv[0] << " fichero_entrada fichero_salida método password operación" << std::endl;
      std::cerr << "Pruebe " << argv[0] << " --help para más información" << std::endl;
      return 1; // Código de error
  }

  // Verificar si se solicita ayuda
  if (std::string(argv[1]) == "--help") {
      std::cout << "./cripto -- Cifrado de ficheros\n";
      std::cout << "Modo de uso: " << argv[0] << " fichero_entrada fichero_salida método password operación\n\n";
      std::cout << "fichero_entrada: Fichero a codificar\n";
      std::cout << "fichero_salida:  Fichero codificado\n";
      std::cout << "método:          Indica el método de encriptado\n";
      std::cout << "                   1: Cifrado xor\n";
      std::cout << "                   2: Cifrado de César\n";
      std::cout << "password:        Palabra secreta en el caso de método 1, Valor de K en el método 2\n";
      std::cout << "operación:       Operación a realizar en el fichero\n";
      std::cout << "                   +: encriptar el fichero\n";
      std::cout << "                   -: desencriptar el fichero\n";
      return 0;
  }

  // Obtener argumentos
  std::string nombreArchivoEntrada = argv[1];
  std::string nombreArchivoSalida = argv[2];
  int metodo = std::atoi(argv[3]);
  std::string password = argv[4];
  char operacion = argv[5][0];

  // Verificar que el método sea válido
  if (metodo != 1 && metodo != 2) {
      std::cerr << "Error: Método no válido. Debe ser 1 (Cifrado xor) o 2 (Cifrado de César)\n";
      return 1; // Código de error
  }

  // Abrir el archivo de entrada
  std::ifstream archivoEntrada(nombreArchivoEntrada);
  if (!archivoEntrada.is_open()) {
      std::cerr << "Error: No se pudo abrir el archivo de entrada: " << nombreArchivoEntrada << std::endl;
      return 1; // Código de error
  }

  // Leer el contenido del archivo de entrada
  std::stringstream buffer;
  buffer << archivoEntrada.rdbuf();
  std::string contenido = buffer.str();

  // Cerrar el archivo de entrada
  archivoEntrada.close();

  // Realizar la operación de encriptar o desencriptar
  std::string resultado;
  if (metodo == 1) {
      resultado = (operacion == '+') ? cifradoXOR(contenido, password) : cifradoXOR(contenido, password);
  } else if (metodo == 2) {
      int k = std::atoi(password.c_str());
      resultado = (operacion == '+') ? cifradoCesar(contenido, k) : cifradoCesar(contenido, -k);
  }

  // Abrir el archivo de salida
  std::ofstream archivoSalida(nombreArchivoSalida);
  if (!archivoSalida.is_open()) {
      std::cerr << "Error: No se pudo abrir el archivo de salida: " << nombreArchivoSalida << std::endl;
      return 1; // Código de error
  }

  // Escribir el resultado en el archivo de salida
  archivoSalida << resultado;

  // Cerrar el archivo de salida
  archivoSalida.close();

  std::cout << "Operación completada. Resultado en: " << nombreArchivoSalida << std::endl;

  return 0;
}

