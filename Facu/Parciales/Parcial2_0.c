/*

Realizar un programa donde:

Se ingrese por teclado un numero ENTERO POSITIVO y luego se genere una serie HASTA otro numero tambien ingresado por teclado (limites inferior y superior de la serie)
	El limite inferior no puede ser CERO
	El limite superior debe ser MAYOR al limite inferior
	La cantidad maxima de numeros a guardar sera 10
	La serie cumple la condicion de: cada numero es la SUMA de los dos anteriores.
	El primer elemento es 0, el segundo elemento es el limite inferior
	Al finalizar, muestre por pantalla todo el conjunto de numeros (ver pantalla de ejemplo)

Condiciones que cumplir: Guiardar la informacion en MEMORIA DINAMICA

Prograamar usando FUNCIONES
	Utilizar el lenguaje C STandard
	BIbliotecas permitidas: STDIO.H, STDLIB.H, STDBOOL.H, STDLIB.H

*/

//	+------------------------------------------------------------------------------------------------+
//	| Project				:	Programacion I                                                       |
//	| Author				:	Zenyatta11                                                           |
//	| Description			:	Ejercicio 1                                                          |
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
#include<stdbool.h>
#include<stdlib.h>

void mostrarSerie(int *serie);
void calcularSerie(int* serie, int limInf, int limSup);
int *reservarMem();
int obtenerInt(int minimo);

//	+------------------------------------------------------------------------------------------------+
//	| Section 2 : Main                                                                               |
//	+------------------------------------------------------------------------------------------------+

int main() {
	
	int *serie, limInf, limSup;
	printf("\n\tParcial 2 - Programacion\n\n\tEjercicio 1 - Serie de Sumas\n");
	
	printf("\n\tLimite inferior de la serie");
	limInf = obtenerInt(0);
	
	printf("\n\tLimite superior de la serie");
	limSup = obtenerInt(limInf);
	
	serie = reservarMem();
	if(serie != NULL) {
	
	calcularSerie(serie, limInf, limSup);
	
	printf("\n\tSerie obtenida: ");
	mostrarSerie(serie);
	
	free(serie);
	} else {
		printf("\n\tHubo un error al intentar reservar la memoria.\a\n\n\t");
	}
	
	system("PAUSE");
	return 0;
}

//	+------------------------------------------------------------------------------------------------+
//	| Section 3 : Funciones Secundarias                                                              |
//	+------------------------------------------------------------------------------------------------+

int obtenerInt(int minimo) {
	int input;
	char charInput;
	do{
		printf("\n\tIngrese un numero: ");
		fflush(stdin);
		scanf("%d%c", &input, &charInput);
		if(input <= minimo || charInput != '\n') {
			printf("\tEl numero ingresado es invalido. Debe ser mayor a %d.\n\a", minimo);
		}
	}while(input <= minimo || charInput != '\n');
	return input;
}

int *reservarMem() {
	int *serie = malloc(10*sizeof(int));
	return serie;
}

void calcularSerie(int* serie, int limInf, int limSup) {
	int i;
	
	serie[0] = limInf;
	for(i = 1; i < 10; i = i + 1) {
		if(i == 1) serie[i] = serie[i-1];
		else if(serie[i-1] + serie[i-2] <= limSup && i != 9) {
			serie[i] = serie[i-1] + serie[i-2];
		} else {
			serie[i] = -1;
		}
	}
}

void mostrarSerie(int *serie) {
	while(*serie != -1) {
		printf("%d", *serie);
		serie = serie + 1;
		if(*serie != -1) printf(", ");
		else printf(";\n\n\t");
	}
}