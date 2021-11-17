// Comparar 2 vectores con 10 elementos enteros ya ordenados en forma ascendente y generar un tercer vector también ordenado.
// (para probarlo en Pseint ver indicación en presentación clase 5)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int Array[10], Array2[10], MergedArray[20], i;
	
	printf("Ordenamiento de un array.\n\nArray 1:");
	
	for(i = 0; i < sizeof(Array)/sizeof(*Array); i = i + 1) {
		*(Array+i) = i*3;
		printf("\n[%x] Array[%d] = %d", *(Array+i), i, *(Array+i));
	}
	
	printf("\n\nArray 2:");
	
	for(i = 0; i < sizeof(Array2)/sizeof(*Array2); i = i + 1) {
		*(Array2+i) = i*2;
		printf("\n[%x] Array2[%d] = %d", &Array2[i], i, *(Array2+i));
	}
	
	printf("\n\nArray mezclado sin ordenar:\n%d", sizeof(Array));	
	
	for(i = 0; i < sizeof(MergedArray)/sizeof(*MergedArray); i = i + 1) {
		if(i < 10) *(MergedArray+i) = *(Array+i);
		else *(MergedArray+i) = *(Array2+i-10);
		printf("\n[%x] MergedArray[%d] = %d", &MergedArray[i], i, *(MergedArray+i));
	}
	
	printf("\n\nArray mezclado ordenado:\n%d", sizeof(MergedArray));
	
	for(i = 1; i < sizeof(MergedArray)/sizeof(*MergedArray); i = i + 1) {
		if(*(MergedArray+i) < *(MergedArray+i-1)) {
			int tmp = *(MergedArray+i);
			*(MergedArray+i) = *(MergedArray+i-1);
			*(MergedArray+i-1) = tmp;
			i = 0;
		}
	}
	
	for(i = 0; i < sizeof(MergedArray)/sizeof(*MergedArray); i = i + 1) {
		printf("\n[%x] MergedArray[%d] = %d", &MergedArray[i], i, *(MergedArray+i));
	}
	
	printf("\n\n");
	system("PAUSE");
	return 0;
}