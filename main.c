#include <stdio.h>
#include "sequential.h"
#include "paralel.h"
#include "timeit.h"
#include <sys/time.h>


int main() {
    struct timeval t1, t2;
    double elapsedTime;

    // start timer
    gettimeofday(&t1, NULL);

    printf("Paralel: ");
    // Parameters: n: coins range, r: number of coins in combination, n_threads: number of threads
    int min = paralel(75, 5, 5);    
    printf("%d\n", min);

    // stop timer
    gettimeofday(&t2, NULL);

    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
    elapsedTime /= 1000.0;
    printf("Time spent: %f\n", elapsedTime); 

    TIME_IT(
        printf("Sequential: ");
        // Parameters: n: coins range, r: number of coins in combination
        int min = sequential(75, 5);    
        printf("%d\n", min);
    );

    return 0;
}