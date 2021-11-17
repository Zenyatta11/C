// De 10 números ingresados por teclado, indicar cuántos ingresados son mayores y cuántos menores a 0.

#include <stdio.h>

int main() {
	
	int countNeg, countZero, countPos, input, i;
	countPos = countNeg = countZero = 0;
	
	printf("Mayores, menores, e iguales a cero.\n\nIngrese diez numeros a continuacion para cuantificar cuantos son mayores, menores, e iguales a cero.\n\n");
	
	for(i = 0; i < 10; i = i + 1) {
		if(i != 0) printf("\nFalta%s %d numero%s.", (10-i==1 ? "" : "n"), 10-i, (10-i==1 ? "" : "s"));
		printf("\nIngrese un numero: ");
		scanf("%d", &input);
		if(input > 0)
			countPos = countPos + 1;
		else if(input < 0)
			countNeg = countNeg + 1;
		else
			countZero = countZero + 1;
	}
	printf("\n\n");
	if(countPos != 0) printf("\nHay %d numero%s mayor%s a cero.", countPos, (countPos==1 ? "" : "s"), (countPos==1 ? "" : "es"));
	if(countNeg != 0) printf("\nHay %d numero%s menor%s a cero.", countNeg, (countNeg==1 ? "" : "s"), (countNeg==1 ? "" : "es"));
	if(countZero != 0) printf("\nHay %d numero%s igual%s a cero.", countZero, (countZero==1 ? "" : "s"), (countZero==1 ? "" : "es"));
	printf("\n\n");
	system("PAUSE");
	return 0;
}