#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_LEN 24

int main() 
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char single, word[MAX_LEN], sentence[MAX_LEN];
    scanf("%c",&single);
    fflush(stdin);
    scanf("%s",word);
    fflush(stdin);
    scanf("%[^\n]",sentence);
    printf("%c\n%s\n%s", single, word, sentence);
	system("PAUSE");
    return 0;
}