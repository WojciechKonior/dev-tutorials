#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  clock_t tic, toc;
  int *array;
  
  srand(time(0));
  int size = 0;
  int *junk = 0;
  for(int i = 0; i<1000; i++){
    size = rand()%16000;
    junk = malloc(size*sizeof(int));
    for(int j = 0; j<size; j++){
      junk[j] = rand();
    }
    free(junk);
  }

  tic = clock();
  array = malloc(1000*sizeof(int));
  toc = clock();
  printf("malloc: %ds\n", double(toc-tic)/CLOCKS_PER_SEC);
  
  for(int i = 0; i<1000; i++)
    printf("%d", array[i]);
  free(array);

  tic = clock();
  array = calloc(1000*sizeof(int));
  toc = clock();
  printf("calloc: %ds\n", double(toc-tic)/CLOCKS_PER_SEC);
  
  for(int i = 0; i<1000; i++)
    printf("%d", array[i]);
  free(array);
  return 0;
}
