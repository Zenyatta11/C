#include <stdio.h>

int main() {
    int test;

    printf("%d -> %d -> %d\n", 6, 6 >> 3, 6 << 2);
    printf("Es impar? %d, %d\n", 7 & 1, 6 & 1);
    printf("6 negativo: paso 1: %d; paso 2: %d\n\n", ~6, ~6 + 1);
    printf("\nIngrese un numero: ");
    scanf("%d", &test);
    printf("%d%d%d%d\n\n", (test & 8 ? 1 : 0), (test & 4 ? 1 : 0), (test & 2 ? 1 : 0), (test & 1 ? 1 : 0));
    system("PAUSE");
	return 0;
}