/*

Desarrollar dos funciones que reciban como parámetro el valor del lado de un cuadrado. 
La primera debe calcular y mostrar la superficie y la segunda calcular y mostrar el perímetro.


Superficie = lado * lado
Perímetro = lado *4 

*/


#include<stdio.h>

#define bool unsigned int //bool.h no existe en mi sistema por algun motivo raro
#define true 1
#define false 0
#define BUFFER_SIZE 16 //No haria falta mas que 16 lugares, total SE SUPONE que se ingresara un numero chico

unsigned int e10(unsigned int power);
unsigned int GetIntFromString();
unsigned int ValidarInput(unsigned char* Print);
void PrintAreaPerimetro(unsigned int side);
bool stopExecution();

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                                    MAIN  LIMPIO                                      // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

int main() {
	
	do{
		system("CLS");
		printf("Perimetro y Area cuadrada.\n\n");
		unsigned int Lado = ValidarInput("Ingrese la longitud del lado del cuadrado: ");
		PrintAreaPerimetro(Lado);
		
	}while(!stopExecution());
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                               FUNCIONES  SECUNDARIAS                                 // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

unsigned int e10(unsigned int power) {
	unsigned int num = 1, i;
	for(; power > 0 ; power = power - 1) {
		num = num * 10;
	}
	return num;
}

unsigned int GetIntFromString() {
	//basicamente aca leeremos un string y le vamos a sacar los numeros.
	unsigned char buffer[BUFFER_SIZE];
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

unsigned int ValidarInput(unsigned char* Print) {
	int buffer;
	do{
		printf("%s", Print);
		buffer = GetIntFromString(); //ya a esta altura podemos validar que ingrese solamente numeros, no?
		if(buffer <= 0) printf("El lado no puede ser %s.\n\n", (buffer < 0 ? "negativo" : "cero"));
	}while(buffer <= 0);
	return buffer;
}

void PrintAreaPerimetro(unsigned int side) {
	
	printf("\n\nEl perimetro del cuadrado es %d.\nEl area del cuadrado es %d.\n\n", side << 2, side * side);
	
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