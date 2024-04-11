/* Nama file  : array-pada-queue.c
Pembuat       : M. Ilham 23343008
Tgl pembuatan : 13 Maret 2024*/

#include <stdio.h>
#include <stdlib.h>
#define maxsize 5 

void insert();
void hapus();
void display();

int front = -1, rear = -1;
int queue[maxsize];

int main(){

    int choice;
    while(choice != 4){
        printf("\n====================Implement Queue Using Array====================\n");
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
    int item;
    printf("\nEnter the element\n");
    scanf("\n%d", &item); // input
    if(rear == maxsize - 1){ // jika ukuran dibelakang(untuk insert) sama dengan maks array (penuh)
        printf("\nOverflow\n");
        return;
    }
    // jika tidak penuh
    if(front == -1 && rear == -1){ // jika masih kosong
        front = 0; // ubah index jdi 0
        rear = 0;
    }
    else {
        rear++; // jika sudah ada isi, increment rear (untuk insert)
    }
    queue[rear] = item; // masukkan nilai ke queue paling belakang
    printf("\nValue inserted ");
}

void hapus(){
    int item;
    if(front == -1 || front > rear){ // jika front -1 atau front besar daripada rear
        printf("\nUnderflow\n"); // queue kosong
        return;
    }
    else { // jika tidak
        item = queue[front]; // masukkan value ke var lokal item
        if(front == rear){ // jika ukuran depan dan belakang sama, berarti nanti jadinya 0 == 0
            front = -1; // kembalikan ke -1
            rear = -1;
        }
        else { // jika front dan end tidak sama
            front++; // front increment, jadinya elemen sebelumnya tidak bisa diakses lagi
        }
        printf("\nValue deleted ");
    }
}

void display(){
    int i;
    if(rear == -1){ // jika rear = -1 berarti kosong
        printf("\nEmpty Queue\n");
    }
    else { // selain kosong
        printf("\nPrinting values...");
        for(i = front; i <= rear; i++){ // tampilkan semua nilai
            printf("\n%d\n", queue[i]);
        }
    }
}