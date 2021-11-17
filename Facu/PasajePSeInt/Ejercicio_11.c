// Ingresar un numero y si el número es mayor a 100 , escribir en la pantalla “el número es mayor a 100”.

#include <stdio.h>

int main() {
	
	int input;
	
	printf("Mayor a cien.\n\nIngrese un numero para ver si es mayor a cien: ");
	scanf("%d",&input);
	printf("\n%s\n\n", (input > 100 ? "\nEl numero ingresado es mayor a cien." : "El numero ingresado no es mayor a cien."));
	system("PAUSE");
	return 0;
}
