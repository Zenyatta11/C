/* 
	Patentes (str) y monto de multa (double)

	Primero se carga, luego se busca

	Maximo 100 multas, puede haber mas de una multa por patente
*/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

#define STR_MAX 10

void formatearPatente(char* patente);
bool patenteValida(char* patente);
void cargarPatente();
bool checkIfValido(double multa);
void consultarPatente();

int main() {
	bool continuar = true;
	char charInput;
	
	do{
		cargarPatente();
		printf("\n\tDesea continuar cargando patentes?\n\tS/N");
		do{
			fflush(stdin);
			scanf("%c", &charInput);
		} while(charInput != 'S' && charInput != 'N' && charInput != 's' && charInput != 'n');
		if(charInput == 'N' || charInput == 'n') continuar = false;
	} while(continuar);
	
	printf("\n\n");
	continuar = true;
	
	do{
		consultarPatente();
		printf("\n\tDesea continuar consultando patentes?\n\tS/N");
		do{
			fflush(stdin);
			scanf("%c", &charInput);
		} while(charInput != 'S' && charInput != 'N' && charInput != 's' && charInput != 'n');
		if(charInput == 'N' || charInput == 'n') continuar = false;
	} while(continuar);
	
	system("PAUSE");
	return 0;
	
}

void cargarPatente() {
	char patente[STR_MAX], charInput, fileName[STR_MAX + 4];
	double multa;
	bool esValida, sobreescribir, seguirCargandoMultas, numValido;
	
	do{
		printf("\n\tCarga de patentes\n\n\tIngrese una patente para cargar: ");
		gets(patente);
		formatearPatente(patente);
		esValida = patenteValida(patente);
		if(!esValida) {
			printf("\n\tLa patente es invalida!\a\n");
		}
	} while(!esValida);
	
	strcat(fileName, patente);
	strcat(fileName, ".txt");
	
	FILE *file = fopen(fileName, "r");
	sobreescribir = true;
	if(file != NULL) {
		fclose(file);
		printf("\n\tLa patente ya existe. Desea sobreescribirla?\n\tS/N");
		do{
			fflush(stdin);
			scanf("%c", &charInput);
		} while(charInput != 'S' && charInput != 'N' && charInput != 's' && charInput != 'n');
		if(charInput == 'N' || charInput == 'n') sobreescribir = false;
	}
	if(sobreescribir) {
		seguirCargandoMultas = true;
		numValido = true;
		
		file = fopen(fileName, "w");
		printf("\n\tPatente [%s]", patente);
		do{
			do{
				printf("\n\tIngrese el monto de la multa: ");
				fflush(stdin);
				scanf("%lf", &multa);
				numValido = checkIfValido(multa);
				if(!numValido) printf("\n\tEl monto ingresado es invalido!\a\n");
			}while(!numValido);
			fprintf(file,"%lf\n",multa);
			printf("\n\tDesea seguir cargando multas?\n\tS/N");
			do{
				fflush(stdin);
				scanf("%c", &charInput);
			} while(charInput != 'S' && charInput != 'N' && charInput != 's' && charInput != 'n');
			if(charInput == 'N' || charInput == 'n') seguirCargandoMultas = false;
		}while(seguirCargandoMultas);
		fclose(file);
	}
}

bool checkIfValido(double multa) {
	if(multa > 0) return true;
	else return false;
}

void formatearPatente(char* patente) { // removemos los espacios si los tiene
	int i, length, i2;
	char patente2[STR_MAX];
	char charInput;
	length = strlen(patente);
	i2 = 0;
	for(i = 0; i < length; i = i + 1) {
		if(patente[i] != ' ') {
			patente2[i2] = toupper(patente[i]);
			i2 = i2 + 1;
		}
	}
	patente2[i2] = 0;
	strcpy(patente, patente2);
}

bool patenteValida(char* patente) {
	int i, length;
	length = strlen(patente);
	for(i = 0; i < length; i = i + 1) {
		if(patente[i] < '0' || patente[i] > '9' && patente[i] < 'A' || patente[i] > 'Z') return false;
	}
	return true;
}

void consultarPatente() {
	char patente[STR_MAX], fileName[STR_MAX+4];
	double multa;
	bool esValida;
	do{
		printf("\n\tConsulta de patentes\n\n\tIngrese la patente para consultar sus multas: ");
		fflush(stdin);
		gets(patente);
		formatearPatente(patente);
		esValida = patenteValida(patente);
		if(!esValida) {
			printf("\n\tLa patente es invalida!\a\n");
		}
	} while(!esValida);
	
	strcat(fileName, patente);
	strcat(fileName, ".txt");
	FILE *file = fopen(fileName, "r");
	
	if(file == NULL) {
		fclose(file);
		printf("\n\tLa patente no existe.");
	} else {
		printf("\tMultas de [%s]:\n", patente);
		while(fscanf(file, "%lf", &multa) == 1) {
			printf("\n\tInfraccion $%.2lf", multa);
		}
		printf("\n\tFIN\n\n");
		fclose(file);
	}
}