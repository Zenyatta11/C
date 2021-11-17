#include<stdio.h>
int main(){
	int fin, numero,numero2; 

	printf("ingrese los valores a sumar a continuacion:\n");

	scanf("%d", &fin);
	scanf("%d", &numero);

	do{ 
		numero2=fin;
		numero = numero + numero2;
		printf ("ingresa el siguiente numero a sumar:"); 
		scanf("%d", &fin);
	} while(fin!=0);

	printf("el resultado: %d\n", numero);
	system("PAUSE");
	return 0;
}