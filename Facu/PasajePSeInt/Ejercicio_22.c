// Convertir un número (dado en segundos) en sus correspondientes minutos y segundos, utilizando ciclos.
// Validar que el nro. ingresado sea mayor a cero. No utilizar la función TRUNC.

#include <stdio.h>

int main() {
	
	int input, minutes;
	
	printf("Segundos a Minutos y Segundos\nSin el operador /, utilizando ciclos unicamente.\n\n");
	
	do {
		
		printf("\nIngrese la cantidad de segundos: ");
		scanf("%d", &input);
		if(input <= 0) printf("El numero ingresado es invalido. Debe ser un numero natural.\n");
		
	} while(input <= 0);
	
	if(input >= 60) printf("\n\n%d segundos ", input);
	minutes = 0;
	
	while(input - 60 >= 0) {
		input = input - 60;
		minutes = minutes + 1;
	}
	
	if(minutes > 0) {
		printf("%s %d minuto%s", (minutes == 1 ? "es" : "son"), minutes, (minutes == 1 ? "" : "s"));
		if( input > 0) printf(" con %d %s", input, (input == 1 ? "segundo" : "segundos"));
	}
	else printf("\n\nEl ingreso (%d %s) no llega al minuto", input, (input == 1 ? "segundo" : "segundos"));
	printf(".\n\n");
	
	system("PAUSE");
	return 0;
}