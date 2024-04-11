/* Nama File: Tugas 4
   Pembuat : Rindhiani Putri (23343017)
   Tanggal Pembuatan: 4 Maret 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void push(Stack *stack, char c) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->data[++stack->top] = c;
}

char pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isPalindrome(char *str) {
    Stack stack;
    stack.top = -1;
    int i, j;
    for (i = 0; str[i]; i++) {
        if (isalpha(str[i])) {
            push(&stack, tolower(str[i]));
        }
    }
    for (j = 0; str[j]; j++) {
        if (isalpha(str[j])) {
            if (tolower(str[j]) != pop(&stack)) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    char sentence[MAX_SIZE];
    printf("Masukkan kalimat: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    
    sentence[strcspn(sentence, "\n")] = '\0';

    if (isPalindrome(sentence)) {
        printf("Kalimat tersebut adalah palindrom.\n");
    } else {
        printf("Kalimat tersebut bukan palindrom.\n");
    }

    return 0;
}
