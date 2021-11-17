/*

	Realizar un programa que lea por teclado un número ENTERO y luego muestre por pantalla los 10 primeros múltiplos, utilizando MEMORIA DINÁMICA.

	Primero, pedir al usuario el primer número. Será un ENTERO POSITIVO O NEGATIVO, pero NO CERO. 
	Segundo, guardar todos los múltiplos generados en un conjunto de 10 elementos en MEMORIA DINÁMICA.
	Por último y al finalizar la generación de los múltiplos, mostrar por pantalla el conjunto.
	ej. de pantalla:
	Ingrese el nro.: -4
	Los múltiplos de -4 son:
	-4 -8 -12 -16 -20 -24 -28 -32 -36 -40

	La función MAIN() no lee ni escribe nada. Llama a otras funciones.


*/


#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int obtenerNumero();
int *obtenerMultiplos(int numero);
void messageOfTheDay();
void mostrarMultiplos(int *pointer, int numero);

int main() {
	
	messageOfTheDay();
	int numero = obtenerNumero();
	int *pointer = obtenerMultiplos(numero);
	
	if(pointer == NULL)
		printf("\n\t\aCould not allocate memory. Terminating...");
	else {
		mostrarMultiplos(pointer, numero);
		free(pointer);
	}
	
	system("PAUSE");
	return 0;
	
}

void messageOfTheDay() {
	printf("\n\tMultiplos de N en memoria dinamica\n");
}

int obtenerNumero() {
	int input, check;
	char antiusers;
	
	do{
		printf("\n\t\tIngrese el numero deseado para obtener sus multiplos: ");
		fflush(stdin);
		check = scanf("%d%c", &input, &antiusers);
		if(check != 2 || antiusers != '\n' || input == 0)
			printf("\n\tEl numero ingresado es invalido. Debe ser un entero distinto de cero.\n");
	}while(check != 2 || antiusers != '\n' || input == 0);
	return input;
}

int* obtenerMultiplos(int numero) {
	
	int *pointer = malloc(MAX * sizeof(int));
	
	if(pointer == NULL) return NULL;
	
	int i;
	int *returnVal = pointer;
	for(i = numero; abs(i) < abs(numero*(MAX + 1)); i = i + numero) {
		*pointer = i;
		pointer = pointer + 1;
	}
	
	return returnVal;
}

void mostrarMultiplos(int *pointer, int numero) {
	printf("\n\n\t\tLos multiplos de %d son:\n\t\t", numero);
	int i;
	for(i = 0; i < MAX; i = i + 1) {
		printf("%d; ", *pointer);
		pointer = pointer + 1;
	}
	printf("\n\n");
}
