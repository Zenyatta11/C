/*

Escribir un programa que lea dos enteros y a continuación imprima el promedio, la suma, el menor y el mayor de ellos (o indicar que son iguales). 
Las operaciones deben hacerse a través de funciones, una para la suma, otra para promedio, otra para menor y la última para mayor. 


*/


#include<stdio.h>


int Min(int numA, int numB);
int Suma(int numA, int numB);
float Promedio(int numA, int numB);


//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                                       MAIN                                           // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

int main() {
	int num[2];
	
	printf("Datos de un par.\n\nIngrese dos numeros:\n");
	scanf("%d%d", &num[0], &num[1]);
	printf("\nEl promedio es: %.2f\nLa suma es: %d\nEl menor es: %d\nEl mayor es: %d\n\n", Promedio(num[0], num[1]), Suma(num[0], num[1]), num[Min(num[0], num[1])], num[!Min(num[0], num[1])]);
	system("PAUSE");
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                               FUNCIONES  SECUNDARIAS                                 // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

float Promedio(int numA, int numB) {
	return (numA + numB) / 2;
}

int Suma(int numA, int numB) {
	return numA + numB;
}

int Min(int numA, int numB) {
	if(numA > numB) return 1;
	else return 0;
}