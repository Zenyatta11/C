// Usando MIENTRAS: Se ingresan por teclado 3 números, se suman y se muestra el resultado por pantalla.

#include <stdio.h>

int main() {
	
	printf("Suma de tres numeros.\nWHILE loop\n\n");
	
	int i, input, sum;
	i = sum = 0;
	
	while(i < 3) {
		if(i) printf("\n\nLa suma hasta el momento es de %d.\nQueda%s %d numero%s.", sum, (i == 2 ? "" : "n"), 3-i, (i == 2 ? "" : "s"));
		printf("\nIngrese un numero para sumar: ");
		scanf("%d", &input);
		sum = sum + input;
		i = i + 1;
	}
	printf("\n\nLa suma de los numeros es de %d\n\n", sum);
	system("PAUSE");
	return 0;
}