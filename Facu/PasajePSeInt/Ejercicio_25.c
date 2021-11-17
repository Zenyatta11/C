// Para mostrar: Recorrer todo un arreglo de 15 elementos numéricos reales y mostrar su contenido en forma de columna


#include <stdio.h>

int main() {
	
	int i, Array[15];
	printf("Muestra de un array\n\n");
	
	for(i = 0; i < sizeof(Array)/sizeof(*Array); i = i + 1) {
		*(Array+i) = 0;
		printf("[%x] - Array[%d] = %d\n", &Array[i], i, *(Array+i));
	}
	system("PAUSE");
	return 0;
}

