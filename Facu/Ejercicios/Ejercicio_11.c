
/*
Primer trimestre
Solicitar por teclado al usuario que ingrese un mes (en número, es decir si es marzo será 3).

Luego evaluar si el mes ingresado corresponde al primer trimestre del año.
*/

#include <stdio.h>

int input;
char *Month[12] = { "Enero\0", "Febrero\0",  "Marzo\0",  "Abril\0",  "Mayo\0",  "Junio\0",  "Julio\0",  "Agosto\0" , "Septiembre\0",  "Octubre\0",  "Noviembre\0", "Diciembre\0" };

int main() {
	
	printf("Primer Trimestre.\n\nIngrese el numero de un mes para ver si corresponde al primer trimestre: ");
	
	do {
		scanf("%d", &input);
		
		if(input < 1 || input > 12) {
			printf("El numero ingresado es invalido.\nIngrese un nuevo numero: ");
		}
	} while(input < 1 || input > 12);
	
	// Se supone que meses 1, 2, 3, y 4 son del primer TRI-mestre.
	
	printf("\nEl mes de %s %ses del primer trimestre.\n\n\n", Month[input-1], (input > 4 ? "no ": ""));
	
	system("PAUSE");
	return 0;
	
}
