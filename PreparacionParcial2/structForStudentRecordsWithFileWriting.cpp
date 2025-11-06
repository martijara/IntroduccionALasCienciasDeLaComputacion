// Struct for Student Records with File Writing

// Define a struct for a student (name, ID, grade). Create an array of students, write their data
// into a text file using pointers to the structs, then read and display the records.

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

struct Estudiantes {
    std::string nombre;
    int id;
    int grado;
};

void escribirEstudiantes(Estudiantes A[], int n) {
    int colWidth = 30;
    Estudiantes* p = A;

    std::ofstream fichero("estudiantes1.txt");

    if (!fichero.is_open()) {
        std::cerr << "Error";

        return;
    }

    // Escribir encabezado
    fichero << std::setw(colWidth) << "ID"
              << std::setw(colWidth) << "Nombre"
              << std::setw(colWidth) << "Grado" << "\n";

    for (int i = 0; i < n; i++) {
        fichero << std::setw(colWidth)
                  << std::fixed << std::setprecision(6)
                  << std::setw(colWidth) << (p + i)->id
                  << std::setw(colWidth) << (p + i)->nombre
                  << std::setw(colWidth) << (p + i)->grado
                  << "\n";
    }

    fichero.close();

}

void leerEstudiantes(Estudiantes B[]) {
    std::ifstream inFile("estudiantes.txt");
    if (!inFile) {
        std::cerr << "Failed to open file for reading.";
        return;
    }

    std::string encabezado;
    getline(inFile, encabezado); // Leer e ignorar encabezado
    
    // int r, c;
    // inFile >> r >> c; // Read rows and columns

    for (int i = 0; i < 3; i++) {
        Estudiantes estudiante;
        inFile >> estudiante.id >> estudiante.nombre >> estudiante.grado;
        B[i] = estudiante;
        }

    inFile.close();
    }



int main() {
    Estudiantes estudiante1;
    estudiante1.nombre = "David";
    estudiante1.id = 1324;
    estudiante1.grado = 10;

    Estudiantes estudiante2;
    estudiante2.nombre = "Ismael";
    estudiante2.id = 1534;
    estudiante2.grado = 5;

    Estudiantes estudiante3;
    estudiante3.nombre = "Agustin";
    estudiante3.id = 2135;
    estudiante3.grado = 11;

    Estudiantes A[3] = {estudiante1, estudiante2, estudiante3};
    Estudiantes B[3];

    leerEstudiantes(B);
    escribirEstudiantes(B, 3);


    return 0;
}