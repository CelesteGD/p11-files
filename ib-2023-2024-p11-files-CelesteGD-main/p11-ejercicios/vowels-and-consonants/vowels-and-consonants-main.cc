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

#include "vowels-and-consonants.h"

void PrintProgramPurpose() {
  std::cout << "Este programa imprime en pantalla la palabra con mayor número de vocales "
	    << "y la palabra con el mayor número de consonantes (independientemente de si "  
	    << "se trata de mayúsculas o minúsculas) que se encuentren en un fichero de "
	    << "texto que se le pase como parámetro por línea de comandos. En caso de empate "
	    << "(haya varias palabras con igual número de vocales/consonantes) el programa " 
	    << "imprimirá la palabra que aparezca antes en el fichero de texto." << std::endl;
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

    // Abrir el archivo
    std::ifstream archivo(argv[1]);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << argv[1] << std::endl;
        return 1; // Código de error
    }

    std::string palabra;
    std::string palabraMaxVocales;
    std::string palabraMaxConsonantes;
    int maxVocales = -1;
    int maxConsonantes = -1;

    // Leer palabras del archivo
    while (archivo >> palabra) {
        int numVocales = contarVocales(palabra);
        int numConsonantes = contarConsonantes(palabra);

        // Actualizar la palabra con más vocales
        if (numVocales > maxVocales || (numVocales == maxVocales && palabra < palabraMaxVocales)) {
            maxVocales = numVocales;
            palabraMaxVocales = palabra;
        }

        // Actualizar la palabra con más consonantes
        if (numConsonantes > maxConsonantes || (numConsonantes == maxConsonantes && palabra < palabraMaxConsonantes)) {
            maxConsonantes = numConsonantes;
            palabraMaxConsonantes = palabra;
        }
    }

    // Mostrar resultados
    std::cout << "Palabra con más vocales: " << palabraMaxVocales << " (" << maxVocales << " vocales)" << std::endl;
    std::cout << "Palabra con más consonantes: " << palabraMaxConsonantes << " (" << maxConsonantes << " consonantes)" << std::endl;

    // Cerrar el archivo
    archivo.close();

    return 0;
}

