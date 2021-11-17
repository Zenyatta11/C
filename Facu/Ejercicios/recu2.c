
#include<stdio.h>

char obtenerPromedio(char notaA, char notaB);

int main() {
	char nombre[24], notaFinal;
	float notaA, notaB;
	printf("\n\tIngrese el nombre del alumno: ");
	gets(nombre);
	do{
		printf("\tIngrese una nota: ");
		scanf("%f", &notaA);
		if(!(notaA > 0 && notaA <= 10)) {
			printf("\tLa nota ingresada es invalida.\n\n");
		}
	}while(!(notaA > 0 && notaA <= 10));
	
	do{
		printf("\tIngrese otra nota: ");
		scanf("%f", &notaB);
		if(!(notaB > 0 && notaB <= 10)) {
			printf("\tLa nota ingresada es invalida.\n\n");
		}
	}while(!(notaB > 0 && notaB <= 10));
	
	notaFinal = obtenerPromedio(notaA, notaB);
	
	printf("\n\tEl estudiante %s tiene un promedio de %c.\n\n\t", nombre, notaFinal);
	
	system("PAUSE");
	return 0;
}

char obtenerPromedio(char notaA, char notaB) {
	float promedio = (notaA + notaB) / 2;
	if(promedio == 10) return 'A';
	if(promedio < 10  && promedio >= 7) return 'B';
	if(promedio <7 && promedio >= 4) return 'C';
	return 'D';
}