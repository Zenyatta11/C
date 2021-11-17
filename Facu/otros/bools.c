
#include<stdio.h>

#define bool int
#define true 1
#define false 0

int main() {
	
	char input;
	bool stopExecution = false;
	
	printf("Pregunta: %d\n", true == 1);
	
	while(!stopExecution) {
		scanf("%c", &input);
		
		switch(input) {
			case 'F':
			case 'f': stopExecution = true; break;
			default: printf("Continuando!\n\n"); break;
		}
	}
	
	system("PAUSE");
	return 0;
	
}