/*

Notas Americanas

*/


#include<stdio.h>

int main() {
	
	char nota;
	
	printf("Ingrese la nota del alumno: ");
	//nota = getch();
	scanf("%c", &nota);
	
	switch(nota) {
		case 'A':
		case 'a': printf("Average\n\n"); break;
		case 'B':
		case 'b': printf("Bad\n\n"); break;
		case 'C':
		case 'c': printf("Catastrophic\n\n"); break;
		case 'D':
		case 'd': printf("Disasterous\n\n"); break;
		case 'F':
		case 'f': printf("Forgotten Forever\n\n"); break;
		default: printf("La nota es invalida.\n\n"); break;
	}
	
	system("PAUSE");
	return 0;
}


