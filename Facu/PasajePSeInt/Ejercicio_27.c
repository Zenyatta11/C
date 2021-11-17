// Para leer: Recorrer todo un arreglo de 15 elementos numéricos reales y completar sus elementos con un nro. ingresado por teclado

#include <stdio.h>

int main() {
	
	int i, Array[15];
	printf("Ingreso de numeros en un array\n\n");
	
	for(i = 0; i < sizeof(Array)/sizeof(*Array); i = i + 1) {
		printf("Ingrese un numero para el indice Array[%d]: ", i);
		scanf("%d", Array+i);
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
