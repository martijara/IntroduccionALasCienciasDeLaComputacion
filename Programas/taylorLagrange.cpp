#include <iostream>
#include <cmath>
#include <random>
#include <cstdlib>

#define COL_MAX 2

//randomNumber = min + (rand()%(max - min + 1))
double randomDouble(double min, double max) {
    static std::random_device rd;
    static std::mt19937 gen(rd()); // Mersenne semilla

    std::uniform_real_distribution<double> dist(min, max);
    return dist(gen);
}

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

// Programa de series de Taylor para ln(x)

int factorial(int n) {
    int factorial = 1;
    for (int i = 2; i <= n; i++) {
        factorial = factorial * i;
    }

    return factorial;
}

// sin(a) + cos(a)(x-a) + [-sin(a)*(x-a)^2]/2! + [-cos(a)*(x-a)^3]/3! + [sin(a)*(x-a)^4]/4! + ....
double derivadaSenoTaylor(int n, double a) {
    if (n % 4 == 0) {
        return sin(a);
    } 
    else if (n % 4 == 1) {
        return cos(a);
    }
    else if (n % 4 == 2) {
        return -sin(a);
    }
    else { // n % 4 == 3
        return -cos(a);
    }
}

// DERIVADA NUMERICA
double derivadaNumerica(int n) {
    for (int j = 0; j <= n; i++) {
        
    }
}

// derivada de sin(x) = cos(x)
// derivada de cos(x) = -sin(x)

// f(x) + f'(x)

// f(a) + f'(a)(x-a) + [f''(a)*(x-a)^2]/(2!) + ... + [f'''...k veces...''(a)*(x-a)^k]/(k!)
double funcionTaylor(double x, int n, double a) {
    double resultado = 0.0;

    for (int i = 0; i <= n; i++) {
        resultado += (derivadaSenoTaylor(i, a) * pow(x - a, i)) / factorial(i);
    }
    return resultado;
}

void randomMatrizAsignacion(int n, double A[][COL_MAX]) {
    for (int i = 0; i < n; i++) {
        A[i][0] = randomDouble(0.2, 3.14/3);
        A[i][1] = sin(A[i][0]);
    }
}

void imprimirResultados(double x, int n, double a, double A[][COL_MAX]) {
        double lagrange = interpolacionDeLagrange(x, A, n); 
        double taylor = funcionTaylor(x, n, a);

        
        std::cout << std::endl << std::endl << "RESULTADO" << std::endl;
        std::cout << "__________" << std::endl;
        std::cout << "Para x: " << x << " -> ";
        std::cout << "sin(x): " << sin(x) << ", ";
        std::cout << "L(x): " << lagrange << ", ";
        std::cout << "T(x, a): " << taylor << ", ";
        std::cout << std::endl << std::endl;
}


int main() {
    int n;
    double a;
    double x;

    std::cout << "Bienvenido al programa que calcula el polinomio de Taylor Lagrange" << std::endl << std::endl;
    std::cout << "Porfavor, digita tu valor de n entre 10 y 20: ";
    std::cin >> n;
    std::cout << std::endl << "Porfavor digita tu valor de a entre 0.3 y 0.5: ";
    std::cin >> a;
    std::cout << std::endl << "Porfavor digita tu valor de x entre 0.2 y pi/3: ";
    std::cin >> x;

    double A[n][COL_MAX];
    randomMatrizAsignacion(n, A);
    
    imprimirResultados(x, n, a, A);

    return 0;
}

/*
 * This C++ file demonstrates how to compute Taylor and Lagrange polynomial approximations.
 * 
 * Overview:
 * 1. Taylor Approximation:
 *    - Approximate a function f(x) near a point a using derivatives of f at a.
 *    - The n-th order Taylor polynomial at point a is:
 *      
 *      P_n(x) = f(a) + f'(a)(x-a) + f''(a)/2!(x-a)^2 + ... + f^n(a)/n!(x-a)^n
 *
 *    - Requires the function values and its derivatives at a.
 *    - Good for smooth functions with known derivatives.
 *
 * 2. Lagrange Interpolation Polynomial:
 *    - Given a set of points (x_i, y_i), construct a polynomial that passes through all points.
 *    - The Lagrange polynomial L(x) is:
 *      
 *      L(x) = Σ y_i * l_i(x),  i=0..n
 *
 *      where l_i(x) = Π (x - x_j) / (x_i - x_j),  j=0..n, j≠i
 * 
 *    - Does not require derivatives, only function values at given points.
 *
 * Step-by-step to compute Taylor polynomial:
 * 1) Choose expansion point a.
 * 2) Calculate f(a) and derivatives f'(a), f''(a), ... up to order n.
 * 3) Compute factorial values for denominators.
 * 4) Evaluate polynomial P_n(x) for the desired x.
 *
 * Step-by-step to compute Lagrange polynomial:
 * 1) Select n+1 data points (x_i, y_i).
 * 2) For each i, construct basis polynomial l_i(x) by multiplying terms (x - x_j)/(x_i - x_j) where j != i.
 * 3) Sum up y_i * l_i(x) for all i.
 *
 * Main derivatives for common functions used in approximations:
 *
 * Trigonometric functions:
 * - d/dx sin(x) = cos(x)
 * - d/dx cos(x) = -sin(x)
 * - d/dx tan(x) = 1 / cos^2(x) = sec^2(x)
 *
 * Logarithmic function:
 * - d/dx ln(x) = 1 / x
 * 
 * Higher order derivatives follow known periodic or recursive patterns, for example:
 * - n-th derivative of sin(x) cycles every 4 derivatives:
 *   sin(x), cos(x), -sin(x), -cos(x), sin(x), ...
 * 
 * - n-th derivative of ln(x):
 *   f'(x) = 1/x,
 *   f''(x) = -1/x^2,
 *   f'''(x) = 2/x^3,
 *   f^(4)(x) = -6/x^4, and so forth,
 *   following the pattern (-1)^(n-1) * (n-1)! / x^n
 *
 * Usage tips:
 * - Taylor approximation works best near the expansion point a.
 * - Lagrange interpolation is useful when function values are given at discrete points without derivative info.
 * - Beware of polynomial degree increase causing oscillations ("Runge phenomenon") especially for Lagrange.
 *
 */