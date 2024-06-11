#include "combinations.h"

struct Stack * printCombination(int n, int r) {
    int arr[n];
    for(int i=0; i<n; i++)
        arr[i] = i+2;
    int data[r];
    struct Stack *pilha = (struct Stack *)malloc(sizeof(struct Stack));
    combinationUtil(arr, data, 0, n-1, 0, r, pilha);
    return pilha;
}

void push(struct Stack *stack, struct currentCombination *current) {
    if (stack->head == NULL) {
        stack->head = current;
        stack->tail = current;
        stack->tail->next = NULL;
    } else {
        stack->tail->next = current;
        stack->tail = current;
        stack->tail->next = NULL;
    }
    stack->size++;
}

void combinationUtil(int arr[], int data[], int start, int end, int index, int r, struct Stack *stack) {
    if (index == r){
        struct currentCombination *current = (struct currentCombination *)malloc(sizeof(struct currentCombination));
        for (int j=0; j<r; j++){
            current->data[j] = data[j];
        }
        push(stack, current);
        return;
    }

    for (int i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r, stack);
    }
}


int countCombination(struct currentCombination *head) {
    int count = 0;
    struct currentCombination *current = head;
    while(current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int ** stackToMatrix (struct Stack *stack) {
    int **matrix = (int **)malloc(stack->size * sizeof(int*));
    int i = 0;
    struct currentCombination *current = stack->head;
    while(current != NULL) {
        matrix[i] = (int *)malloc(6 * sizeof(int));
        matrix[i][0] = 0;
        matrix[i][1] = 1;
        for(int j=2; j<6; j++) {
            matrix[i][j] = current->data[j-2];
        }
        current = current->next;
        i++;
    }
    return matrix;
}