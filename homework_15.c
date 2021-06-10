#include "geek.h"
#include <stdio.h>

#define SIZE 10
#define SIZEm 5

typedef int K;
typedef int htIndex;

int htSize;

htIndex hash(T data) {
    return data % htSize;
}

boolean chainInsertNode(OneLinkNode **table, K data) {
    OneLinkNode *p, *p0;

    htIndex bucket = hash(data);
    p = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    if (p == NULL) {
        printf("Out of memory! \n");
        return false;
    }

    p0 = table[bucket];
    table[bucket] = p;
    p->next = p0;
    p->dat = data;
    return true;
}

OneLinkNode* chainFindNode(OneLinkNode **table, K data) {
    OneLinkNode *p = table[hash(data)];
    while (p && !(p->dat == data))
        p = p->next;
    return p;
}

void chainDeleteNode(OneLinkNode **table, K data) {
    OneLinkNode *parent, *current;
    parent = NULL;
    htIndex bucket = hash(data);
    current = table[bucket];
    while (current && !(current->dat == data)) {
        parent = current;
        current = current->next;
    }
    if (!current) {
        printf("Value not found \n");
        return;
    }
    if (parent)
        parent->next = current->next;
    else
        table[bucket] = current->next;
    free(current);
}

void printTable(OneLinkNode** table, int size) {
    OneLinkNode *p;
    for (int i = 0; i < size; ++i) {
        p = table[i];
        while (p) {
            printf("%5d", p->dat);
            p = p->next;
        }
        printf("\n");
    }
    printf("\n");
}

int maxMoney (int* task, int K) {
    int max = 0;
    for(unsigned i = 0; i < SIZEm; ++i) {
        if (max < task[i] && task[i] <= K) {
            max = task[i];
        }
    }
    return max;
}

int Calculation(int* task, int K, int sum) {
    int current = maxMoney(task, K);
    while((K - current) > 0) {
        K = K - current;
        sum++;
    }
    if (K < current) {
        Calculation(task, K, sum);
    }
    printf("%d\n", sum);
    return sum;
}

int main(int argc, char *argv[]) {
    htSize = 8;
    int* arr;
    const int SZ = 20;
    arr = (int*) malloc(sizeof(int) * SZ);
    fillIntRandom(arr, SZ, 100);

    int text[SIZE];
    printf("Enter the text: ");
    scanf("%ls", text);
    int ins = 0;
    OneLinkNode** hashTable = (OneLinkNode**) calloc(htSize, sizeof(OneLinkNode*));

    for (int i = 0; i < SIZE; ++i) {
        chainInsertNode(hashTable, text[i]);
    }

    printTable(hashTable, htSize);
    //printf("\n");

    int task[SIZEm] = {50, 10, 5, 2, 1};
    const int SUM = 98;
    int count = 0;

    printf("%d\n", Calculation(task, SUM, count));

    return 0;
}
