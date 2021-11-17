/*
Superficie de triángulos
Confeccionar un programa que lea n pares de datos. Cada par de datos corresponde a la medida de la base y la altura de un triángulo. El programa deberá informar:

a) De cada triángulo la medida de su base, su altura y su superficie. 
b) La cantidad de triángulos cuya superficie es mayor a 12.
Recordar que la superficie de un triángulo es base * altura /2
*/

#include <stdio.h> //incluimos librerias
#include <stdlib.h>

#define true 1 //true y false son de bool.h

int main() { //breakpoint
	
	printf("Superficies de Triangulos\n\n");
	
	int i, input, action; //Declaramos variables
	
	do { //declarar bloque de loop
		printf("Ingrese la cantidad de triangulos que desea confeccionar: ");
		scanf("%d", &input); //tener el ingreso de la consola
		if(input <= 0) printf("El numero ingresado es invalido. Debe ser entero mayor a 1\n\n"); //avisar si el numero es invalido
	} while(input <= 0); //no salgamos de aca si el numero sigue siendo invalido
	
	int* Array = malloc(sizeof(int)*input*2); //pedimos permiso para asignar memoria en el sistema. 4 bytes u 8 bytes por numero, 2 numeros por triangulo
												// si compilas para x64, son 8 bytes. para x86, son 4 u 8, a veces elije. para x32, 4 bytes, y para x16, 2 bytes
												
	if(Array == NULL) { //si el pointer no existe, no se aloco. no podemos continuar
		printf("\n\nException in memory allocation. Terminating...\n");
		system("PAUSE");
	return 0;
		return;
	}
	
	action = i = 0; //pedimos datos de los triangulos a sacar el area
	
	while(true) { //loopeamos hasta que terminamos de pedir los datos
	
		switch(action) { //mas ordenado de esta manera
			case 0: {
				printf("Ingrese la base del triangulo %d: ", i/2+1); //bases
				scanf("%d", Array+i);
				if(*(Array + i) <= 0)
					printf("El numero ingresado es invalido.\n\n"); //el ingreso debe ser natural
				else {
						action = 1; //si ingreso bien, seguir al siguiente paso
						i = i + 1;
					}
				break;
			}
			
			case 1: {
				printf("Ingrese la altura del triangulo %d: ", (i-1)/2+1); //asegurarse de no dividir con decimales con ints
				scanf("%d", Array+i); //alturas
				if(*(Array + i) <= 0)
					printf("El numero ingresado es invalido.\n\n");
				else {
						action = 0; //si ingreso bien, volver al primer paso pero del triangulo siguiente
						printf("\n");
						i = i + 1;
					}
				break;
			}
			
			default: action = 0; //nunca deberia llegar aca pero si lo hace, que rehaga la confeccion de ese triangulo
		}
		if(i == input*2) break; //salgamos de aca si ya tenemos todos los datos
	}
	
	system("CLS");
	printf("\n\t   Se muestran hasta 3\n\ttriangulos por pantalla.\n\n"); //limpiamos y mostramos
	
	for(i = 0; i < input*2; i = i + 2) {
		printf("\t#################\n\tTriangulo %d:\n\t#################\n\tBase: %d; Altura: %d\n\tSuperficie: %d.\n\n", i/2 + 1, *(Array + i), *(Array + i+1), (*(Array + i) * (*(Array + i+1)))/2); //mostrar la info
		if(i % 5 == 4) {
			system("PAUSE");
	return 0; //pausa por pantalla (asi se ven todos)
			system("CLS");
			printf("\n\t   Se muestran hasta 3\n\ttriangulos por pantalla.\n\n");
		}
	}
	free(Array); //liberamos la memoria
	
	system("PAUSE");
	return 0; //fin del programa
}
	