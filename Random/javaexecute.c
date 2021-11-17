#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *str_replace(char *orig, char *rep, char *with);

int main( int argc, char *argv[] )  {

	if(argc == 2 ) {
		char* command = "java \"";
		
		char* strB = str_replace(argv[1], ".java", "");
		char* strA = calloc(strlen(command) + strlen(argv[1]) + 3, sizeof(char));  
		
		if(strB != NULL && strA != NULL) {
			sprintf(strA,"%s%s\"",command, strB);
			system(strA);
			
			free(strA); 
			free(strB); 
		} else printf("Memory allocation error."); //laughs in 64GBs of RAM
		
	} else printf("One argument expected.\n");
	
	return 0;
}


char *str_replace(char *orig, char *rep, char *with) {
	char *result;
	char *ins;
	char *tmp;
	
	int len_rep;
	int len_with;
	int len_front; 
	int count;
	
	if (!orig || !rep)
		return NULL;
	
	len_rep = strlen(rep);
	
	if (len_rep == 0)
		return NULL;
	
	if (!with)
		with = "";
	
	len_with = strlen(with);

	ins = orig;
	
	for (count = 0; tmp = strstr(ins, rep); ++count) {
		ins = tmp + len_rep;
	}

	tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

	if (!result)
		return NULL;

	while (count--) {
		ins = strstr(orig, rep);
		len_front = ins - orig;
		
		tmp = strncpy(tmp, orig, len_front) + len_front;
		tmp = strcpy(tmp, with) + len_with;
		
		orig += len_front + len_rep;
	}
	
	strcpy(tmp, orig);
	
	return result;
}