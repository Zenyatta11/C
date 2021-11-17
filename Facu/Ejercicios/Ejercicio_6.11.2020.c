
/* segundo parcial tn2 ej1
triángulos */


#include <stdio.h>
#include <stdlib.h>
#define CANT 3
#define CANTANG 3

void mostrarTri(int* pointer);
void cargarTri(int* pointer);

int sumarAngulos(ang1, ang2, ang3) {
	if(ang1 + ang2 + ang3 == 180) return 1; else return 0;
}

int main(){
	int *conj = (int*) malloc(CANTANG * CANT * sizeof(int)) ;
	if (conj == NULL) printf("Error no se pudo reservar");
	else {
		
		//cargar datos: datos de los triángulos, datos enteros
		cargarTri(conj);
		
		
		//mostrar los triángulos que se pudieron dibujar
		mostrarTri(conj);	
		
		free(conj);
		system("PAUSE");
	}
	
	return 0;
}

void cargarTri(int* pointer) {
	int i = 0;
	char charinput;
	
	for(i = 0; i < CANTANG * CANT; ) {
		if(i % 3 == 0) printf("\n");
		
		printf("Ingrese el %s angulo del triangulo N. %d: ", (i % 3 == 0 ? "primer" : (i % 3 == 1 ? "segundo" : "tercer")), i / 3 + 1);
		fflush(stdin);
		scanf("%d%c", pointer, &charinput);
		
		if(*pointer > 0 && *pointer < 180 && charinput == '\n') {
			i = i + 1;
			pointer = pointer + 1;
		} else printf("El numero ingresado es invalido.\n\n");
	}
	return;
}

void mostrarTri(int* pointer) {
	int i, cant = 0;
	printf("\nTriangulos\n\n");
	for(i = 0; i < CANT; i = i + 1) {
		if(sumarAngulos(*pointer, *(pointer+1), *(pointer+2))) {
			cant = cant + 1;
			printf("Se puede dibujar el triangulo N. %d!\nAngulos: %d, %d, %d;\n\n", i+1, *pointer, *(pointer+1), *(pointer+2));
		}			
		else printf("El triangulo N. %d no se puede dibujar.\n\n", i+1);
		pointer = pointer + 3;
	}
	printf("\n\nSe pudieron hacer %d triangulos.\n\n", cant);
	return;
}

