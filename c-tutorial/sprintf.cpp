#include <stdio.h>

int main(){

	char string[100];
	sprintf(string, "Hello %d %f", 2, 10.5);
	
	printf("%s\n", string);
	
	int length = strlen(string);
	for(int i = 0; i<length; i++)
		printf("string[%d] = %c\n", i, string[i];
		
	char pi[10];
	double dblpi = 3.141592;
	sprintf(pi, "%f", dblpi);
	
	printf("%s\n", pi);
	
	return 0;
}
