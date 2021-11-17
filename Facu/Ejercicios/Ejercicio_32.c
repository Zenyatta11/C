/*

Ingresar dos nombres por teclado. Mostrar un mensaje si son iguales y sino mostrar el que es mayor alfabéticamente.

*/


#include<stdio.h>
#include<string.h>

int main() {
	char nom_1[16];
	char nom_2[16];
	int i;
	
	printf("Nombre mayor.\n\nIngrese el primer nombre: ");
	scanf("%s", &nom_1);
	printf("Ingrese el segundo nombre: ");
	scanf("%s", &nom_2);
	
	if(strcmp(nom_1, nom_2) == 0)
		printf("\nLos nombres son iguales.\n\n");
	else if(strcmp(nom_1, nom_2) > 0)
		printf("\nEl nombre %s es mayor.\n\n", nom_1);
	else 
		printf("\nEl nombre %s es mayor.\n\n", nom_2);
	system("PAUSE");
	return 0;
}


