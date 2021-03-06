/*

	Realizar un programa donde:
	dado un archivo .txt con la siguiente informacion de la ultima olimpiada:
	pais; disciplina; medalla;
	siendo la medalla oro/plata/bronce
	liste por pantalla todos los registros por medalla, primero todos los oros, luego todas las platas, y luego todos los bronces
	muestre por pantalla las cantidades logradas de cada medalla

	Condiciones que cumplir:
	programar usando FUNCIONES
	Utilizar el lenguaje C STANDARD
	Bibliotecas permitidas: STDIO.H, STDLIB.H, STDBOOL.H STDLIB.H

	Archivo:
	escribir en bloc de notas o en el mismo IDE
	los datos no estan ordenados

*/

//	+------------------------------------------------------------------------------------------------+
//	| Project				:	Programacion I                                                       |
//	| Author				:	Zenyatta11                                                           |
//	| Description			:	Ejercicio 2                                                          |
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

#define STR_MAX 24

int mostrarTabla(int tipo);
void tableLn();

//	+------------------------------------------------------------------------------------------------+
//	| Section 2 : Main                                                                               |
//	+------------------------------------------------------------------------------------------------+

int main() {
	
	printf("\n\tJuegos Olimpicos - Premios Obenidos\n");
	
	if(!mostrarTabla(2)){
		printf("\tNo se pudo abrir el archivo para mostrar los ganadores de ORO.\a\n\n\t"); //0 - Bronce; 1 - Plata; 2 - Oro
		system("PAUSE");
	} 

	if(!mostrarTabla(1)){
		printf("\tNo se pudo abrir el archivo para mostrar los ganadores de PLATA.\a\n\n\t");
		system("PAUSE");
	} 
	
	if(!mostrarTabla(0)){
		printf("\tNo se pudo abrir el archivo para mostrar los ganadores de BRONCE.\a\n\n\t");
		system("PAUSE");
	}
	
	return 0;
}

//	+------------------------------------------------------------------------------------------------+
//	| Section 3 : Funciones Secundarias                                                              |
//	+------------------------------------------------------------------------------------------------+

int mostrarTabla(int tipo) {
	char pais[STR_MAX], juego[STR_MAX], medalla;
	printf("\n");
	int i = 0;
	FILE* file = fopen("medallas.txt", "r");
	
	if(file == NULL) return 0;
	
	tableLn();
	printf("\t# Mostrando: %-50s#\n", (tipo == 0 ? "BRONCE" : tipo == 1 ? "PLATA" : "ORO"));
	tableLn();
	
	while(fscanf(file, "%s %s %c\n", pais, juego, &medalla) == 3) {
		switch(medalla) {
			case 'O': medalla = 2; break;
			case 'B': medalla = 0; break;
			case 'P': medalla = 1; break;
		}
		if(medalla == tipo) {
			i = i + 1;
			printf("\t# %-24s # %-24s # %-6s #\n", pais, juego, (medalla == 0 ? "BRONCE" : medalla == 1 ? "PLATA" : "ORO"));
		}
	}
	
	tableLn();
	printf("\t# Cantidad de Medallas: %-38d #\n", i);
	tableLn();
	
	fclose(file);
	printf("\n\t");
	system("PAUSE");
	return 0;
	
	return 1;
}

void tableLn() {
	int i = 64;
	printf("\t");
	for(;i > 0; i = i - 1)
		printf("#");
	printf("\n");
}