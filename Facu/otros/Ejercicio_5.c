/*

Promedio de Cinco Numeros

*/


#include<stdio.h>

int main() {
	
	int Array[5], i;
	float average;
	
	printf("Promedio de cinco numeros.\n\n");
	
	for(i = 0; i < 5; i = i + 1) {
		printf("Ingrese el numero %d: ", i+1);
		scanf("%d", &Array[i]);
	}
	
	for(i = 0; i < 5; i = i + 1) {
		average = average + Array[i];
	}
	
	average = average / 5;
	printf("El promedio es: %.2f\n\n", average);
	system("PAUSE");
	return 0;
}


