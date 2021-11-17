/*

Mostrar el abecedario de la 'A' a la 'Z' primero en mayúsculas y luego en minúsculas.
Utilizar una variable de tipo char dentro de un for.

*/


#include<stdio.h>

void abc(int i, int max) {
	max = max + i + 1;
	char letra;
	for(; i < max; i = i + 1) {
		letra = (char)i;
		printf("%c%s", letra, (letra == 'Z' || letra == 'z' ? ";\n" : ", "));
	}
}

int main() {

	printf("Abecedario\n\n\t");
	abc('A', 'Z'-'A');
	printf("\n\t");
	abc('a', 'z'-'a');
	printf("\n\n");
	system("PAUSE");
	return 0;
	
}


