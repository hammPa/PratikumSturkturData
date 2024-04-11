#include <stdio.h>
#include <stdlib.h>
#define MAXCHAR 30
struct Album {
    int no;
    char title[MAXCHAR];
    char time[MAXCHAR];
    struct Album *next;
    struct Album *prev;
};

struct Album *head, *tail, *newNode, *curr, *del;

struct Album* input(){
    struct Album *newNode = (struct Album*)malloc(sizeof(struct Album));
    printf("Masukkan nomor album : ");
    scanf("%d", &newNode->no);
    getchar();
    printf("Masukkan judul album : ");
    fgets(&newNode->title, MAXCHAR, stdin);
    printf("Masukkan waktu album : ");
    fgets(&newNode->time, MAXCHAR, stdin);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insert_begin(){    
    if(head == NULL){
        head = input();
        tail = head;
    }
    else {
        newNode = input();
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }
}

void insert_last(){    
    if(head == NULL){
        head = input();
        tail = head;
    }
    else {
        newNode = input();
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        tail->next = newNode;
        tail = newNode;
    }
}

void display(){
    if(head == NULL) printf("Album Masih Kosong\n");
    else {
        curr = head;
        do {
            printf("No    : %d\n", curr->no);
            printf("Title : %s\n", curr->title);
            printf("Time  : %s\n\n", curr->time);
            curr = curr->next;
        } while(curr != head);
    }
}

void delete_begin(){
    if(head == NULL) printf("Album masih kosong\n");
    else {
        del = head;
        curr = head->next;
        curr->prev = tail;
        tail->next = curr;
        free(del);
    }
}

void delete_last(){
    if(head == NULL) printf("Album masih kosong\n");
    else {
        del = tail;
        curr = tail->prev;
        curr->next = head;
        head->prev = curr;
        free(del);
    }
}

void deleteMemory(){
    curr = tail;
    while(curr != NULL){
        if(curr !=  head){ // selama bukan head
            curr = curr->prev; // mundur
            free(curr->next); // nextnya bebaskan
        }
        else { // jika head
            free(curr->next); // nextnya bebaskan
            free(curr); // headnya juga
        }
    }
}

int main(){

    insert_last();
    insert_last();
    insert_last();
    insert_begin();
    insert_begin();
    display();

    delete_begin();
    delete_last();
    delete_last();
    display();

    deleteMemory();

    return 0;
}