//Suma de 3 numeros

#include <stdio.h>

int main() {
	
	int sum, i, inputNum;
	
	printf("Suma de 3 datos.\n\n");
	sum = 0;
	for(i = 0; i < 3; i = i + 1) {
		if(sum != 0) printf("\nLa suma actual es de %d", sum);
		printf("\nIngrese %s numero para sumar: ",i==0?"un":"otro");
		scanf("%d", &inputNum);
		sum = sum + inputNum;
	}
	printf("\n\nLa suma total es %d\n\n\n",sum);
	system("PAUSE");
	return 0;
}

