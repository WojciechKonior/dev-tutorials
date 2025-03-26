#include <stdio.h>

int main(){
	FILE *file;
	file = fopen("data.txt", "r");
	if(file == NULL){
		printf("Error opening file.\n");
		return 1;
	}
	
	car c;
	while((c=fgetc(file)) != EOF){
		printf("%c", c);
	}
	printf("\n");
	
	rewind(file);
	while((c=fgetc(file)) != EOF){
		printf("%c", c);
	}
	printf("\n");
	
	fclose(file);
	return 0;
}
