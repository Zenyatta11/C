/*

Confeccionar una función que calcule la superficie de un rectángulo y la retorne.
 Recibe como parámetros los valores de dos de sus lados:

int retornarSuperficie(int lado1,int lado2) 

En la función main del programa cargar los lados de dos rectángulos y luego mostrar cuàl de los dos tiene una superficie mayor.

*/


#include<stdio.h>

int stopExecution();
unsigned int retornarSuperficie(int lado1, int lado2);
unsigned int GetArea(unsigned char* print);

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                                       MAIN                                           // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

int main() {
	unsigned int AreaA, AreaB;
	do{
		system("CLS");
		printf("Area Mayor.\n\n");
		AreaA = GetArea("Ingrese los dos lados de un rectangulo: ");
		AreaB = GetArea("Ingrese los dos lados de un segundo rectangulo: ");
		if(AreaA > AreaB) printf("\nEl primer rectangulo tiene mayor superficie.\n\n");
		else if(AreaA == AreaB) printf("\nAmbos rectangulos tienen la misma superficie.\n\n");
		else printf("\nEl segundo rectangulo tiene mayor superficie.\n\n");
	}while(!stopExecution());
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                               FUNCIONES  SECUNDARIAS                                 // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
unsigned int retornarSuperficie(int lado1, int lado2){
	return lado1 * lado2;
}
///////////////////////////////////////////////////////////////

unsigned int GetArea(unsigned char* print) {
	int inputA, inputB;
	do{
		printf("%s", print);
		scanf("%d%d", &inputA, &inputB);
		if(inputA <= 0 || inputB <= 0) printf("%s lados %s invalido%s.\n\n", (inputA <= 0 && inputB <= 0 ? "Ambos" : "Uno de los"), (inputA <= 0 && inputB <= 0 ? "son" : "es"), (inputA <= 0 && inputB <= 0 ? "s" : ""));
	}while(inputA <= 0 || inputB <= 0);
	return retornarSuperficie(inputA, inputB);
}

int stopExecution() {
	unsigned char input;
	printf("Presione C para continuar/repetir o E para terminar.\n\n");
	do {
		input = getch();
		if(input == 'C' || input == 'c') return 0;
		if(input == 'E' || input == 'e') return 1;
	}while(1);
}