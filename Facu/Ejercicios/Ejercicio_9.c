
/*
Una, dos o tres cifras?
Confeccionar un programa que permita cargar un número entero positivo de hasta tres cifras y muestre un mensaje indicando si tiene 1, 2, o 3 cifras. 

Utilizar if encadenados sin llaves.

Mostrar un mensaje de error si el número de cifras es mayor.
*/

#include <stdio.h>

int main() {
	
	int input;
	
	printf("Uno, dos, o tres digitos.\n\nIngrese un numero positivo de uno, dos, o tres digitos: ");
	
	do {
		scanf("%d", &input);
		
		if(input < 1 || input > 999) {
			printf("El numero ingresado es invalido.\nIngrese un nuevo numero: ");
		}
	} while(input < 1 || input > 999);
	
	//printf("\nEl numero ingresado tiene %s digito%s.\n\n\n", (input > 99 ? "tres" : (input > 9 ? "dos" : "un")), (input > 9 ? "s" : ""));
	//tecnicamente es lo mismo pero lo puede tomar mal
	
	printf("\nEl numero ingresado tiene ");
	if(input > 99) printf("tres digitos.\n\n");
	else if(input > 9) printf("dos digitos.\n\n");
	else printf("un digito.\n\n");
	
	system("PAUSE");
	return 0;
	
}
