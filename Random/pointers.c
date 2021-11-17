#include <stdio.h>

int main() {
	int* Array[5];
	int i;
	
	for(i = 0; i < 5; i = i + 1) {
		printf("%X\n", Array + i);
	}
	
	system("PAUSE");
	return 0;
}