/*

	Se ingresa nombre, sexo, y edad de las personas y se graba toda la informacion en un archivo.
	Una vez finalizada la carga, el usuario dira sexo y rango de edad.
	Con esta pregunta se mostraran los nombres que cumplen esa condicion y la cantidad encontrada.

*/

//	+------------------------------------------------------------------------------------------------+
//	| Project				:	Programacion I                                                       |
//	| Author				:	Zenyatta11                                                           |
//	| Description			:	Ejercicio I - Turno Noche                                            |
//	+------------------------------------------------------------------------------------------------+
//	| Table of Contents                                                                              |
//	| 1. Preparacion/Definiciones                                                                    |
//	| 2. Main                                                                                        |
//	| 3. Funciones Secundarias - Consultas                                                           |
//	| 4. Funciones Secundarias - Cargas                                                              |
//	| 5. Funciones Secundarias - Secundarias de las Secundarias                                      |
//	+------------------------------------------------------------------------------------------------+

//	+------------------------------------------------------------------------------------------------+
//	| Section 1 : Preparacion/Definiciones                                                           |
//	+------------------------------------------------------------------------------------------------+

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define STRING_MAX 64

char fileName[STRING_MAX] = "ejercicio_67.txt\0"; // Mantengamos esto global por las dudas

int obtenerNumero(bool allowZero, bool positive);
bool validarNombre(char nombre[]);
double obtenerDouble(bool allowZero, bool positive);

void consultarDatos();
void consultarEdad();
void consultarNombre();
void consultarSexo();

void menuOpciones();
void nombreArchivo();

void obtenerDatos();
void previewDatos(char* stringNombre, char* sexo, int edad);

//	+------------------------------------------------------------------------------------------------+
//	| Section 2 : Main                                                                               |
//	+------------------------------------------------------------------------------------------------+


int main() {
	
	menuOpciones(); //podria ponerlo aca pero el nombre de la funcion indica que hace
	return 0;
}

void menuOpciones() {
	bool seguir = true;
	char charinput;
	int opcion = 0;
	int action = 0;
	
	while(seguir) {
		system("CLS");
		switch(action) {
			case 0:
				printf("\n\tBase de Datos de Personas");
				printf("\n\n\tQue accion desea realizar?\n\t%s - %s - %s\n\t<----------- ------ ----------->", (opcion == 0 ? "[CARGAR]" : " CARGAR "), (opcion == 1 ? "[CONSULTAR]" : " CONSULTAR "), (opcion == 2 ? "[SALIR]" : " SALIR "));
				
				fflush(stdin);
				charinput = getch();
				
				if (charinput == -32) {
					switch(getch()) {
						case 77:
							if(opcion < 2) opcion = opcion + 1;
							else printf("\a");
							break;
						case 75:
							if(opcion > 0) opcion = opcion - 1;
							else printf("\a");
							break;
					}
				} else if(charinput == '\r'){
					switch(opcion) {
						case 0: obtenerDatos(); break;
						case 1: consultarDatos(); break;
						default: seguir = false; break;
					}
				}
				break;
		}
	}
}

void consultarDatos() {
	int action = 0;
	bool seguir = true;
	char charinput;
	int opcion = 0;
	
	nombreArchivo();
	
	while(seguir) {
		system("CLS");
		switch(action) {
			case 0:
				printf("\n\tBase de Datos de Personas - Consultas\n\n\tUtilizando el archivo [%s]", fileName);
				printf("\n\n\tQue consulta desea realizar?\n\n\t%s - %s - %s - %s\n\t<--------- -------------- --------->", (opcion == 0 ? "[NOMBRE]" : " NOMBRE "), (opcion == 1 ? "[SEXO]" : " SEXO "), (opcion == 2 ? "[EDAD]" : " EDAD "), (opcion == 3 ? "[SALIR]" : " SALIR "));
				
				fflush(stdin);
				charinput = getch();
				
				if (charinput == -32) {
					switch(getch()) {
						case 77:
							if(opcion < 3) opcion = opcion + 1;
							else printf("\a");
							break;
						case 75:
							if(opcion > 0) opcion = opcion - 1;
							else printf("\a");
							break;
					}
				} else if(charinput == '\r'){
					switch(opcion) {
						case 0: consultarNombre(); break;
						case 1: consultarSexo(); break;
						case 2: consultarEdad(); break;
						case 3: 
						default: seguir = false; break;
					}
				}
				break;
		}
	}
}

