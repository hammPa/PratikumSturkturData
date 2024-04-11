/* Nama file  : struct-album 
Pembuat       : M. Ilham 23343008
Tgl pembuatan : 26 February 2024*/

#include <stdio.h>
#include <stdlib.h>

#define MAXCHAR 30

struct Node {
    int albumNum;
    char albumName[MAXCHAR];
    char date[MAXCHAR];
    struct Node *next;
};

struct Node *head;
struct Node* input();
void unshift();
void pop();
void push();
void shift();
void display();


int main(){


    int choice;


    while(choice != 6){

        printf("\n*********Circular Doubly Linked List*********\n");
        printf("\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list...\n");
        printf("\n==================================================\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at last\n");
        printf("3. Delete at beginning\n");
        printf("4. Delete at last\n");
        printf("5. Display All\n");
        printf("6. Exit\n");
        printf("Number of option : ");
        scanf("%d", &choice);
        getchar();

        switch (choice){
            case 1:
            unshift();
        break;
            case 2:
            push();
        break;
            case 3:
            shift();
        break;
            case 4:
            pop();
        break;
            case 5:
            display();
        break;
            case 6:
            exit(0);
        break;
        default: printf("Your choice isn't valid");
        }
    }

    return 0;
}

struct Node* input(){
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Masukkan nomor album : ");
    scanf("%d", &newNode->albumNum);
    getchar();
    printf("Masukkan nama album : ");
    fgets(&newNode->albumName, sizeof(newNode->albumName), stdin);
    printf("Masukkan tanggal album : ");
    fgets(&newNode->date, sizeof(newNode->date), stdin);
    newNode->next = NULL;
    return newNode;
}

void unshift(){
    struct Node *newNode;
    if(head == NULL) head = input();
    else {
        newNode = input();
        newNode->next = head;
        head = newNode;
    }
}

void push(){
    struct Node *newNode, *temp;
    if(head == NULL) head = input();
    else {
        newNode = input();
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void shift(){
    struct Node *del;
    if(head == NULL) printf("Lagu masih kosong\n");
    else {
        del = head;
        head = head->next;
        free(del);
        printf("Lagu paling awal berhasil di hapus!");
    }
}

void pop(){
    struct Node *del, *prevDel;
    if(head == NULL) printf("Lagu masih kosong\n");
    else {
        del = head;
        while(del->next != NULL) {
            prevDel = del;
            del = del->next;
        }
        prevDel->next = NULL;
        free(del);
    }
}

void display(){
    struct Node *temp;
    temp = head;
    if(temp == NULL) printf("Album masih kosong!!\n");
    else {
        while(temp != NULL){
            printf("No   : %d\n", temp->albumNum);
            printf("Name : %s", temp->albumName);
            printf("Date : %s\n\n", temp->date);
            temp = temp->next;
        }
    }
}
