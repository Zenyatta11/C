
/*
¿Cuál es el mayor?
Ingresar 3 números y mostrar el mayor
*/

#include <stdio.h>

int main() {
	
	int input[3];
	
	printf("Numero mayor del set.\n\n\nIngrese el primer numero:");
	scanf("%d", input);
	
	int max = *input;
	
	printf("Ingrese el segundo numero:");
	scanf("%d", input+1);
	
	printf("Ingrese el tercer numero:");
	scanf("%d", input+2);
	
	if(*(input+1) > max) max = *(input+1);
	if(*(input+2) > max) max = *(input+2);
	
	printf("\n\nEl numero mas grande es %d.\n\n", max);
	system("PAUSE");
	return 0;
}

