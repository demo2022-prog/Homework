#include <stdio.h>
#include <stdlib.h>

#define SIZE 256
#define STEP 3 // Шаг смещения
#define ABC 26 // Для крайних символов таблицы ASCII (циркулируем в рамках строчных символов)
#define NU '#' // Условный NULL

// Lesson 1
void CezarCipher (char* arr) { // Шифратор
    for(unsigned i = 0; i < SIZE; ++i) {
        if(arr[i] == 'x' || arr[i] == 'y' || arr[i] == 'z') { 
            arr[i] = arr[i] + STEP - ABC;
        } else if(arr[i] == 35 || arr[i] == 0) { // Игнорируем '0' и NULL
            arr[i] = NU;
        } else {
        arr[i] = arr[i] + STEP;
        }
    }
}

void CezarDecipher (char* arr) { // Дешифратор
    for(unsigned i = 0; i < SIZE; ++i) {
        if(arr[i] == 'a' || arr[i] == 'b' || arr[i] == 'c') { 
            arr[i] = arr[i] - STEP + ABC;
        } else if(arr[i] == NU) {
            arr[i] = NU;
        } else {
        arr[i] = arr[i] - STEP;
        }
    }
}

// Lesson 2

void arrCipher (char** arr, char* array, int row, int col) { // Создаем массив-шифр
    for (int i = 0; i < row; ++i) {
        if (i >= 1) {
            for (int j = 0; j < col; ++j) {
                *((*(arr + i)) + j) = array[j + (col * i)];
            }
    } else {
         for (int j = 0; j < col; ++j) {
                *((*(arr + i)) + j) = array[j];
            }
        }
    }
}

void permutationCipher (char** arr, char* array, int row, int col) { // Шифратор
    for (int i = 0; i < col; i++) {
        if (i >= 1) {
            for (int j = 0; j < row; ++j) {
                array[j + (row * i)] = *((*(arr + j)) + i);
            }
    } else {
         for (int j = 0; j < row; j++) {
                array[j] = *((*(arr + j)) + i);
            }
        }
    }
}

void permutationDecipher (char** arr, char* array, int row, int col) { // Дешифратор
    for (int i = 0; i < row; ++i) {
        if (i >= 1) {
            for (int j = 0; j < col; ++j) {
                array[j + (col * i)] = *((*(arr + i)) + j);
            }
    } else {
         for (int j = 0; j < col; ++j) {
                array[j] = *((*(arr + i)) + j);
            }
        }
    }
}

// Вспомогательные функции
 
char get2dInt(char** array, const int row, const int col) {
    return *((*(array + row)) + col);
}

void set2dInt(char** array, const int row, const int col, int value) {
    *((*(array + row)) + col) = value;
}

char** init2dIntArray(char** array, const int row, const int col) {
    array = (char**) calloc(sizeof(char*), row);
    for (int i = 0; i < row; ++i) {
        *(array + i) = (char*) calloc(sizeof(char), col);
    }
    return array;
}
    
void print2dIntArray(char** array, const int row, const int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%4c", *((*(array + i)) + j));
        }
        printf("\n");
    }
}

void fill2dIntArray(char** array, const int row, const int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            *((*(array + i)) + j) = NU;
        }
    }
}

void clearCharArray(char* arr, const int size) { //Заполняем массив "условными" NULL
    for (int i = 0; i < size; ++i) {
        arr[i] = NU;
    }
}

void printIntArray(char* arr, int size, int offset) {
    for (int i = 0; i < size; ++i) {
        if(arr[i] >= 97 && arr[i]<= 122) {
        printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void printCharArray(char* arr, int size, int offset) {
    for (int i = 0; i < size; ++i) {
        if(arr[i] != NU) {
            printf("%c", arr[i]);
        } 
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    char text[SIZE];
    int row, col = 0;
    clearCharArray(text, SIZE);
    printf("Enter the text: ");
    scanf("%s", text);
    printf("\n");
    printf("Enter the number of lines: ");
    scanf("%d", &row);
    printf("\n");
    printf("Enter the number of columns: ");
    scanf(" %d", &col);
    printf("\n");
// Lesson 1
 
    printCharArray(text, SIZE, 3);
    CezarCipher(text);
    printCharArray(text, SIZE, 3);
    CezarDecipher(text);
    printCharArray(text, SIZE, 3);
    printf("\n");

// Lesson 2
    
    char** textmulti = init2dIntArray(textmulti, row, col);
    fill2dIntArray(textmulti, row, col);
    print2dIntArray(textmulti, row, col);
    printf("\n");
    arrCipher(textmulti, text, row, col);
    print2dIntArray(textmulti, row, col);
    printf("\n");
    permutationCipher(textmulti, text, row, col);
    printCharArray(text, SIZE, 3);
    printf("\n");
    permutationDecipher(textmulti, text, row, col);
    printCharArray(text, SIZE, 3);
    printf("\n");
    free(textmulti);


    return 0;
}
