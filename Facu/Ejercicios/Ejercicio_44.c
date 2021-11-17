/*

Confeccionar un programa que defina dos funciones, una que permita cargar un vector de 5 elementos enteros y otra que muestre un vector de 5 elementos enteros.
En la función main definir una variable de tipo vector y seguidamente llamar a las dos funciones.

*/


#include<stdio.h>

#define vector int
#define MAX 5

void ShowData(vector Array[MAX]);
void GetData(vector Array[MAX]);

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                                       MAIN                                           // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

int main() {
	
	vector Array[MAX];
	GetData(Array);
	printf("\n\n");
	ShowData(Array);
	printf("\n\n");
	system("PAUSE");
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                               FUNCIONES  SECUNDARIAS                                 // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

void GetData(vector Array[MAX]) {
	int i;
	for(i = 0; i < MAX; i = i + 1) {
		printf("Ingrese %s numero: ", (i == 0 ? "un" : "otro"));
		scanf("%d", &Array[i]);
		if(i+1 != MAX) printf("Restan %d.\n\n", MAX-i-1);
	}
}

void ShowData(vector Array[MAX]) {
	int i;
	printf("\t[");
	for(i = 0; i < MAX; i = i + 1) {
		printf("%d%s", Array[i], (i+1 == MAX ? "]\n" : ", "));
	}
}