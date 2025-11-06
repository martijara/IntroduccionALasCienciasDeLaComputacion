// Largest Element in an Array Using Pointers

// Find the largest integer in an array by iterating over it with pointers.
#include <iostream>

int main()
{
    int n = 5;
    int A[5] = {4, 9, 2, 15, 6};

    // In most contexts, A implicitly converts (decays) to int* that points 
    // to A[0].So the assignment int *p = A; means p points to the first 
    // element of the array A.
    int *p = A;         // Pointer a el primer elemento del arreglo
    int masGrande = *p; // Inicializamos mas grande como primer elemento

    for (int i = 1; i < n; i++)
    {
        p += 1; // Mover el pointer al siguiente elemento

        if (*p > masGrande)
        {
            masGrande = *p;
        }
    }

    std::cout << "Mas grande es: " << masGrande << std::endl;
}