/*

Cargar los nombres de dos personas y sus edades. 
Mostrar el nombre de la persona que tiene mayor edad. 
Los nombres de las personas no superan los 20 caracteres.


*/


#include<stdio.h>

int main() {
	
	char *Nombres[42];
	int Edades[2];
	int action = 0;
	
	printf("Mayor edad.\n\n");
	
	do{
		switch(action) {
			case 0:
			case 21:
				printf("Ingrese el nombre de %s persona: ", (action == 0 ? "una" : "otra"));
				scanf("%20s", Nombres);
				Nombres[action+21] = '\0';
				action = action + 1;
				break;
				
			case 1:
			case 22:
				printf("Ingrese la edad de %s: ", Nombres[action-1]);
				scanf("%d", &Edades[action-21]);
				if(Edades[action-21] <= 0) {
					printf("La edad es invalida.\n\n");
				} else {
					action = action + 19;
					break;
				}
		}
		
	} while(action != 41);
	
	printf("%s, %d\n", Nombres[0], Edades[0]);
	printf("%s, %d\n\n", Nombres[21], Edades[1]);
	system("PAUSE");
	return 0;
	
}


