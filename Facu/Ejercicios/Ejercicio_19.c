/*
Nros hasta N
Escribir un programa que solicite la carga de un valor positivo y nos muestre desde 1 hasta el valor ingresado de uno en uno.

Ejemplo: Si ingresamos 30 se debe mostrar en pantalla los números del 1 al 30.
*/

#include <stdio.h> //incluimos librerias

int main() { //breakpoint
	
	printf("Numeros hasta N\n\n");
	
	int i, input; //Declaramos variables
	
	do { //declarar bloque de loop
		printf("Ingrese un numero natural para contar hasta ese numero: ");
		scanf("%d", &input); //tener el ingreso de la consola
		if(input <= 0) printf("El numero ingresado es invalido.\n\n"); //avisar si el numero es invalido
	} while(input <= 0); //no salgamos de aca si el numero sigue siendo invalido
	
	for(i = 0; i < input; i = i + 1) { // "input" iteraciones
		printf("%d\n", i+1);
		if((i+1) % 20 == 0) { //cada 20 numeros hagamos una pausa para no saturar la consola
								//ya que el scroll lock no hace naca desde Windows 95
			printf("\n");
			system("PAUSE");
			printf("\n");
		} else if(i == input-1) system("PAUSE"); //hacer una pausa si no entra dentro del grupete de 20 (puede pasar si se ingresa 34 por ejemplo
	}
	return 0;
}