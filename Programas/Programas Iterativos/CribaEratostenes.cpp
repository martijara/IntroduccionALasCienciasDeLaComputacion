#include <stdio.h>
#include <iostream>
#include <cmath>

int main()
{
    int n = 1000, A[n];
    
    // Creamos la lista de numeros de 0 a n
    for(int i = 0; i < n; i++){
        A[i] = i+1;
    }
    
    for(int i = 1; i<n;i++) { // Miramos todos los numeros 
        int isPrime = true;
        for(int j = 1; j < pow(i, 0.5); j++) { // Mucho mas eficiente checar sqrt(i) que ir hasta i - 1
            if (A[i] % A[j] == 0) { // Miramos si i es divisible entre j
                isPrime = false;
                break;
            } 
        }
        
        if (isPrime == true) {
            std::cout << A[i] << std::endl;
        }
    }
    
    return 0;
}