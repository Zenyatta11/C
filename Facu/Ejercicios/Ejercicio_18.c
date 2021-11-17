/*
Numerar hasta 100 v2.
Imprimir los números del 1 al 100 utilizando la instrucción WHILE.
*/

#include <stdio.h> //Incluimos librerias

int main() { //no devolvemos nada, que el breakpoint sea aca
	int i = 0; //definimos i como interger e iniciamos en cero
	printf("Numeros hasta 100\nWHILE loop\n\n");
	while(i < 100) { //100 iteraciones
		i = i + 1; //aca hay que sumar manuelmente. Sumo aca para mostrar 1-100 y no 0-99
		printf("%d\n",i); 
		if(i % 20 == 0) { //cada 20 numeros hagamos una pausa para no saturar la consola
								//ya que el scroll lock no hace naca desde Windows 95
			printf("\n");
			system("PAUSE");
			printf("\n");
		}
	}
	return 0;
}

//No hace falta el pause final porque 100/20 da resto 0 y hara una pausa el if del modulo.
