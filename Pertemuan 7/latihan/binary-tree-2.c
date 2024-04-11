/* Nama file  : binary-tree-2.c 
Pembuat       : M. Ilham
Tgl pembuatan : 11 Maret 2024 */

#include <stdio.h>
#include <stdlib.h>

struct data {
    int number;
    struct data *left, *right;
} *root;

void push(struct data **current, int number){
    if((*current) == NULL){
        (*current) = (struct data *)malloc(sizeof(struct data));
        (*current)->number = number;
        (*current)->left = (*current)->right = NULL;
    }
    else if(number < (*current)->number){
        push(&(*current)->left, number);
    }
    else if(number >= (*current)->number){
        push(&(*current)->right, number);
    }
}

void inOrder(struct data **current){
    if((*current) != NULL){
        inOrder(&(*current)->left);
        printf("%d -> ", (*current)->number);
        inOrder(&(*current)->right);
    }
}

void preOrder(struct data **current){
    if((*current) != NULL){
        printf("%d -> ", (*current)->number);
        preOrder(&(*current)->left);
        preOrder(&(*current)->right);
    }
}

void postOrder(struct data **current){
    if((*current) != NULL){
        postOrder(&(*current)->left);
        postOrder(&(*current)->right);
        printf("%d -> ", (*current)->number);
    }
}

void search(struct data **current, int number){
    if((*current) != NULL){
        if(number < (*current)->number){
            search(&(*current)->left, number);
        }
        else if(number > (*current)->number){
            search(&(*current)->right, number);
        }
        else {
            printf("Found : %d", (*current)->number);
        }
    }
    else {
        printf("Not Found.");
    }
}

int main(){

    push(&root, 11);
    push(&root, 22);
    push(&root, 13);
    push(&root, 15);
    push(&root, 9);
    inOrder(&root);
    printf("\n");
    preOrder(&root);
    printf("\n");
    postOrder(&root);
    printf("\n");
    search(&root, 91);
    getchar();

    return 0;
}