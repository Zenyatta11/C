// Promedio de 5 numeros

#include <stdio.h>

int main() {
	
	int sum, i, inputNum;
	
	printf("Promedio de 5 datos.\n\n");
	sum = 0;
	for(i = 0; i < 5; i = i + 1) {
		printf("\nIngrese %s numero para sacarle el promedio: ", i==0?"un":"otro");
		scanf("%d", &inputNum);
		sum = sum + inputNum;
	}
	printf("\n\nEl promedio total es %.2f\n\n\n",(float)sum/5);
	system("PAUSE");
	return 0;
}
