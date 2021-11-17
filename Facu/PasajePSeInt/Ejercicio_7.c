// Calcular el promedio de una lista de N datos. El usuario carga el valor  N y luego  los N datos.
// Validar que N sea mayor a 0.

#include <stdio.h>

int main() {
	
	int inputAmt, sum, i, inputNum;
	
	printf("Promedio de N datos.\n\nIngrese la cantidad de datos que ingresara: ");
	scanf("%d",&inputAmt);
	
	if(!(inputAmt > 0)) {
		printf("\nEl ingreso es invalido. La cantidad de datos debe ser mayor a cero.\n\n");
		main();
	} else {
		sum = 0;
		for(i = 0; i < inputAmt; i = i + 1) {
			printf("\nLa suma actual es %d.\nIngrese %s numero para sumar: ", sum, i==0?"un":"otro");
			scanf("%d", &inputNum);
			sum = sum + inputNum;
		}
		printf("\n\nLa suma total es %d\n\n\n",sum);
		system("PAUSE");
	}
	
	return 0;
}
