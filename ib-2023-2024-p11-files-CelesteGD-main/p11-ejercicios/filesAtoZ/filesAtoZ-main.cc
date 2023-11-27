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

#include "filesAtoZ.h"

void PrintProgramPurpose() {
  std::cout << "lee un fichero de texto que se le pase como parámetro y produzca como salida "
	    << "ficheros con nombre A.txt, B.txt, ..., Z.txt. Cada uno de esos ficheros ha de "
	    << "contener en líneas separadas todas las palabras del fichero pasado como "
	    << "parámetro que comiencen por la correspondiente letra." << std::endl;
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
  // Vector de vectores de palabras, uno por cada letra del alfabeto
  std::vector<std::vector<std::string>> palabrasPorLetra(26);
  std::string palabra;

  // Leer palabras del archivo de entrada
  while (archivoEntrada >> palabra) {
      // Asegurarse de que la palabra tiene al menos una letra
      if (!palabra.empty()) {
          char primeraLetra = std::toupper(palabra[0]); // Convertir a mayúscula
          if (std::isalpha(primeraLetra)) {
              // Obtener el índice correspondiente a la letra
              int indice = primeraLetra - 'A';
              palabrasPorLetra[indice].push_back(palabra);
          }
      }
  }

  // Cerrar el archivo de entrada
  archivoEntrada.close();

  // Crear y escribir archivos de salida
  for (int i = 0; i < 26; ++i) {
      char letra = 'A' + i;
      std::string nombreArchivoSalida = obtenerNombreArchivo(letra);

      // Ordenar las palabras alfabéticamente
      std::sort(palabrasPorLetra[i].begin(), palabrasPorLetra[i].end());

      // Abrir el archivo de salida
      std::ofstream archivoSalida(nombreArchivoSalida);
      if (!archivoSalida.is_open()) {
          std::cerr << "No se pudo abrir el archivo de salida: " << nombreArchivoSalida << std::endl;
          return 1; // Código de error
      }
      // Escribir las palabras en el archivo de salida
      for (const std::string& palabra : palabrasPorLetra[i]) {
          archivoSalida << palabra << '\n';
      }

      // Cerrar el archivo de salida
      archivoSalida.close();

      std::cout << "Archivo " << nombreArchivoSalida << " creado con éxito." << std::endl;
  }

  return 0;
}

