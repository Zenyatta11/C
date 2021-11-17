
/*
Promocionan si o no?
Confeccionar un programa que pida por teclado tres notas de un alumno, calcule el 
promedio e imprima alguno de estos mensajes:

	Si el promedio es >=7 mostrar "Promocionado".
	Si el promedio es >=4 y <7 mostrar "Regular".
	Si el promedio es <4 mostrar "Reprobado".

*/

#include <stdio.h>

float input, average = 0;

int main() {
		printf("Promocionan?\n\nIngrese las tres notas de un alumno: \n\n");
	
	int i = 0;
	
	for(;i < 3; i = i + 1) {
		printf("Nota del ");
		switch(i) {
			case 0: printf("primer"); break;
			case 1: printf("segundo"); break;
			case 2: printf("tercer"); break;
			default: printf(""); //no deberia entrar aca
		}
		printf(" trimestre: ");
		scanf("%f", &input);
		
		if(input < 1 || input > 10) {
			printf("La nota ingresada es invalida.\nIngrese una nueva nota: ");
			i = i - 1;
		} else average = average + input;
	}
	
	average = average / 3;
	if((int)average >= 7) printf("\nEl alumno promociona!\n\n");
	else if((int)average >= 4) printf("\nEl alumno escolariza!\n\n");
	else printf("\nEl alumno debe recursar.\n\n");
	
	system("PAUSE");
	return 0;
}
