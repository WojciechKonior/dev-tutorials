#include <stdio.h>
#include <stdlib.h>

int main(){
  char *home_dir = getenv("HOME");
  printf("The home directory is: %s \n", home_dir);
  return 0;
}
