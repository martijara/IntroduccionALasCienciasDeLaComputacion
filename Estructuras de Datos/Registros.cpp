#include <iostream>

// Que es un registro? 
// Es una estructura que permite agrupar datos bajo un mismo nombre
struct Registro {
    int propiedad1;
    char propiedad2[20];
    float propiedad3;
};

// Se pueden hacer registros que representen objetos
struct Estudiante {
    int id;
    float promedio;
};

// Tambien se pueden anidar registros
struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Persona {
    char nombre[50];
    Fecha FechaDeNacimiento;
};

int main()
{
    // Inicializamos un registro
    Registro registro1;
    
    // Inicializamos las propiedades de ese registro
    registro1.propiedad1 = 101;
    registro1.propiedad3 = 750.50;
    
    // Imprimimos una propiedad del registro
    std::cout << "Codigo del registro1: " << registro1.propiedad1 << std::endl;
    
    
    // Inicializamos un registro al principio de declaracion
    Estudiante estudiante1 = {15452, 4.84};
    
    // Imprimimos ambas propiedades del registro
    std::cout << "El estudiante " << estudiante1.id << " tiene promedio " << estudiante1.promedio << std::endl;
    

    return 0;
}