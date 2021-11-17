/*

	Escribir un programa que devuelva el máximo y el mínimo de los números almacenados en memoria dinámica.  
	En la función main, preguntar el número de elementos a introducir, reservar espacio de memoria con malloc(),
	y luego llamar a funciones que carguen los valores y otra que busque el mínimo y máximo.
	El valor del máximo y el mínimo se presentarán por pantalla en la función main().

*/


#include<stdio.h>
#include<stdlib.h>


double min(double* loc);
double max(double* loc);
void cargarDatos(double* loc);
double* assignMemory();

int main() {
	
	double *loc;
	
	loc = assignMemory();
	
	cargarDatos(loc);
	printf("\n\tEl valor maximo ingresado es %.2lf y el minimo es %.2lf\n\n", max(loc), min(loc));
	free(loc);
	system("PAUSE");
	return 0;
}

void cargarDatos(double* loc) {
	int i;
	for(i = 1; i <= *loc; i = i + 1) {
		printf("\n\tIngrese %s numero: ", (i == 1 ? "un" : "otro"));
		scanf("%lf", loc+i);
		if(i < *loc) printf("\tRestan %d numeros.\n",(int)(*loc - i));
	}
}

double max(double* loc) {
	double max, *cant = (loc + (int)*loc);
	loc = loc + 1;
	max = *loc;
	while(loc <= cant) {
		if(*loc > max) max = *loc;
		loc = loc + 1;
	}
	return max;
}

double min(double* loc) {
	double min, *cant = (loc + (int)*loc);
	loc = loc + 1;
	min = *loc;
	while(loc <= cant) {
		if(*loc < min) min = *loc;
		loc = loc + 1;
	}
	return min;
}

double* assignMemory() {
	
	int cantidad;
	do{
		printf("\n\tIngrese la cantidad de numeros que desea cargar: ");
		scanf("%d", &cantidad);
		if(cantidad <= 0) printf("El numero ingreasdo es invalido.\n\n");
	} while(cantidad <= 0);
	
	double* pointer = (double*)malloc(sizeof(cantidad) * (cantidad+1));
	
	if(pointer != NULL){ 
		*(pointer) = (double)cantidad;
		return pointer;
	}
	
	printf("\n\nError allocating memory. Terminating...\a");
	exit(EXIT_FAILURE);
}