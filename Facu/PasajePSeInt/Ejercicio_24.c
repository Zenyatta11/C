// Para inicializar: Recorrer todo un arreglo de 15 elementos numéricos reales e inicializar en 0

#include <stdio.h>

int main() {
	
	int i, Array[15];
	printf("Inicializacion de un array\n\n");
	for(i = 0; i < sizeof(Array)/sizeof(*Array); i = i + 1) {
		*(Array+i) = 0;
	}
	system("PAUSE");
	return 0;
}