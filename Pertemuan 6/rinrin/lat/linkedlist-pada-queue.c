/* Nama file : implementasi linked list pada queue
   Pembuat   : Rindhiani Putri
   Tanggal pembuatan : 13 Maret 2024
*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *front;
struct node *rear;
void insert();
void hapus();
void display();

int main() {
    int choice;
    while (choice != 4)
    {
        printf("\n=========Implement Queue Using Linked List=========\n");
        printf("\n=============================================\n");
        printf("\n***********Main Menu***********");
        printf("\n=============================================\n");
        printf("\n1.Insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");
        printf("Enter your choice?");
        scanf("%d",&choice);
        switch (choice)
        {
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
}

void insert() {
    struct node *ptr;
    int item;

    ptr = (struct node *) malloc (sizeof(struct node));
    if(ptr==NULL) {
        printf("\nOVERFLOW");
        return;
    }
    else {
        printf("\nEnter value\n");
        scanf("%d",&item);
        ptr -> data = item;
        if (front == NULL) {
            front = ptr;
            rear = ptr;
            front -> next = NULL;
            rear -> next = NULL;
        }
        else {
            rear -> next = ptr;
            rear = ptr;
            rear ->next = NULL;
        }
    }
}   
   
void hapus() {
    struct node *ptr;
    if (front == NULL) {
        printf("\nUNDERFLOW");
        return;
    }
    else {
        ptr = front;
        front = front -> next;
        free(ptr);
    }
}

void display() {
    struct node *ptr;
    ptr = front;
    if (front=NULL) {
        printf("\nEmpty Queue\n");
    }
    else {
        printf("\nprinting values.....\n");
        while (ptr != NULL)
        {
            printf("\n%d\n",ptr -> data);
            ptr = ptr -> next;
        } 
    }     
}
