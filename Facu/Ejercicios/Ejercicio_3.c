// Ingresar dos números y mostrar la suma

#include <stdio.h>


int main() {
	int input, add;
	
	add = 0;

	printf("Sumatoria de dos numeros.\n\nIngrese el primer numero para sumar: ");
	scanf("%d",&input);
	add = add + input;
	
	printf("Ingrese el segundo numero para sumar: ");
	scanf("%d",&input);
	add = add + input;

	printf("\nLa sumatoria de los numeros ingresados es %d\n\n", add, input);

	system("PAUSE");
	return 0;
}
