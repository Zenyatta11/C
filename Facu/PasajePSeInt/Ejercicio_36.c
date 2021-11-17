// Obtener el promedio de edad de un grupo de N alumnos (realizar tres algoritmos uno con cada estructura de control Mientras, Repetir, Para).
// N será ingresado por el usuario, quien luego ingresará las N edades.
// N debe ser mayor a 0.

#include <stdio.h>
#include <stdlib.h>

// int type = 0; // 0 - FOR; 1 - WHILE; 2 - DO;

void main(int argumentAmt,char* arguments[]) {
	int type = atoi(*(arguments+1));
	int i, age, input;
	float total = 0;
	
	
	
	switch(type) {
		case 1: printf("Type 1 - For loop\n\n"); break;
		case 2: printf("Type 2 - While loop\n\n"); break;
		case 3: printf("Type 3 - Do - While loop\n\n"); break;
		default: type = 1; printf("Type 1 - For loop\nUse 1-3 como argumento para cambiar de loop.\n\n"); break;
	}
	
	type = type - 1; // invalid argument correction
	
	printf("Promedio de edad de N alumnos.\n\n\nIngrese la cantidad de alumnos: ");
	scanf("%d", &input);
	
	if(input > 0) {
		switch(type) {
			
			case 0: { // PARA / FOR
				for(i = 0; i < input; i = i + 1) {
					printf("Ingrese la edad del alumno %d: ", i + 1);
					scanf("%d", &age);
					if(age > 0) total = total + (float)age;
					else {
						printf("La edad debe ser mayor a cero!\n");
						i = i - 1;
					}
				}
				printf("\n\nEl promedio de edades es %.2f\n\n", total 	/ input);
				system("PAUSE");
				break;
			}
			
			case 1: { // MIENTRAS / WHILE
				i = 0;
				while(i < input){
					printf("\nIngrese la edad del alumno %d: ", i + 1);
					scanf("%d", &age);
					if(age > 0) total = total + age;
					else {
						printf("La edad debe ser mayor a cero!\n");
						i = i - 1;
					}
					i = i + 1;
				}
				printf("\n\nEl promedio de edades es %.2f\n\n", total / input);
				system("PAUSE");
				break;
			}
			
			case 2: { // REPETIR / DO
				i = 0;
				do{
					printf("\nIngrese la edad del alumno %d: ", i + 1);
					scanf("%d", &age);
					if(age > 0) total = total + age;
					else {
						printf("La edad debe ser mayor a cero!\n");
						i = i - 1;
					}
					i = i + 1;
				} while(i < input);
				printf("\n\nEl promedio de edades es %.2f\n\n", total / input);
				system("PAUSE");
				break;
			}
			
		}
	} else {
		printf("La cantidad de alumnos debe ser mayor a cero.\n\n");
		main(argumentAmt,arguments);
	}
	
	return 0;
}
