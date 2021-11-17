
/*
Eres de Aries?
Ingresar por teclado el nombre y el signo de una persona. Imprima por consola el nombre de la persona solo si su signo es Aries, de lo contrario imprimir “La persona no es de Aries”.
*/

#include <stdio.h>

int main() {
	
	char Name[64];
	char Sign[16];
	//Name[63] = Sign[15] = "\0";
	
	printf("Sos de Aries?\n\nIngrese su nombre: ");
	scanf("%s", Name);
	printf("\nIngrese su signo: ");
	scanf("%s", &Sign); //41 52 49 45 53
	if((Sign[0] == 'A' || Sign[0] == 'a') && (Sign[1] == 'R' || Sign[1] == 'r') && (Sign[2] == 'I' || Sign[2] == 'i') &&
	(Sign[3] == 'E' || Sign[3] == 'e') && (Sign[4] == 'S' || Sign[4] == 's'))
		//podria haber usado strcmp() pero no es suficientemente C H A D
		printf("\n%s\n\n", Name);
	else printf("\nNo es de Aries.\n\n");
	system("PAUSE");
	return 0;
	
}
