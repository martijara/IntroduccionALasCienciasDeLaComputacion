#include <iostream>

int recursiveFibonacci(int n) {
    if (n==1 || n==2) {
        return 1;
    } else {
        return recursiveFibonacci(n-1) + recursiveFibonacci(n-2);
    }
}

int printFibonacciSequence(int n) {
    for (int i = 1; i <= n; i++) {
        std::cout << i << "\t" << recursiveFibonacci(i) << std::endl;
    }
}

int main()
{
    printFibonacciSequence(20);
    
    return 0;
}