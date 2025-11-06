#include <iostream>
#include <cmath>
#include <random>
#include <cstdlib>
#include <fstream>

#define N_MAX 20
#define A_MAX 28
#define A_MIN 5

void crearFichero(int A[N_MAX][N_MAX], int n) {
    std::ofstream fichero("archivo.txt");
    if (!fichero) {
        std::cerr << "Failed to open file for writing.";
        return;
    }

    fichero << "Matriz aleatoria\n"; // Titulo
    fichero << n << " " << n << "\n"; // Dimensiones

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fichero << A[i][j] << "\t";
        }
        fichero << "\n";
    }

    fichero << "\n\n";

    for (int i = 0; i < n; i++) {
        int sumaFilas = 0;
        int sumaColumnas = 0;

        for (int j = 0; j < n; j++) {
            sumaFilas = sumaFilas + A[i][j];
            sumaColumnas = sumaColumnas + A[j][i];
        }
        fichero << "Suma de elementos fila # " << i + 1 << ": " << sumaFilas << "\n";
        fichero << "Suma de elementos columna # " << i + 1<< ": " << sumaColumnas << "\n";
        fichero << "Suma total de fila y columna # " << i + 1<< ": " << sumaFilas + sumaColumnas << "\n\n";        
    }

    fichero.close();

}

// Generador de enteros aleatorios inclusivo [min,max]
int numeroAleatorio(int min, int max) {
    if (min > max) std::swap(min, max);
    thread_local static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

void crearMatriz(int A[][N_MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = numeroAleatorio(A_MIN, A_MAX);
        }
    }
}

int main() {
    int n = 0;
    std::cout << "Porfavor inserte el numero n (entre 2 y " << N_MAX << ") de la matriz n*n: ";
    std::cin >> n;

    int A[N_MAX][N_MAX];
    crearMatriz(A, n);
    crearFichero(A, n);

    return 0;
}