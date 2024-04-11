/* Nama file : implementasi array pada queue
   Pembuat   : Rindhiani Putri
   Tanggal pembuatan : 13 Maret 2024
*/

#include<stdio.h>
#include<stdlib.h>
#define maxsize 5

void insert();
void hapus();
void display();
int front = -1, rear = -1;
int queue[maxsize];
int main() {
    int choice;
    while (choice != 4)
    {
        printf("\n=========Implement Queue Using Array=========\n");
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
    int item;
    printf("\nEnter the element");
    scanf("\n%d",&item);
    if(rear== maxsize-1) {
        printf("\nOVERFLOW");
        return;
    }
    if(front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    }
    else {
        rear = rear+1;
    }
    queue[rear] = item;
    printf("\nValue Inserted");
}

void hapus() {
    int item;
    if(front == -1 || front > rear) {
        printf ("\nUNDERFLOW");
        return;
    }
    else {
        item = queue[front];
        if(front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = front + 1;
        }
        printf("\nValue deleted");
    }
}

void display() {
    int i;
    if(rear == -1) {
        printf("\nEmpty queue");
    }
    else {
        printf("\nPrinting values...\n");
        for(i=front;i<=rear; i++) 
        {
            printf("\n%d\n",queue[i]);
        }
    }
}
