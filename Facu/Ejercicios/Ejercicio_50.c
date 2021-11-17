/*

Leer un carácter y luego a través de una función imprimirlo en mayúscula. 
PISTAS: Se debe incluir la librería ctype.h y se debe utilizar la función toupper.


*/


#include<stdio.h>

int main() {
	unsigned char input;
	printf("minusculas a MAYUSCULAS\n\nIngrese un caracter: ");
	scanf("%c", &input);
	
	printf("\nEl caracter en mayusculas es %c!\n\n", (input >= 'a' && input <= 'z' ? input - 32 : input));
	//dado que es un caracter, es mas facil restarle la diferencia
	
	system("PAUSE");
	return 0;
	
}


