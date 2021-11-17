// Convertir un número (dado en Mb) a su correspondiente Gb, utilizando ciclos.
// Validar que el nro. ingresado sea mayor a 0. No utilizar la función TRUNC, REDON

#include <stdio.h>

int main() {
	
	int input, gigabytes;
	
	printf("Megabytes a Gigabytes\nSin el operador /, utilizando ciclos unicamente.\n\n");
	
	do {
		
		printf("\nIngrese la cantidad de megabytes (MB): ");
		scanf("%d", &input);
		if(input <= 0) printf("El numero ingresado es invalido. Debe ser un numero natural.\n");
		
	} while(input <= 0);
	
	if(input >= 1024) printf("\n\n%d megabytes (MB) ", input);
	gigabytes = 0;
	
	while(input - 1024 >= 0) {
		input = input - 1024;
		gigabytes = gigabytes + 1;
	}
	
	if(gigabytes > 0) {
		printf("%s %d gigabyte%s (GB%s)", (gigabytes == 1 ? "es" : "son"), gigabytes, (gigabytes == 1 ? "" : "s"), (gigabytes == 1 ? "" : "s"));
		if( input > 0) printf(" con %d %s", input, (input == 1 ? "megabyte (MB)" : "megabytes (MBs)"));
	}
	else printf("\n\nEl ingreso (%d %s) no llega al gigabyte (GB)", input, (input == 1 ? "megabyte (MB)" : "megabytes (MBs)"));
	printf(".\n\n");
	
	system("PAUSE");
	return 0;
}
