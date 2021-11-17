// Serie Fibonacci : es una sucesión infinita de números naturales donde cada número se calcula sumando los dos anteriores a él, partiendo de 0, 1. 
// Escribir los primeros N números de la serie Fibonacci. Por ej. Si N = 5 : 0,1,1,2,3,5,8 

#include <stdio.h>

int main() {
	
	int sum = 0, prev = 0, actual = 1, total = 0, input;
	
	printf("Serie Fibonacci.\n\nIngrese la cantidad de numeros de Fibonacci que desea calcular: ");
	scanf("%d", &input);
	if(input > 1) {
		printf("1, ");
		for(; input > 0; input = input - 1) {
			total = total + sum;
			sum = actual + prev;
			prev = actual;
			actual = sum;
			if(input == 1) printf("%d\n\n", sum);
			else printf("%d, ", sum);
		}
		system("PAUSE");
	} else {
		printf("\nEl numero ingresado es invalido.\nDebe ser un numero entero mayor a uno.\n\n\n");
		main();
	}
	
	return 0;
}