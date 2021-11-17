/*

Cargar por teclado dos nombres de personas que tengan distinta cantidad de caracteres. 
Almacenar en un tercer vector de caracteres el nombre que tenga más caracteres. 
Luego imprimir dicho vector.

*/

//////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#define true 1
#define false 0
#define BUFFER_SIZE 64
#define bool unsigned int

//////////////////////////////////////////////////////////////////////////////////////////

bool ValidateNombre(unsigned char* string);

void SetString(unsigned char* stringTarget, unsigned char* stringTemplate);
void GetNombre(unsigned char* string, int unOtro);

unsigned int GetLength(unsigned char* string);

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                                    MAIN  LIMPIO                                      // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

int main() {
	unsigned char Nombre_A[BUFFER_SIZE];
	unsigned char Nombre_B[BUFFER_SIZE];
	unsigned char Nombre_C[BUFFER_SIZE];
	
	printf("Nombre mas largo.\n\n");
	GetNombre(Nombre_A, 0);
	GetNombre(Nombre_B, 1); 
	
	if(GetLength(Nombre_A) > GetLength(Nombre_B))
		SetString(Nombre_C, Nombre_A); //podia usar memcpy pero mantengamonos con cosas mas simples para el humano (simple para el humano es mas complejo para la maquina)
	else //tambien podia cambiar punteros y no haria ni falta copiar memorias
		SetString(Nombre_C, Nombre_B);
	
	printf("\n\nEl nombre mas largo es %s.\n\n", Nombre_C);
	system("PAUSE");
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                               FUNCIONES  SECUNDARIAS                                 // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

void GetNombre(unsigned char* string, int unOtro) {
	unsigned char buffer[BUFFER_SIZE];
	do {
		printf("Ingrese %s nombre: ", (unOtro == 0 ? "un" : "otro"));
		gets(buffer);
	} while(!ValidateNombre(buffer));
	SetString(string, buffer);
}

bool ValidateNombre(unsigned char* string) {
	int i;
	for(i = 0; i < BUFFER_SIZE; i = i + 1) {
		if((string[i] < 65 || string[i] > 90) && (string[i] < 97 || string[i] > 122) && string[i] != 0 && string[i] != 32) { //hay que permitir espacios para nombres italianos
			printf("El nombre es invalido.\n\n");
			return false;
		} else if(string[i] == 0) break;
	}
	return true;
}

void SetString(unsigned char* stringTarget, unsigned char* stringTemplate) {
	int i;
	for(i = 0; i < BUFFER_SIZE; i = i + 1) {
		stringTarget[i] = stringTemplate[i];
		if(stringTemplate[i] == 0) break;
	}
}

unsigned int GetLength(unsigned char* string) {
	int i;
	for(i = 0; i < BUFFER_SIZE; i = i + 1) {
		if(string[i] == 0) break;
	}
	return i+1;
}
