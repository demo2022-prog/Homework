#include <stdio.h>
#include <stdlib.h>
//#include "geek.h"

#define true 1 == 1
#define false 1 != 1
typedef int boolean;
#define SZ 10
#define TREE 50 // Задаем кол-во деревьев
#define SIZE 10000 // Задаем кол-во елементов в дереве

FILE *file;

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} TreeNode;

TreeNode* balancedTree(int n) {
    TreeNode *newNode;
    int x;
    int nL;
    int nR;

    if(n == 0) {
        return NULL;
    } else {
        fscanf(file, "%d", &x);
        nL = n / 2;
        nR = n - nL - 1;
        newNode = (TreeNode*) malloc(sizeof(TreeNode));
        newNode->key = x;
        newNode->left = balancedTree(nL);
        newNode->right = balancedTree(nR);
    }
    return newNode;
}

TreeNode* treeInsert(TreeNode *t, int data) {
    TreeNode *newNode;
    newNode = (TreeNode*) malloc(sizeof(TreeNode));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    TreeNode *current = t;
    TreeNode *parent = t;
    if(t == NULL) {
        t = newNode;
    } else {
        while(current->key != data) {
            parent = current;
            if(current->key > data) {
                current = current->left;
                if(current == NULL) {
                    parent->left = newNode;
                    return t;
                }
            } else {
                current = current->right;
                if(current == NULL) {
                    parent->right = newNode;
                    return t;
                }
            }
        }
    }
    return t;
}

void fillIntRandom(int* array, int size, int border) {
    for (int i = 0; i < size; ++i)
        *(array + i) = rand() % border;
}

void printIntArray(int* array, int size, int offset) {
    char format[7];
    sprintf(format, "%%%dd", offset);
    for (int i = 0; i < size; ++i) {
        printf(format, array[i]);
        if (i != size - 1)
            printf(",");
    }
    printf("\n");
}

void printTree(TreeNode *root) {
    if(root) {
        printf("%d", root->key);
        if (root->left || root->right) {
            printf("(");
            if(root->left) {
                printTree(root->left);
            } else {
                printf("NULL");
            }
            printf(",");
            if(root->right) {
                printTree(root->right);
            } else {
                printf("NULL");
            }
            printf(")");
        }
    }
}

TreeNode* getSuccessor(TreeNode *node) {
    TreeNode *current = node->right;
    TreeNode *parent = node;
    TreeNode *s = node;

    while(current != NULL) {
        parent = s;
        s = current;
        current = current->left;
    }
    if(s != node->right) {
        parent->left = s->right;
        s->right = node->right;
    }
    return s;
}

boolean rmTree(TreeNode *root, int key) {
    TreeNode *current = root;
    TreeNode *parent = root;
    boolean isLeftChild = true;

    while (current->key != key) {
        parent = current;
        if (key < current->key) {
            current = current->left;
            isLeftChild = true;
        } else {
            current = current->right;
            isLeftChild = false;
        }
        if (current == NULL)
            return false;
    }

    if (current->left == NULL && current->right == NULL) {
        if (current == root)
            root = NULL;
        else if (isLeftChild)
            parent->left = NULL;
        else
            parent->right = NULL;
    }
    else if (current->right == NULL) {
        if (isLeftChild)
            parent->left = current->left;
        else
            parent->right = current->left;
    }
    else if (current->left == NULL) {
        if (isLeftChild)
            parent->left = current->right;
        else
            parent->right = current->right;
    }
    else {
        TreeNode *successor = getSuccessor(current);
        if (current == root)
            root = successor;
        else if (isLeftChild)
            parent->left = successor;
        else
            parent->right = successor;
        successor->left = current->left;
    }
    return true;
}

