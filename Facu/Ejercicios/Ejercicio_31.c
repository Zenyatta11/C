/*

Ingresar por teclado una palabra. Mostrar luego por pantalla la cantidad de letras que tiene.

*/


#include<stdio.h>

int main() {
	char str[16];
	int i;
	
	printf("Cantidad de Letras.\n\nIngrese una palabra: ");
	scanf("%s", &str);
	
	for(i = 0; i < 16; i = i + 1) {
		if((int)str[i] == 0) break;
	}
	
	printf("La palabra %s tiene %d letras.\n\n", str, i);
	system("PAUSE");
	return 0;
}


