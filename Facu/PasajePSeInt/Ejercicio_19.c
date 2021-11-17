// Calcular el producto de 2 números naturales SIN utilizar la operación *
// utilizando ciclos. Validar que los dos nros. ingresados por teclado sean mayores a 0.

#include <stdio.h>

int main() {
	
	int factor, sum, i, input;
	
	printf("Multiplicacion sin el operador *.\n\n");
	
	do {
		
		printf("\nIngrese un factor: ");
		scanf("%d", &input);
		if(input <= 0) printf("El numero ingresado es invalido. Debe ser un numero natural.\n");
		
	} while(input <= 0);
	
	factor = input;
	
	do {
		
		printf("\nIngrese el otro factor: ");
		scanf("%d", &input);
		if(input <= 0) printf("El numero ingresado es invalido. Debe ser un numero natural.\n");
		
	} while(input <= 0);
	
	for(i = sum = 0; i < input; i = i + 1) {
		sum = sum + factor;
	}
	
	printf("\n\n%d * %d = %d\n\n", factor, input, sum);
	system("PAUSE");
	return 0;
}