
/*
Cuadrado de un nro.
Escribir el algoritmo para calcular y mostrar el cuadrado de un número que se ingresa por teclado. El número que se ingresa debe ser mayor a 0 y si no lo es mostrar mensaje de error.
*/

#include <stdio.h>

int main() {
	printf("Cuadrado de un numero.\n\nIngrese un numero positivo para calcularle el cuadrado: ");
	int input;
	do {
		scanf("%d", &input);
		
		if(input <= 0) {
			printf("El numero ingresado es invalido.\n\nIngrese un nuevo numero: ");
		}
	} while(input <= 0);
	
	printf("\nEl cuadrado de %d es: %d.\n\n\n", input, input * input);
	
	system("PAUSE");
	return 0;
}
