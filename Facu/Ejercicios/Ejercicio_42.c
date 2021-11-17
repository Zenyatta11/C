/*

Elaborar una función que reciba tres enteros y nos retorne el valor promedio de los mismos

*/


#include<stdio.h>

float GetPromedio(int inputA, int inputB, int inputC);
int stopExecution();

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                                       MAIN                                           // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

int main() {
	int inA, inB, inC;
	do{
		system("CLS");
		printf("Promedio de tres enteros.\n\n");
		printf("Ingrese tres enteros: ");
		scanf("%d%d%d", &inA, &inB, &inC);
		printf("\nEl promedio es %.2f!\n\n", GetPromedio(inA, inB, inC));
	}while(!stopExecution());
	return 0;
	
}

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                               FUNCIONES  SECUNDARIAS                                 // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

float GetPromedio(int inputA, int inputB, int inputC) {
	float average = inputA + inputB + inputC;
	return average / 3;
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