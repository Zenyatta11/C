/*

Desarrollar una función que reciba como parámetro un caracter.
La función debe mostrar un mensaje si es una vocal o no es una vocal.
Debe funcionar tanto con mayúsculas y minúsculas.

*/


#include<stdio.h>

int getVowels(char input);
int stopExecution();

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                                    MAIN  LIMPIO                                      // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

int main() {
	do{
		system("CLS");
		printf("Vocal o consonante?\n\n");
		printf("Presione una letra.\n\n");
		getVowels(getch());
	}while(!stopExecution());
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                               FUNCIONES  SECUNDARIAS                                 // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

int stopExecution() {
	unsigned char input;
	printf("Presione C para continuar/repetir o E para terminar.\n\n");
	do {
		input = getch();
		if(input == 'C' || input == 'c') return 0;
		if(input == 'E' || input == 'e') return 1;
	}while(1);
}

int getVowels(char input) {
	switch(input) {
		case 'A':
		case 'a':
		case 'E':
		case 'e':
		case 'I':
		case 'i':
		case 'O':
		case 'o':
		case 'U':
		case 'u': printf("\tEs una vocal!\n\n"); return;
		default: break;
	}
	if(input >= 'A' && input <= 'Z' || input >= 'a' && input <= 'z') printf("\tEs una consonante.\n\n");
	else printf("\tNo es una letra!\n\n");
}
