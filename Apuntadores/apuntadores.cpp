#include <iostream>

// Esta función recibe una referencia a un entero como parámetro.
// Sin embargo, dentro de la función se declara una nueva variable local llamada 'x',
// lo que genera un error porque ya existe un parámetro con ese nombre.
// Además, la intención parece ser modificar el valor referenciado, pero la variable local 'x' oculta el parámetro.
// El valor retornado es la suma de 'x' (local) más 3.

int f2(int &x) {
    x = 8; // Se asigna 9 a la variable referenciada por 'x'.
    int a = x + 3; // Se declara una variable local 'a' que es la suma de 'x' más 3.
    return a; // Se retorna el valor de 'a'.
}

int main() {
    std::cout << std::endl << std::endl;
    int x = 8;      // Se declara una variable entera 'x' y se inicializa en 8.
    int *p;         // Se declara un apuntador a entero 'p'.

    p = &x;         // El apuntador 'p' almacena la dirección de memoria de 'x'.
    std::cout << f2(*p) << std::endl; // Se llama a la función 'f2' pasando el valor apuntado por 'p'.
                                      // Se imprime el resultado en pantalla

    std::cout << x; // Se imprime el valor de 'x' en pantalla.    
    std::cout << x; // Se imprime el valor de 'x' en pantalla.

    std::cout << std::endl << std::endl;
}