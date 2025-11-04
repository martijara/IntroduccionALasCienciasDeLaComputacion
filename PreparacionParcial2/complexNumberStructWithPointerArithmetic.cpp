// Complex Number Struct with Pointer Arithmetic

// Define a struct for complex numbers, write functions using pointers that add, subtract, and 
// print complex numbers.
#include <iostream>

struct Complejo {
    double real = 0;
    double imaginario = 0;
};

Complejo sumarComplejos(Complejo numero1, Complejo numero2) {
    Complejo resultado;
    resultado.real = numero1.real + numero2.real;
    resultado.imaginario = numero1.imaginario + numero2.imaginario;

    return resultado;
}

Complejo restarComplejos(Complejo numero1, Complejo numero2) {
    Complejo resultado;
    resultado.real = numero1.real - numero2.real;
    resultado.imaginario = numero1.imaginario - numero2.imaginario;

    return resultado;
}

void imprimirComplejos(Complejo complejo) {
    std::cout << complejo.real << " + " << complejo.imaginario << "i" << std::endl;
}

int main() {
    Complejo complejo1;
    complejo1.real = 10;
    complejo1.imaginario = 3;

    Complejo complejo2;
    complejo2.real = 6;
    complejo2.imaginario = 4;

    Complejo resultadoSuma = sumarComplejos(complejo1, complejo2);
    Complejo resultadoResta = restarComplejos(complejo1, complejo2);

    imprimirComplejos(resultadoSuma);
    imprimirComplejos(resultadoResta);

    return 0;
}
