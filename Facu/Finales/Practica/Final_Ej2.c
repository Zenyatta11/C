
struct {
	char Nombre[24];
	char Apellido[24];
}Estudiante;

bool guardarNombres(char* nombreArchivo, struct Estudiante[], int cantDeAlumnos) {
	
	FILE file = fopen(nombreArchivo, "w");
	if(file == NULL) return false;
	
	int i;
	for(i = 0; i < cantDeAlumnos, i = i + 1)
		fprintf("%s\t%s\n", Estudiante[i].Nombre, Estudiante[i].Apellido);
	
	fclose(file);
}