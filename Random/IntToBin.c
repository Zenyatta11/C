

int IntToBin(int input) {
	printf("%d%d%d%d\n\n", (input & 8 ? 1 : 0), (input & 4 ? 1 : 0), (input & 2 ? 1 : 0), (input & 1 ? 1 : 0));
	return 1;
}

