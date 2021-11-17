/*

	Definir tres vectores de cinco posiciones de tipo entero.
	Realizar la carga de los dos primeros por teclado.
	Definir una única función que realice la carga de un vector y llamar a dicha
	función dos veces pasando el primer y segundo vector definido.
	
	Plantear otra función que reciba tres vectores y proceda a sumar elemento a
	elemento los dos primeros vectores y se carguen en el tercer vector.
	
	Imprimir los tres vectores.
	Usar punteros.

*/


#include<stdio.h>
#define MAX 5

void cargarDatos(int *Array);
void sumarDatos(int *ArrayEnd, int *ArrayA, int *ArrayB);
void mostrarDatos(int *Array);

int main() {
	int ArrayA[MAX], ArrayB[MAX], ArrayC[MAX];
	
	cargarDatos(ArrayA);
	cargarDatos(ArrayB);
	sumarDatos(ArrayC, ArrayB, ArrayA);
	
	printf("\n\tArray A: ");
	mostrarDatos(ArrayA);
	
	printf("\n\tArray B: ");
	mostrarDatos(ArrayB);
	
	printf("\n\tArray C: ");
	mostrarDatos(ArrayC);
	
	printf("\n\n\t: ");
	system("PAUSE");
	return 0;
}

void cargarDatos(int *Array){
	int i;
	printf("\n\tSuma de dos vectores.\n");
	for(i = 0; i < MAX; i = i + 1) {
		printf("\n\tIngrese un numero para sumar: ");
		scanf("%d", Array+i);
	}
}

void sumarDatos(int *ArrayEnd, int *ArrayA, int *ArrayB) {
	int i;
	for(i = 0; i < MAX; i = i + 1) {
		*(ArrayEnd+i) = *(ArrayA+i) + *(ArrayB+i);
	}
}

void mostrarDatos(int *Array) {
	int i;
	for(i = 0; i < MAX; i = i + 1) {
		printf("%d, ", *(Array + i));
	}
}