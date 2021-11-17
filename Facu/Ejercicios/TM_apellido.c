/*

Cargar por teclado en dos variables de tipo string el nombre y el apellido de una persona. 
Definir un tercer string y guardar la concatenación del nombre y apellido.

*/


#include<stdio.h>

/////////////////////////////////////////////////////////////////////////////////////////

#define true 1
#define false 0

#define BUFFER_SIZE 64

/////////////////////////////////////////////////////////////////////////////////////////

void ConcatenateString(unsigned char* Return, unsigned char* First, unsigned char* Second);
void GetString(unsigned char* Print, unsigned char* String);
void SetString(unsigned char* stringTarget, unsigned char* stringTemplate);

int ValidateNombre(unsigned char* String);

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                                    MAIN  LIMPIO                                      // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

int main() {
	
	unsigned char Nombre[BUFFER_SIZE], Apellido[BUFFER_SIZE], NomCompleto[BUFFER_SIZE*2];
	
	printf("Concatenacion de strings.\n\n");
	
	GetString("Ingrese su nombre: ", Nombre);
	GetString("Ingrese su apellido: ", Apellido);
	
	ConcatenateString(NomCompleto, Nombre, Apellido);
	printf("\n\nSu nombre completo es %s!\n\n", NomCompleto);
	
	system("PAUSE");
	return 0;
	
}

//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                               FUNCIONES  SECUNDARIAS                                 // 
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

void ConcatenateString(unsigned char* Return, unsigned char* First, unsigned char* Second){
	int FirstSecond, i;
	FirstSecond = i = 0;
	while(1) {
		if(FirstSecond == 0) {
			Return[i] = First[i];
			if(First[i] == 0) {
				Return[i] = 32;
				FirstSecond = i;
				i = 0; 
			}
		} else {
			Return[FirstSecond+i] = Second[i-1]; //Si i == 0, se come la primera letra del segundo string
			if(Second[i] == 0) {
				break;
			}
		}
		i = i + 1;
	}
}

void GetString(unsigned char* Print, unsigned char* String) {
	unsigned char buffer[BUFFER_SIZE];
	do {
		printf("%s", Print);
		gets(buffer);
	} while(!ValidateNombre(buffer));
	SetString(String, buffer);
}

void SetString(unsigned char* stringTarget, unsigned char* stringTemplate) {
	int i;
	for(i = 0; i < BUFFER_SIZE; i = i + 1) {
		stringTarget[i] = stringTemplate[i];
		if(stringTemplate[i] == 0) break;
	}
}

int ValidateNombre(unsigned char* String) {
	int i;
	for(i = 0; i < BUFFER_SIZE; i = i + 1) {
		if((String[i] < 65 || String[i] > 90) && (String[i] < 97 || String[i] > 122) &&  //Algunos apellidos y nombres tienen espacios
		String[i] != 0 && String[i] != 32 && (String[i] < 127 || String[i] > 154)  && //Algunos tildes y eñes
		(String[i] < 160 || String[i] > 165)) { 
			printf("El ingreso es invalido.\n\n"); 
			return false;
		} else if(String[i] == 0) break;
	}
	return true;
}
