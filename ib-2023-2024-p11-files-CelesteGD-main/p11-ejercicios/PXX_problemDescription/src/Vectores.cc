#include <iostream>
#include <fstream>
#include <vector>

int main() {
    // Nombre de los archivos de entrada y salida
    const std::string inputFile = "entrada.txt";
    const std::string outputFile = "salida.txt";

    // Abrir el archivo de entrada
    std::ifstream input(inputFile);

    if (!input.is_open()) {
        std::cerr << "Error al abrir el archivo de entrada: " << inputFile << std::endl;
        return 1;
    }

    // Abrir el archivo de salida
    std::ofstream output(outputFile);

    if (!output.is_open()) {
        std::cerr << "Error al abrir el archivo de salida: " << outputFile << std::endl;
        return 1;
    }

    // Leer y procesar cada línea del archivo de entrada
    std::string line;
    while (std::getline(input, line)) {
        std::vector<int> vector;

        // Utilizar un stringstream para separar los números de la línea
        std::istringstream iss(line);
        int num;

        // Leer la longitud del vector
        iss >> num;

        // Leer los elementos del vector y escribirlos al archivo de salida
        while (iss >> num) {
            vector.push_back(num);
        }

        // Escribir el vector al archivo de salida
        for (int i : vector) {
            output << i << " ";
        }

        output << std::endl;
    }

    // Cerrar los archivos
    input.close();
    output.close();

    std::cout << "Proceso completado. Resultados escritos en " << outputFile << std::endl;

    return 0;
}

