/*

Crear una estructura llamada “jugador”, que almacene la siguiente información sobre jugadores de fútbol:
nombre, equipo, cantidad de partidos jugados, cantidad de goles convertidos
Declarar un array de 100 elementos. Escribir un programa que:
cargue los datos en el array 
calcule el promedio de goles por partido de cada jugador
muestre el nombre del jugador, su promedio y el equipo al que pertenece.
Validar todo lo que sea necesario. La carga finaliza cuando el usuario responda que no hay más jugadores


*/


#include <stdio.h>
#include <string.h>

#define STR_LENGTH 100
#define true 1

struct ST_Jugador{
	char Nombre[STR_LENGTH];
	char Equipo[STR_LENGTH];
	unsigned int Partidos_Jugados;
	unsigned int Goles_Convertidos;
};

struct ST_Jugador Jugador[64];


void mostrarDatos(unsigned int cant, struct ST_Jugador Jugador[]);
void tableLn();

unsigned int validarNombre(char nombre[]);
unsigned int obtenerJugadores(struct ST_Jugador Jugador[]);

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                                       MAIN                                           // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

int main() {
	
	unsigned int cantidadJugadores = obtenerJugadores(Jugador);
	system("PAUSE");
	mostrarDatos(cantidadJugadores, Jugador);
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                               FUNCIONES  SECUNDARIAS                                 // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

void mostrarDatos(unsigned int cant, struct ST_Jugador Jugador[]) {
	int min, i;
	char input;
	min = i = 0;
	
	while(true) {
		system("CLS");
		
		printf("\n\n");
		
		tableLn();
		
		printf("\t#%62s#\n", " ");
		printf("\t# <- Mostrando jugador %d de %d %32s #\n", i, cant, "->");
		printf("\t#%62s#\n", " ");
		
		tableLn();
		
		printf("\t#%62s#\n", " ");
		printf("\t# Viendo: %-52s #\n", Jugador[i].Nombre);
		printf("\t#%62s#\n", " ");
		printf("\t# Equipo %53s #\n", Jugador[i].Equipo);
		printf("\t# Partidos %51d #\n", Jugador[i].Partidos_Jugados);
		printf("\t# Goles %54d #\n", Jugador[i].Goles_Convertidos);
		printf("\t# Promedio %51.2f #\n", (float)Jugador[i].Goles_Convertidos / (float)Jugador[i].Partidos_Jugados);
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

unsigned int validarNombre(char nombre[]) {
	int i = 0;
	while(nombre[i] != '\0'){
		if((nombre[i] < 'A' || nombre[i] > 'Z' && nombre[i] < 'a' || nombre[i] > 'z') && nombre[i] != ' ') return !true;
		i = i + 1;
	}
	return true;
}

unsigned int obtenerJugadores(struct ST_Jugador Jugador[]) {
	unsigned int action, masJugadores, i, sino;
	int input;
	char charinput;
	masJugadores = true;
	action = i = 0;
	sino = 1;
	char buffer[STR_LENGTH];
	
	do {
		switch(action) {
			case 0:
				printf("Jugadores de Futbol\n\nIngrese el nombre del jugador Nro. %d: ", i);
				gets(buffer);
				if(validarNombre(buffer)) {
					strcpy(Jugador[i].Nombre, buffer);
					action = 1;
				} else {
					printf("El nombre es invalido.\n\n");
				}
				break;
				
			case 1:
				printf("Ingrese el equipo de %s: ", Jugador[i].Nombre);
				gets(buffer);
				if(validarNombre(buffer)) {
					strcpy(Jugador[i].Equipo, buffer);
					action = 2;
				} else {
					printf("El equipo es invalido.\n\n");
				}
				break;
			
			case 2:
				printf("Ingrese la cantidad de partidos jugados de %s: ", Jugador[i].Nombre);
				scanf("%d", &input);
				if(input > 0) {
					Jugador[i].Partidos_Jugados = input;
					action = 3;
				} else {
					printf("La cantidad de partidos jugados es invalido.\n\n");
				}
				break;
			
			case 3:
				printf("Ingrese la cantidad de goles que metio %s: ", Jugador[i].Nombre);
				scanf("%d", &input);
				if(input >= 0) {
					Jugador[i].Goles_Convertidos = input;
					action = 4;
				} else {
					printf("La cantidad de goles metidos es invalido.\n\n");
				}
				break;
			
			case 4:
				system("CLS");
				printf("Jugador %s\n", Jugador[i].Nombre);
				printf("\tEquipo: %s\n", Jugador[i].Equipo);
				printf("\tPartidos Jugados: %d\n", Jugador[i].Partidos_Jugados);
				printf("\tGoles: %d\n", Jugador[i].Goles_Convertidos);
				printf("\tPromedio de goles por partido: %.2f\n\nJugadores cargados: %d.\nCargar mas jugadores? ", (float)Jugador[i].Goles_Convertidos / (float)Jugador[i].Partidos_Jugados, i + 1);
				printf("%s | %s\n", (sino ? "[SI]" : " SI "), (!sino ? "[NO]" : " NO "));
				charinput = getch();
				if (charinput == -32) {
					switch(getch()) {
						case 77:
							if(sino == 1) sino = 0;
							break;
						case 75:
							if(sino == 0) sino = 1;
							break;
					}
				} else if(charinput == '\r') {
					if(sino == 1){
						action = 0;
						i = i + 1;
						system("CLS");
						fflush(stdin);
						break;
					} else {
						masJugadores = !true;
						break;
					}
				}
				break;
		}
		
	} while(masJugadores);
	return i;
}
