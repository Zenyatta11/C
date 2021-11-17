
#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int * MergedArray = malloc(80);
	
	printf("Size of merged: %d\n", sizeof(*MergedArray));
	
	free(MergedArray);
	system("PAUSE");
	return 0;
}