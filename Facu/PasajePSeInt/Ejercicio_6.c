// Adivinar un número en 10 intentos. El número es generado al azar y es entre 0 y 100, para ello utilizar la función azar(100).
// Despuès de cada intento, indicarle al usuario si el nro. a adivinar es mayor o menor al ingresado. 
// Validar que el nro. ingresado en cada intento sea entre 0 y 100.

// (rand() % (upper – lower + 1)) + lower

#include <math.h>
#include <stdio.h>

int main() {
	
	srand (time(NULL));
	int Input;
	int Rand = rand() % 100;
	int MaxTries = 10;
	int Try = 0;
	
	printf("Adivinanza de un numero entre 0 y 100.\n%d\n\n", Rand);
	
	while(Try < MaxTries+1){
		if(Try != MaxTries) {
			printf("Ingrese el numero que cree que es: ");
			
			scanf("%d",&Input);
			
			if(Input == Rand) {
				printf("Adivinaste!\n\n");
				break;
			} else {
				if(MaxTries-Try-1 != 0)
					printf("Nop! Intente nuevamente!\nLe quedan %d intentos.\n\n",MaxTries-Try-1);
			}
		} else {
			printf("Se le agotaron los intentos.\nEl numero era %d\n\n",Rand);
		}
		Try = Try + 1;
	}
	system("PAUSE");
	return 0;
}
