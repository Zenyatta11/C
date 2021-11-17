
/*
Mayor o menor a 100?
Ingresar un número por teclado. Si el número es mayor a 100, escribir en pantalla “El número es mayor a 100”.
Si es menor a 100, escribir “El número es menor a 100”. Utilizar la estructura IF-ELSE
*/

#include <stdio.h>

int main() {
	int input;
	
	printf("Mayor o menor a 100.\n\n\nIngrese el numero: ");
	scanf("%d", &input);
	
	printf("\n\nEl numero es");
	if(input > 100) printf(" mayor a cien.\n\n");
	else if(input < 100) printf(" menor a cien.\n\n");
	else printf(" cien.\n\n");
	system("PAUSE");
	return 0;
}
