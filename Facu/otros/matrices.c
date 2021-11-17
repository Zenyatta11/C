
/* ej 45 
Cecilia 2020
Matriz de 6 x 5 para llenar con enteros
*/

#include <stdio.h>
#include <stdbool.h>
//variables globales
#define FILAS 6
#define COLS 5

//declaracion de funciones
void vaciar_matriz(int m[FILAS][COLS]);
void mostrar_matriz(int m[FILAS][COLS]);
void rellenar_matriz(int m[FILAS][COLS]);


int main(){
	//variables
	int m[FILAS][COLS];
	
	//inicializar matriz
	vaciar_matriz(m);
	
	//cargar matriz
	rellenar_matriz(m);

	//mostrar matriz
	mostrar_matriz(m);		
	
	printf("\n");
	system("PAUSE");
	
	return 0;
}
void vaciar_matriz(int m[FILAS][COLS]){
	int i, j;
	for (i =0; i< FILAS; i++)	
		for (j=0; j<COLS; j++) m[i][j] = 0;
	return;
}

void rellenar_matriz(int m[FILAS][COLS]){
	int i, j;
	for(i = 0; i < FILAS; i = i + 1) {
		for(j = 0; j < COLS; j = j + 1) {
			printf("Ingrese para Array[%d][%d]: ", i, j);
			scanf("%d", &m[i][j]);
		}
	}
}

void mostrar_matriz(int m[FILAS][COLS]){
	int i, j;
	printf("\n\t");
	for (i =0; i<FILAS; i++){
		for (j=0; j<COLS; j++) printf("%2d   ", m[i][j]);
		printf("\n\t");
	}
	return;
}
