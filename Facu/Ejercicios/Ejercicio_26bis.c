//Ejercicio 26: Roizman Pezzoni Gibert Glass Silvestri

/*

Definir un vector de 5 componentes de tipo float que representen las alturas de 5 personas.
Obtener el promedio de las mismas. 
Contar cuántas personas son más altas que el promedio y cuántas más bajas

*/

#include <stdio.h>
#define MAX 5

float Array[MAX], input, promedio = 0;
int i, masAltos, masBajos;

void obtenerDatos() {
	for(i = 0; i < MAX; i = i + 1) {
		printf("Ingrese la altura en metros de la persona %d: ", i+1);
		scanf("%f", &input);
		if(input <= 0) {
			printf("La altura no puede ser %s.\n\n", (input < 0 ? "negativa" : "cero"));
			i = i - 1;
		} else if(input > 2.5) {
			printf("La altura no puede ser tan alta.\n\n");
			i = i - 1;
		} else {
			*(Array+i) = input;
			promedio = promedio + input;
		}
	}
}

void mostrarDatos() {
	for(i = 0; i < MAX; i = i + 1) {
		
		printf(" \tPersona %d: %.2fm", i+1, *(Array+i));
		
		if(*(Array+i) > promedio) {
			printf("\tMas ALTA que el promedio\n");
			masAltos = masAltos + 1;
		} else if(*(Array+i) < promedio){
			printf("\tMas BAJA que el promedio\n");
			masBajos = masBajos + 1;
		}
		else printf("\tIGUAL al promedio\n");
	} 

	printf("\n Altura promedia: %.2fm.\n\n", promedio);
	printf("\n Hay %d personas mas altas que el promedio.", masAltos);
	printf("\n Hay %d personas mas bajas que el promedio.", masBajos);
	printf("\n Hay %d personas con la misma altura que el promedio.\n\n", MAX - masAltos - masBajos);
}

int main() {
	
	masAltos = masBajos = 0;
	
	printf("Altura promedio de cinco personas.\n\n");
	
	obtenerDatos();
	
	system("PAUSE");
	system("CLS");
	
	promedio = promedio / MAX;
	
	printf(" Las alturas son las siguientes:\n\n");
	
	mostrarDatos();
	
	system("PAUSE");
	return 0;
}