/*
Múltiplos de 11
Realizar un programa que imprima 25 términos de la serie 11 - 22 - 33 - 44, etc. (No se ingresan valores por teclado).
*/

#include <stdio.h> //libs

int main() { //bp
	int i; //declaramos variables
	printf("+----------------+----------------+\n"); //hacemos un cuadrito lindo
	printf("|                                 |\n");// a la profe le gusta que hagamos cuadritos lindos
	printf("|        25 Multiplos de 11       |\n");
	printf("|                                 |\n");
	printf("+----------------+----------------+\n");
	
	for(i = 1; i < 26; i = i + 1){ //no le gusta ver ensaladas como la siguiente linea
		printf("%s 11 * %s%d = %s%d |%s", (i & 1 ? "|" : ""), (i > 99 ? "" : (i > 9 ? " " : "  ")), i, (11*i > 99 ? "" : (11*i > 9 ? " " : "  ")),11*i, (i & 1 ? "" : "\n"));
	} //aca hacemos: si es numero impar, poner la primera linea. despues 11* y despues corregir espacios segun digitos faltantes, el resultado con espacios en
	// digitos faltantes, despues la linea que terminaria la celda, y si es par, poner linea nueva
	// mucho mas facil hacerlo aca que en el pseint, te digo ya
	// si pensas que esto es un lio, imaginate lo que era en el pseint
	
	printf("                |\n+----------------+----------------+\n\n"); //y aca cerramos la tablita ^.^
	system("PAUSE");
	return 0;
}