/*

Inicializar a cero una matriz de 6 filas por 5 columnas.
Cargar valores enteros en un elemento determinado, para lo cual se debe ingresar por teclado primero el valor y luego el número de fila y número de columna donde se desea guardar.
La carga termina con valor = 0.
Mostrar toda la matriz

*/


#include<stdio.h>

#define FILAS 6
#define COLUMNAS 5

int Matrix[FILAS*COLUMNAS]; //Matrix[6*5] es lo mismo que Matrix[6][5] ya que la memoria es una entidad lineal

int main() {
	
	InitializeMatrix();
	LoadData();
	return 0;
}



void InitializeMatrix() {
	int i;
	printf("Inicializando la matriz...\n[");
	for(i = 0; i < FILAS*COLUMNAS; i = i + 1) {
		if(i % 6 == 0) printf("|");
		Matrix[FILAS*i + i] = 0;
	}
	printf("]\n\n");
}

void LoadData() {
	printf("Cargar enteros en un vector\n\n");
	do {
		switch(action) {
			case 0:
				printf("Ingrese el valor de X (col): ");
				scanf("%u", &x);
				if(x >= 0 && x <= FILAS) {
					action = 1;
				} else {
					printf("La columna es invalida.\nRango: 0 - %d.\n\n", FILAS);
				}
				break;
			
			case 1:
				printf("Ingrese el valor de Y (fil): ");
				scanf("%u", &y);
				if(y >= 0 && y <= COLUMNAS) {
					action = 2;
				} else {
					printf("La fila es invalida.\nRango: 0 - %d.\n\n", COLUMNAS);
				}
				break;
			
			case 2:
				printf("Ingrese el valor a cargar: ");
				scanf("%d", &input);
				if(x >= 0 && x <= 5) {
					action = action + 1;
				} else {
				printf("La columna es invalida.\nRango: 0 - 5.\n\n");
				break;
			
		}
	}while(input > 0);
}