#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

void Consecionaria();

int main(){
	int flag;
	
	Consecionaria();
	
	system("PAUSE");
	return flag;
}

void Consecionaria(){
	FILE *F;
    char marca[20],modelo[20];
	int i=0, flag = 0,Unidades=0,autos = 0;
	float Precio=0,total = 0;
	
	F = fopen("Concesionaria.txt", "r");	
	
	if(F == NULL){
		printf("Error al abrir el archivo\n");
		flag = 1;
	}else{
		
		
		printf("Marca Modelo Unidades Precio \n");
		for(i = 0;fscanf(F,"%s %s %d %f",marca,modelo,&Unidades,&Precio)==4; i++){
			printf("%s %s %d $%.2lf\n",marca,modelo,Unidades,Precio);
			printf("Precio en 60 cuotas sin interes\n $%.2lf\n",Precio/60);
			total = total + Precio;
			autos = autos + Unidades;
		}
		
		printf("El valor total del stock es: $%.2lf\n", total * autos);
		
		fclose(F);
	}
	
	return;
}