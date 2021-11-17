/*

Definir un vector de 5 componentes de tipo float que representen las alturas de 5 personas.
Obtener el promedio de las mismas. 
Contar cuántas personas son más altas que el promedio y cuántas más bajas

*/

#include <stdio.h>

float Vector[5];

void ObtenerDatos();
float SacarPromedio();
void MostrarDatos(float promedio);

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                                       MAIN                                           // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

int main() {
	
	printf("Promedio de alturas.\n\n");
	ObtenerDatos();
	printf("\n");
	MostrarDatos(SacarPromedio());
	printf("\n\n");
	system("PAUSE");
	return 0;
	
}

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                               FUNCIONES  SECUNDARIAS                                 // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

void ObtenerDatos() {
	int i;
	for(i = 0; i < 5; i = i + 1) {
		do{
			
			printf("Ingrese la altura de %s alumno en metros: ", (i == 0 ? "un" : "otro"));
			scanf("%f", &Vector[i]);
			if(Vector[i] <= 0 || Vector[i] > 2.5) printf("La altura es invalida.\n\n");
			else if(i+1 != 5) printf("Restan %d.\n\n", 5-i-1);
			
		}while(Vector[i] <= 0 || Vector[i] > 2.5);
	}
}

float SacarPromedio() {
	return (Vector[0] + Vector[1] + Vector[2] + Vector[3] + Vector[4]) / 5;
}

void MostrarDatos(float promedio) {
	int i;
	printf("El promedio es de %.2fm.\n\n", promedio);
	for(i = 0; i < 5; i = i + 1) {
		printf("\tAlumno %d: %.2fm\t", i + 1, Vector[i]);
		if(Vector[i] > promedio) printf("(MAYOR al promedio)\n");
		else if(Vector[i] < promedio) printf("(MENOR al promedio)\n");
		else printf("(IGUAL al promedio)\n");
	}
}

//nois