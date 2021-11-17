// Escribir el algoritmo que calcule la superficie de un tri�ngulo a partir del ingreso de su base y su altura.
// Condici�n:b y h deben ser mayores a 0.

#include <stdio.h>

int main() {
	
	int base, height;
	
	printf("Superficie de un triangulo.\n\n");
	
	do {
		printf("Ingrese la medida de la base: ");
		scanf("%d", &base);
		if(base <= 0) printf("\nLa base debe ser mayor a cero.\n");
	} while(base <= 0);
	
	do {
		printf("Ingrese la medida de la altura: ");
		scanf("%d", &height);
		if(height <= 0) printf("\nLa altura debe ser mayor a cero.\n");
	} while(height <= 0);
	
	printf("\n\nLa superficie del triangulo es %d\n\n", base * height);
	system("PAUSE");
	return 0;
}