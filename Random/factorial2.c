#include<stdio.h>

int factorial(int num) {
	if(num > 1) num = num * factorial(num - 1);
	return num;
}

int main() {
	printf("\nResult: %d", factorial(5));
	system("PAUSE");
	return 0;
}