//	+------------------------------------------------------------------------------------------------+
//	| Section 3 : Funciones Secundarias - Consultas                                                  |
//	+------------------------------------------------------------------------------------------------+


void consultarNombre() {
	char stringNombre[STRING_MAX];
	char nameToFind[STRING_MAX];
	char stringSexo[STRING_MAX];
	int edad, found;
	
	system("CLS");
	
	do{
		printf("\n\tBase de Datos de Personas - Consultas por Nombre");
		
		printf("\n\t\tIngrese el nombre de la persona: ");
		fflush(stdin);
		gets(nameToFind);
		if(!validarNombre(nameToFind)){
			printf("\n\tEl nombre ingresado es invalido.\a\n\t");
		}
	}while(!validarNombre(nameToFind));
	
	printf("\n\tBuscando [NOMBRE: %s]\n", nameToFind);
	
	found = 0;
	FILE* file = fopen(fileName, "r");
	if(file == NULL) {
		printf("\n\tNo se pudo abrir el archivo %s para lectura!\a\n\t", fileName);
		system("PAUSE");
	return 0;
	} else {
	
	while(fscanf(file, "%[^\t] %[^\t] %d\n", stringNombre, stringSexo, &edad) == 3){
		if(stricmp(stringNombre, nameToFind) == 0) {
			found = 1;
			printf("\n\t%-24s - %-8s - %d", stringNombre, stringSexo, edad);
		}
	}
	if(!found) printf("\n\tNo se encontraron entradas con esa consulta!\a");
	fclose(file);
	}
	
	printf("\n\n\t");
	system("PAUSE");
	return 0;
}

void consultarSexo() {
	bool validado = false;
	char stringNombre[STRING_MAX];
	char stringSexo[STRING_MAX];
	char charInput;
	char sexoToFind[STRING_MAX];
	int edad, found;
	
	system("CLS");
	
	do{
		printf("\n\tBase de Datos de Personas - Consultas por Sexo");
		
		printf("\n\tIngrese el sexo de la persona: ");
		fflush(stdin);
		scanf("%c", &charInput);
		switch(charInput) {
			case 'f':
			case 'F': strcpy(sexoToFind, "Femenino"); validado = true; break;
			case 'm':
			case 'M': strcpy(sexoToFind, "Masculino"); validado = true; break;
			default: printf("\n\tEl nombre ingresado es invalido.\a\n\t"); break;
		}
	}while(!validado);
	
	FILE* file = fopen(fileName, "r");
	printf("\n\tBuscando [SEXO: %s]\n", sexoToFind);
	if(file == NULL) {
		printf("\n\tNo se pudo abrir el archivo %s para lectura!\a\n\t", fileName);
		system("PAUSE");
	return 0;
	} else {
		found = 0;
		while(fscanf(file, "%[^\t] %[^\t] %d\n", stringNombre, stringSexo, &edad) == 3){
			if(stricmp(stringSexo, sexoToFind) == 0) {
				found = 1;
				printf("\n\t%-24s - %-8s - %d", stringNombre, stringSexo, edad);
			}
		}
		if(!found) printf("\n\tNo se encontraron entradas con esa consulta!\a");
		fclose(file);
	}
	
	printf("\n\n\t");
	system("PAUSE");
	return 0;
}

void consultarEdad() {
	bool validado = false;
	char stringNombre[STRING_MAX];
	char stringSexo[STRING_MAX];
	int edad, found, edadMin, edadMax;
	
	system("CLS");
	
	printf("\n\tBase de Datos de Personas - Consultas por Edad");
	
	printf("\n\tIngrese la edad minima de la persona: ");
	fflush(stdin);
	
	edadMin = obtenerNumero(false, true);
	
	printf("\n\tIngrese la edad maxima de la persona: ");
	fflush(stdin);
	edadMax = obtenerNumero(false, true);
	
	if(edadMin > edadMax) {
		printf("\n\tNOTA: Se invirtieron los numeros ya que el menor es mayor al mayor.\a\n\t");
		system("PAUSE");
	return 0;
		int temp = edadMin;
		edadMin = edadMax;
		edadMax = temp;
	}
	
	printf("\n\tBuscando [EDAD] con el rango de %d - %d\n", edadMin, edadMax);
	
	FILE* file = fopen(fileName, "r");
	
	if(file == NULL) {
		printf("\n\tNo se pudo abrir el archivo %s para lectura!\a\n\t", fileName);
		system("PAUSE");
	return 0;
	} else {
		found = 0;
		while(fscanf(file, "%[^\t] %[^\t] %d\n", stringNombre, stringSexo, &edad) == 3){
			if(edad >= edadMin && edad <= edadMax) {
				found = 1;
				printf("\n\t%-24s - %-8s - %d", stringNombre, stringSexo, edad);
			}
		}
		if(!found) printf("\n\tNo se encontraron entradas con esa consulta!\a");
		fclose(file);
	}
	printf("\n\n\t");
	system("PAUSE");
	return 0;
}

