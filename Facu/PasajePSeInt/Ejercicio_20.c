// Calcular el cociente entero y el resto de dividir dos números SIN utilizar la operación /, utilizando ciclos.
// Validar que los dos nros. ingresados por pantalla sean mayores a 0.

#include <stdio.h>

int main() {
	
	int numerator, input, quotient;
	
	printf("Division sin el operador /.\n\n");
	
	do {
		
		printf("\nIngrese el dividendo/numerador: ");
		scanf("%d", &input);
		if(input <= 0) printf("El numero ingresado es invalido. Debe ser un numero natural.\n");
		
	} while(input <= 0);
	
	numerator = input;
	
	do {
		
		printf("\nIngrese el divisor/denominador: ");
		scanf("%d", &input);
		if(input <= 0) printf("El numero ingresado es invalido. Debe ser un numero natural.\n");
		
	} while(input <= 0);
	
	printf("\n\n%d / ", numerator);
	quotient = 0;
	
	while(numerator - input >= 0) {
		numerator = numerator - input;
		quotient = quotient + 1;
	}
	
	if(numerator > 0) printf("%d = %d con resto %d.\n\n", input, quotient, numerator);
	else printf("%d = %d.\n\n", input, quotient);
	system("PAUSE");
	return 0;
}