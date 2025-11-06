#include <iostream>
#include <algorithm>


struct Rectangulo {
    int x1, y1;
    int x2, y2;
};

bool seIntersectan(const Rectangulo& r1, const Rectangulo& r2, Rectangulo& interseccion) {
    interseccion.x1 = std::max(r1.x1, r2.x1);
    interseccion.x2 = std::min(r1.x2, r2.x2);

    interseccion.y1 = std::max(r1.y1, r2.y1);
    interseccion.y2 = std::min(r1.y2, r2.y2);

    return (interseccion.x1 <= interseccion.x2) && (interseccion.y1 <= interseccion.y2);
}

int main() {
    Rectangulo r1;
    Rectangulo r2;
    Rectangulo interseccion;

    std::cout << "Primer Rectangulo";
    std::cout << "Punto x1: ";
    std::cin >> r1.x1;
    std::cout << "Punto y1: ";
    std::cin >> r1.y1;

    std::cout << "Punto x2: ";
    std::cin >> r1.x2;
    std::cout << "Punto y2: ";
    std::cin >> r1.y2;

    std::cout << std::endl << std::endl;
    std::cout << "Segundo Rectangulo";
    std::cout << "Punto x1: ";
    std::cin >> r2.x1;
    std::cout << "Punto y1: ";
    std::cin >> r2.y1;

    std::cout << "Punto x2: ";
    std::cin >> r2.x2;
    std::cout << "Punto y2: ";
    std::cin >> r2.y2;

    bool hayInterseccion = seIntersectan(r1, r2, interseccion);
    if (hayInterseccion) {
        std::cout << "Hay interseccion.\n";
        std::cout << "Interseccion: (" << interseccion.x1 << ", " << interseccion.y1 << ") - ("
                  << interseccion.x2 << ", " << interseccion.y2 << ")\n";
        if (interseccion.x1 == interseccion.x2 && interseccion.y1 == interseccion.y2) {
            std::cout << "Interseccion puntual en (" << interseccion.x1 << ", " << interseccion.y1 << ")\n";
        } else if (interseccion.x1 == interseccion.x2) {
            std::cout << "Interseccion segmento vertical x=" << interseccion.x1 << " y en [" << interseccion.y1 << "," << interseccion.y2 << "]\n";
        } else if (interseccion.y1 == interseccion.y2) {
            std::cout << "Interseccion segmento horizontal y=" << interseccion.y1 << " x en [" << interseccion.x1 << "," << interseccion.x2 << "]\n";
        } else {
            std::cout << "Interseccion area positiva.\n";
        }
    } else {
        std::cout << "No hay interseccion.\n";
    }

    return 0;
}


