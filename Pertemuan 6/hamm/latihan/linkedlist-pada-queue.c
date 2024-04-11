/* Nama file  : linkedlist-pada-queue.c
Pembuat       : M. Ilham 23343008
Tgl pembuatan : 13 Maret 2024*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front, *rear;

void insert();
void hapus();
void display();

int main(){

    int choice;
    while(choice != 4){
        printf("\n====================Implement Queue Using Linked List====================\n");
        printf("\n===================================================================\n");
        printf("\n*****************************Main Menu*****************************\n");
        printf("\n===================================================================\n");
        printf("\n 1. Insert an element\n 2. Delete an element\n 3. Display the queue\n 4. Exit\n");
        printf("\nEnter your choice?");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            insert();
            break;
        case 2:
            hapus();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nEnter valid choice??\n");
        }
    }

    return 0;
}


void insert(){
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("\nOverflow\n");
    }
    else { // jika berhasil di alokasi
        printf("\nEnter value?\n"); // input nilai
        scanf("%d", &item);
        ptr->data = item;
        if(front == NULL){ // jika masih kosong
            front = ptr; // masukkan node baru ke front
            rear = ptr; // masukkan node baru ke rear
            front->next = NULL;
            rear->next = NULL;
        }
        else { // jika sudah ada data
            rear->next = ptr; // node paling akhir menunjuk node baru
            rear = ptr; // node terakhir adalah node baru
            rear->next = NULL; // next node baru null
        }
    }
}

void hapus(){
    struct node *ptr;
    if(front == NULL){
        printf("\nUnderflow\n");
        return;
    }
    else { // jika ada data
        ptr = front; // front dimasukkan ke ptr
        front = front->next; // front adalh elemen kedua
        free(ptr); // bebaskan memori elemen depan
    }
}

void display(){
    struct node *ptr;
    ptr = front;
    if(front == NULL){
        printf("\nEmpty queue\n");
    }
    else {
        printf("\nPrinting values...\n");
        while(ptr != NULL){
            printf("\n%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}