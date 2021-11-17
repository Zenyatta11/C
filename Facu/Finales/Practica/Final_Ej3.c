
struct {
	char Modelo[24];
	char Vendedor[24];
	double Valor;
}Vehiculo;

double obtenerSueldo(char* Empleado, struct Vehiculo[], int cantDeVehiculos) {
	
	int sueldo = 5000;
	int i
	double suma = 0;
	
	for(i = 0; i < cantDeVehiculos, i = i + 1)
		if(!stricmp(Empleado, Vehiculo[i].Vendedor))
			suma = suma + Vehiculo[i].Valor;
	
	return (double)sueldo + suma*0.1;
}
