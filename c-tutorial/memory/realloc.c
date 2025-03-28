#include <stdio.h>
#include <stdlib.h>

int main(void){
  int *a = malloc(sizeof(int)*5);

  for(int i = 0; i<5; i++) a[i] = i;
  a = realloc(a, sizeof(int)*10);
  for(int i = 5; i<10; i++) a[i] = i;

  for(int i = 0; i<10; i++) printf("a[%d] = %d\n", i, a[i]);

  int *a1 = malloc(sizeof(int)*5);
  int *a2 = malloc(sizeof(int)*5);

  for(int i = 0; i<5; i++) a1[i] = i;
  for(int i = 0; i<5; i++) a2[i] = i;

  printf("a1: %p\n", a1);
  printf("a2: %p\n", a2);

  int *save_ptr = a1;
  a1 = realloc(a1, sizeof(int)*20);

  printf("a1 after realloc: %p\n", a1);

  // old data is left at the old position even if at new possition it is copied
  for(int i = 0; i<10; i++) printf("save[%d] = %d\n", i, save_ptr[i]);

  free(a);
  return 0;
}