//	+------------------------------------------------------------------------------------------------+
//	| Section 3 : Funciones Secundarias - Cargas                                                     |
//	+------------------------------------------------------------------------------------------------+

void obtenerDatos() {
	bool seguir = true;
	char charinput;
	bool sino = true;
	int action = 0;
	
	char stringNombre[STRING_MAX];
	char sexo;
	int edad;
	
	nombreArchivo();
	
	while(seguir) {
		system("CLS");
		printf("\n\tEscribiendo en [%s]\n\n", fileName);
		fflush(stdin);
		switch(action) { 						
			case 0: // Nombre
				printf("\t\tIngrese el nombre de la persona: ");
				gets(stringNombre);
				if(validarNombre(stringNombre)) action = 1;
				else {
					printf("\n\tEl nombre ingresado es invalido.\a\n\t");
					system("PAUSE");
	return 0;
				}
				break;
			
			case 1: // Sexo
				printf("\t\tIngrese el sexo de %s: ", stringNombre);
				scanf("%c", &sexo);
				switch(sexo) {
					case 'f':
					case 'F': action = 2; break;
					case 'M':
					case 'm': action = 2; break;
					default:
						printf("\n\tEl genero ingresado es invalido.\a\n\tIngrese Femenino o Masculino\n\t");
						system("PAUSE");
	return 0;
						break;
				}
				break;
			
			case 2: // Edad de la persona
				printf("\t\tIngrese la edad de %s: ", stringNombre);
				edad = obtenerNumero(false, true);
				action = 3;
				break;
			
			case 3: // Buena practica de no escribir, manteniendo el handle del archivo ocupado al divino boton
					// (ademas de que, como estoy usando append, ir para atras para corregir errores no es tan sencillo)
				printf("\tConfirmacion:\n\t\tEsta a punto de escribir los siguientes datos:\n");
				previewDatos(stringNombre, (sexo == 'f' || sexo == 'F' ? "Femenino" : "Masculino"), edad);
				printf("\n\n\tEs correcta esta informacion?\n\n\t%s - %s\n\t<--- - --->", (sino ? "[SI]" : " SI "), (sino ? " NO " : "[NO]"));
				
				fflush(stdin);
				charinput = getch();
				
				if (charinput == -32) {
					switch(getch()) {
						case 77:
							if(sino == true) sino = !true;
							break;
						case 75:
							if(sino == !true) sino = true;
							break;
					}
				} else if(charinput == '\r'){
					if(sino) action = 4;
					else action = 0;
				}
				break;
			
			case 4:
				printf("\t\tEscribiendo los datos...\n");
				FILE *file = fopen(fileName, "a");
				
				if(file == NULL) { // no se pudo pero tampoco tengo un codigo de error para saber por que no. gracias C
					action = 5;
					break;
				}
				
				fprintf(file, "%s\t%s\t%d\n", stringNombre, (sexo == 'f' || sexo == 'F' ? "Femenino" : "Masculino"), edad);
				
				fclose(file);
				
				action = 6; //tuve que sacar la pregunta de aca porque cada vez que cambiabas
							// de opcion volvia a escribir. oopsie
				break;
				
			case 5:
				printf("\tNo se pudo escribir los datos! ");
				printf("\n\n\tDesea intentar nuevamente o abortar?\n\n\t%s - %s\n\t<--- - --->", (sino ? "[REINTENTAR]" : " REINTENTAR "), (sino ? " ABORTAR " : "[ABORTAR]"));
				
				fflush(stdin);
				charinput = getch();
				
				if (charinput == -32) {
					switch(getch()) {
						case 77:
							if(sino == true) sino = !true;
							break;
						case 75:
							if(sino == !true) sino = true;
							break;
					}
				} else if(charinput == '\r'){
					if(sino) action = 4;
					else seguir = false;
				}
				break;
				
			case 6: // Consultar si desea continuar o terminar
				printf("\n\t\tSe pudieron escribir los datos correctamente!\n\n\tDesea ingresar una nueva persona a la base de datos?\n\n\t%s - %s\n\t<--- - --->\n\t", (sino ? "[SI]" : " SI "), (sino ? " NO " : "[NO]"));
				
				fflush(stdin);
				charinput = getch();
				
				if (charinput == -32) {
					switch(getch()) {
						case 77:
							if(sino == true) sino = !true;
							break;
						case 75:
							if(sino == !true) sino = true;
							break;
					}
				} else if(charinput == '\r'){
					if(sino) action = 0;
					else seguir = false;
				}
				break;
				
		}
	
	}
}

