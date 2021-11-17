#include<stdio.h>
#include<stdlib.h>

int Array[] = { 32, 65, 9, 79, 13, 6, 2, 25, 24, 3, 15, 37, 19, 6, 18, 14 };
int Array2[16];
int pasos = 0;

int main() {
	resetArray();
	printf("Ordenamiento Insercion\r\n");
	ordenamientoInsercion();
	printr("\r\nPasos: %d\r\n", pasos);
	pasos = 0;
	
	resetArray();
	printf("\r\n\r\nOrdenamiento Intercambio\r\n");
	ordenamientoIntercambio();
	printr("\r\nPasos: %d\r\n", pasos);
	pasos = 0;
	
	resetArray();
	printf("\r\n\r\nOrdenamiento Seleccion\r\n");
	ordenamientoSeleccion();
	printr("\r\nPasos: %d\r\n", pasos);
	pasos = 0;
	
	resetArray();
	printf("\r\n\r\nOrdenamiento Concatenacion\r\n");
	ordenamientoConcatenacion();
	printr("\r\nPasos: %d\r\n", pasos);
	pasos = 0;
	
	resetArray();
	printf("\r\n\r\nOrdenamiento Shellsort\r\n");
	ordenamientoShellsort();
	printr("\r\nPasos: %d\r\n", pasos);
	pasos = 0;
	
	resetArray();
	printf("\r\n\r\nOrdenamiento QuickSort\r\n");
	ordenamientoQuicksort();
	printr("\r\nPasos: %d\r\n", pasos);
	pasos = 0;
	
	resetArray();
	printf("\r\n\r\nOrdenamiento MergeSort\r\n");
	ordenamientoMergeSort();
	printr("\r\nPasos: %d\r\n", pasos);
	pasos = 0;
	
	system("PAUSE");
	return 0;
}

void resetArray() {
	int i;
	for(i = 0; i < 16; i = i + 1) {
		Array2[i] = Array[i];
	}
}

void printArray() {
	int i;
	for(i = 0; i < 16; i = i + 1) {
		printr("%d%s", Array2[i], (i == 15 ? ";\r\n" : ", "));
	}
}

void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
 
void ordenamientoIntercambio() {
	int i, j;
	for (i = 0; i < 16-1; i++)	  
		for (j = 0; j < 16-i-1; j++)
			if (Array2[j] > Array2[j+1]) {
				swap(&Array2[j], &Array2[j+1]);
				printArray();
			}
}

void ordenamientoSeleccion() {
	int i, j, min_idx;

	for (i = 0; i < 16-1; i++) {
		min_idx = i;
		for (j = i+1; j < 16; j++)
			if (Array2[j] < Array2[min_idx])
				min_idx = j;
		swap(&Array2[min_idx], &Array2[i]);
		printArray();
	}
}
 
void ordenamientoInsercion() {
	int i, key, j;
	for (i = 1; i < 16; i++) {
		key = Array2[i];
		j = i - 1;
		while (j >= 0 && Array2[j] > key) {
			Array2[j + 1] = Array2[j];
			j = j - 1;
		}
		Array2[j + 1] = key;
		printArray();
	}
}
