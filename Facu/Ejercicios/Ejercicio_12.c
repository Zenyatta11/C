
/*
Notas en letras.
Dada una nota de un examen mediante un código (un solo carácter) escribir el literal que le corresponde a la nota. 

Si se ingresa A es Excelente
Si se ingresa B es Notable
Si se ingresa C es Aprobado
Si se ingresa D y F es Reprobado
*/

#include <stdio.h>

int main() {
	
	char grade;
	printf("Notas Americanas.\n\nIngrese la nota (A; B; C; D; F) que se saco el alumno: ");
	scanf("%c", &grade);
	
	if(grade != 'F' && ((int)grade < 65 || (int)grade > 68) && grade != 'f' && ((int)grade < 97 || (int)grade > 100)) {
		printf("\nLa nota ingresada es invalida.\n\n");
	} else {
		switch(grade){
			case 'A':
			case 'a': printf("\nExcelente!\n\n"); break;
			case 'B':
			case 'b': printf("\nNotable.\n\n"); break;
			case 'C':
			case 'c': printf("\nAprobado\n\n"); break;
			case 'D':
			case 'd':
			case 'F':
			case 'f': printf("\nReprobado\n\n"); break;
			default: printf("Nota invalida.\n\n"); break;
		}
	}	
	system("PAUSE");
	return 0;
}
