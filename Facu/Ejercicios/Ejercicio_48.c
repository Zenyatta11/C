/*

Escribir un programa que lea una variable del tipo float representando una velocidad en m/s e imprima el valor ingresado en km por hora.

1 metro por segundo = 3.6 km por hora

Utilizar una única variable.


*/


#include<stdio.h>

int main() {
	float input;
	printf("M/s a KM/h\n\nIngrese un valor en metros por segundo: ");
	scanf("%f", &input);
	printf("%.2fm/s son %.2fkm/h\n\n", input, input * 3.6);
	system("PAUSE");
	return 0;
}


