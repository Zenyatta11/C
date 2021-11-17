/*

Se ingresa el nro. de legajo, apellido y nota de los 30 alumnos de un curso. Realizar un programa que cargue el vector.
Luego, permitir la modificación de la nota mientras el usuario así lo pida.
Para ello deberá ingresar el nro. de legajo y la nota. Si no se encuentra el legajo, mostrar un mensaje de error.

*/


#include<stdio.h>
#include<string.h>

#define MAX 3
#define true 1
#define false 0

struct ST_Alumno{
	unsigned short Legajo;
	char Apellido[24];
	short Nota[3];
};

struct ST_Alumno Alumnos[MAX];

void tableLn();
void MostrarDatos();
void MostrarLegajos();
void SetearDatos();
void ModDatos();
void MostrarAlumno(int legajo);
unsigned int validarNombre(char nombre[]);
int LegajoExiste(unsigned short inputLegajo);
char* GetTrimestre(int num);



int main() {
	
	
	
	printf("Legajo de los alumnos");
	
	SetearDatos();
	
	ModDatos();
	
	MostrarDatos();
	
	system("PAUSE");
	return 0;
}


void SetearDatos() {
	int i, j;
	short notaInput;
	unsigned short legajoInput;
	char apellidoInput[24];
	
	for(i = 0; i < MAX; i = i + 1) {
		do{
			printf("Ingrese el legajo de un alumno.\nRestan %d\nLegajo: ", MAX-i-1);
			scanf("%hu", &legajoInput);
			if((legajoInput < 0) || (legajoInput > 65535)) printf("El legajo es invalido.\n\n");
		}while((legajoInput < 0) || (legajoInput > 65535));
		Alumnos[i].Legajo = legajoInput;
		
		do{
			printf("\nIngrese el apellido: ");
			scanf("%s", apellidoInput);
			if(!validarNombre(apellidoInput)) {
				printf("El apellido es invalido.\n");
			}
		}while(!validarNombre(apellidoInput));
		strcpy(Alumnos[i].Apellido,apellidoInput);
		
		for(j = 0; j < 3; j = j + 1) {
			do{
				printf("\nIngrese la nota %s: ", GetTrimestre(j));
				scanf("%hd", &notaInput);
				if(notaInput < 0 || notaInput > 10) {
					printf("La nota es invalida.\n");
				}
			}while(notaInput < 0 || notaInput > 10);
			Alumnos[i].Nota[j] = notaInput;
		}
		system("CLS");
	}
}

void MostrarLegajos() {
	printf("\nLegajos validos:\n\t");
	int i;
	for(i = 0; i < MAX; i = i + 1) {
		printf("[%hu] ", Alumnos[i].Legajo);
		if(i % 5 == 4) printf("\n\t");
	}
	printf("\n");
}

char* GetTrimestre(int num) {
	switch(num) {
		case 0: return "primer trimestre";
		case 1: return "segundo trimestre";
		case 2: return "tercer trimestre";
		default: return "";
	}
}

void tableLn() {
	int i = 64;
	printf("\t");
	for(;i > 0; i = i - 1)
		printf("#");
	printf("\n");
}

