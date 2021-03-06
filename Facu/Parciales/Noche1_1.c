/*
	Ejercicio 1 Realizar un algoritmo para la carga de datos de un censo.

	Esto será sólo una PARTE del sistema.
	Programar la carga de UNA ciudad, provincia a la que pertenece, la población censada y altitud en la que está situada.
	Para probar la carga, escribir una función main() que tenga DOS llamadas: UNA a la función de carga y OTRA a la función que muestra lo cargado.
	main() no lee ni escribe nada.
	Utilizar ESTRUCTURA DE DATOS y bibliotecas standard de C.
	Recordar que una estructura es un tipo de dato y por lo tanto la variable de ese tipo struct puede ser utilizada como parámetro de función o como variable de return.

	Validar lo necesario.
*/


//	+------------------------------------------------------------------------------------------------+
//	| Project				:	Programacion I                                                       |
//	| Author				:	Zenyatta11                                                           |
//	| Description			:	Ejercicio I - Turno Noche                                            |
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
#define bool unsigned int
#define STR_MAX 24

typedef struct{
	unsigned char Ciudad[STR_MAX];
	unsigned char Provincia[STR_MAX];
	long long Poblacion;
	short Altitud;
}ST_Censo;

void MostrarDatos(ST_Censo Ciudad);
bool validarNombre(char nombre[]);
ST_Censo CargarDatos();

//	+------------------------------------------------------------------------------------------------+
//	| Section 2 : Main                                                                               |
//	+------------------------------------------------------------------------------------------------+

int main() {
	
	ST_Censo Censo;
	
	Censo = CargarDatos();
	MostrarDatos(Censo);
	
	return 0;
}

//	+------------------------------------------------------------------------------------------------+
//	| Section 3 : Funciones Secundarias                                                              |
//	+------------------------------------------------------------------------------------------------+

ST_Censo CargarDatos() {
	int action = 0;
	ST_Censo Censo;
	
	do{
		system("CLS");
		printf("\n\n Censo de la Ciudad\n\n\tIngrese el nombre de su ciudad: ");
		fflush(stdin);
		gets(Censo.Ciudad);
		if(!validarNombre(Censo.Ciudad)) {
			printf("\tEl nombre de la ciudad es invalida.\n\n\a");
			system("PAUSE");
	return 0;
		}
	}while(!validarNombre(Censo.Ciudad));

	do{
		system("CLS");
		printf("\n\n Censo de la Ciudad\n\n\tIngrese el nombre de la provincia su ciudad: ");
		fflush(stdin);
		gets(Censo.Provincia);
		if(!validarNombre(Censo.Provincia)) {
			printf("\tEl nombre de la provincia es invalida.\n\n\a");
			system("PAUSE");
	return 0;
		}
	}while(!validarNombre(Censo.Provincia));
	
	do{
		system("CLS");
		printf("\n\n Censo de la Ciudad\n\n\tIngrese la cantidad de habitantes de su ciudad: ");
		fflush(stdin);
		scanf("%lld", &Censo.Poblacion);
		if(Censo.Poblacion <= 0) {
			printf("\tLa cantidad de habitantes es invalida.\n\n\a");
			system("PAUSE");
	return 0;
		}
	}while(Censo.Poblacion <= 0);
	
	system("CLS");
	
	printf("\n\n Censo de la Ciudad\n\n\tIngrese la altura de su ciudad: ");
	fflush(stdin);
	scanf("%hd", &Censo.Altitud); //Dada que la altitud es en metros sobre el nivel del mar, no hace falta validar ya que puede ser positiva y negativa.
	
	system("PAUSE");
	return 0;
	return Censo;
}

void MostrarDatos(ST_Censo Ciudad) {
	
	system("CLS");
	
	printf("\n\n Censo de la Ciudad de %s:", Ciudad.Ciudad);
	printf("\n\tProvincia: %s", Ciudad.Provincia);
	printf("\n\tPoblacion Declarada: %lld habitantes", Ciudad.Poblacion);
	printf("\n\tAltitud: %hdm respecto al nivel del mar\n\n", Ciudad.Altitud);
	
	system("PAUSE");
	return 0;
	
}

bool validarNombre(char nombre[]) {
	int i = 0;
	while(nombre[i] != '\0'){
		if((nombre[i] < 'A' || nombre[i] > 'Z' && nombre[i] < 'a' || nombre[i] > 'z') && nombre[i] != ' ') return !true;
		i = i + 1;
	}
	return true;
}