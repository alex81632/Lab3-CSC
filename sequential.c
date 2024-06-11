#include "coins.h"
#include "combinations.h"

int sequential(int n, int r) {
    struct Stack *pilha = printCombination(n, r-1);
    int **matrix = stackToMatrix(pilha);
    int min = 10000;
    for(int i=0; i<pilha->size; i++) {
        int sum = 0;
        for (int j=0; j<=100; j++) {
            int coins = coin_change(matrix[i], j, 5);
            sum += coins;
        }
        if (sum < min) {
            min = sum;
        }
    }
    return min;
}