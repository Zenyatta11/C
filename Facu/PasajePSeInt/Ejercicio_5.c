// Ingresar 3 números y mostrar el mayor

#include <stdio.h>


int main() {
	int input0, input1, input2, max;
	
	max = 0;
	
	printf("Numero mayor.\n\nIngrese el primer numero: ");
	scanf("%d",&input0);
	
	printf("Ingrese el segundo numero: ");
	scanf("%d",&input1);
	
	printf("Ingrese el tercer numero: ");
	scanf("%d",&input2);
	
	if(input0 > input1 && input0 > input2) 
		printf("\nEl numero mayor es %d\n\n", input0);
	else if(input0 < input1 && input1 > input2) 
		printf("\nEl numero mayor es %d\n\n", input1);
	else if(input2 > input1 && input0 < input2) 
		printf("\nEl numero mayor es %d\n\n", input2);
	else
		printf("\nNo hay un numero mas grande que los demas.\n\n");

	system("PAUSE");
	return 0;
}

