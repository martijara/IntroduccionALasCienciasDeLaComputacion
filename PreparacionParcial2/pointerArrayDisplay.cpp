// Pointer and Array Address Display

// Declare an array of floats and use a pointer to iterate through it, printing the address 
// and value of each element with both pointer arithmetic and array indexing.
#include <iostream>



int main() {
    int n = 5;
    float A[n] = {3.5, 5.4, 1.7, 4.6, 3.1};
    
    float* p = A;

    for (int i = 0; i < n; i++) {
        std::cout << "Elemento #" << i << std::endl;
        std::cout << "  Direccion: " << p << std::endl;
        std::cout << "  Valor: " << *p << std::endl;
        
        p += 1;
    }
    delete[] p;

    return 0;

}