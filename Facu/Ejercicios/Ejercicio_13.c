
/*
Par o impar?
A partir de un número ingresado por teclado indicar si es par o impar utilizando el operador “?”.
*/

//dado que ya lo hice con modulo, vamos con manipulacion binaria

#include <stdio.h>

int main() {
	
	int input;
	
	printf("Par o impar?\n\nIngrese un numero: ");
	scanf("%d", &input);
	printf("\nEl numero es %s.\n\n", (input & 1 ? "impar" : "par"));
	system("PAUSE");
	return 0;	
}
