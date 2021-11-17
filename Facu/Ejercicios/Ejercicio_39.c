/*

Confeccionar una función que reciba tres enteros y nos muestre el mayor de ellos. La carga de los valores hacerlo por teclado en la función main.

*/


#include<stdio.h>

#define bool unsigned int //bool.h no existe en mi sistema por algun motivo raro
#define true 1
#define false 0
#define BUFFER_SIZE 16

bool stopExecution();

int GetMayor(int A, int B, int C);

unsigned int GetIntFromString(unsigned char* printString);
unsigned int e10(unsigned int power);

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                                    MAIN  LIMPIO                                      // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

int main() {
	do{
		system("CLS");
		printf("Mayor de los tres.\n\n");
		printf("El mayor de los numeros ingresados es %d.\n\n", GetMayor(GetIntFromString("Ingrese el tercer numero: "), GetIntFromString("Ingrese el segundo numero: "), GetIntFromString("Ingrese el primer numero: "))); //impecable
		
	}while(!stopExecution());
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                               FUNCIONES  SECUNDARIAS                                 // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

int GetMayor(int A, int B, int C) {
	int returnValue = A;
	if(B > returnValue)
		returnValue = B;
	
	if(C > returnValue)
		returnValue = C;
	
	return returnValue;
}

unsigned int GetIntFromString(unsigned char* printString) {
	//basicamente aca leeremos un string y le vamos a sacar los numeros.
	unsigned char buffer[BUFFER_SIZE];
	printf("%s", printString);
	scanf("%s", buffer);
	unsigned int i, returnVal, stringLength;
	returnVal = 0;
	for(stringLength = 0; stringLength < BUFFER_SIZE; stringLength = stringLength + 1) 
		if(buffer[stringLength] == 0) break;
	
	for(i = 0; stringLength > 0; i = i + 1) { //los caracteres que no son numeros se consideraran ceros
		if(buffer[i] >= '0' && buffer[i] <= '9') {
			returnVal = returnVal + (buffer[i] - '0') * e10(stringLength-1);
		}
		stringLength = stringLength - 1;
	}
	return returnVal;
}

unsigned int e10(unsigned int power) {
	unsigned int num = 1, i;
	for(; power > 0 ; power = power - 1) {
		num = num * 10;
	}
	return num;
}

bool stopExecution() {
	unsigned char input;
	printf("Presione C para repetir o E para terminar.\n\n");
	do {
		input = getch();
		if(input == 'C' || input == 'c') return false; //algunos sistemas toman el raw input en mayusculas, otros en minusculas. En nivel bajo por lo menos
		if(input == 'E' || input == 'e') return true; //corriendo en un OS no se pero por las dudas...
	}while(1);
}