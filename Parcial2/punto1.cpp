#include <iostream>

float calcularImpuestoEnCOP(int baseGravableEnCOP) {
    float baseGravableEnUVT = baseGravableEnCOP/28278; // 1 UVT = 28279 COP -> 1/28279 UVT = 1 COP
    float impuestoEnUVT = 0;
    std::cout << "Su base gravable en UVT es: " << baseGravableEnUVT << std::endl << std::endl;

    if (baseGravableEnUVT >= 0 && baseGravableEnUVT <= 1090) {
        std::cout << "Su rango esta entre 0 UVT y 1090 UVT" << std::endl << std::endl;
        impuestoEnUVT = 0;

    } 
    else if (baseGravableEnUVT > 1090 && baseGravableEnUVT <= 1600) {
        std::cout << "Su rango esta entre 1090 UVT y 1600 UVT" << std::endl << std::endl;
        impuestoEnUVT = (baseGravableEnUVT - 1090)*0.18;

    }
    else if (baseGravableEnUVT > 1600 && baseGravableEnUVT <= 4200) {
        std::cout << "Su rango esta entre 1600 UVT y 4200 UVT" << std::endl << std::endl;
        impuestoEnUVT = (baseGravableEnUVT - 1600)*0.29 + 110;
    }
    else if (baseGravableEnUVT > 4200) {
        std::cout << "Su rango esta en mas de 4200 UVT" << std::endl << std::endl;
        impuestoEnUVT = (baseGravableEnUVT - 4200)*0.33 + 878;
    }

    float impuestoEnCOP = 28279*impuestoEnUVT;

    return impuestoEnCOP;
}

int main() {
    float baseGravableEnCOP;

    std::cout << "Bienvenido al programa de calcular su impuesto gravable en COP. Ingrese su valor en COP: ";
    std::cin >> baseGravableEnCOP;

    std::cout << std::endl << std::endl;

    float impuestoGravable = calcularImpuestoEnCOP(baseGravableEnCOP);

    std::cout << "Su impuesto gravable es: " << impuestoGravable << " COP" << std::endl << std::endl;


    return 0;
}