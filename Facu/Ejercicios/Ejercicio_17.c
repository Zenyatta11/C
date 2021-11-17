/*
Numerar hasta 100
Imprimir los números del 1 al 100 utilizando la instrucción FOR
*/

#include <stdio.h> //Incluimos librerias

int main() { //no devolvemos nada, que el breakpoint sea aca
	int i; //definimos i como interger
	printf("Numeros hasta 100\nFOR loop\n\n");
	for(i = 0; i < 100; i = i + 1) { //100 iteraciones
		printf("%d\n",i+1); //mostramos i+1 porque el ejercicio pide del 1 al 100
		if((i+1) % 20 == 0) { //cada 20 numeros hagamos una pausa para no saturar la consola
								//ya que el scroll lock no hace naca desde Windows 95
			printf("\n");
			system("PAUSE");
			printf("\n");
		}
	}
	return 0;
}

//No hace falta el pause final porque 100/20 da resto 0 y hara una pausa el if del modulo.