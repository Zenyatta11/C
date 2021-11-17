/*
Promedio de 10 números
Desarrollar un programa que permita la carga de 10 valores por teclado y nos muestre su promedio.
*/

#include <stdio.h> //libs

int main() { //bp
	
	int i, Array[10]; //declaramos los ints
	float average = 0; //declaramos el float
	
	printf("Promedio de 10 numeros!\n\n");
	
	for(i = 0; i < 10; i = i + 1) { //10 iteraciones
		printf("Ingrese un numero: "); 
		scanf("%d", &Array[i]); //leemos al array
		if(i < 9) printf("\n\nRestan %d numeros.\n",9-i); //cuantos numeros faltan?
	}
	
	printf("Array[] = "); //mostramos el array
	
	for(i = 0; i < 10; i = i + 1) { //10 iteraciones
		printf("%d, ", Array[i]); //mostramos el indice del array
		average = average + (float)Array[i]; //sumamos al promedio
	}
	
	average = average / 10 * 100; //sacamos el promedio (10) y corremos la coma dos lados por lo que viene mas abajo
	printf("\nEl promedio es de "); //mostramos el principio del string para rellenar con el numero correspondiente

	//los decimales con 0 son horrendos, hagamos algo al respecto
	if((int)average % 100 == 0)  //si sus dos digitos del comienzo son ceros
		printf("%d.\n\n", (int)average/100); //no hay decimales y mostramos como int.
	else if((int)average % 10 == 0) //si no, fijate si el ultimo digito es cero
		printf("%.1f.\n\n", average/100); //un solo decimal, aca hay que mostrar como float si o si
	else //si no
		printf("%.2f.\n\n", average/100); //dos decimales, no mas.
	
	system("PAUSE");
	return 0; //pausa de sistema
}
