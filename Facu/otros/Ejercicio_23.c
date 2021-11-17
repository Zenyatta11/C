/*

 Multiplos de 3 y 5

*/


#include<stdio.h>

int main() {
	
	int input, multiplo;
	
	printf("Multiplo de 3 y 5\n\nIngrese un numero: ");
	scanf("%d", &input);
	
	multiplo = esmultiplode(input);
	
	if(multiplo == 0) printf("El numero es multiplo de 3 y de 5\n\n");
	else if(multiplo == 1) printf("El numero es multiplo de 3\n\n");
	else if(multiplo == 2) printf("El numero es multiplo de 5\n\n");
	else printf("El numero no es multiplo ni de 3 ni de 5\n\n");
	
	system("PAUSE");
	return 0;
	
}

int esmultiplode(int numb) {
	if(numb % 15 == 0) return 0;
	else if(numb % 3 == 0) return 1;
	else if(numb % 5 == 0) return 2;
	else return -1;
}

