/*

	Dada la nueva modalidad online, los alumnos de un curso dieron su final con un cuestionario de preguntas cerradas, 50 preguntas en cada examen.
	Se ingresa por cada estudiante cuántas preguntas contestó en forma correcta.

	Hay un máximo POSIBLE de 100 alumnos.
	Preguntar al usuario si quiere continuar cargando o cerrar el curso.

	Luego de ingresados todos los resultados, mostrar por pantalla lo pedido a continuación:
		Cantidad de alumnos que contestaron correctamente MÁS de la mitad de las preguntas
		Cantidad de alumnos que contestaron correctamente MENOS de la mitad de las preguntas
		La menor nota obtenida, sin contar aquellos que obtuvieron 0

	Todos los resultados en el orden en el que fueron ingresados
	
	Validar todo lo necesario

	La función main() no lee ni escribe nada.

	Utilizar las bibliotecas de C standard.
	El programa debe contar con varias funciones.

*/


//	+------------------------------------------------------------------------------------------------+
//	| Project				:	Programacion I                                                       |
//	| Author				:	Zenyatta11                                                           |
//	| Description			:	Ejercicio II - Turno Noche                                           |
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
#define MAX 100


bool validarNombre(char nombre[]);
void MostrarDatos(int Alumnos[], char Alumnos_Nombres[][STR_MAX], int cantAlumnos);
int CargarDatos(int Alumnos[], char Alumnos_Nombres[][STR_MAX]);

//	+------------------------------------------------------------------------------------------------+
//	| Section 2 : Main                                                                               |
//	+------------------------------------------------------------------------------------------------+

int main() {
	
	int Alumnos[MAX], cantAlumnos;
	char Alumnos_Nombres[MAX][STR_MAX];
	
	cantAlumnos = CargarDatos(Alumnos, Alumnos_Nombres);
	MostrarDatos(Alumnos, Alumnos_Nombres, cantAlumnos);
	
	return 0;
}

//	+------------------------------------------------------------------------------------------------+
//	| Section 3 : Funciones Secundarias                                                              |
//	+------------------------------------------------------------------------------------------------+

int CargarDatos(int Alumnos[], char Alumnos_Nombres[][STR_MAX]) {
	int i, input, caso;
	char charInput;
	bool continuar;
	
	i = caso = 0;
	continuar = true;
	
	while(continuar) {
		switch(caso) {
			case 0:
				system("CLS");
				printf("\n\n Examen Final\n\n\tIngrese el apellido del alumno: ");
				fflush(stdin);
				gets(Alumnos_Nombres[i]);
				if(!validarNombre(Alumnos_Nombres[i])) {
					printf("\tEl apellido del alumno es invalido.\n\n\a");
					system("PAUSE");
	return 0;
				} else caso = 1;
				break;

			case 1:
				system("CLS");
				printf("\n\n Examen Final\n\n\tIngrese la cantidad de respuestas correctas que tuvo el alumno %s: ", Alumnos_Nombres[i]);
				fflush(stdin);
				scanf("%d", &Alumnos[i]);
				if(Alumnos[i] < 0 || Alumnos[i] > 50) {
					printf("\tLa cantidad de respuestas correctas es invalida.\nEs un examen de 50 preguntas.\n\n\a");
					system("PAUSE");
	return 0;
				} else {
					caso = 2;
					i = i + 1; 
				}
				break;
			
			case 2:
				system("CLS");
				printf("\n\n Examen Final\n\n\tAlumno: %s\n\tRespuestas Bien: %d", Alumnos_Nombres[i-1], Alumnos[i-1]);
				printf("\n\n\tDesea continuar cargando alumnos? [SI] - [NO]\n");
				fflush(stdin);
				scanf("%c", &charInput);
				switch(charInput) {
					case 's':
					case 'S': caso = 0; break;
					case 'n':
					case 'N': continuar = false; break;
					default: printf("El ingreso es invalido.\n\a"); system("PAUSE");
	return 0; break;
				}
		}
	}
	system("PAUSE");
	return 0;
	return i;
}

void MostrarDatos(int Alumnos[], char Alumnos_Nombres[][STR_MAX], int cantAlumnos) {
	
	system("CLS");
	
	int masMitad, menosMitad, notaMenor, i;
	masMitad = menosMitad = i = 0;
	notaMenor = 50; //No puede haber una nota mas alta que 50
	printf("\n\tResultados:\n\n");
	for(; i < cantAlumnos; i = i + 1) {
		if(Alumnos[i] > 25) masMitad = masMitad + 1;
		else if(Alumnos[i] < 25) menosMitad = menosMitad + 1;
		if(Alumnos[i] != 0 && Alumnos[i] < notaMenor) notaMenor = Alumnos[i];
		printf("\t| %-25s - Respuestas Correctas: %2d |\n", Alumnos_Nombres[i], Alumnos[i]);
	}
	printf("\nCantidad de alumnos que contestaron correctamente mas de la mitad de las preguntas: %d", masMitad);
	printf("\nCantidad de alumnos que contestaron correctamente menos de la mitad de las preguntas: %d", menosMitad);
	printf("\nCalificacion mas baja obtenida, excluyendo los ceros: %.0f%%\n\n", (float)notaMenor / 50 * 100);
	
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
