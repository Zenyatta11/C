// Ingresados 20 números por teclado contabilizar los números pares y los impares

#include <stdio.h>

int main() {
	
	int input, even, odd, i;
	even = odd = i = 0;
	
	printf("Pares e Impares.\n\n");
	
	for(i = 0; i < 20; i = i + 1) {
		if(i) printf("\nQueda%s %d numero%s.", (i == 19 ? "" : "n"), 20-i, (i == 19 ? "" : "s"));
		printf("\nIngrese un numero: ");
		scanf("%d", &input);
		if(input % 2 != 0) odd = odd + 1; else even = even + 1;
	}
	
	printf("\n\nSe ingresaron ");
	if(even > 0) printf("%d numero%s par%s %s ", even, (even == 1 ? "" : "s"),  (even == 1 ? "" : "es"), (odd ? "y" : ""));
	if(odd > 0) printf("%d numero%s impar%s", odd, (odd == 1 ? "" : "s"),  (odd == 1 ? "" : "es"));
	printf(".\n\n");
	
	system("PAUSE");
	return 0;
}