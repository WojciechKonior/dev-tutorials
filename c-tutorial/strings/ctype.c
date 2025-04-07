#include <stdio.h>
#include <ctype.h>

int main(){
  char a = '1';
  if(isalnum(a)) 
    printf("'%c' is alpha-numeric character\n");
  return 0;
}
