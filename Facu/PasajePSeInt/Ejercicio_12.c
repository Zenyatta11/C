// Ingresar un n�mero por teclado. Si el n�mero es mayor a 100, escribir en pantalla �El n�mero es mayor a 100�.
// Si es menor a 100, escribir �El n�mero es menor a 100�. Utilizar la estructura Si-SINO

#include <stdio.h>

// jijiji pseint go brrrrrrrrr
#define SI if
#define SINO else


int main() {
	
	int input;
	
	printf("Mayor a cien.\n\nIngrese un numero para ver si es mayor a cien: ");
	scanf("%d", &input);
	
	SI (input > 100) 
		printf("\n\nEl numero ingresado es mayor a cien.\n\n");
	SINO 
		printf("\n\nEl numero ingresado no es mayor a cien.\n\n");
	system("PAUSE");
	return 0;
}