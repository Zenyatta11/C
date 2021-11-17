#include <stdio.h>

void main () {
	char buf[64];
	int i;
	
	for (i = 0; i < 50; i++) {
		snprintf(buf, 64, "Ejercicio_%d.c", i);
		FILE *fp = fopen(buf, "w+");
		printf("%s\n", buf);
		if(fp != NULL)	printf("Closed file return: %d",fclose (fp));
	}
	
	system("PAUSE");
	return 0;
}