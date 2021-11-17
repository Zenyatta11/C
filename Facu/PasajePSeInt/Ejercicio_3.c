//Leer los 5 números que se ingresan por teclado y calcular su promedio. 

#include <stdio.h>
#include <math.h>


int main() {
	int input, add;
	float average;
	
	add = 0;
	
	printf("Sumatoria de cinco numeros.\n\nIngrese el primer numero para sumar: ");
	scanf("%d",&input);
	add = add + input;
	
	printf("Ingrese el segundo numero para sumar: ");
	scanf("%d",&input);
	add = add + input;
	
	printf("Ingrese el tercer numero para sumar: ");
	scanf("%d",&input);
	add = add + input;
	
	printf("Ingrese el cuarto numero para sumar: ");
	scanf("%d",&input);
	add = add + input;
	
	printf("Ingrese el quinto numero para sumar: ");
	scanf("%d",&input);
	add = add + input;
	
	average = (float)add / 5;
	average = roundf(average*100);
	average = average / 100;
	input = trunc(average);
	//printf("%f",average);
	if(average == input)
		printf("\nLa sumatoria de los numeros ingresados es %d\nEl promedio es %d\n\n", add, input);
	else
		printf("\nLa sumatoria de los numeros ingresados es %d\nEl promedio es %.2f\n\n", add, average);
	system("PAUSE");
	return 0;
}