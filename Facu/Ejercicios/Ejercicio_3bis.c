/*
	Ejercicio 3 bis
	Suma de 3 numeros
*/

#include<stdio.h>

int main() {
	
	int suma, num_0, num_1, num_2;
	
	printf("Suma de tres numeros.\n\nIngrese el primer numero: ");
	scanf("%d", &num_0);
	printf("\nIngrese el segundo numero: ");
	scanf("%d", &num_1);
	printf("\nIngrese el tercer numero: ");
	scanf("%d", &num_2);
	
	suma = num_0 + num_1 + num_2;
	
	printf("\n\nLa suma %d + %d + %d = %d\n\n", num_0, num_1, num_2, suma);
	system("PAUSE");
	return 0;
}

