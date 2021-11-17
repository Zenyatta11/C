/*

En un banco se procesan datos de las cuentas corrientes de sus clientes. De cada cuenta corriente se conoce: número de cuenta y saldo actual. 
El ingreso de datos finaliza cuando el operador responde que no hay más cuentas para ingresar.

Se pide confeccionar un programa que lea los datos de las cuentas corrientes e informe:

De cada cuenta: 
número de cuenta y estado de la cuenta según su saldo, sabiendo que:
Estado de la cuenta	'Acreedor' si el saldo es >0.
			'Deudor' si el saldo es <0.
			'Nulo' si el saldo es =0.

*/


#include<stdio.h>

#define true 1

struct ST_Cuenta{
	unsigned int Numero;
	long Saldo;
};

struct ST_Cuenta CuentaBancaria[64];


void mostrarDatos(unsigned int cant, struct ST_Cuenta CuentaBancaria[]);
void tableLn();

unsigned int obtenerCuentas(struct ST_Cuenta CuentaBancaria[]);

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                                       MAIN                                           // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

int main() {
	
	unsigned int cantidadCuentas = obtenerCuentas(CuentaBancaria);
	system("PAUSE");
	mostrarDatos(cantidadCuentas, CuentaBancaria);
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                               FUNCIONES  SECUNDARIAS                                 // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////


void mostrarDatos(unsigned int cant, struct ST_Cuenta CuentaBancaria[]) {
	int min, i;
	char input;
	min = i = 0;
	
	while(true) {
		system("CLS");
		
		printf("\n\n");
		
		tableLn();
		
		printf("\t#%62s#\n", " ");
		printf("\t# <- Mostrando Cuenta Bancaria %d de %d %24s #\n", i+1, cant+1, "->");
		printf("\t#%62s#\n", " ");
		
		tableLn();
		
		printf("\t#%62s#\n", " ");
		printf("\t# Viendo: %-52u #\n", CuentaBancaria[i].Numero);
		printf("\t#%62s#\n", " ");
		printf("\t# Saldo $%53ld #\n", CuentaBancaria[i].Saldo);
		printf("\t# Estado $%52s #\n", (CuentaBancaria[i].Saldo > 0 ? "Acreedor" : (CuentaBancaria[i].Saldo < 0 ? "Deudor" : "Nulo")));
		printf("\t#%62s#\n", " ");
		
		tableLn();
		
		printf("\t# %s%56s #\n", "<---", "--->");
		
		tableLn();
		
		input = getch();
		if (input == -32) {
			switch(getch()) {
				case 77:
					if(i < cant) i = i + 1;
					break;
				case 75:
					if(i > 0) i = i - 1;
					break;
			}
		} else if(input == 27) {
			return;
		}
		fflush(stdin);
	}
	
}

void tableLn() {
	int i = 64;
	printf("\t");
	for(;i > 0; i = i - 1)
		printf("#");
	printf("\n");
}

unsigned int obtenerCuentas(struct ST_Cuenta CuentaBancaria[]) {
	unsigned int action, masCuentaBancariaes, i, sino, invalido, j;
	int input;
	unsigned int existentes[64];
	char charinput;
	masCuentaBancariaes = true;
	action = i = 0;
	sino = 1;
	
	do {
		switch(action) {
			case 0:
				invalido = 0;
				printf("\nCuentas Bancarias\n\n\tIngrese el numero de la cuenta: ");
				scanf("%u", &CuentaBancaria[i].Numero);
				
				for(j = 0; j < i; j = j + 1) 
					if(existentes[j] == CuentaBancaria[i].Numero)
						invalido = true;
				if(invalido) {
					printf("\tEl numero ingresado ya existe.\n\n");
					getch();
					system("CLS");
				} else {
					action = 1;
					existentes[j] = CuentaBancaria[i].Numero;
				}
				break;
				
			case 1:
				printf("Ingrese el saldo de la cuenta %u: ", CuentaBancaria[i].Numero);
				scanf("%ld", &CuentaBancaria[i].Saldo);
				action = 2;
				break;
				
			case 2:
				system("CLS");
				printf("Cuenta Nro: %u\n", CuentaBancaria[i].Numero);
				printf("\tSaldo: $%ld\n", CuentaBancaria[i].Saldo);
				printf("%s | %s\n", (sino ? "[SI]" : " SI "), (!sino ? "[NO]" : " NO "));
				charinput = getch();
				if (charinput == -32) {
					switch(getch()) {
						case 77:
							if(sino == 1) sino = 0;
							break;
						case 75:
							if(sino == 0) sino = 1;
							break;
					}
				} else if(charinput == '\r') {
					if(sino == 1){
						action = 0;
						i = i + 1;
						system("CLS");
						fflush(stdin);
						break;
					} else {
						masCuentaBancariaes = !true;
						break;
					}
				}
				break;
		}
		
	} while(masCuentaBancariaes);
	return i;
}



