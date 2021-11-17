/*
Suma de los primeros n nros
Sumar los primeros n números enteros. El valor de n lo debe ingresar el usuario.  La suma final se debe informar por pantalla.
Ejemplo: si es n=4, entonces mostrar la suma de 1+2+3+4
*/

#include <stdio.h> //incliumos librerias

int main() { //breakpoint
	
	printf("Suma hasta N\n\n");
	
	int i, input, sum = 0; //Declaramos variables
	
	do { //declarar bloque de loop
		printf("Ingrese un numero natural para sumar hasta ese numero: ");
		scanf("%d", &input); //tener el ingreso de la consola
		if(input <= 0) printf("El numero ingresado es invalido.\n\n"); //avisar si el numero es invalido
	} while(input <= 0); //no salgamos de aca si el numero sigue siendo invalido
	
	for(i = 0; i < input; i = i + 1) { // input iteraciones 
		printf("%s%d", (i == 0 ? "" : " + "), i+1); // mostramos un + siempre que no sea el primer numero
		sum = sum + i+1; // sumamos con i+1 para que no aparezca el cero
	}
	printf(" = %d.\n\n", sum); //mostramos la suma y fin
	system("PAUSE");
	return 0;
}