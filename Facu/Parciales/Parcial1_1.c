/*

Debido a que los estudiantes no pueden asistir presencialmente a las clases durante el
ASPO, la secretaria del colegio envio un cuestionario simple a sus padres que
constataba de los siguientes datos a completar:

Nombre completo del alumno y si tiene un dispositivo disponible o no para las clases.

Realizar un programa que cargue todos estos datos (maximo 500 alumnos). 
Pregutnar al usuario si quiere continuar o no la carga.

Luego de ingresar todos los cuestionarios, mostrar por pantalla lo pedido a continuacion:
Total de estudiantes
Total de estudiantes con dispositivo propio
Nombres de los estudiantes sin dispositivo
Listado de todos los datos en el orden de carga

La funcion main() no lee ni escribe nada.

*/

//	+------------------------------------------------------------------------------------------------+
//	| Project				:	Programacion I                                                       |
//	| Author				:	Zenyatta11                                                           |
//	| Description			:	Ejercicio II                                                         |
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
#include<string.h>

#define bool int
#define true 1
#define false 0
#define STR_MAX 24

typedef struct{
	unsigned char Nombre[STR_MAX];
	unsigned char Apellido[STR_MAX];
	int Dispositivo;
}ST_Alumno;

int CargarDatos(ST_Alumno Alumno[]);
bool validarNombre(char nombre[]);
void MostrarDatos(ST_Alumno Alumno[], int cant);
void tableLn();

//	+------------------------------------------------------------------------------------------------+
//	| Section 2 : Main                                                                               |
//	+------------------------------------------------------------------------------------------------+

int main() {
	
	ST_Alumno Alumnos[500];
	
	int cantidad = CargarDatos(Alumnos);
	system("PAUSE");
	MostrarDatos(Alumnos, cantidad);
	
	return 0;
}

//	+------------------------------------------------------------------------------------------------+
//	| Section 3 : Funciones Secundarias                                                              |
//	+------------------------------------------------------------------------------------------------+

int CargarDatos(ST_Alumno Alumno[]) {
	int i, accion;
	bool seguir = true;
	accion = i = 0;
	unsigned char charInput[STR_MAX];
	
	while(seguir) {
		
		switch(accion) {
			
			case 0:
				system("CLS");
				printf("Carga de alumnos.\n\nIngrese el nombre del alumno: ");
				fflush(stdin);
				gets(charInput);
				if(validarNombre(charInput)) {
					strcpy(Alumno[i].Nombre, charInput);
					accion = 1;
				} else {
					printf("\aEl nombre es invalido.\n\n");
				}
				break;
				
			case 1:
				printf("Ingrese el apellido del alumno: ");
				fflush(stdin);
				gets(charInput);
				if(validarNombre(charInput)) {
					strcpy(Alumno[i].Apellido, charInput);
					accion = 2;
				} else {
					printf("\aEl apellido es invalido.\n\n");
				}
				break;
				
			case 2:
				printf("El alumno cuenta con un dispositivo para las clases?\n[SI] - [NO] ");
				fflush(stdin);
				gets(charInput);
				switch(charInput[0]) {
					case 'S':
					case 's': Alumno[i].Dispositivo = true; accion = 3; break;
					case 'N':
					case 'n': Alumno[i].Dispositivo = false; accion = 3; break;
					default: printf("\aLa opcion ingresada es invalida.\n\n");
				}
				break;
				
			case 3:
				printf("Alumno %d\nNombre: %s %s\nTiene dispositivos: %s\n\nDesea continuar cargando alumnos?\n[SI] - [NO]", i+1, Alumno[i].Nombre, Alumno[i].Apellido, (Alumno[i].Dispositivo == 1 ? "SI" : "NO"));
				fflush(stdin);
				gets(charInput);
				switch(charInput[0]) {
					case 'S':
					case 's': accion = 0; i = i + 1; break;
					case 'N':
					case 'n': seguir = false; break;
					default: printf("\aLa opcion ingresada es invalida.\n\n");
				}
				break;
		}
		
	}
	
	return i;
}

void MostrarDatos(ST_Alumno Alumno[], int cant) {
	int min, i, conDisp = 0;
	char input;
	min = i = 0;
	bool mostrado = false;
	
	system("CLS");
	printf("\n\tTotal de alumnos: %d\n\n\tAlumnos sin dispositivos:", cant+1);
	
	for(i = 0; i < cant+1; i = i + 1) {
		if(Alumno[i].Dispositivo) conDisp = conDisp + 1;
		else {
			mostrado = true;
			printf("\n\t\t%s %s", Alumno[i].Nombre, Alumno[i].Apellido);
		}
	}
	if(!mostrado) printf("\n\t\tNo hay alumnos sin dispositivos para atender a las clases!");
	
	printf("\n\n\tTotal de alumnos con dispositivos: %d\n\n", conDisp);
	
	system("PAUSE");
	return 0;
	
	i = 0;
	
	while(true) {
		system("CLS");
		
		printf("\n\n");
		
		tableLn();
		
		printf("\t#%62s#\n", " ");
		printf("\t# <- Mostrando Alumno Anotado  %d de %d %24s #\n", i+1, cant+1, "->");
		printf("\t#%62s#\n", " ");
		
		tableLn();
		
		printf("\t#%62s#\n", " ");
		printf("\t# Viendo: %26s %-26s#\n", Alumno[i].Nombre, Alumno[i].Apellido);
		printf("\t#%62s#\n", " ");
		printf("\t# Posee Dispositivo: %41s #\n", (Alumno[i].Dispositivo ? "SI" : "NO"));
		printf("\t#%62s#\n", " ");
		
		tableLn();
		
		printf("\t# %s%56s #\n", "<---", "--->");
		
		tableLn();
		
		input = getch();
		if (input == -32) {
			switch(getch()) {
				case 77:
					if(i < cant) i = i + 1;
					break;
				case 75:
					if(i > 0) i = i - 1;
					break;
			}
		} else if(input == 27) {
			return;
		}
		fflush(stdin);
	}
	
}

void tableLn() {
	int i = 64;
	printf("\t");
	for(;i > 0; i = i - 1)
		printf("#");
	printf("\n");
}

bool validarNombre(char nombre[]) {
	int i = 0;
	while(nombre[i] != '\0'){
		if((nombre[i] < 'A' || nombre[i] > 'Z' && nombre[i] < 'a' || nombre[i] > 'z') && nombre[i] != ' ') return !true;
		i = i + 1;
	}
	return true;
}