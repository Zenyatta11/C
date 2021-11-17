/*
23	Cuántos múltiplos de 3 y 5
Escribir un programa que lea 10 números enteros y luego muestre cuántos valores ingresados fueron múltiplos de 3 y cuántos de 5.
Debemos tener en cuenta que hay números que son múltiplos de 3 y de 5 a la vez.
*/

#include <stdio.h> //libs

int main() { //breakpoint
	int mult3, mult5, multA, input[10], i; //declaramos variables y arrays
	mult3 = mult5 = multA = 0; //inicializamos
	
	printf("Multiplos de 3 y de 5\n\n");
	
	for(i = 0; i < 10; i = i + 1) { //10 iteraciones
		printf("Ingrese %s numero al stack: ", (i == 0 ? "un" : "otro")); //mostrar "un numero" si es el primero, "otro numero" si no lo es
		scanf("%d", &input[i]);
		
		if(input[i] % 3 == 0 && input[i] % 5 == 0) //chequear si es multiplo
			multA = multA + 1; //es multi de ambos
		else if(input[i] % 3 == 0) 
			mult3 = mult3 + 1; //solo de 3
		else if(input[i] % 5 == 0) 
			mult5 = mult5 + 1; //solo de 5
		if(i < 9) printf("\nResta%s %d numero%s.\n", (9-i == 1 ? "" : "n"), 9-i, (9-i == 1 ? "" : "s")); //mostrar cuantos faltan
	}
	
	system("CLS"); //limpiar la pantalla
	printf("Ingreso: [ "); //mostrar el ingreso
	
	for(i = 0; i < 10; i = i + 1) {
		printf("%d%s",input[i], (i == 9 ? " ]\n\n" : ", ")); // mostramos el ingreso
	}
	
	if(multA > 0) printf("Hay %d numero%s multiplo%s de 3 y de 5.\n", multA, (multA == 1 ? "" : "s"), (multA == 1 ? "" : "s")); //mostrar la cantidad de multiplos
	if(mult3 > 0) printf("Hay %d numero%s multiplo%s de 3.\n", mult3, (mult3 == 1 ? "" : "s"), (mult3 == 1 ? "" : "s")); 		// solo si las hay
	if(mult5 > 0) printf("Hay %d numero%s multiplo%s de 5.\n", mult5, (mult5 == 1 ? "" : "s"), (mult5 == 1 ? "" : "s"));		// si hay solo uno, no poner la s
	if(mult3 == 0 && multA == 0 && mult5 == 0) printf("No se ingresaron multiplos ni de 3 ni de 5.\n"); //si no, decir que no hay
	
	system("PAUSE");
	return 0; //pause
}