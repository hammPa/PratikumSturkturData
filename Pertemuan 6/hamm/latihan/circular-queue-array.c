/* Nama file  : circular-queue-array.c
Pembuat       : M. Ilham 23343008
Tgl pembuatan : 13 Maret 2024*/

#include <stdio.h>

#define max 6
int queue[max];
int front = -1;
int rear = -1;

void enqueue(int element){
    if(front == -1 && rear == -1){ // jika queue kosong
        front = 0; // ubah ke 0
        rear = 0;
        queue[rear] = element; // masukkan data ke rear
    }
    else if( (rear+1)%max == front ){ // jika queue penuh, kan batasnya 6, jika 5+1 % 6 == 0(si front)
        printf("Queue is overflow"); // penuh
    }
    else { // selain kosong dan penuh
        rear = (rear + 1) % max; // misal rear awal 2, maka jdi : (2 + 1) % 6 = 3, intinya increment
        queue[rear] = element; // pakai %max agar kembali ke0 saat sudah max
    }
}

void dequeue(){
    if(front == -1 && rear == -1){ // jika data kosong
        printf("\nQueue is undeflow.."); // tampilkan kosong
    }
    else if(front == rear){ // jika ukuran front dan rear sama
        printf("\nThe dequeued element is %d", queue[front]); // tampilkan value
        front = -1; // ubah jadi kosong
        rear = -1;
    }
    else { // selain kosong dan sama
        printf("\nThe dequeued element is %d", queue[front]); // tampilkam elemen
        front = (front+1) % max; // increment si front
    }
}

void display(){
    int i = front;
    if(front == -1 && rear == -1){
        printf("\nQueue is empty..");
    }
    else {
        printf("\nElements in a Queue are : ");
        while(i <= rear){
            printf("%d ", queue[i]);
            i = (i + 1) % max;
        }
    }
}

int main(){

    int choice = 1, x;
    while(choice < 4 && choice != 0){
        printf("\n====================Implement pf circular queue using Array====================\n");
        printf("\n===================================================================\n");
        printf("\n*****************************Main Menu*****************************\n");
        printf("\n===================================================================\n");
        printf("\nPress 1 : Insert an element");
        printf("\nPress 2 : Delete an element");
        printf("\nPress 3 : Display the queue");
        printf("\nEnter your choice?");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            printf("Enter the element which is to be inserted : ");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
        display();
            break;
        }
    }

    return 0;
}
