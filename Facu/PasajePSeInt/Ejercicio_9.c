// Escribir el algoritmo para calcular y mostrar el cuadrado de un número que se ingresa por teclado.
// El número que se ingresa debe ser mayor a 0 y si no lo es mostrar mensaje de error.

#include <stdio.h>

int main() {
	
	int input;
	
	printf("Cuadrado de un numero.\n\nIngrese un numero para calcular su cuadrado: ");
	scanf("%d",&input);
	
	if(input > 0) {
		printf("El cuadrado de %d es %d\n\n",input,input*input);
		system("PAUSE");
	} else {
		printf("El numero ingresado es invalido. Debe ser mayor a cero.\n\n");
		main();
	}
	
	return 0;
}