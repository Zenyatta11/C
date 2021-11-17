/*

	Realizar un programa que genere un listado con el stock de una tienda de ropa en un archivo TXT (string, string, int, int, double). 
	El usuario ingresará por teclado: (tipo de dato y validación figuran entre paréntesis):
	nombre del producto (string)
	color (string)
	talle (int > 0)
	cantidad (int >= 0)
	precio actual (double >= 0)

	Para finalizar la carga se le pregunta al usuario si quiere continuar o no. No hay límite. 
	La función MAIN() no lee ni escribe nada. Llama a otras funciones que lo hacen. 

*/


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define STRING_MAX 64

char fileName[STRING_MAX] = "inventario.txt\0"; // Mantengamos esto global por las dudas

int obtenerNumero(bool allowZero);

bool validarNombre(char nombre[]);

double obtenerDouble(bool allowZero, bool positive);

void messageOfTheDay();
void nombreArchivo();
void obtenerDatos();
void previewDatos(char* stringNombre, char* stringColor, int talle, int cantidad, double precio);

int main() {
	
	messageOfTheDay();
	nombreArchivo();
	obtenerDatos();
	
	system("PAUSE");
	return 0;
	
}

void messageOfTheDay() {
	printf("\n\tStock de una tienda de ropa\n");
}

void obtenerDatos() {
	bool seguir = true;
	char charinput;
	bool sino = true;
	int action = 0;
	
	char stringNombre[STRING_MAX];
	char stringColor[STRING_MAX];
	int talle, cantidad;
	double precio;
	
	while(seguir) {
		system("CLS");
		printf("\n\tEscribiendo en [%s]\n\n", fileName);
		fflush(stdin);
		switch(action) { // Pense en desarmar este switch en varios llamados a funciones (pensando en PHP) pero en C, no puedo devolver algo que evalue
						// unicamente a false como if(action === false) porque no existe (o desconozco) para diferenciar un ingreso 0 del usuario
						// de un 0 de que no se pudo pedir correctamente.
						
			case 0: // Nombre del articulo
				printf("\t\tIngrese el nombre del articulo: ");
				gets(stringNombre);
				if(validarNombre(stringNombre)) action = 1;
				else {
					printf("\n\tEl nombre ingresado es invalido.\a\n\t");
					system("PAUSE");
	return 0;
				}
				break;
			
			case 1: // Color del articulo
				printf("\t\tIngrese el color de %s: ", stringNombre);
				gets(stringColor);
				if(validarNombre(stringColor)) action = 2;
				else {
					printf("\n\tEl color ingresado es invalido.\a\n\t");
					system("PAUSE");
	return 0;
				}
				break;
			
			case 2: // Talla del articulo
				printf("\t\tIngrese el talle de %s: ", stringNombre);
				talle = obtenerNumero(false);
				action = 3;
				break;
			
			case 3: // Cantidad
				printf("\t\tIngrese la cantidad que hay de %s: ", stringNombre);
				cantidad = obtenerNumero(true);
				action = 4;
				break;
			
			case 4: // Precio
				printf("\t\tIngrese el precio de %s: ", stringNombre);
				precio = obtenerDouble(true, true);
				action = 5;
				break;
			
			case 5: // Buena practica de no escribir, manteniendo el handle del archivo ocupado al divino boton
					// (ademas de que, como estoy usando append, ir para atras para corregir errores no es tan sencillo)
				printf("\tConfirmacion:\n\t\tEsta a punto de escribir los siguientes datos:\n");
				previewDatos(stringNombre, stringColor, talle, cantidad, precio);
				printf("\n\n\tEs correcta esta informacion?\n\t%s - %s\n\t<--- - --->", (sino ? "[SI]" : " SI "), (sino ? " NO " : "[NO]"));
				
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
					if(sino) action = 6;
					else action = 0;
				}
				break;
			
			case 6:
				printf("\t\tEscribiendo los datos...\n");
				FILE *file = fopen(fileName, "a");
				
				if(file == NULL) { // no se pudo pero tampoco tengo un codigo de error para saber por que no. gracias C
					action = 7;
					break;
				}
				
				fprintf(file, "%s\t%s\t%d\t%d\t%.2lf\n", stringNombre, stringColor, talle, cantidad, precio);
				
				fclose(file);
				
				action = 8; //tuve que sacar la pregunta de aca porque cada vez que cambiabas
							// de opcion volvia a escribir. oopsie
				break;
				
			case 7:
				printf("\tNo se pudo escribir los datos! ");
				printf("\n\n\tDesea intentar nuevamente o abortar?\n\t%s - %s\n\t<--- - --->", (sino ? "[REINTENTAR]" : " REINTENTAR "), (sino ? " ABORTAR " : "[ABORTAR]"));
				
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
					if(sino) action = 6;
					else seguir = false;
				}
				break;
				
			case 8: // Consultar si desea continuar o terminar
				printf("\n\t\tSe pudieron escribir los datos correctamente!\n\n\tDesea ingresar un nuevo articulo?\n\t%s - %s\n\t<--- - --->\n\t", (sino ? "[SI]" : " SI "), (sino ? " NO " : "[NO]"));
				
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

void previewDatos(char* stringNombre, char* stringColor, int talle, int cantidad, double precio) {
	printf("\n\t\tArticulo: %s", stringNombre);
	printf("\n\t\tColor: %s", stringColor);
	printf("\n\t\tTalle: %d", talle);
	printf("\n\t\tEn inventrario: %d", cantidad);
	printf("\n\t\t$ %.2lf", precio);
}

void nombreArchivo() {
	
	do{
		fflush(stdin);
		printf("\n\t\tIngrese el nombre del archivo para guardar el stock: ");
		gets(fileName);
		if(!validarNombre(fileName)) {
			printf("\n\tEl nombre ingresado es invalido.\a\n\t");
			system("PAUSE");
	return 0;
		}
	}while(!validarNombre(fileName));
	
	strcat(fileName, ".txt");
}

bool validarNombre(char nombre[]) {
	int i = 0;
	while(nombre[i] != '\0'){
		if((nombre[i] < 'A' || nombre[i] > 'Z' && nombre[i] < 'a' || nombre[i] > 'z') && nombre[i] != ' ') return !true;
		i = i + 1;
	}
	return true;
}

int obtenerNumero(bool allowZero) {
	int input, check;
	char antiusers;
	
	do{
		fflush(stdin);
		check = scanf("%d%c", &input, &antiusers);
		if(check != 2 || antiusers != '\n' || (input == 0 && !allowZero))
			printf("\n\a\tEl numero ingresado es invalido. Debe ser un entero%s\n\n\t\tIngreselo nuevamente: ", (allowZero ? "." : " distinto de cero."));
	}while(check != 2 || antiusers != '\n' || (input == 0 && !allowZero));
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
			printf("\n\a\tEl numero ingresado es invalido. Debe ser un entero%s%s\n\n\t\tIngreselo nuevamente: ", (allowZero ? "" : " distinto de cero"), (positive ? " positivo." : "."));
	}while(check != 2 || antiusers != '\n' || (input == 0 && !allowZero) || (input < 0 && positive));
	return input;
}