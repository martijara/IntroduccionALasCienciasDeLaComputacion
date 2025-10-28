#include <iostream>

int mcd(int a, int b) {
    int greater = a;
    int lower = b;
    
    if (greater >= lower) {
        
    } else {
        lower = a;
        greater = b;
    }
    
    int residuo = greater % lower;
    while (residuo != 0) {
        greater = lower;
        lower = residuo;
        residuo = greater % lower;
    }
    
    return lower;
}

int main()
{
    std::cout << mcd(35443, 64521) << std::endl;

    return 0;
}