// Se requiere saber cuánto ahorró una persona en un año, si al final de cada mes deposita lo que pudo ahorrar.
// Mostrar también lo que se va ahorrando mes a mes. Si no ahorró nada, ingresará 0.

#include <stdio.h>

int main() {
	
	int i, max0;
	char *Months[] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
	float total = 0, max, input;
	
	printf("Ahorro Anual.\n\n");
	for (i = 0; i < sizeof(Months) / sizeof(*Months); i = i + 1) {
		printf("Ingrese la cantidad de dinero que ahorro el mes de %s: ", *(Months+i));
		scanf("%f", &input);
		if(input < 0) {
			printf("El ingreso no puede ser negativo.\nEn el caso que no haya ahorrado nada, ingrese cero.\n");
			i = i - 1;
		} else {
			total = total + input;
			if(i == 0) {
				max = input;
				max0 = i;
			} else if(input > max) {
				max = input;
				max0 = i;			
			}
		}
	}
	printf("\n\nEl mes de mayor ahorro fue del mes de %s.\nEl ahorro total fue de $%.2f\n\n", *(Months+max0), total);
	system("PAUSE");
	return 0;
}