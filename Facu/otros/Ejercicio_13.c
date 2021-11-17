/*

 Par o impar?

*/


#include<stdio.h>

int main() {
	
	int input;
	
	printf("Par o impar?\n\nIngrese un numero: ");
	scanf("%d", &input);
	
	printf("El numero es %s.\n\n", (input & 1 ? "impar" : "par"));
	system("PAUSE");
	return 0;
	
}

/*

1000
0100
0010
0001

1011 8*1 + 4*0 + 2*1 + 1*1 = 11

1101 1001

0001
1110 8*1 + 4*1 + 2*1 + 1*0

*/
