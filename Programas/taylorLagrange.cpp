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