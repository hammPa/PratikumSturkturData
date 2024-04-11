/* Nama file  : deque.c
Pembuat       : M. Ilham 23343008
Tgl pembuatan : 13 Maret 2024*/

#include <stdio.h>

#define size 5
int deque[size];
int f = -1, r = -1;

void insert_front(int x){
    if( (f == -1 && r == -1) || (f == r + 1)){  // jika front atau rear belum diisi atau front melebihi rear
        printf("Overflow"); // data penuh
    }
    else if( (f == -1) && (r == -1) ){ // jika front dan rear sama sama kosong
        f = r = 0; // ubah index data menjadi 0
        deque[f] = x; // masukkan data ke array front
    }
    else if( f == 0){ // jika frontnya 0, berarti suadh ada 1 data
        f = size - 1; // front di tetapkan 4 
        deque[f] = x; // input data di index ke 4
    }
    else { // selain ketiga diatas, ukuran f adalah f dikurang 1
        f = f -1; // decrement
        deque[f] = x;
    }
}

void insert_rear(int x){
    if( (f == -1 && r == -1) || (f == r + 1)){  // jika data penuh
        printf("Overflow");
    }
    else if( (f == -1) && (r == -1) ){ // jika data kosong
        r = 0;
        deque[r] = x; // masukkan di rear
    }
    else if( f == 0){ // jika data sudah ada 1
        r = 0;
        deque[r] = x; // masukkan ke data rear
    }
    else { // selain ketiga di atas, ukurannya increment
        r++; 
        deque[r] = x;
    }
}

void display(){
    int i = f;
    printf("\nElements in a Queue are : ");
    while(i != r){
        printf("%d", deque[i]);
        i = (i + 1) % size;
    }
    printf("%d ", deque[r]);
}

void getFront(){
    if(f == -1 && r == -1){
        printf("Deque is empty");
    }
    else {
        printf("\nThe value of the element at front is %d", deque[f]);
    }
}

void getRear(){
    if(f == -1 && r == -1){
        printf("Deque is empty");
    }
    else {
        printf("\nThe value of the element at rear is %d", deque[r]);
    }
}

void delete_front(){
    if(f == -1 && r == -1){
        printf("Deque is empty");
    }
    else if(f == r){
        printf("\nThe deleted element is %d", deque[f]);
        f = -1;
        r = -1;
    }
    else if(f == (size - 1)){
        printf("\nThe deleted element is %d", deque[f]);
        f = 0;
    }
    else {
        printf("\nThe deleted element is %d", deque[f]);
        f = f + 1;
    }
}

void delete_rear(){
    if(f == -1 && r == -1){
        printf("Deque is empty");
    }
    else if(f == r){
        printf("\nThe deleted element is %d", deque[r]);
        f = -1;
        r = -1;
    }
    else if(r == 0){
        printf("\nThe deleted element is %d", deque[r]);
        r = size - 1;
    }
    else {
        printf("\nThe deleted element is %d", deque[r]);
        f = f - 1;
    }
}

int main(){

    printf("\n====================Implement Deque====================\n");
    printf("\n=======================================================\n");
    insert_front(20);
    insert_front(10);
    insert_rear(30);
    insert_rear(50);
    insert_rear(80);
    display();
    getFront();
    getRear();
    delete_front();
    delete_rear();
    display();

    return 0;
}