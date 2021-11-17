/*

Confeccionar un programa que solicite el pago por hora de un empleado y la cantidad de horas trabajadas.
Solicitar la cantidad de empleados de los que se desea obtener el sueldo.
Elaborar una función que reciba como parámetro el valor de la hora y la cantidad de horas trabajadas y nos muestre el total a pagar.

nota: la consigna de la evaluacion tiene diferencias con el del archivo. Esta modificado para cumplir los de la evaluacion

*/


#include<stdio.h>
#include<stdlib.h>

// Es mas nitido ver primero el main y despues el resto para ver como los llama el main
void ShowDatasheet(unsigned int* Datasheet, unsigned int Empleados);
void Horizontal_Rule(int length, int type);

unsigned int GetEmpleadosSueldos_Horas(unsigned int* Datasheet, unsigned int Empleados);
unsigned int GetNumb(char* text);

int main() {
	
	int i;
	//Pedir los datos
	printf("Costo total de sueldos.\n\n");
	unsigned int Empleados = GetNumb("Ingrese la cantidad de empleados: ");
	unsigned int* Datasheet = malloc(sizeof(unsigned int)*Empleados*2);
	
	if(Datasheet == NULL) { // Si el pointer no existe, no se aloco. no podemos continuar
		printf("\n\nException in memory allocation. Terminating...\n");
		system("PAUSE");
	return 0;
		return;
	}
	
	unsigned int Costo_Total = GetEmpleadosSueldos_Horas(Datasheet, Empleados);
	
	printf("\n\nPresione ENTER para mostrar una tabla con el resumen de sueldo.");
	
	while(getch() != '\r');
	
	system("CLS");
	
	//Mostramos el cuadro
	printf("\n");
	Horizontal_Rule(56,1);
	Horizontal_Rule(56,0);
	printf("\t|                  Resumen de cuentas                  |\n");
	Horizontal_Rule(56,0);
	Horizontal_Rule(56,1);
	
	ShowDatasheet(Datasheet, Empleados);
	
	//Resaltamos el total final
	printf("\n");
	Horizontal_Rule(56,2);
	printf("\t# Total de sueldos a pagar: $%25u #\n", Costo_Total);
	Horizontal_Rule(56,2);
	printf("\n\n");
	
	system("PAUSE");
	return 0;
}

	///////////////////////////////
	//	                     	 //
	//	Funciones secundarias	 //
	//	                     	 //
	///////////////////////////////
	
void ShowDatasheet(unsigned int* Datasheet, unsigned int Empleados) {
	int i;
	for(i = 0; i < Empleados; i = i + 1) {
		Horizontal_Rule(56,0);
		printf("\t| Empleado Nro. %38u |\n", i+1);
		Horizontal_Rule(56,0);
		printf("\t| Costo por hora: $%35u |\n", *(Datasheet+i*2));
		printf("\t| Horas trabajadas: %32uhs |\n", *(Datasheet+i*2+1));
		printf("\t| Costo total de horas trabajadas: $%18u |\n", *(Datasheet+i*2+1) * *(Datasheet+i*2));
		Horizontal_Rule(56,0);
		Horizontal_Rule(56,1);
		if(i % 3 == 2) {
			printf("\t| %-52s |\n","Presione ENTER para continuar..."); //No mostrar mas que el tamaño de la consola (80 caracteres la mia)
			Horizontal_Rule(56,1);
			while(getch() != '\r');
			
		}
	}
}

unsigned int GetEmpleadosSueldos_Horas(unsigned int* Datasheet, unsigned int Empleados){
	unsigned int i, Costo_Total = 0;
	for(i = 0; i < Empleados; i = i + 1) {
		printf("\nEmpleado numero %d\n", i + 1);
		unsigned int costo = GetNumb("\tIngrese el costo por hora: $");
		unsigned int horas = GetNumb("\tIngrese la cantidad de horas de trabajo: ");
		Costo_Total = Costo_Total + costo*horas;
		*(Datasheet+i*2) = costo;
		*(Datasheet+i*2+1) = horas;
	}
	return Costo_Total;
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
	if(type == 1) {
		printf("\t+");
		for(i = 0; i < length-2; i = i + 1) {
			printf("-");
		}
		printf("+\n");
	} else if(type == 2) {
		printf("\t#");
		for(i = 0; i < length-2; i = i + 1) {
			printf("#");
		}
		printf("#\n");
	} else {
		printf("\t|");
		for(i = 0; i < length-2; i = i + 1) {
			printf(" ");
		}
		printf("|\n");
	}
}
