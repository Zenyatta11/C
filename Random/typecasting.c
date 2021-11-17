#include <stdio.h>

void main () {
	int ch;
	
	FILE *fp = fopen("output.txt", "w+");
	
	if(fp == NULL) printf("Unable to open file.");
	
	for( ch = 0 ; ch <= 255; ch++ ) {
		printf("ASCII value = %d, Character = %c\n", ch , ch );
		fprintf (fp, "ASCII value = %d, Character = %c\n", ch , ch );
	}
	
	if(fp != NULL)	printf("Closed file return: %d",fclose (fp));
	system("PAUSE");
	return 0;
}