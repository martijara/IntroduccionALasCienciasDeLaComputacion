#include <iostream>
#include <utility>
#include <cmath>

void sortArreglo(int n, int A[]) {
	int tracker = 0;

	while (tracker < n) {
		int mayor = tracker;
		for (int i = tracker; i < n; i++) {
			if (A[mayor] < A[i]) {
				mayor = i;
			}
		}

		if (mayor != tracker) {
			std::swap(A[mayor], A[tracker]);
		}
		tracker += 1;
	}
}

void convertirIntAArreglo(int numero, int n, int A[]) {
	int num = numero;

	// Ponemos el numero en un arreglo
	for(int i = 0; i < n; i++) {
		A[n-i-1] = num%10;
		num /= 10;
	}
}

int kaprekar(int numero) {
	int n = 4, A[n];

	int resultado = numero;

	int iteraciones = 0;
	while (resultado != 6174) {
		// Ponemos el numero en un arreglo
		convertirIntAArreglo(resultado, n, A);

		std::cout << std::endl;

		// Ahora vamos a sort el arreglo de mayor a menor
		sortArreglo(n, A);

		// Ahora vamos a obtener el numero ordenado de mayor a menor
		int mayor = A[0]*pow(10, 3) + A[1]*pow(10, 2) + A[2]*pow(10, 1) + A[3];
		int menor = A[3]*pow(10, 3) + A[2]*pow(10, 2) + A[1]*pow(10, 1) + A[0];

		// Ahora restamos los numeros
		resultado = mayor - menor;

		std::cout << mayor << " - " << menor << " = " << resultado << std::endl;

		// Ahora we keep track del numero de iteraciones
		iteraciones += 1;
	}

	return iteraciones;
}


int main()
{
	int numero;

	std::cout << "Bienvenido al programa de hallar constante de Kaprekar. Entre su numero: ";

	std::cin >> numero;

	int iteraciones = kaprekar(numero);

	std::cout << std::endl << std::endl;

	std::cout << "Numero de iteraciones que tomo para llegar a la constante: " << iteraciones;

	return 0;
}