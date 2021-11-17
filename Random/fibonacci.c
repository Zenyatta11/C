#include <stdio.h>

int fibonacci(int num) {
	printf("%d \n", num);
	if(num <= 1) return num;
	return (fibonacci(num - 1) + fibonacci(num - 2));
}

int main() {
	printf("%d", fibonacci(9));
	system("PAUSE");
	return 0;
}

