/*

Definir un vector de 5 componentes de tipo float que representen las alturas de 5 personas.
Obtener el promedio de las mismas. 
Contar cuántas personas son más altas que el promedio y cuántas más bajas

*/


#include<stdio.h>
#define MAX 5

int main() {
	
	int i, havg, lavg, eavg;
	float Array[MAX], input, avg;
	
	havg = lavg = eavg = 0;
	
	printf("Altura de cinco personas.\n\n");
	
	for(i = 0; i < MAX; i = i + 1) {
		printf("Ingrese en metros la altura de la persona %d: ", i + 1);
		scanf("%f", &input);
		if(input <= 0) {
			printf("La altra no puede ser %s.\n\n", (input < 0 ? "negativa" : "cero"));
			i = i - 1;
		} else {
			*(Array+i) = input;
			avg = avg + input;
		}
	}
	
	avg = avg / MAX;
	system("PAUSE");
	system("cls");
	printf("\n\nLas alturas son las siguientes:\n\n");
	
	for(i = 0; i < MAX; i = i + 1) {
		
		if(*(Array+i) > avg)
			havg = havg + 1;
		else if(*(Array+i) < avg)
			lavg = lavg + 1;
		else eavg = eavg + 1;
		
		printf("\tPersona %d: %.2fm\t%s\n", i + 1, *(Array+i), (*(Array+i) > avg ? "(Mas ALTA que el promedio)" : *(Array+i) < avg ? "(Mas BAJA que el promedio)" : "(ALTURA PROMEDIO)"));
	}
	
	printf("\nPromedio de altura: %.2f\n", avg);
	
	if(havg > 0)
		printf("Mas altas que el promedio: %d\n", havg);
	
	if(havg > 0)
		printf("Mas bajas que el promedio: %d\n", lavg);
	
	if(eavg > 0)
		printf("Iguales al promedio: %d\n", eavg);
	
	printf("\n");
	system("PAUSE");
	return 0;
}

