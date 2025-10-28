#include <iostream>
#include <cmath>
#include <random>


// Programa de series de Taylor para ln(x)

int factorial(int n) {
    int factorial = 1;
    for (int i = 2; i <= n; i++) {
        factorial = factorial * n;
    }

    return factorial;
}

// sin(a) + cos(a)(x-a) + [-sin(a)*(x-a)^2]/2! + [-cos(a)*(x-a)^3]/3! + [sin(a)*(x-a)^4]/4! + ....
double derivadaSenoTaylor(int n, int a) {
    if (n % 4 == 0) {
        return sin(a);
    } 
    else if (n % 4 == 1) {
        return cos(a);
    }
    else if (n % 4 == 2) {
        return -sin(a);
    }
    else if (n % 4 == 3) {
        return -cos(a);
    }
}

// derivada de sin(x) = cos(x)
// derivada de cos(x) = -sin(x)

// f(x) + f'(x)

// f(a) + f'(a)(x-a) + [f''(a)*(x-a)^2]/(2!) + ... + [f'''...k veces...''(a)*(x-a)^k]/(k!)
double funcionTaylor(double x, int n, double a) {
    int resultado = 0;

    for (int i = 0; i <= n; i++) {
        resultado += (derivadaSenoTaylor(n, a)*pow(x-a, i))/(factorial(i));
    }
    return resultado;
}

int main() {
    return 0;
}