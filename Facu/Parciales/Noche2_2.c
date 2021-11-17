/*

	Realizar un programa que simule la caja de un negocio y sus transacciones diarias (máximo 100).
	
	Las transacciones posibles son cobros (ingresos) por ventas y pagos (egresos) a proveedores.
	
	Se ingresan los montos en pesos a medida que van sucediendo.
	Preguntar al usuario si quiere continuar cargando o cerrar la caja.
	
	Luego de ingresadas todas las operaciones, mostrar por pantalla lo pedido a continuación:  
		Total de cobros 
		Total de pagos 
		El monto de la mayor venta del día 

	Listado de todas las operaciones en el orden en el que fueron hechas Validar todo lo necesario.
	
	La función main() no lee ni escribe nada.
	Utilizar las bibliotecas de C standard.
	
	El programa debe contar con varias funciones.

*/


//	+------------------------------------------------------------------------------------------------+
//	| Project				:	Programacion I                                                       |
//	| Author				:	Zenyatta11                                                           |
//	| Description			:	Ejercicio IIbis - Turno Noche                                        |
//	+------------------------------------------------------------------------------------------------+
//	| Table of Contents                                                                              |
//	| 1. Preparacion/Definiciones                                                                    |
//	| 2. Main                                                                                        |
//	| 3. Funciones Secundarias                                                                       |
//	+------------------------------------------------------------------------------------------------+

//	+------------------------------------------------------------------------------------------------+
//	| Section 1 : Preparacion/Definiciones                                                           |
//	+------------------------------------------------------------------------------------------------+

#include<stdio.h>

#define true 1
#define false 0
#define bool unsigned int
#define STR_MAX 24
#define MAX 100

void MostrarDatos(long long Transaccion[], int cantTransaccion);
bool validarNombre(char nombre[]);
int CargarDatos(long long Transaccion[]);

//	+------------------------------------------------------------------------------------------------+
//	| Section 2 : Main                                                                               |
//	+------------------------------------------------------------------------------------------------+

int main() {
	
	long long Transaccion[MAX];
	int cantTransaccion;
	
	cantTransaccion = CargarDatos(Transaccion);
	MostrarDatos(Transaccion, cantTransaccion);
	
	return 0;
}

//	+------------------------------------------------------------------------------------------------+
//	| Section 3 : Funciones Secundarias                                                              |
//	+------------------------------------------------------------------------------------------------+

int CargarDatos(long long Transaccion[]) {
	int i, caso;
	char charInput;
	bool continuar;
	
	i = caso = 0;
	continuar = true;
	
	while(continuar) {
		switch(caso) {
			case 0:
				system("CLS");
				printf("\n\n Ventas y Pagos\n\n\tIngrese el tipo de operacion: \n\t[VENTA] - [PAGO]\n\n");
				fflush(stdin);
				scanf("%c", &charInput);
				switch(charInput) {
					case 'v':
					case 'V': caso = 1; break;
					case 'p':
					case 'P': caso = 2; break;
					default: printf("El ingreso es invalido.\n\a"); system("PAUSE");
	return 0; break;
				}
				break;

			case 1:
				system("CLS");
				printf("\n\n Ventas y Pagos: VENTA\n\n\tIngrese el monto de la venta: ");
				fflush(stdin);
				scanf("%lld", &Transaccion[i]);
				if(Transaccion[i] <= 0) {
					printf("\tEl monto ingresado es invalido. Una venta no puede ser negativa.\n\n\a");
					system("PAUSE");
	return 0;
				} else {
					caso = 3;
					i = i + 1; 
				}
				break;
				
			case 2:
				system("CLS");
				printf("\n\n Ventas y Pagos: PAGO\n\n\tIngrese el monto del pago realizado: ");
				fflush(stdin);
				scanf("%lld", &Transaccion[i]);
				if(Transaccion[i] <= 0) {
					printf("\tEl monto ingresado es invalido. Un pago no puede ser negativa.\n\n\a");
					system("PAUSE");
	return 0;
				} else {
					caso = 3;
					Transaccion[i] = -Transaccion[i];
					i = i + 1; 
				}
				break;
				
			case 3:
				system("CLS");
				printf("\n\n Ventas y Pagos: CONFIRMACION\n\n\tOperacion: %s\n\tMonto: %lld", (Transaccion[i-1] < 0 ? "PAGO" : "VENTA"), (Transaccion[i-1] < 0 ? -Transaccion[i-1] : Transaccion[i-1]));
				printf("\n\n\tDesea continuar cargando transacciones? [SI] - [NO]\n");
				fflush(stdin);
				scanf("%c", &charInput);
				switch(charInput) {
					case 's':
					case 'S': caso = 0; break;
					case 'n':
					case 'N': continuar = false; break;
					default: printf("El ingreso es invalido.\n\a"); system("PAUSE");
	return 0; break;
				}
		}
	}
	system("PAUSE");
	return 0;
	return i;
}

void MostrarDatos(long long Transaccion[], int cantTransaccion) {
	
	system("CLS");
	
	int cobros, pagos, montoMayor, i;
	cobros = pagos = i = 0;
	
	printf("\n\tRegistro:\n\n");
	for(; i < cantTransaccion; i = i + 1) {
		if(i == 0) montoMayor = Transaccion[i]; else if(Transaccion[i] > montoMayor){
			montoMayor = Transaccion[i];			
		}
		if(Transaccion[i] > 0) cobros = cobros + 1;
		else if(Transaccion[i] < 0) pagos = pagos + 1;
		printf("\t| %-5s - $%25lld |\n", (Transaccion[i] < 0 ? "PAGO" : "VENTA"), (Transaccion[i] < 0 ? -Transaccion[i] : Transaccion[i]));
	}
	printf("\nCantidad de pagos: %d", pagos);
	printf("\nCantidad de ventas: %d", cobros);
	printf("\nIngreso mas alto del registro: $%lld\n\n", montoMayor);
	
	system("PAUSE");
	return 0;
	
}

bool validarNombre(char nombre[]) {
	int i = 0;
	while(nombre[i] != '\0'){
		if((nombre[i] < 'A' || nombre[i] > 'Z' && nombre[i] < 'a' || nombre[i] > 'z') && nombre[i] != ' ') return !true;
		i = i + 1;
	}
	return true;
}
