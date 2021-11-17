/*

	Se cuenta con la siguiente información:
	
	Las edades de 5 estudiantes del turno mañana.
	Las edades de 8 estudiantes del turno tarde.
	Las edades de 12 estudiantes del turno noche.
	
	Las edades de cada estudiante deben ingresarse por teclado.
	a) Obtener el promedio de las edades de cada turno (tres promedios diferentes).
	Hacerlo mediante una única función que sea invocada tres veces, el prototipo de la función será:
		float promedio(int array[]); 
		
	Para el tamaño del array utilizar la sentencia sizeof de la siguiente manera:
		sizeof(array)/sizeof(array[0])
		
	Reemplazar la palabra array con el nombre del array que van a utilizar.
		b) Imprimir dichos promedios (promedio de cada turno)
		c) Mostrar por pantalla un mensaje que indique cuál de los tres turnos tiene un promedio de edades mayor.
	
*/

#include<stdio.h>


char* promedioMayor(float promedio1, float promedio2, float promedio3);
float promedio(int array[], int max);
void cargarDatos(int array[], int max);

int main() {
	int turnoMan[5];
	int turnoTar[8];
	int turnoNoc[12];
	
	printf("\n\n\tTurno mañana");
	cargarDatos(turnoMan, sizeof(turnoMan) / sizeof(turnoMan[0]));
	
	printf("\n\n\tTurno tarde");
	cargarDatos(turnoTar, sizeof(turnoTar) / sizeof(turnoTar[0]));
	
	printf("\n\n\tTurno noche");
	cargarDatos(turnoNoc, sizeof(turnoNoc) / sizeof(turnoNoc[0]));
	
	float promedio1 = promedio(turnoMan, sizeof(turnoMan) / sizeof(turnoMan[0]));
	float promedio2 = promedio(turnoTar, sizeof(turnoTar) / sizeof(turnoTar[0]));
	float promedio3 = promedio(turnoNoc, sizeof(turnoNoc) / sizeof(turnoNoc[0]));
	
	printf("\n\n\tEl promedio del turno mañana es de %.2f", promedio1);
	printf("\n\tEl promedio del turno tarde es de %.2f", promedio2);
	printf("\n\tEl promedio del turno noche es de %.2f\n\n\t", promedio3);
	printf("El promedio mas grande es el del %s.\n\n\t", promedioMayor(promedio1, promedio2, promedio3));
	system("PAUSE");
	return 0;
}

void cargarDatos(int *array, int max) {
	int i = 0;
	
	for(i = 0; i < max; i = i + 1) {
		printf("\n\tIngrese la edad de %s alumno: ", (i == 0 ? "un" : "otro"));
		scanf("%d", (array+i));
		if(array[i] <= 0 || *(array+i) > 120) {
			printf("\n\tLa edad ingresada es invalida.\a");
			i = i - 1;
		}
	}
}

float promedio(int array[], int max) {
	int i;
	float promedio = 0;
	
	for( i = 0; i < max; i = i + 1) {
		promedio = promedio + (float)*(array+i);
	}
	return promedio/max;
}

char* promedioMayor(float promedio1, float promedio2, float promedio3) {
	float mayor = promedio1;
	if(promedio2 > mayor)
		mayor = promedio2;
	if(promedio3 > mayor)
		mayor = promedio3;
	
	if(mayor == promedio1) return "turno mañana";
	else if(mayor == promedio2) return "turno tarde";
	else return "turno noche";
}