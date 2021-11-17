/*
	Ejercicio 5 bis
	Promedio de 5 numeros
*/

#include<stdio.h>
#define MAX 5

int main() {
	
	int input, i;
	double suma = 0;
	
	printf("Promedio de cinco numeros.\n\n");
	
	for(i = 0; i < MAX; i = i + 1) {
		printf("Ingrese un numero. Restan %d: ", MAX-i);
		scanf("%d", &input);
		suma = suma + input;
	}
	
	suma = suma / 5;
	
	printf("\n\nEl promedio es %.16lf\n\n", suma);
	system("PAUSE");
	return 0;
}

