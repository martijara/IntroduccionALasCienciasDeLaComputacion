#include <stdio.h>
#include <iostream>

float aurea(float n, int iterations) {
	if (iterations <= 1) {
		return n;
	}
	else {
		return aurea(1 + 1/n, iterations - 1);
	}
}

int main()
{
	float aureas = aurea(1, 100);

	std::cout << aureas;


	return 0;
}