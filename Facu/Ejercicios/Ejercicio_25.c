/*

5 empleados
Leer y guardar en un arreglo los cinco sueldos de empleados. Luego mostrarlos en pantalla.

*/


#include<stdio.h>
#define MAX 5

int main() {
	
	int input, Array[MAX], i;
	printf("Sueldo de cinco empleados.\n\n");
	
	for(i = 0; i < MAX; i = i + 1) {
		printf("Ingrese el sueldo del empleado numero %d: $", i + 1);
		scanf("%d", &input);
		if(input <= 0) {
			printf("El sueldo no puede ser %s.\n\n", (input < 0 ? "negativo" : "cero"));
			i = i - 1;
		} else {
			*(Array+i) = input;
		}
	}
	
	system("PAUSE");
	system("cls");
	printf("\n\nLos sueldos de los empleados son los siguientes:\n\n");
	
	for(i = 0; i < MAX; i = i + 1) {
		printf("\tEmpleado %d: $%d\n", i + 1, *(Array+i));
	}
	
	printf("\n");
	system("PAUSE");
	return 0;
}


