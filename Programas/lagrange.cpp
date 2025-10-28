#include <iostream>
#define COL_MAX 2

// Polinomio de Lagrange

double polinomiosBaseDeLagrange(double x, int j, int k, double A[][COL_MAX]) {
    double numerador = 1;
    double denominador = 1;

    for (int i = 0; i < k; i++) {
        if (i != j) {
            numerador = numerador * (x - A[i][0]);
            denominador = denominador * (A[j][0] - A[i][0]);
        }
    }

    return numerador/denominador;
}

double interpolacionDeLagrange(double x, double A[][COL_MAX], int n) {
    double suma = 0;

    for (int j = 0; j < n; j++) {
        suma += A[j][1]*polinomiosBaseDeLagrange(x, j, n, A);
    }

    return suma;
}

int main() {
    const int n = 6;
    double A[n][COL_MAX] = {{0.5, -0.6931}, {1, 0}, {1.23, 0.2070}, {2.05, 0.7178}, {3.41, 1.2267}, {5.32, 1.6714}};
    double resultado = interpolacionDeLagrange(0.5, A, n);

    std::cout << "Programa de interpolación de Lagrange: " << resultado << std::endl << std::endl;
    return 0;
}