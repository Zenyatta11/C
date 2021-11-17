/*

Confeccionar un programa que solicite el pago por hora de un empleado y la cantidad de horas trabajadas.
Solicitar la cantidad de empleados de los que se desea obtener el sueldo.
Elaborar una función que reciba como parámetro el valor de la hora y la cantidad de horas trabajadas y nos muestre el total a pagar.

*/


#include<stdio.h>

// Es mas nitido ver primero el main y despues el resto para ver como los llama el main
unsigned int GetNumb(char* text);
void Horizontal_Rule(int length, int type);
unsigned int getSueldosAPagar(unsigned int empleados, unsigned int costoHora, unsigned int cantHoras);

int main() {
	
	//Pedir los datos
	printf("Costo total de sueldos.\n\n");
	unsigned int Empleados = GetNumb("Ingrese la cantidad de empleados: ");
	unsigned int Hora_Costo = GetNumb("Ingrese el costo por hora: $");
	unsigned int Hora_Cantidad = GetNumb("Ingrese la cantidad de horas trabajadas: ");
	printf("\n\nPresione una tecla para mostrar una tabla con el resumen de sueldo.");
	
	getch();
	system("CLS");
	
	//Mostramos el cuadro
	printf("\n");
	Horizontal_Rule(56,1);
	Horizontal_Rule(56,0);
	
	printf("\t|                  Resumen de cuentas                  |\n");
	
	Horizontal_Rule(56,0);
	Horizontal_Rule(56,1);
	Horizontal_Rule(56,0);
	
	printf("\t| Cantidad de Empleados: %29u |\n", Empleados);
	printf("\t| Costo por hora: %34uhs |\n", Hora_Costo);
	printf("\t| Costo total de horas trabajadas: %17uhs |\n", Hora_Cantidad);
	
	Horizontal_Rule(56,0);
	Horizontal_Rule(56,1);
	Horizontal_Rule(56,0);
	
	printf("\t| Total de sueldos a pagar: $%25u |\n", getSueldosAPagar(Empleados, Hora_Costo, Hora_Cantidad));
	
	Horizontal_Rule(56,0);
	Horizontal_Rule(56,1);
	printf("\n\n");
	
	system("PAUSE");
	return 0;
}

	///////////////////////////////
	//	                     	 //
	//	Funciones secundarias	 //
	//	                     	 //
	///////////////////////////////

unsigned int getSueldosAPagar(unsigned int empleados, unsigned int costoHora, unsigned int cantHoras) {
	return empleados * costoHora * cantHoras;
}

unsigned int GetNumb(char* text) {
	int input;
	do{
		printf("%s", text);
		scanf("%d", &input);
		if(input <= 0)
			printf("El valor no puede ser %s.\n\n", (input < 0 ? "negativo" : "cero"));
	}while(input <= 0);
	return (unsigned int)input;
}

void Horizontal_Rule(int length, int type) {
	int i;
	if(type) {
		printf("\t+");
		for(i = 0; i < length-2; i = i + 1) {
			printf("-");
		}
		printf("+\n");
	} else {
		printf("\t|");
		for(i = 0; i < length-2; i = i + 1) {
			printf(" ");
		}
		printf("|\n");
	}
}
