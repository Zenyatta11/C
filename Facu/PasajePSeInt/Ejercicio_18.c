// Ingresar el nombre del empleado, la cantidad de horas trabajadas y luego calcular sueldo bruto (a 210 pesos la hora), 
// el seguro y el sueldo a pagar (bruto - seguro). El seguro es 85 pesos si el sueldo bruto es inferior a 2500 pesos, 
// y el 3,5% si es mayor. Utilizar constantes.

#include <stdio.h>

#define SEGURO_A 85
#define SEGURO_B 0.965

int main() {
	
	char *name;
	float salary;
	
	printf("Calculo de Seguro de Sueldo.\n\nIngrese el nombre del empleado: ");
	scanf("%s", &name);
	
	printf("\nIngrese el salario actual del emplado: $");
	scanf("%f", &salary);
	
	printf("\n\nEl sueldo a pagar de %s es de $%.2f.\n\n", &name, (salary < 2500 ? salary-SEGURO_A : salary*SEGURO_B));
	system("PAUSE");
	return 0;
}
