/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Celeste González Díaz
 * @date 27 Nov 2023
 * @contact alu0101648361@ull.edu.es
 * @brief Lee un fichero en el cual hay vectores
 *        de número enteros y escribe otro sin
 *        longitud y separados por espacios
 */

#include <iostream>
#include <vector>
#include <fstream> 

/**
 *@brief Esta función mira si se hace buen uso de los parámetros
 *@param Se le pasa los parametros
 *@return Si están bien retorna true si está mal retorna false junto con
 *        el texto Uso: 2 <nombre_de_archivo> 
 */

bool CheckCorrectParameters(const int argc, char *argv[], const int kCorrectNumber) {
  if (argc != kCorrectNumber) {
    std::cerr << "Uso: " << argv[0] << " <nombre_de_archivo>" << std::endl;
    return false;
  }
  return true;
}

/**
 *@brief Esta función mira si el fichero del usuario existe
 *@param Se le pasa el nombre del archivo del usuario
 *@return Como la función es void no retorna nada
 */

void abrirFicheroEntrada(std::string& inputFile) {
  std::ifstream input(inputFile);

  if (!input.is_open()) {
     std::cerr << "Error al abrir el archivo de entrada: " << inputFile << std::endl;
     return 1;
  }
}

void abrirFicheroSalida(std::string& outputFile) 
  std::ofstream output(outputFile);
 
  if (!output.is_open()) {
      std::cerr << "Error al abrir el archivo de salida: " << outputFile << std::endl;
      return 1;
  }
}

/**
 *@brief Función main
 */

int main(int argc, char* argv[])  {
  const std::string inputFile = "entrada.txt";
  const std::string outputFile = "salida.txt";
  std::string line;
  while (std::getline(input, line)) {
      std::vector<int> vector;
  }  

  std::istringstream iss(line);
  int numero;
  iss >> numero;
  while (iss >> numero) {
	std::vector.push_back(numero);
  }

  for (int i : std::vector) {
      output << i << " ";
  }  

 return output;

  input.close();
  output.close();
  std::cout << "Proceso completado. Resultados escritos en " << outputFile << std::endl;

    return 0;
  }
