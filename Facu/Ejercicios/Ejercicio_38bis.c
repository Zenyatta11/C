/*

Desarrollar una función que reciba como parámetro un caracter. Si llega una 'M' mostrar por pantalla el mensaje "Masculino", si llega una 'F' mostrar el mensaje "Femenino".
Para probarla, desarrollar una función main que lea del teclado el caracter.


*/


#include<stdio.h>

void getGenero(char gend) {
	switch(gend) {
		case 'm':
		case 'M': printf("masculino"); break;
		case 'f':
		case 'F': printf("femenino"); break;
		default: printf("invalido"); break;
	}
}

int main() {
	
	char genero;
	
	printf("Masculino o Femenino.\n\nIngrese una letra (M o F): ");
	
	scanf("%c", &genero);
	
	printf("El genero es ");
	getGenero(genero);
	printf(".\n\n");
	system("PAUSE");
	return 0;
}


