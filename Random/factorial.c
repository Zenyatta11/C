#include<stdio.h>

int factorial(int number) {
	printf("\nNumber Received: %d", number);
	if(number > 1)
		number = number * factorial(number - 1);
	printf(", Returning %d", number);
	return number;
}

int main() {
	printf("Result: %d", factorial(5));
	system("PAUSE");
	return 0;
}