//	+------------------------------------------------------------------------------------------------+
//	| Section 5 : Funciones Secundarias - Secundarias de las Secundarias                             |
//	+------------------------------------------------------------------------------------------------+

void previewDatos(char* stringNombre, char* sexo, int edad) {
	printf("\n\t\tNombre: %s", stringNombre);
	printf("\n\t\tSexo: %s", sexo);
	printf("\n\t\tEdad: %d", edad);
}

void nombreArchivo() {
	
	bool seguir = true;
	char charinput;
	int opcion = 1;
	int action = 0;
	
	while(seguir) {
		system("CLS");
		printf("\n\tBase de Datos de Personas");
		printf("\n\n\tSe esta leyendo actualmente en [%s].\n\n\tDesea utilizar otro archivo?\n\n\t%s - %s\n\t<--- - --->",fileName, (opcion ? "[NO]" : " NO "), (opcion ? " SI " : "[SI]"));
		
		fflush(stdin);
		charinput = getch();
		
		if (charinput == -32) {
			switch(getch()) {
				case 77:
				case 75:
					opcion = !opcion;
					break;
			}
		} else if(charinput == '\r'){
			switch(opcion) {
				case 0: do{
							fflush(stdin);
							printf("\n\t\tIngrese el nombre del archivo: ");
							gets(fileName);
							if(!validarNombre(fileName)) {
								printf("\n\tEl nombre ingresado es invalido.\a\n\t");
								system("PAUSE");
	return 0;
							}
						}while(!validarNombre(fileName));
						
						strcat(fileName, ".txt");
						seguir = false; 
						break;
						
				default: seguir = false; break;
			}
		}
	}
}

bool validarNombre(char nombre[]) {
	int i = 0;
	while(nombre[i] != '\0'){
		if((nombre[i] < 'A' || nombre[i] > 'Z' && nombre[i] < 'a' || nombre[i] > 'z') && nombre[i] != ' ') return !true;
		i = i + 1;
	}
	return true;
}

int obtenerNumero(bool allowZero, bool positive) {
	int input, check;
	char antiusers;
	
	do{
		fflush(stdin);
		check = scanf("%d%c", &input, &antiusers);
		if(check != 2 || antiusers != '\n' || (input == 0 && !allowZero) || (input < 0 && positive))
			printf("\n\a\tEl numero ingresado es invalido. Debe ser un entero%s%s.\n\n\t\tIngreselo nuevamente: ", (allowZero ? "" : " distinto de cero"), (positive ? " positivo" : ""));
	}while(check != 2 || antiusers != '\n' || (input == 0 && !allowZero) || (input < 0 && positive));
	return input;
}

double obtenerDouble(bool allowZero, bool positive) {
	double input;
	int check;
	char antiusers;
	
	do{
		fflush(stdin);
		check = scanf("%lf%c", &input, &antiusers);
		if(check != 2 || antiusers != '\n' || (input == 0 && !allowZero) || (input < 0 && positive))
			printf("\n\a\tEl numero ingresado es invalido. Debe ser un entero%s%s.\n\n\t\tIngreselo nuevamente: ", (allowZero ? "" : " distinto de cero"), (positive ? " positivo" : ""));
	}while(check != 2 || antiusers != '\n' || (input == 0 && !allowZero) || (input < 0 && positive));
	return input;
}
