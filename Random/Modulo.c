int main() {
	
    int n;
    scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.
	int sum = 0;
	int i;
	for(i = 0; i < 5; i = i + 1) {
		sum = sum + n % 10;
		n = n / 10;
	}
	printf("%d", sum);
    return 0;
}