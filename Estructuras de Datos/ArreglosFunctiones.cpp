#include <iostream>
#include <cmath>

void proc1(int A[], int n) { // Objetivo -> Devolver el arreglo 
    for (int i = 0; i < n; i++) {
        A[i] = std::pow(i, 2);
    }
}

void imprimirArreglo(int n, int A[]) {
    for (int i = 0; i < n; i++) {
        std::cout << A[i] << " , ";
    }
    std::cout << std::endl;
}

// Leer arreglo
void leerArreglo(int n, int A[]) {
    for (int i = 0; i < n; i++) {
        std::cout << "Entre componente " << i << " : ";
        std::cin >> A[i];
    }
}

int main()
{
    int tamanoArreglo;
    std::cout << "Entre el numero de componentes del arreglo a crear: ";
    std::cin >> tamanoArreglo;   
    int B[tamanoArreglo];
    leerArreglo(tamanoArreglo, B);
    imprimirArreglo(tamanoArreglo, B);

    return 0;
}