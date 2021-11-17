// Factorial de N. Calcular el producto de los N primeros números naturales. 
// N! = N.(N-1).(N-2)…1 ; por ej. 4! = 4 * 3 * 2 * 1 = 24

#include <stdio.h>

int main() {
	
	int fact = 1, i, input;
	
	printf("Factorial de N.\n\nIngrese un numero natural para calcular su factorial: ");
	scanf("%d", &input);
	if(input > 0) {
		for (i = 0; i < input; ) {
			i = i + 1;
			fact = fact * i;
			if(i == 1) printf("%d! = %d", input, i);
			else printf(" * %d", i);
		}
		printf(" = %d\n\n", fact);
		system("PAUSE");
	} else {
		printf("\nEl numero ingresado es invalid.\nDebe ser un numero natural (entero mayor a cero)\n\n\n");
		main();
	}
	return 0;
}
