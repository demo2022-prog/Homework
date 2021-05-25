#include <stdio.h>
#include <stdlib.h>

#define SIZEarr 100
#define T char
#define SIZE 10
#define true 1 == 1
#define false 1 != 1

typedef int boolean;
int cursor = -1;
T Stack[SIZEarr];

boolean pushStack(T data) 
{
    if (cursor < SIZEarr) 
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

void binaryTranslator(int number)
{
	int i;
	int num = number;
	while (number != 0)
	{
		if (number % 2 == 0)
		{
		pushStack('0');
 		number /= 2;
		} else
		{
			pushStack('1');
			number = number / 2;
		}
	i++;
	}
}

typedef struct 
{
    int pr;
    int dat;
} Node;

Node* arr[SIZE];
int head;
int tail;
int items;

void init() {
    for (int i = 0; i < SIZE; ++i) 
    {
        arr[i] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}

void ins(int pr, int dat) 
{
    Node *node = (Node*) malloc(sizeof(Node));
    node->dat = dat;
    node->pr = pr;
    int flag;

    if (items == 0) 
    {
        arr[tail++] = node;
        items++;
    } else if (items == SIZE) 
    {
        printf("%s \n", "Queue is full");
        return;
    } else 
    {
        int i = 0;
        int idx = 0;
        Node *tmp;
        for (i = head; i < tail; ++i) 
        {
            idx = i % SIZE;
            if (arr[idx]->pr > pr)
            {
                break;
            }
            else
            {
                idx++;
            }
        }
        flag = idx % SIZE;
        i++;
        while (i <= tail) 
        {
            idx = i % SIZE;
            tmp = arr[idx];
            arr[idx] = arr[flag];
            arr[flag] = tmp;
            i++;
        }
        arr[flag] = node;
        items++;
        tail++;
    }
}

Node* rem() 
{
    if (items == 0) 
    {
        return NULL;
    } else 
    {
        int idx = head++ % SIZE;
        Node *tmp = arr[idx];
        arr[idx] = NULL;
        items--;
        return tmp;
    }
}

void printQueue() 
{
    printf("[ ");
    for (int i = 0; i < SIZE; ++i) 
    {
        if (arr[i] == NULL) 
        {
            printf("[*, *] ");
        }
        else 
        {
            printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
        }
    }
    printf(" ]\n");
}

void prQueueTest() 
{
    init();
    ins(1, 11);
    ins(3, 22);
    ins(4, 33);
    ins(2, 44);
    ins(3, 55);
    ins(4, 66);
    ins(5, 77);
    ins(1, 88);
    ins(2, 99);
    ins(6, 100);
    printQueue();
    for (int i = 0; i < 7; ++i) 
    {
        Node* n = rem();
        printf("pr=%d, dat=%d \n", n->pr, n->dat);
    }
    printQueue();

    ins(1, 110);
    ins(3, 120);
    ins(6, 130);
    printQueue();

    for (int i = 0; i < 5; ++i) 
    {
        Node* n = rem();
        printf("pr=%d, dat=%d \n", n->pr, n->dat);
    }
    printQueue();

}

int main(int argc, char const *argv[])
{
	int number;
	printf("Enter the number: ");
	scanf("%d", &number);

	binaryTranslator(number);
	while (cursor != -1) 
	{
		printf("%c ", popStack());
    }
    printf("\n\n");

	prQueueTest();
	return 0;
}