// Se ingresa por teclado la cantidad de agua caída en mm día a día durante un SOLO mes. Se pide el día de mayor lluvia, el de menor lluvia y el promedio de mm llovidos.
// Si un día no llueve se ingresa 0. Todos los meses tendrán 30 días.

#include <stdio.h>

int main() {
	
	int i, max, min, input, max0, min0;
	float avg = 0;
	
	printf("Lluvia en un mes.\n\n");
	for (i = 0; i < 30; i = i + 1) {
		printf("\nIngrese la cantidad de lluvia que cayo el dia %d: ", i + 1);
		scanf("%d", &input);
		if(input < 0) {
			printf("El ingreso debe ser mayor o igual a cero\n");
			i = i - 1;
		} else {
			avg = avg + input;
			if(i == 0) {
				max = min = input;
				max0 = min0 = i;
			} else if(input > max) {
				max = input;
				max0 = i;			
			} else if(input < min) {
				min = input;
				min0 = i;			
			}
		}
	}
	printf("\n\nEl dia mas llovedor fue el dia %d con %dmm\ny el menor llovedor fue el dia %d con %dmm.\nEl promedio de lluvia del mes es de %.2fmm.\n\n", max0+1, max, min0+1, min, avg/30);
	system("PAUSE");
	return 0;
}