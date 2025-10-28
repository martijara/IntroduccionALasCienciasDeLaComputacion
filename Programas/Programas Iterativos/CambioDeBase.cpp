#include <iostream>
#include <string>

std::string cambiarDecimalABaseK(int numeroDecimal, int nuevaBase) {
    std::string resultado = "";
    int numero = numeroDecimal;
    std::string Plus10[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L"};
    
    while (numero > 0) {
        resultado = Plus10[numero % nuevaBase] + resultado;
        numero /= nuevaBase;
    }
    
    return resultado;
}

int main()
{
    std::cout << cambiarDecimalABaseK(558, 16) << std::endl;

    return 0;
}