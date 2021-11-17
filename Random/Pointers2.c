#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
	int bufA, bufB;
	bufA = *a + *b;
	bufB = *a - *b;
	if(bufB < 0) bufB = -bufB;
	
	*a = bufA;
	*b = bufB;
	
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}