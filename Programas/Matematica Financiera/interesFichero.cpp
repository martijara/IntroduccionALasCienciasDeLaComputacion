#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#define MAX_FILAS 40
#define MAX_COLUMNAS 5

#include <iostream>
#include <iomanip>

void imprimirTabla(int rows, int cols, double data[][2]) {
    int colWidth = 15;

    // Imprimir encabezado
    std::cout << std::setw(colWidth) << "Periodo"
              << std::setw(colWidth) << "Monto"
              << std::setw(colWidth) << "Interes Pagado" 
              << std::setw(colWidth) << "Aporte Capital"
              << std::setw(colWidth) << "Deuda" << "";

    std::cout << std::string(colWidth * cols + colWidth, '-') << "";

    // Imprimir filas
    for (int i = 0; i < rows; i++) {
        std::cout << std::setw(colWidth) << i + 1
                  << std::fixed << std::setprecision(6)
                  << std::setw(colWidth) << data[i][0]
                  << std::setw(colWidth) << data[i][1]
                  << std::setw(colWidth) << data[i][2]
                  << std::setw(colWidth) << data[i][3]
                  << std::setw(colWidth) << data[i][4]
                  << "";
                }
}

// Función para crear un archivo con una matriz y sus dimensiones (matriz tradicional)
void crearFicheroMatriz(const std::string& nombreArchivo, int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas) {
    std::ofstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "Error al crear el archivo.\n";
        return;
    }
    // Escribir dimensiones
    archivo << filas << " " << columnas << "\n";
    // Escribir la matriz
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            archivo << matriz[i][j] << " ";
        }
        archivo << "\n";
    }
    archivo.close();
}

// Función para leer una matriz y sus dimensiones desde un archivo (matriz tradicional)
bool leerFicheroMatriz(const std::string& nombreArchivo, int matriz[MAX_FILAS][MAX_COLUMNAS], int& filas, int& columnas) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo.\n";
        return false;
    }
    archivo >> filas >> columnas;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            archivo >> matriz[i][j];
        }
    }
    archivo.close();
    return true;
}

// Función para editar un elemento de la matriz en el archivo (matriz tradicional)
void editarElementoFichero(const std::string& nombreArchivo, int fila, int columna, int nuevoValor) {
    int matriz[MAX_FILAS][MAX_COLUMNAS];
    int filas, columnas;
    if (!leerFicheroMatriz(nombreArchivo, matriz, filas, columnas)) return;
    if (fila < 0 || fila >= filas || columna < 0 || columna >= columnas) {
        std::cerr << "Índices fuera de rango.\n";
        return;
    }
    matriz[fila][columna] = nuevoValor;
    crearFicheroMatriz(nombreArchivo, matriz, filas, columnas);
}

// Función para imprimir la matriz en consola (matriz tradicional)
void imprimirMatriz(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas) {
    std::cout << "Matriz:\n";
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << "\n";
    }
}

double calcularCuota(double capital, int periodos, double interes) {
    return (capital*interes)/(1-std::pow(1+interes, -(periodos)));
}

void escribirCuotasAFichero(double capital, int periodos, double interes) {
    int colWidth = 30;
    double cuota = calcularCuota(capital, periodos, interes);


    std::ofstream fichero("datos.txt");

    if (!fichero.is_open()) {
        std::cerr << "Error";

        return;
    }

    fichero << "Capital: " << capital << "\n";
    fichero << "Tasa: " << interes << "\n";
    fichero << "Periodos: " << periodos << "\n";
    fichero << "Cuota: " << cuota << "\n" << "\n";

    // Imprimir encabezado
    fichero << std::setw(colWidth) << "Periodo"
              << std::setw(colWidth) << "Monto"
              << std::setw(colWidth) << "Interes Pagado" 
              << std::setw(colWidth) << "Aporte Capital"
              << std::setw(colWidth) << "Deuda" << "\n";

    double monto = capital;

    for (int i = 1; i <= periodos; i++) {
        double interesPagado = interes*monto;
        double aporteCapital = cuota - interesPagado;
        double deuda = monto - aporteCapital;

        fichero << std::setw(colWidth)
                  << std::fixed << std::setprecision(6)
                  << std::setw(colWidth) << i
                  << std::setw(colWidth) << monto
                  << std::setw(colWidth) << interesPagado
                  << std::setw(colWidth) << aporteCapital
                  << std::setw(colWidth) << deuda
                  << "\n";

        monto = deuda;
        
    }

    fichero.close();

}

int main() {
    int periodos;
    double capital, interes;
 
    std::cout << "Bienvenido al Programa de Interes Fichero \n";
    std::cout << std::endl << "Porfavor, entre el numero de periodos de su prestamo: ";
    std::cin >> periodos;
    std::cout << std::endl << "Porfavor, entre el capital que presto: ";
    std::cin >> capital;
    std::cout << std::endl << "Porfavor, defina el interes del prestamo: ";
    std::cin >> interes;
    std::cout << std::endl << std::endl;

    escribirCuotasAFichero(capital, periodos, interes);

    std::cout << "Se ha creado un archivo datos.txt con una tabla que representa la info de su prestamo conforme a las cuotas";

    return 0;
}