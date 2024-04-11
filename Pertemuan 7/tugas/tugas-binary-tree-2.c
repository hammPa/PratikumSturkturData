/* Nama file  : tugas-binary-tree-2.c 
Pembuat       : M. Ilham
Tgl pembuatan : 14 Maret 2024 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *left, *right;
};


void createBinaryTree(struct Node **temp){
    *temp = NULL;
}

void addNode(struct Node **temp, char value){
    *temp = (struct Node *)malloc(sizeof(struct Node));
    (*temp)->data = value;
    (*temp)->left = (*temp)->right = NULL;
}

void preOrder(struct Node **target){
    if((*target) != NULL){
        printf("%c -> ", (*target)->data);
        preOrder(&(*target)->left);
        preOrder(&(*target)->right);
    }
}

void inOrder(struct Node **target){
    if((*target) != NULL){
        inOrder(&(*target)->left);
        printf("%c -> ", (*target)->data);
        inOrder(&(*target)->right);
    }
}

void postOrder(struct Node **target){
    if((*target) != NULL){
        postOrder(&(*target)->left);
        postOrder(&(*target)->right);
        printf("%c -> ", (*target)->data);
    }
}

int main(){

    struct Node *root;   
    createBinaryTree(&root);

    addNode(&root, 'R');
    addNode(&root->left, 'A');
    addNode(&root->left->left, 'S');
    addNode(&root->left->left->left, 'I');
    addNode(&root->left->left->right, 'T');
    addNode(&root->right, 'E');

    printf("Pre Order : ");
    preOrder(&root);
    printf("\n");
    printf("In Order : ");
    inOrder(&root);
    printf("\n");
    printf("Post Order : ");
    postOrder(&root);
    printf("\n");


    return 0;
}
