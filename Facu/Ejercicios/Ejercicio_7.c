/*
7	Uno a dos dígitos.
Solicitar el ingreso por teclado de un número positivo de uno o dos dígitos (1..99). Mostrar un mensaje indicando si el número tiene uno o dos dígitos.
*/

#include <stdio.h>

int input;

int main() {
	
	printf("Uno o dos digitos.\n\nIngrese un numero positivo de uno o dos digitos: ");
	
	do {
		scanf("%d", &input);
		
		if(input < 1 || input > 99) {
			printf("El numero ingresado es invalido.\nIngrese un nuevo numero: ");
		}
	} while(input < 1 || input > 99);
	
	printf("\nEl numero ingresado tiene %s digito%s.\n\n\n", (input > 9 ? "dos" : "un"), (input > 9 ? "s" : ""));
	
	system("PAUSE");
	return 0;
}
