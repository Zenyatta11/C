// Se ingresan por teclado tres números, se suman y se muestra por pantalla el resultado.

#include <stdio.h>

int main() {
	
	int input, sum;
	sum = 0;
	
	printf("Suma de tres numeros.\n\nIngrese el primer numero a sumar: ");
	scanf("%d",&input);
	sum = sum + input;
	
	printf("\nIngrese el segundo numero a sumar: ");
	scanf("%d",&input);
	sum = sum + input;
	
	printf("\nIngrese el tercer numero a sumar: ");
	scanf("%d",&input);
	sum = sum + input;
	
	printf("\nLa suma de los tres numeros es de %d.\n\n", sum);
	system("PAUSE");
	return 0;
}