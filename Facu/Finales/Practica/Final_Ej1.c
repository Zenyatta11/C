/*

	Ejercicio 1 - MEMORIA DINÁMICA y/o PUNTEROS (60 puntos)

	Una empresa importa y comercializa máquinas expendedoras automáticas de bebidas ofreciendo también el servicio de reposición de los productos.
	Para la reposición cuenta con TRES (3) vendedores dedicados a recoger pedidos, armar el envío y aprovisionar las máquinas.

	Cada vez que uno de ellos necesita reponer el stock de una máquina emite un formulario especificando:

	- número de pedido
	- número de vendedor
	- número de producto
	- cantidad de unidades

	Los productos con sus costos son:

	1. lata de gaseosa cola $60.00
	2. botella de agua $50.00
	3. leche chocolatada $40.50
	4. jugo de naranja $75.00

	Se carga toda la información y luego al finalizar la semana se informa:

	- la CANTIDAD DE UNIDADES PEDIDAS POR PRODUCTO (40 puntos)

	Validar lo necesario
	Utilizar funciones y lenguaje C standard
	Utilizar memoria dinámica y/o punteros

*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#define MAX 4

char* getProductoName(int producto);
void informarProductos(int* productos);
void realizarFormulario(int* productos);

int main() {
	
	int *productos = (int*)calloc(MAX,sizeof(int));
	
	bool seguirRealizandoPedidos = true;
	char charInput;
	
	printf("\n\tReposicion de Maquinas Vendedoras\n\tFinal Noviembre 2020 - Ejercicio 1");
	
	do{
		realizarFormulario(productos);
		printf("\n\tDesea continuar rellenando formularios de pedidos?\n\tS/N - ");
		
		do{
			fflush(stdin);
			scanf("%c", &charInput);
		} while(charInput != 'S' && charInput != 'N' && charInput != 's' && charInput != 'n');
		
		if(charInput == 'N' || charInput == 'n') seguirRealizandoPedidos = false;
	} while(seguirRealizandoPedidos);
	
	informarProductos(productos);
	free(productos);
	
	system("PAUSE");
	return 0;
}

void realizarFormulario(int* productos) {
	
	char charInput;
	int vendedor, producto, cantidad;
	bool seguirCargandoPedidos = true;
	srand(time(NULL));
	int pedido = rand() % 32000;
	
	do{
		printf("\n\tFormulario de Pedidos\n\n\tIngrese su numero de vendedor: ");
		fflush(stdin);
		scanf("%d%c", &vendedor, &charInput);
		if(charInput != '\n' || vendedor < 1 || vendedor > 3) {
			printf("\n\tEl numero de vendedor es invalido!\a\n");
		}
	} while(charInput != '\n' || vendedor < 1 || vendedor > 3);
	
	printf("\n\tPedido [%d] del vendedor Nro. %d", pedido, vendedor);
	do{
		do{
			printf("\n\tIngrese el ID del producto: ");
			fflush(stdin);
			scanf("%d%c", &producto, &charInput);
			if(producto < 1 || producto > 4 || charInput != '\n') printf("\n\tEl numero de producto es invalido!\a\n\n\t1 - Lata de Coca Cola\n\t2 - Botella de Agua\n\t3 - Leche Chocolatada\n\t4 - Jugo de Naranja\n");
		}while(producto < 1 || producto > 4 || charInput != '\n');
		
		do{
			printf("\n\tIngrese la cantidad de unidades: ");
			fflush(stdin);
			scanf("%d%c", &cantidad, &charInput);
			if(cantidad <= 0 || charInput != '\n') printf("\n\tLa cantidad de unidades a pedir es invalida!\a\n");
		} while(cantidad <= 0 || charInput != '\n');
		
		*(productos + producto-1) = *(productos + producto-1) + cantidad;
		printf("\n\tDesea continuar pidiendo productos?\n\tS/N - ");
		
		do{
			fflush(stdin);
			scanf("%c", &charInput);
		} while(charInput != 'S' && charInput != 'N' && charInput != 's' && charInput != 'n');
		
		if(charInput == 'N' || charInput == 'n') seguirCargandoPedidos = false;
	}while(seguirCargandoPedidos);
}

void informarProductos(int* productos) {
	printf("\n\tProductos Pedidos:\n");
	int i;
	
	for(i = 0; i < MAX; i = i + 1)
		printf("\n\t%-18s - %d unidades", getProductoName(i+1), *(productos+i));
	printf("\n\n\t");
}

char* getProductoName(int producto) {
	switch(producto) {
		case 1: return "Lata de Coca Cola";
		case 2: return "Botella de Agua";
		case 3: return "Leche Chocolatada";
		case 4: return "Jugo de Naranja";
	}
}
