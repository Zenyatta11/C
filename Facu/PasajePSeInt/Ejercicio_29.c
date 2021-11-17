// Calcular el promedio de 5 números ingresados por teclado. Utilizar un vector. Primero leer los cinco números, luego recorrerlo para calcular el promedio

#include <stdio.h>

int main() {
	
	int i, Array[5];
	printf("Calculo de un promedio con arrays.\n\n");
	
	for(i = 0; i < sizeof(Array)/sizeof(*Array); i = i + 1) {
		printf("Ingrese un numero para el indice Array[%d]: ", i);
		scanf("%d", Array+i);
	}
	
	printf("\n\nPresione cualquier tecla para mostrar el promedio.\n");
	getch();
	
	for(i = 1; i < sizeof(Array)/sizeof(*Array); i = i + 1) {
		*Array = *(Array + i) + *Array;
	}
	
	printf("El promedio es de %d\n\n", *Array / (sizeof(Array)/sizeof(*Array)));
	system("PAUSE");
	return 0;
}
	