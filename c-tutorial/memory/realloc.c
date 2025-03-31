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


  char *password1 = malloc(7*sizeof(char));
  char *password2 = malloc(7*sizeof(char));

  strcpy(password1, "abc123");
  strcpy(password2, "xyz789");

  printf("p1 addr: %p\np2 addr: %p\n", password1, password2");
  printf("p1 addr. %d\nnp2 addr: %d\n", (int)password1, (int)password2);

  for(int i = 0; i<100; i++)
    printf("%c", password1[i]);
  printf("\n");

  free(a);
  return 0;
}
