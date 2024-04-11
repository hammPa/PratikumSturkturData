/* Nama file : implementasi circular queue menggunakan array
   Pembuat   : Rindhiani Putri
   Tanggal pembuatan : 13 Maret 2024
*/
#include<stdio.h>
#define max 6

int queue[max]; 
int front = -1;
int rear = -1;

void enqueue(int element) {
    if(front== -1 && rear== -1) {
        front=0;
        rear=0;
        queue[rear]= element;
    }
    else if ((rear+1)%max==front) {
        printf("Queue is overflow...");
    }
    else {
        rear=(rear+1)%max;
        queue[rear]=element;
    }
}

int dequeue() {
    if(front== -1 && rear== -1) {
        printf("\nQueue is underflow...");
        return -1;
    }
    else if(front==rear) {
        printf("\nThe dequeued is %d", queue[front]);
        front=-1;
        rear=-1;
        return queue[front];
    }
    else {
        printf("\nThe dequeued element is %d", queue[front]);
        int x = queue[front];
        front=(front+1) %max;
        return x;
    }
}

void display() {
    int i= front;
    if(front==-1 && rear==-1) {
        printf("\nQueue is empty..");
    }
    else {
        printf("\nElements in queue are : ");
        while (i<= rear)
        {
            printf("%d",queue[i]);
            i=(i+1)%max;
        }      
    }
}

int main() {
    int choice=1,x;
    
    while(choice!=0) {
        printf("\n========Implementation of circular queue using Array======\n");
        printf("\n============================================================");
        printf("\n**********Main Menu**********\n");
        printf("\n============================================================");
        printf("\nPress 1: Insert an element");
        printf("\nPress 2: Delete an element");
        printf("\nPress 3: Display the element");
        printf("\nEnter your choice");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element which is to be inserted");
            scanf("%d",&x);
            enqueue(x);
            break;
        
        case 2:
            dequeue();
            break;
        
        case 3:
            display();
            break;
        
        case 0:
            printf("\nExiting the program...");
            break;
        
        default:
            printf("\nInvalid choice...");
            break;
        }
    }
    return 0;
}