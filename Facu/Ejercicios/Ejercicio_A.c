/*

	Ejercicio A
	
*/

#include<stdio.h>

int main() {
	int i, Array[10];
	float avg = 0;
	
	for(i = 0; i < 10; i = i + 1) {
		printf("Ingrese un numero: ");
		scanf("%d", &Array[i]);
		avg = avg + Array[i];
		if(i != 9) printf("Restan %d\n\n", 9-i);
	}
	
	printf("\n\nArray ingresado: [");
	
	for(i = 0; i < 10; i = i + 1) {
		printf("%d%s", Array[i], (i < 9 ? ", " : "]"));
	}
	
	printf("\n\nEl promedio es de %.2f\n\n", avg/10);
	system("PAUSE");
	return 0;
}