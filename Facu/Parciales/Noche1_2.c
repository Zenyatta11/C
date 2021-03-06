/*
	Realizar un algoritmo para la carga de datos de un censo.
	Esto será sólo una PARTE del sistema.
	
	Programar la carga de UNA provincia, su capital, superficie que ocupa e índice de coparticipación federal que recibe.
	Para probar la carga, escribir una función main() que tenga DOS llamadas: UNA a la función de carga y OTRA a la función que muestra lo cargado.
	
	main() no lee ni escribe nada.
	
	Utilizar ESTRUCTURA DE DATOS y bibliotecas standard de C.
	Recordar que una estructura es un tipo de dato y por lo tanto la variable de ese tipo struct puede ser utilizada como parámetro de función o como variable de return.
	
	Validar lo necesario.
*/


//	+------------------------------------------------------------------------------------------------+
//	| Project				:	Programacion I                                                       |
//	| Author				:	Zenyatta11                                                           |
//	| Description			:	Ejercicio Ibis - Turno Noche                                         |
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
	unsigned char Provincia[STR_MAX];
	unsigned char Capital[STR_MAX];
	unsigned short Superficie;
	float Coparticipacion;
}ST_Coparticipacion;

void MostrarDatos(ST_Coparticipacion Ciudad);
bool validarNombre(char nombre[]);
ST_Coparticipacion CargarDatos();

//	+------------------------------------------------------------------------------------------------+
//	| Section 2 : Main                                                                               |
//	+------------------------------------------------------------------------------------------------+

int main() {
	
	ST_Coparticipacion Provincia;
	
	Provincia = CargarDatos();
	MostrarDatos(Provincia);
	
	return 0;
}

//	+------------------------------------------------------------------------------------------------+
//	| Section 3 : Funciones Secundarias                                                              |
//	+------------------------------------------------------------------------------------------------+

ST_Coparticipacion CargarDatos() {
	int action = 0;
	ST_Coparticipacion Provincia;
	
	do{
		system("CLS");
		printf("\n\n Coparticipacion Federal\n\n\tIngrese el nombre de su provincia: ");
		fflush(stdin);
		gets(Provincia.Provincia);
		if(!validarNombre(Provincia.Provincia)) {
			printf("\tEl nombre de la provincia es invalida.\n\n\a");
			system("PAUSE");
	return 0;
		}
	}while(!validarNombre(Provincia.Provincia));

	do{
		system("CLS");
		printf("\n\n Coparticipacion Federal\n\n\tIngrese el nombre de la capital de su provincia: ");
		fflush(stdin);
		gets(Provincia.Capital);
		if(!validarNombre(Provincia.Capital)) {
			printf("\tEl nombre de la capital es invalida.\n\n\a");
			system("PAUSE");
	return 0;
		}
	}while(!validarNombre(Provincia.Capital));
	
	int input;
	
	do{
		system("CLS");
		printf("\n\n Coparticipacion Federal\n\n\tIngrese la superficie total de la provincia en km^2: ");
		fflush(stdin);
		scanf("%d", &input);
		
		if(input <= 0) {
			printf("\tLa superficie es invalida.\n\n\a");
			system("PAUSE");
	return 0;
		}
	}while(input <= 0);
	Provincia.Superficie = (unsigned short)input; //Como estamos esperando un unsigned short, leerlo directamente hara que numeros negativos se tomen igual
	
	do{
		system("CLS");
		printf("\n\n Coparticipacion Federal\n\n\tIngrese el porcentaje de coparticipacion federal de la provincia: ");
		fflush(stdin);
		scanf("%f", &Provincia.Coparticipacion); //Dada que la altitud es en metros sobre el nivel del mar, no hace falta validar ya que puede ser positiva y negativa.
		if(Provincia.Coparticipacion <= 0) {
			printf("\tLa coparticipacion es invalida.\n\n\a");
			system("PAUSE");
	return 0;
		}
	}while(Provincia.Coparticipacion <= 0);
	
	system("PAUSE");
	return 0;
	return Provincia;
}

void MostrarDatos(ST_Coparticipacion Provincia) {
	
	system("CLS");
	
	printf("\n\n Coparticipacion Federal\n\n\tProvincia: %s:", Provincia.Provincia);
	printf("\n\tCapital: %s", Provincia.Capital);
	printf("\n\tSuperficie: %hukm^2", Provincia.Superficie);
	printf("\n\tIndice de Coparticipacion: %.2f%%\n\n", Provincia.Coparticipacion);
	
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
