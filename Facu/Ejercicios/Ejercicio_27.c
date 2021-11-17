/*

Una empresa tiene dos turnos (mañana y tarde) en los que trabajan 8 empleados (4 por la mañana y 4 por la tarde).

Confeccionar un programa que permita almacenar los sueldos de los empleados agrupados por turno (definir los dos vectores con componentes de tipo float)
Imprimir los gastos en sueldos de cada turno.

*/


#include<stdio.h>
#define MAX 8

int main() {
	int input, i;
	//float Sueldos[MAX];
	
	printf("Sueldos de dos jornadas.\n\n");
	scanf("%d", &input);
	int Array[input];
	
	for(i = 0; i < input; i = i + 1) {
		*(Array+i) = i;
	}
	
	for(i = 0; i < input; i = i + 1) {
		printf("%d\n",*(Array+i));
	}
	
	system("PAUSE");
	return 0;
	
}


