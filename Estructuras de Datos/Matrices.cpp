#include <iostream>
#include <cmath>

#define N 20 // Para declarar variables globales

void leerMatriz(int filas, int columnas, int Matriz[][N]) {
	std::cout << "Trying this out";
	for(int i = 0; i < filas; i++) {
		std::cout << "Hi #" << i << std::endl;
		for (int j = 0; j < columnas; j++) {
			std::cout << "Entre la componente de la Matriz en posicion " << i << ", " << j << ": ";
			std::cin >> Matriz[i][j];
		}
	}
}

void imprimirMatriz(int filas, int columnas, int Matriz[][N]) {
	std::cout << std::endl << "Este es el resultado de tu matriz: " << std::endl;
	for(int j = 0; j < columnas; j++) {
		for (int i = 0; i < filas; i++) {
			std::cout << Matriz[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

int traza(int filas, int columnas, int Matriz[][N]) {
	int resultado = 0;
	if (filas == columnas) {
		for(int i = 0; i < filas; i++) {
			resultado += Matriz[i][i];
		}
	}

	return resultado;
}

void intercambiarFilas(int filas, int columnas, int Matriz[][N], int fila1, int fila2) {
	if (filas > fila1 && filas > fila2) {
		int Guardado[columnas];

		for(int j = 0; j < columnas; j++) {
			Guardado[j] = Matriz[fila1][j];
		}

		for(int j = 0; j < columnas; j++) {
			Matriz[fila1][j] = Matriz[fila2][j];
			Matriz[fila2][j] = Guardado[j];
		}

		// Tambien se puede hacer con swap(Matriz[fila1][j], Matriz[fila2][j])

	} else {
		std::cout << "Operacion no se puede realizar." << std::endl;
	}
}

void matrizEratostenes(int n, int Matriz[][N]) {
	Matriz[0][0] = 2;

	int numero = 3;
	int i = 1;
	int j = 0;
	while(j < n) { // Miramos todos los numeros
		std::cout << numero << std::endl;

		int isPrime = true;

		int index_i = 0;
		int index_j = 0;

		while (index_j <= j) {
			std::cout << "i = " << index_i << std::endl;
			std::cout << "j = " << index_j << std::endl;
			if (Matriz[index_i][index_j] > std::pow(numero, 0.5) || isPrime == false) {
				std::cout << Matriz[index_i][index_j] << " > " << std::pow(numero,0.5) << std::endl;
				break;
			}

			std::cout << index_i << " < " << i << " ?" << std::endl;

			if (index_j < j) {
				while (index_i < n) {
					std::cout << "Testing" << numero << " % " << Matriz[index_i][index_j] << std::endl;
					if (numero % Matriz[index_i][index_j] == 0) {
						isPrime = false;
						break;
					}
					index_i += 1;
				}
			}
			else {
				while (index_i < i) {
					std::cout << "Testing" << numero << " % " << Matriz[index_i][index_j] << std::endl;
					if (numero % Matriz[index_i][index_j] == 0) {
						isPrime = false;
						break;
					}
					index_i += 1;
				}
			}
			index_j += 1;
		}

		if (isPrime == true) {
			std::cout << "New prime in i = " << i << " and j = " << j << std::endl;
			Matriz[i][j] = numero;
			i += 1;

			if (i==n) {
				i = 0;
				j += 1;
			}
			std::cout << "Prime: " << numero << std::endl;
		}

		std::cout << std::endl << std::endl;
		numero += 1;
	}
}

int main()
{
	int filas = 14;
	int columnas = 14;
	int A[filas][N];

	// leerMatriz(filas, columnas, A);
	// imprimirMatriz(filas, columnas, A);
	//std::cout << std::endl << "La suma de las diagonales es: " << traza(3, 3, A);

	// intercambiarFilas(filas, columnas, A, 0, 2);
	// std::cout << "Esta es la impresion de tu nueva matriz con la fila 0 intercambiada con la 2";

	matrizEratostenes(filas, A);
	imprimirMatriz(filas, columnas, A);


	return 0;
}