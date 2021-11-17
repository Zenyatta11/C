// Ingresar por teclado 10 elementos enteros, colocarlos en un vector y luego mostrar su contenido separado por comas.

#include <stdio.h>

int main() {
	
	int i, Array[10];
	printf("Ingreso de enteros en un array\n\n");
	
	for(i = 0; i < sizeof(Array)/sizeof(*Array); i = i + 1) {
		printf("Ingrese un numero para el indice Array[%d]: ", i);
		scanf("%d", Array+i);
	}
	
	printf("\n\nPresione cualquier tecla para mostrar el array.\n");
	getch();
	
	for(i = 0; i < sizeof(Array)/sizeof(*Array); i = i + 1) {
		printf("%d%s", *(Array + i), (i == 9 ? "" : ", "));
	}
	
	printf("\n\n");
	system("PAUSE");
	return 0;
}

