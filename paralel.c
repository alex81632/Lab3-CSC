#include "coins.h"
#include "combinations.h"
#include "paralel.h"
#include <pthread.h>
#include <semaphore.h>


int min = 10000;
sem_t sem;

void *parallel_coin_change(void *arg){

    parallelSum* Range = (parallelSum*)arg;

    for(int i=Range->index; i < Range->max; i += Range->stride) {
        int sum = 0;

        for (int j= 0; j<=100; j++) {
            int coins = coin_change(Range->matrix[i], j, 5);
            sum += coins;
        }

        if (sum < min) {
            sem_wait(&sem);
            min = sum;
            sem_post(&sem);
        }

    }

    pthread_exit(NULL);
}

int paralel(int n, int r, int n_threads) {
    struct Stack *pilha = printCombination(n, r-1);
    int **matrix = stackToMatrix(pilha);

    int stride = n_threads;

    pthread_t v_threads[n_threads];
    parallelSum v_structs[n_threads];

    for(int i = 0; i < n_threads; i++){
        v_structs[i].index = i;
        v_structs[i].stride = stride;
        v_structs[i].max = pilha->size;
        v_structs[i].matrix = matrix;
    }

    sem_init(&sem, 0, 1);

    for(int i = 0; i < n_threads; i++){
        pthread_create(&v_threads[i], NULL, parallel_coin_change, (void*)&v_structs[i]);
    }

    for(int i = 0; i < n_threads; i++){
        pthread_join(v_threads[i], NULL);
    }

    sem_destroy(&sem);

    return min;
}