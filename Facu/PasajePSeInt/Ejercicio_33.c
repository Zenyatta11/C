// Calcular la suma de los primeros N números pares. N debe ser mayor a cero y será ingresado por teclado. Por ej. si N=3, el resultado es 2+4+6=12

#include <stdio.h>

int main() {
	
	int sum = 0, input;
	
	printf("Suma de los primeros N numeros pares.\n\nIngrese un numero mayor a cero: ");
	scanf("%d", &input);
	if(input > 0) {
		for(; input > 0; input = input - 1) {
			sum = sum + input*2;
			if(input == 1) printf("%d = %d\n\n", input*2, sum);
			else printf("%d + ", input*2);
		}
		system("PAUSE");
	} else {
		printf("El numero ingresado es invalido.\nDebe ser mayor a cero.\n\n");
		main();
	}
	
	return 0;
}