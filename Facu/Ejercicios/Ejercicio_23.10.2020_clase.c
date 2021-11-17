/*

	reserva de memoria para 50 floats;
	generen 50 nros al azar;
	busquen el menor y el mayor en una misma función;
	el resultado del mayor y menor lo imprime quien llama a la búsqueda

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

float* obtenerArray();
void sort(float* pointer);
void minMax(float* pointer, float* min, float* max);

int main() {
	int i;
	float min, max;
	float* pointer = obtenerArray();
	
	if(pointer == NULL) printf("Could not allocate memory. Terminating...");
	else {
		sort(pointer);
		minMax(pointer,&min, &max);
		
		for(i = 0; i < MAX; i = i + 1) {
			if(i % 10 == 0) printf("\n\t");
			printf("%.2f, ", pointer[i]);
		}
		printf("\n\n\tEl mayor es %.2f y el menor es %.2f\n\n\t", max, min);
	}
	
	system("PAUSE");
	return 0;
}

void minMax(float* pointer, float* min, float* max){
	*min = *pointer;
	*max = *(pointer + MAX - 1);
}

float* obtenerArray() {
	float* array = malloc(MAX * sizeof(float));
	int i;
	
	if(array == NULL) return NULL;
	float* returnArray = array;
	
	srand(time(NULL));
	for(i = 0; i < MAX; i = i + 1) {
		*array = (float)(rand() % 10000)/100;
		array = array + 1;
	}
	return returnArray;
}

void sort(float* pointer) {
	float temp;
	int i;
	for(i = 0; i < MAX-1; i = i + 1) {
		if(pointer[i] > pointer[i+1]) {
			temp = pointer[i+1];
			pointer[i+1] = pointer[i];
			pointer[i] = temp;
			i = -1;
		}
	}
}