void preOrderTravers(TreeNode *root) {
    if(root) {
        printf("%d ", root->key);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}

void inOrderTravers(TreeNode *root) {
    if(root) {
        inOrderTravers(root->left);
        printf("%2d ", root->key);
        inOrderTravers(root->right);
    }
}

boolean isBalansed(TreeNode *root) { // Функция проверки на сбалансированность (крайне кривая но я пытался)
    int left = 0;
    int right = 0;
    TreeNode *current = root;
    while (root) { // Бежим влево
        root = root->left;
        left++; // Счетчик левых узлов
    }
    root = current;
    while (root) { // Бежим вправо
        root = root->right;
        right++; // Счетчик правых узлов
    }
    printf("left =%d\n", left);
    printf("right =%d\n", right);
    if((left - right) == 1 || (right - left) == 1 || (left == right)) { // Сравниваем левую и правую часть на сбалансированность
        printf("Tree is balansed. \n");
        return 1;
    } else {
        printf("Tree is not balansed. \n");
        return -1;
    }
}

void postOrderTravers(TreeNode *root) {
    if(root) {
        postOrderTravers(root->left);
        postOrderTravers(root->right);
        printf("%2d ", root->key);
    }
}

boolean binSearch(TreeNode *root, int value) {
    if(root == NULL) {
        return false;
    }
    if (root->key == value) {
        return true;
    }

    TreeNode *current = root;
    while(current->key != value) {
        if(value < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
        if(current == NULL) {
            return false;
        }
    }
}

boolean binSearchRec(TreeNode *root, int value) {
    if(root == NULL) {
        return false;
    }
    if (root->key == value) {
        return true;
    }

    //TreeNode *current = root;
    if(value < root->key) {
        binSearchRec(root->left, value);
    } else {
        binSearchRec(root->right, value);
    }
}

void buildTree(int* arr, int new, int size) {
    int maxIdx = new;
    int newElem = arr[new];
    while(true) {
        int child = new * 2 + 1;
        if((child < size) && (arr[child] > newElem)) {
            maxIdx = child;
        }
        child = new * 2 + 2;
        if((child < size) && (arr[child] > arr[maxIdx])) {
            maxIdx = child;
        }
        if(maxIdx == new) {
            break;
        }
        arr[new] = arr[maxIdx];
        arr[maxIdx] = newElem;
        new = maxIdx;
    }
}

void heapSort(int* arr, int size) {
    for (int i = size / 2 - 1; i >= 0; --i) {
        buildTree(arr, i, size);
    }
    while(size > 1) {
        --size;
        int firstElem = arr[0];
        arr[0] = arr[size];
        arr[size] = firstElem;
        buildTree(arr, 0, size);
    }
}

void treeTest () {
TreeNode *tree = treeInsert(tree, 10);
treeInsert(tree, 8);
treeInsert(tree, 19);
treeInsert(tree, 5);
treeInsert(tree, 9);
treeInsert(tree, 16);
treeInsert(tree, 21);
printTree(tree);
printf("\n");
isBalansed(tree);

//printf("8 in search = %s\n", binSearch(tree, 8) ? "true" : "false");
//printf("100 in search = %s\n", binSearch(tree, 100) ? "true" : "false");
//preOrderTravers(tree);
//printf("\n");
//inOrderTravers(tree);
//printf("\n");
//postOrderTravers(tree);
//printf("\n");
//
//    int arr[SZ];
//    fillIntRandom(arr, SZ, 100);
//    printIntArray(arr, SZ, 3);
//    heapSort(arr, SZ);
//    printIntArray(arr, SZ, 3);
}

int main(int argc, char const *argv[]) {
    int push;
    for(unsigned i = 0; i < TREE; ++i) {
        push = 1 + rand()%SIZE;
        TreeNode *tree = treeInsert(tree, push);
        for(unsigned j = 0; j < SIZE; ++j) {
            push = 1 + rand()%SIZE;
            treeInsert(tree, push);
            }
        printTree(tree);
        isBalansed(tree);
        printf("101 in search = %s\n", binSearchRec(tree, 101) ? "true" : "false");
        printf("100 in search = %s\n", binSearchRec(tree, 100) ? "true" : "false");
        printf("\n");
    }

    return 0;
}
