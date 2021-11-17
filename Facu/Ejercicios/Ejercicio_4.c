/*Convertir de dólares a euros
Convertir un monto en dólares a euros. Ambos montos son de tipo double. 
Definir la constante con el valor de conversión. Por ej. 0.8
Leer el monto en dólares por teclado.
Imprimir el resultado con un mensaje del tipo “ xx dólares son xx euros”
*/

#include <stdio.h>

#define DOL_EUR 0.8

int main() {
	double input;
	
	printf("Dolares a Euros\n\nIngrese la cantidad de dolares para convertir: ");
	scanf("%lf",&input);
	
	printf("\n\n$%.2lf dolares son $%.2lf euros.\n\n", input, input * DOL_EUR);
	
	system("PAUSE");
	return 0;
}

