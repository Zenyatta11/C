/*

Definir dos vectores de cinco posiciones de tipo entero.
Realizar la carga de los dos primeros por teclado.  Definir una única función que realice la carga de un vector y llamar a dicha función dos veces.
Plantear otra función que reciba dos vectores y proceda a sumar elemento a elemento imprimir los tres valores.


*/


#include<stdio.h>

#define ARRAY_LENGTH 5

void MostrarDatos(int ArrayA[], int ArrayB[]);
void LlenarVector(int Array[]);

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                                       MAIN                                           // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

int main() {
	int Array_A[ARRAY_LENGTH], Array_B[ARRAY_LENGTH];
	
	printf("Suma de dos vectores.\n\n");
	LlenarVector(Array_A);
	printf("\n");
	system("PAUSE");
	
	LlenarVector(Array_B);
	printf("\n");
	system("PAUSE");
	
	system("CLS");
	MostrarDatos(Array_A, Array_B);
	system("PAUSE");
	
	return 0;
}




//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                               FUNCIONES  SECUNDARIAS                                 // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

void LlenarVector(int Array[]){
	int i;
	for(i = 0; i < ARRAY_LENGTH; i = i + 1) {
		if(i != 0) printf("Resta%s %d.\n\n", ((ARRAY_LENGTH - i) != 1 ? "n" : ""), ARRAY_LENGTH - i);
		printf("Ingrese %s numero: ", (i == 0 ? "un" : "otro"));
		scanf("%d", &Array[i]);
	}
}

void MostrarDatos(int ArrayA[], int ArrayB[]){
	int i;
	
	for(i = 0; i < ARRAY_LENGTH; i = i + 1) {
		printf("%d + %d = %d\n", ArrayA[i], ArrayB[i], ArrayA[i] + ArrayB[i]);
	}
}