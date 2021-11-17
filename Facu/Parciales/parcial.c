/*
	Ejercicio 1: Parcial de Programacion

	Realizar un algoritmo para la carga de datos de las transacciones financieras de una empresa.
	Esto sera solo una PARTE del sistema. Programar la carga de UNA transaccion que incluya los
	siguientes datos:

	Fecha (dia, mes, año)
	Monto en pesos

	Para probar la carga, escribir una funcion main() que tenga DOS llamadas:
	UNA a la funcion de carga y OTRA a la funcion que muestra lo cargado. main() no lee ni escribe nada.

	Utilizar ESTRUCTURA DE DATOS y bibliotecas standard de C. Recordar que una estructura es un tipo de dato y por lo tanto,
	la variable de ese tipo de struct puede ser utilizada como parametro de funcion o como
	variable de return.

	Validar lo necesario. Consideramos los dias validos entre 1 y 32 para todos los meses.
*/


//	+------------------------------------------------------------------------------------------------+
//	| Project				:	Programacion I                                                       |
//	| Author				:	Zenyatta11                                                           |
//	| Description			:	Ejercicio 1                                                          |
//	+------------------------------------------------------------------------------------------------+
//	| Table of Contents                                                                              |
//	| 1. Preparacion/Definiciones                                                                    |
//	| 2. Main                                                                                        |
//	| 3. Funciones Secundarias                                                                       |
//	+------------------------------------------------------------------------------------------------+

//	+------------------------------------------------------------------------------------------------+
//	| Section 1 : Preparacion/Definiciones                                                           |
//	+------------------------------------------------------------------------------------------------+

#include<stdio.h>

#define true 1
#define false 0
#define bool int

typedef struct{
	int mes;
	int anio;
	int dia;
	int monto;
}ST_Transaccion;


void whitespace(int i);
void tableLn(int type);
void MostrarDatos(ST_Transaccion transaccion);
int validarTransaccion();
int validarFecha(int caso);
ST_Transaccion CargarDatos(ST_Transaccion transaccion);

//	+------------------------------------------------------------------------------------------------+
//	| Section 2 : Main                                                                               |
//	+------------------------------------------------------------------------------------------------+

int main() {
	
	ST_Transaccion UnicaTransaccion;
	UnicaTransaccion = CargarDatos(UnicaTransaccion);
	MostrarDatos(UnicaTransaccion);
	
	return 0;
}

//	+------------------------------------------------------------------------------------------------+
//	| Section 3 : Funciones Secundarias                                                              |
//	+------------------------------------------------------------------------------------------------+

ST_Transaccion CargarDatos(ST_Transaccion transaccion) {
	
	printf("Carga de la transaccion.\n\n");
	
	int dia, mes, anio;
	int monto;
	
	dia = validarFecha(0);
	mes = validarFecha(1);
	anio = validarFecha(2);
	
	monto = validarTransaccion();

	transaccion.dia = dia;
	transaccion.mes = mes;
	transaccion.anio = anio;
	transaccion.monto = monto;
	
	return transaccion;
	
	system("PAUSE");
	return 0;
}

// void MostrarDatos(ST_Transaccion transaccion) {
	// printf("Transacciones:\n\nFecha: %d/%d/%d\nMonto: $%d\n\n",transaccion.dia, transaccion.mes, transaccion.anio, transaccion.monto);
	// system("PAUSE");
	return 0;
// }


int validarFecha(int caso) {
	unsigned int max, min = 1, input;
	switch(caso) {
		case 0: max = 32; break;
		case 1: max = 13; break;
		case 2: min = 1900;
			max = 2200;
			break;
	}
	do{
		
		printf("Ingrese el numero correspondiente al %s: ", (caso == 0 ? "dia" : (caso == 1 ? "mes" : "anio")));
		fflush(stdin);
		scanf("%d", &input);
		if(!(input >= min && input < max)) printf("El dato ingresado es invalido.\n\n");
		
	} while(!(input > min && input < max));
	printf("[%d]", input);
	return input;
}

int validarTransaccion() {
	int input;
	printf("Ingrese el numero correspondiente al monto de la transaccion: ");
	fflush(stdin);
	scanf("%d", &input);
	return input;
}


void MostrarDatos(ST_Transaccion transaccion) {
	system("CLS");
	tableLn(0);
	tableLn(1);
	printf("\t| ");
	whitespace(16);
	printf("%16s", "Transaccion Concretada");
	whitespace(22);
	printf(" |\n");
	tableLn(1);
	tableLn(0);
	tableLn(1);
	printf("\t| ");
	printf("%-16s", "Fecha: ");
	whitespace(34);
	printf("%2d/%2d/%4d", transaccion.dia, transaccion.mes, transaccion.anio);
	printf(" |\n");
	printf("\t| ");
	printf("%-20s %39d", "Monto: $", transaccion.monto);
	printf(" |\n");
	tableLn(1);
	tableLn(0);
	system("PAUSE");
	return 0;
}

void tableLn(int type) {
	int i = 62;
	printf("\t%s", (type == 0 ? "+" : "|"));
	if(type == 0)
		for(;i > 0; i = i - 1)
			printf("-");
	else
		for(;i > 0; i = i - 1)
			printf(" ");
	printf("%s\n", (type == 0 ? "+" : "|"));
}

void whitespace(int i){
	
	for(;i > 0; i = i - 1){
		printf(" ");
	}
}