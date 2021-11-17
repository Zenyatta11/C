// Comprobar si un número es par SIN utilizar la función MOD (%) o ES PAR o ES ENTERO o TRUNC, utilizando ciclos.
// Validar que el nro. ingresado sea mayor a 0.

#include <stdio.h>

int main() {
	
	int input;
	printf("Par o impar sin el operador %.\n\n");
	
	do {
		
		printf("\nIngrese el numero: ");
		scanf("%d", &input);
		if(input <= 0) printf("El numero ingresado es invalido. Debe ser un numero natural.\n");
		
	} while(input <= 0);

	printf("\n\nEl numero %d es ", input);
	
	while(input - 2 >= 0) {
		input = input - 2;
	}

	printf("%s.\n\n", (input == 1 ? "impar" : "par"));
	system("PAUSE");
	return 0;
}