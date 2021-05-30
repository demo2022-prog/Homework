#include <stdio.h>
#include <stdlib.h>
#include "geek.h"

#define T char
#define SIZE 100
#define true 1 == 1
#define false 1 != 1

typedef int boolean;
int cursor = -1;
int cursorBuf = -1;
int tmp = 0;
T Stack[SIZE];
T Buf[SIZE];

// Lesson 1

boolean pushStack(T data) {
    if (cursor < SIZE) {
        Stack[++cursor] = data;
        return true;
    } else {
        printf("%s \n", "Stack overflow");
        return false;
    }
}

boolean pushBuf(T data) {
    if (cursor < SIZE) {
        Buf[++cursorBuf] = data;
        return true;
    } else {
        printf("%s \n", "Stack overflow");
        return false;
    }
}

T popStack() {
    if (cursor != -1) {
        return Stack[cursor--];
    } else {
        printf("%s \n", "Stack is empty");
        return -1;
    }
}

T popBuf() {
    tmp = cursorBuf - 1;
    if (cursorBuf != tmp) {
        return Buf[cursorBuf--];
    } else {
        printf("%s \n", "Stack is empty");
        return -1;
    }
}


boolean emptyStack (T data) { // на вывод ошибок не смог, получился простой фильтр
    if (data == '(') {
        pushStack(data);
        pushBuf(data);
    } else if (data == '[') {
        pushStack(data);
        pushBuf(data);
    } else if (data == '{') {
        pushStack(data);
        pushBuf(data);
    } else if (data == ')') {
        if (Buf[cursorBuf] == '(') {
            pushStack(data);
            popBuf();
        }
    } else if (data == ']') {
        if (Buf[cursorBuf] == '[') {
        pushStack(data);
        popBuf();
        }
    } else if (data == '}') {
        if (Buf[cursorBuf] == '{') {
            pushStack(data);
            popBuf();
        }
    } else {
    printf("Incorrect sequence \n");
    }
}                             //p.s пробовал разные if..else

// Lesson 2

typedef struct OneLinkCopyNode {
    int dat;
    struct OneLinkCopyNode *next;
} OneLinkCopyNode;

typedef struct {
    OneLinkCopyNode *head;
    int size;
} OneLinkCopyList;

void initOneLinkCopyList(OneLinkCopyList *cplst) {
    cplst->head = NULL;
    cplst->size = 0;
}

void insert(OneLinkList *lst, int data) {
    OneLinkNode *new = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    new->dat = data;
    new->next = NULL;

    OneLinkNode *current = lst->head;
    if (current == NULL) {
        lst->head = new;
        lst->size++;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
        lst->size++;
    }
}

void printOneLinkIntCopyNode(OneLinkCopyNode *n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%d]", n->dat);
}

void printOneLinkIntCopyList(OneLinkCopyList *cplst) {
    OneLinkCopyNode *current = cplst->head;
    if (current == NULL) {
        printOneLinkIntCopyNode(current);
    } else {
        do {
            printOneLinkIntCopyNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size copy: %d \n", cplst->size);
}

void insertCopy(OneLinkCopyList *cplst, int data) {
    OneLinkCopyNode *new = (OneLinkCopyNode*) malloc(sizeof(OneLinkCopyNode));
    new->dat = data;
    new->next = NULL;

    OneLinkCopyNode *current = cplst->head;
    if (current == NULL) {
        cplst->head = new;
        cplst->size++;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
        cplst->size++;
    }
}

void copyList(OneLinkList* lst, OneLinkCopyList *cplst) { //не смог победить последний элемент
    OneLinkNode *current = lst->head;                     // копирует все, кроме последнего
    if (current == NULL) {
        printf("List is null\n");;
    }
    while (current->next != NULL) {
        insertCopy(cplst, current->dat);
        current = current->next;
    }
}

OneLinkNode* rm(OneLinkList *lst, int data) {
    OneLinkNode *current = lst->head;
    OneLinkNode *parent = NULL;
    if (current == NULL)
        return NULL;

    while (current->next != NULL && current->dat != data) {
        parent = current;
        current = current->next;
    }
    if (current->dat != data) {
        return NULL;
    }
    if (current == lst->head) {
        lst->head = current->next;
        lst->size--;
        return current;
    }
    parent->next = current->next;
    lst->size--;
    return current;
}

// Lesson 3

boolean sortList(OneLinkList* lst) {
    OneLinkNode *current = lst->head; 
    if (current == NULL) return -1;
    int tmp = 0; 
    boolean retUP = 1; 
    boolean retDown = 1; 
    tmp = current->dat; 
    current = current->next;
    while (current->next != NULL) {
        if (tmp <= current->dat) {
            retUP = -1;
            tmp = current->dat;
            current = current->next;
        }
        if (tmp >= current->dat) {
            retDown = -1;
            tmp = current->dat;
            current = current->next;
        }
    }
    if(retUP == retDown){ 
        printf("List is not sorted\n");
    } else {
        printf("List is sorted\n");
        }
} 

int main(int argc, char const *argv[]) {

    printf("Lesson 1\n");

    emptyStack('(');
    emptyStack('{');
    emptyStack(']');
    emptyStack(']');
    emptyStack('}');
    emptyStack(')');

    for (int i = 0; i < cursor + 1; ++i) { // для текущего ввода выводит "({})"
        printf("%c", Stack[i]);
    }
    printf("\n");

    printf("Lesson 2\n");

    OneLinkList *lst = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(lst);
    printOneLinkIntList(lst);
    insert(lst, 1);
    printOneLinkIntList(lst);
    insert(lst, 10);
    printOneLinkIntList(lst);
    insert(lst, 11);
    printOneLinkIntList(lst);
    insert(lst, 12);
    printOneLinkIntList(lst);


    OneLinkCopyList *cplst = (OneLinkCopyList*) malloc(sizeof(OneLinkCopyList));
    initOneLinkCopyList(cplst);
    copyList(lst, cplst);
    printOneLinkIntCopyList(cplst);

    printOneLinkIntList(lst);

    printf("Lesson 3\n");

    sortList(lst);

    return 0;
 }  