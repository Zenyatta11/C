/*

	Realizar un programa que pida un nombre y lo guarde utilizando la función malloc().
	La función main asignará la memoria, pedirá el nombre para mostrar luego un mensaje en pantalla: “Hola, ….”. 

*/

#include<stdio.h>
#include<stdlib.h>

int main() {
	int leave = 0;
	char input, length = 0;
	char* string;
	
	printf("\n\tIngrese su nombre: ");
	
	while(leave == 0) {
		
		input = getc(stdin);
		length = length + 1;
		string = realloc(string, sizeof(length) * length);
		
		if(string == NULL) {
			leave = 1;
		} else {
			if(input == '\n') {
				string[length-1] = '\0';
				leave = 2;
			} else
				string[length-1] = input;
		}
	}
	printf("\n\tBytes asignados: %d", sizeof(length) * length);
	if(leave == 2){
		printf("\n\n\tHola %s!\n\n", string);
		free(string);
	} else if(leave == 1)
		printf("\n\n\tError allocating memory.\n\n");
	system("PAUSE");
	return 0;
}

