#include <iostream>
#include <fstream>
#include <string>
#define MAX_FILAS 10
#define MAX_COLUMNAS 10

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

int main() {
    // Ejemplo educativo de uso de las funciones con matriz tradicional
    std::string nombreArchivo = "matriz.txt";
    int matriz[MAX_FILAS][MAX_COLUMNAS];
    int filas = 2, columnas = 3;
    // Inicializar matriz de ejemplo
    matriz[0][0] = 1; matriz[0][1] = 2; matriz[0][2] = 3;
    matriz[1][0] = 4; matriz[1][1] = 5; matriz[1][2] = 6;
    crearFicheroMatriz(nombreArchivo, matriz, filas, columnas);

    // Leer la matriz del archivo y mostrarla
    int matrizLeida[MAX_FILAS][MAX_COLUMNAS];
    if (leerFicheroMatriz(nombreArchivo, matrizLeida, filas, columnas)) {
        imprimirMatriz(matrizLeida, filas, columnas);
    }

    // Editar un elemento de la matriz en el archivo
    editarElementoFichero(nombreArchivo, 1, 2, 99);

    // Leer y mostrar la matriz editada
    if (leerFicheroMatriz(nombreArchivo, matrizLeida, filas, columnas)) {
        std::cout << "Matriz después de editar:\n";
        imprimirMatriz(matrizLeida, filas, columnas);
    }

    return 0;
}