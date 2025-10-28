#include <iostream>

int main()
{
    int n = 10, A[n]; // entero A[0, ..., n-1], n es size del arreglo
    
    A[0] = 1; // A[0] <- 1
    A[1] = 1; // A[1] <- 1 
    
    std::cout << A[0] << "\n" << A[1] << std::endl;
    for (int i=2; i<=n-1; i++) { // Para(i < 2) hasta(n - 1) en paso(1)
        A[i] = A[i-1] + A[i-2]; // A[i] <- A[i-1] + A[i-2]
        std::cout << A[i] << "\n"; // imprimir(A[i])
    }
    

    return 0;
}