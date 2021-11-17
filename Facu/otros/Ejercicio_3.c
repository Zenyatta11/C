/*

Suma de dos numeros

*/


#include<stdio.h>

int main() {
	
	int numA, numB;
	
	printf("Suma de dos numeros.\n\nIngrese un numero para sumar: ");
	scanf("%d", &numA);
	
	printf("Ingrese otro numero para sumar: ");
	scanf("%d", &numB);
	
	printf("La suma de los numeros es: %d\n\n", numA + numB);
	system("PAUSE");
	return 0;
	
}