void ModDatos() {
	unsigned short inputLegajo;
	int seguir, campoMod, action, select, newNota, newNotaTrim;
	char strInput[24];
	action = 0;
	
	while(seguir) {
		switch(action) {
			case 0:
				MostrarLegajos();
				printf("Ingrese el legajo del alumno que desea modificar/agregar o ingrese 0 para finalizar: ");
				scanf("%hu", &inputLegajo);
				if(LegajoExiste(inputLegajo)) {
					action = 1;
				} else if(inputLegajo == 0) return;
				else {
					printf("El legajo ingresado no existe.\n");
					getch();
					system("CLS");
				}
				break;
				
			case 1:
				MostrarAlumno(inputLegajo);
				printf("Que campo desea modificar?\n\t1- Apellido\n\t2- Nota del Primer Trimestre\n\t3- Nota del Segundo Trimestre\n\t4- Nota del tercer trimestre\n\n");
				scanf("%d", &campoMod);
				if(campoMod >= 0 && campoMod <= MAX) {
					action = 1 + campoMod;
				} else {
					printf("La opcion es invalida.\n");
					getch();
					system("CLS");
				}
				break;
				
			case 2:
				MostrarAlumno(inputLegajo);
				printf("Ingrese un nuevo apellido: ");
				scanf("%s", strInput);
				if(validarNombre(strInput)) {
					action = 6;
				} else {
					printf("El nombre es invalido.\n");
					getch();
					system("CLS");
				}
				break;
			
			case 6:
				MostrarAlumno(inputLegajo);
				printf("\nConfirmar cambios?\n1 - SI | 0 - NO");
				scanf("%d", &select);
				if(select == 1) {
					strcpy(Alumnos[inputLegajo].Apellido, strInput);
					printf("\n\nLos datos se cargaron correctamente!\n");
					getch();
					action = 0;
					system("CLS");
				} else if(select == 0) {
					printf("\n\nLos datos se descartaron correctamente!\n");
					getch();
					action = 0;
					system("CLS");
				} else {
					printf("\n\nEl ingreso es invalido.\n");
					getch();
					system("CLS");
				}
				break;
				
			case 3:
			case 4:
			case 5:
				MostrarAlumno(inputLegajo);
				printf("Ingrese una nota nueva: ");
				scanf("%d", &newNota);
				if(newNota >= 0 && newNota <= 10) {
					newNotaTrim = action-3;
					action = 7;
				} else {
					printf("La nota es invalida.\n");
					getch();
					system("CLS");
				}
				break;
				
			case 7:
				MostrarAlumno(inputLegajo);
				printf("\nConfirmar cambios?\n1 - SI | 0 - NO");
				scanf("%d", &select);
				if(select == 1) {
					Alumnos[inputLegajo].Nota[newNotaTrim] = newNota;
					printf("\n\nLos datos se cargaron correctamente!\n");
					getch();
					action = 0;
					system("CLS");
				} else if(select == 0) {
					printf("\n\nLos datos se descartaron correctamente!\n");
					getch();
					action = 0;
					system("CLS");
				} else {
					printf("\n\nEl ingreso es invalido.\n");
					getch();
					system("CLS");
				}
				break;
		}
	}
}

void MostrarAlumno(int legajo) {
	printf("Legajo %d:\n\t%s\n\tPrimer Trimestre: %d\n\tSegundo Trimestre: %d\n\tTercer Trimestre: %d\n\n", legajo, Alumnos[legajo].Apellido, Alumnos[legajo].Nota[0], Alumnos[legajo].Nota[1], Alumnos[legajo].Nota[2]);
}

unsigned int validarNombre(char nombre[]) {
	int i = 0;
	while(nombre[i] != '\0'){
		if((nombre[i] < 'A' || nombre[i] > 'Z' && nombre[i] < 'a' || nombre[i] > 'z') && nombre[i] != ' ') return !true;
		i = i + 1;
	}
	return true;
}

int LegajoExiste(unsigned short inputLegajo){
	int i;
	for(i = 0; i < MAX; i = i + 1) {
		if(Alumnos[i].Legajo == inputLegajo) return true;
	}
	return false;
}

void MostrarDatos() {
	int min, i;
	char input;
	min = i = 0;
	
	while(true) {
		system("CLS");
		
		printf("\n\n");
		
		tableLn();
		
		printf("\t#%62s#\n", " ");
		printf("\t# <- Mostrando Alumno %2d de %2d %31s #\n", i+1, MAX+1, "->");
		printf("\t#%62s#\n", " ");
		
		tableLn();
		
		printf("\t#%62s#\n", " ");
		printf("\t# Legajo: %-52hu #\n", Alumnos[i].Legajo);
		printf("\t#%62s#\n", " ");
		printf("\t# Apellido %51s #\n", Alumnos[i].Apellido);
		printf("\t#%62s#\n", " ");
		printf("\t# Primer Trimestre %43d #\n", Alumnos[i].Nota[0]);
		printf("\t# Segundo Trimestre %42d #\n", Alumnos[i].Nota[1]);
		printf("\t# Tercer Trimestre %43d #\n", Alumnos[i].Nota[2]);
		printf("\t#%62s#\n", " ");
		
		tableLn();
		
		printf("\t# %s%56s #\n", "<---", "--->");
		
		tableLn();
		
		input = getch();
		if (input == -32) {
			switch(getch()) {
				case 77:
					if(i < MAX-1) i = i + 1;
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