
#include<stdio.h>

int main() {
	int A[5][5];
	int i, j;
for (i = 0; i< 3; i++)
    for (j = 0; j< 4; j++)
         A[i][j] = i*j;
printf("%d", A[2][3]);
system("PAUSE");
	return 0;
}