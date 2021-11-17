/*

Una, dos, o tres cifras?

*/


#include<stdio.h>

int main() {
	
	int input;
	
	printf("Una, dos, o tres cifras?\n\nIngrese un numero: ");
	scanf("%d", &input);
	printf("%d\n\n", input);
	
	if(input < 0) input = input * -1;
	
	if(input < 1000) {
		printf("El numero tiene tres digitos\n\n");
	} else if(input < 100) {
		printf("El numero tiene dos digitos\n\n");
	} else if(input < 10) {
		printf("El numero tiene un digito\n\n");
	} else printf("El numero tiene mas de tres digitos\n\n");
	system("PAUSE");
	return 0;
}


