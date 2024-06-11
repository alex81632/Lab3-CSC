#include <stdio.h>
#include <stdlib.h>

int paralel(int n, int r, int n_threads);
void *parallel_coin_change(void *arg);


typedef struct{
    int index;
    int stride;
    int max;
    int **matrix;    
} parallelSum ;