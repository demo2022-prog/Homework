#include "geek.h"

#define SIZE 6
#define SIZEstack 1000
#define WIDTH 10
#define HEIGHT 8
#define OBSTACLE -1
#define BLANK -2
#define n 6

int matrix[n][n] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
};
int visitedDepth[SIZE] = {0};

int cursor = -1;
T Stack[SIZEstack];

boolean pushStack(T data)
{
    if (cursor < SIZEstack)
    {
        Stack[++cursor] = data;
        return true;
    } else
    {
        printf("%s \n", "Stack overflow");
        return false;
    }
}

T popStack()
{
    if (cursor != -1)
    {
        return Stack[cursor--];
    } else {
        printf("%s \n", "Stack is empty");
        return -1;
    }
}

int pointX[HEIGHT * WIDTH];
int pointY[HEIGHT * WIDTH];

void clearVisited(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = 0;
    }
}

void depthTravers(int st) {
    int r;
    printf("%d ", st);

    visitedDepth[st] = 1;
    for (r = 0; r < n; ++r) {
        if (matrix[st][r] == 1 && !visitedDepth[r]) {
            depthTravers(r);
        }
    }
}

void depthTraversStack(int st) {
    int r;
    printf("%d ", st);

    pushStack(st);
    for (r = 0; r < n; ++r) {
        if (matrix[st][r] == 1 && Stack[r] != 1) {
            depthTravers(r);
        }
    }
}

void resetArr() {
    for (int i = 0; i < n; ++i) {
        visitedDepth[i] = 0;
    }
}

void widthTravers(int** matrix, int start, const int size) {
    TwoLinkList* queue = (TwoLinkList*) malloc(sizeof(TwoLinkList));
    initTwoLinkList(queue);
    int visited[size];
    clearVisited(visited, size);
    TwoLinkEnqueue(queue, start);
    while (queue->size > 0) {
        int indx = TwoLinkDequeue(queue);
        if (visited[indx] == 1) continue;
        visited[indx] = 1;
        printf("%d ", indx);
        for (int i = 0; i < size; ++i) {
            if (get2dInt(matrix, indx, i) == 1 && visited[i] == 0)
                TwoLinkEnqueue(queue, i);
        }
    }
}

int main() {
    int** adjacency = init2dIntArray(adjacency, SIZE, SIZE);
    int** matrix = init2dIntArray(matrix, HEIGHT, WIDTH);
    depthTravers(0);
    resetArr();
    printf("\n");
    depthTravers(2);
    resetArr();
    printf("\n");
    depthTravers(1);
    resetArr();
    printf("\n");
    printf("\n");

    depthTraversStack(0);
    printf("\n");
    depthTraversStack(2);
    printf("\n");
    depthTraversStack(1);
    printf("\n");
    return 0;
}
