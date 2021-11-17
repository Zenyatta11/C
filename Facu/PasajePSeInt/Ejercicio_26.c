// Para llenar: Recorrer todo un arreglo de 15 elementos numéricos reales y completar sus elementos con un nro. al azar

#include <stdio.h>
#include <math.h>

int main() {
	
	int i, Array[15];
	printf("Numeros al azar en un array\n\nIngresando numeros al azar en el array...");
	
	for(i = 0; i < sizeof(Array)/sizeof(*Array); i = i + 1) {
		srand (rand() * time(NULL));
		*(Array+i) = rand();
	}
	
	printf("\n\nPresione cualquier tecla para mostrar el array.\n");
	getch();
	
	for(i = 0; i < sizeof(Array)/sizeof(*Array); i = i + 1) {
		printf("\n[%x] - Array[%d] = %d", &Array[i], i, *(Array+i));
	}
	
	printf("\n\n");
	system("PAUSE");
	return 0;
}
