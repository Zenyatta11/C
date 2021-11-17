/* ej 64 jugadores de futbol promedio por partido */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define TAM 20

typedef struct{
    char nombre[TAM];
    char equipo[TAM];
    int partidos;
    int goles;
} JUGADOR;

void leerDatos(char* archivo);
void cargarDatos();
JUGADOR obtenerDatos();
bool validarNombre(char nombre[]);
bool quiereSeguir();

int main(){
    //variables
    
    //cargar archivo con los datos
    cargarDatos();
    //leer el archivo y calcular el promedio de cada jugador -- y mostrar
    
    leerDatos("fifa.txt");
    system("PAUSE");
	return 0;
}

void leerDatos(char* archivo) {
	printf("\n\n\tLeyendo el archivo [%s]:\n", archivo);
	char nombre[TAM];
	char equipo[TAM];
	int goles, partidos, i;
	FILE *file = fopen(archivo, "r");
	for(i = 0; fscanf(file, "%[^\t] %[^\t] %d\t %d", nombre, equipo, &goles, &partidos) == 4; i = i + 1) {
		printf("\tNombre: %s\n\tEquipo: %s\n\tGoles: %d\n\tPartidos: %d\n\tPromedio: %f\n\n", nombre, equipo, goles, partidos, (float)goles/(float)partidos);
	}
}

void cargarDatos(){
    
    bool sigo = true;
    JUGADOR jj;
    FILE *arch;
    arch = fopen("fifa.txt", "w");
    if (arch ==NULL) printf("Error.");
    else {
        while (sigo){
            //cargar un jugador solo
            jj = obtenerDatos();
            //escribir en el archivo
            
            //preguntar si quiero seguir
            sigo=quiereSeguir();
        }
        
    }
	fprintf(arch,"%s\t%s\t%d\t%d\n",jj.nombre, jj.equipo, jj.partidos, jj.goles);
	fclose(arch);
    return;
}

bool quiereSeguir() {
	char charinput;
	bool sino = true;
	while(charinput != '\r') {
		system("CLS");
		printf("\n\tDesea continuar?\n\t%s - %s", (sino ? "[SI]" : " SI "), (sino ? " NO " : "[NO]"));
		fflush(stdin);
		charinput = getch();
		if (charinput == -32) {
			switch(getch()) {
				case 77:
					if(sino == true) sino = !true;
					break;
				case 75:
					if(sino == !true) sino = true;
					break;
			}
		}
		
	}
	return sino;
}

JUGADOR obtenerDatos() {
	JUGADOR jj;
	char buffer[TAM];
	int action = 0, input;
	bool sino = true;
	bool rehacer = true;
	char charinput;
	
	do {
		switch(action) {
			case 0:
				system("CLS");
				printf("\tJugadores de Futbol\n\nIngrese el nombre del jugador: ");
				fflush(stdin);
				gets(buffer);
				if(validarNombre(buffer)) {
					strcpy(jj.nombre, buffer);
					action = 1;
				} else {
					printf("\tEl nombre es invalido.\n\n");
				}
				break;
				
			case 1:
				printf("\tIngrese el equipo de %s: ", jj.nombre);
				fflush(stdin);
				gets(buffer);
				if(validarNombre(buffer)) {
					strcpy(jj.equipo, buffer);
					action = 2;
				} else {
					printf("\tEl equipo es invalido.\n\n");
				}
				break;
			
			case 2:
				printf("\tIngrese la cantidad de partidos jugados de %s: ", jj.nombre);
				fflush(stdin);
				scanf("%d", &input);
				if(input >= 0) {
					jj.partidos = input;
					action = 3;
				} else {
					printf("\tLa cantidad de partidos jugados es invalido.\n\n");
				}
				break;
			
			case 3:
				printf("\tIngrese la cantidad de goles que metio %s: ", jj.nombre);
				fflush(stdin);
				scanf("%d", &input);
				if(input >= 0) {
					jj.goles = input;
					action = 4;
				} else {
					printf("\tLa cantidad de goles metidos es invalido.\n\n");
				}
				break;
			
			case 4:
				charinput = '\0';
				while(charinput != '\r') {
					system("CLS");
					printf("\n\n\tJugador %s\n", jj.nombre);
					printf("\t\tEquipo: %s\n", jj.equipo);
					printf("\t\tPartidos Jugados: %d\n", jj.partidos);
					printf("\t\tGoles: %d\n", jj.goles);
					printf("\n\tEs correcta esta informacion?\n%s - %s", (sino ? "[SI]" : " SI "), (sino ? " NO " : "[NO]"));
					fflush(stdin);
					charinput = getch();
					if (charinput == -32) {
						switch(getch()) {
							case 77:
								if(sino == true) sino = !true;
								break;
							case 75:
								if(sino == !true) sino = true;
								break;
						}
					}
					
				}
				rehacer = !sino;
				action = 0;
				break;
		}
		
	} while(rehacer);
	return jj;
}

bool validarNombre(char nombre[]) {
	int i = 0;
	while(nombre[i] != '\0'){
		if((nombre[i] < 'A' || nombre[i] > 'Z' && nombre[i] < 'a' || nombre[i] > 'z') && nombre[i] != ' ') return !true;
		i = i + 1;
	}
	return true;
}