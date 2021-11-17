/*

Elaborar una función que reciba un valor entero y nos muestre desde el 1 hasta dicho valor. Si la función recibe un valor negativo mostrar un mensaje de error

*/


#include<stdio.h>

void GetNumeros(int input);
int GetNumero();

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                                    MAIN  LIMPIO                                      // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

int main() {
	
	printf("1 hasta N\n\n");
	GetNumeros(GetNumero());
	printf("\n\n");
	system("PAUSE");
	return 0;
	
}

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                               FUNCIONES  SECUNDARIAS                                 // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

int GetNumero() {
	int input;
	do{
		printf("Ingrese un numero entero positivo: ");
		scanf("%d", &input);
		if(input <= 0)
			printf("El numero no puede ser %s.\n\n", (input < 0 ? "negativo" : "cero"));
	}while(input <= 0);
	return input;
}

void GetNumeros(int input) {
	int i;
	for(i = 0; i < input; i = i + 1) {
		printf("%d%s", i + 1, (i + 1 == input ? ";" : ", "));
	}
}
