// Lagrange Polynomial Interpolation Using Pointers

// Given arrays of points (x, y), write a function using pointers to compute the Lagrange 
// interpolation polynomial and evaluate it at a given value.
#include <iostream>
#define MAX_COL 2

// formula de Base de lagrange: 
// l_j = multiplicacion excepto cuando m = j hasta n de todos los ((x - xm)/(xj - xm))
double baseDeLagrange(double x, double A[][MAX_COL], int n, int j) {
    double base = 1;

    for (int i = 0; i < n; i++) {
        if (i != j) {
            base = base * ( (x - A[i][0]) / (A[j][0] - A[i][0]) );
        }
    }

    return base;
}

// Formula interpolacion de lagrange:
// L = suma de todos los y_j*l_j
double interpolacionLagrange(double x, double A[][MAX_COL], int n) {
    double interpolacion = 0;

    for (int j = 0; j < n; j++) {
        interpolacion += A[j][1]*baseDeLagrange(x, A, n, j);
    }

    return interpolacion;
}

int main() {
    int n = 5;
    double A[n][MAX_COL] = {{0.5, -0.6931}, {1, 0}, {1.23, 0.2070}, {2.05, 0.7178}, {3.41, 1.2267}, {5.32, 1.6714}};
    double resultado = interpolacionLagrange(0.5, A, n);

    std::cout << resultado;


    return 0;
}