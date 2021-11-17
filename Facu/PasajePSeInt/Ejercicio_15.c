// Usando REPETIR. Calcular la suma de los primeros N números enteros. El valor de N se ingresa por teclado. 
// Validar que N sea mayor a 0.
// Por ej.: si N fuera 3, sería la suma de 1+2+3

#include <stdio.h>

int main() {
	
	int sum, i, input;
	i = sum = 0;
	
	printf("Suma de N numeros naturales.\n\n\nIngrese el numero objetivo: ");
	scanf("%d", &input);
	if(input > 0) {
		do {
			i = i + 1;
			sum = sum + i;
			printf("%s%d", (i==1 ? "\n\n" : " + "), i);
		} while (i < input);
		printf(" = %d\n\n", sum);
		system("PAUSE");
	} else {
		printf("\nEl numero ingresado es invalido.\nDebe ser un numero natural (Entero mayor a cero)\n");
		main();
	}
	return 0;
}
