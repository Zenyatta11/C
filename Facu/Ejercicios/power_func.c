
#include <stdio.h>

int dospordos() {
	return 4;
}

int main() {
	int input, input2;
	
	printf("Ingrese un numero para sacarle la potencia: ");
	scanf("%d", &input);
	
	printf("Ingrese la potencia: ");
	scanf("%d", &input2);
	
	printf("El resultado es %d", dospordos());
	system("PAUSE");
	return 0;
}

