#include <stdio.h>
#include <stdlib.h>

struct currentCombination {
    int data[4];
    struct currentCombination *next;    
};

struct Stack {
    struct currentCombination *head;
    struct currentCombination *tail;
    int size;
};

void push(struct Stack *stack, struct currentCombination *current);

void combinationUtil(int arr[], int data[], int start, int end, int index, int r, struct Stack *stack);

struct Stack * printCombination(int n, int r);

int countCombination(struct currentCombination *head);

int ** stackToMatrix (struct Stack *stack);