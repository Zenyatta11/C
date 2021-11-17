/*

Ingresar por teclado una palabra en minúsculas.
Mostrar por pantalla la cantidad de vocales que tiene dicha palabra.

*/


#include<stdio.h>

int getVowels(char string[]) {
	int vowels = 0, i;
	
	for(i = 0; i < sizeof(string)/sizeof(string[0]); i = i + 1) {
		switch(string[i]) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u': vowels = vowels + 1; break;
			default: break;
		}
	}
	return vowels;
}

int main() {
	char str[16];
	
	printf("Vocales en un string.\n\nIngrese una palabra en minusculas: ");
	
	scanf("%s", &str);
	
	printf("\nLa palabra %s tiene %d vocales.\n\n", str, getVowels(str));
	system("PAUSE");
	return 0;
}


