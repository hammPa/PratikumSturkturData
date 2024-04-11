/* Nama file  : Doubly Linked List 
Pembuat       : M. Ilham 23343008
Tgl pembuatan : 26 February 2024*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    struct node *next;
    int data;
};

struct node *head;

void insertion_beginning();
void insertion_last();
void insertion_specified();
void deletion_beginning();
void deletion_last();
void deletion_specified();
void display();
void search();

int main(){

    int choice = 0;
    while(choice != 9){
        printf("\n*********Doubly Linked List*********\n");
        printf("\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list...\n");
        printf("\n==================================================\n");
    
        printf("\n1. Insert in beginning\n 2. Insert at last\n 3. Insert at any random location\n 4. Delete from Beginning\n 5. Delete from last\n 6. Delete the node after the given data\n 7. Search\n 8. Show\n 9. Exit\n");
        printf("\nEnter your choice\n");
        scanf("\n%d", &choice);
        switch(choice){
            case 1:
                insertion_beginning();
                break;
            case 2:
                insertion_last();
                break;
            case 3:
                insertion_specified();
                break;
            case 4:
                deletion_beginning();
                break;
            case 5:
                deletion_last();
                break;
            case 6:
                deletion_specified();
                break;
            case 7:
                search();
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Please enter valid choice");
        }
    }
    
    return 0;
}

void insertion_beginning(){
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL){ 
        printf("\nOverflow");
    }
    else { // jika bukan null
        printf("\nEnter item value");
        scanf("%d", &item); // masukkan data
        if(head == NULL){ // jika data masih belum ada
            ptr->next = NULL; // next jadi null
            ptr->prev = NULL; // prev jadi null
            ptr->data = item; // data di isi dengan item
            head = ptr; // head adalah ptr
        }
        else { // jika data sudah ada
            ptr->data = item; // data di isi dengan item
            ptr->prev = NULL; // prev nya jadi null
            ptr->next = head; // nextnya head
            head = ptr; // head di ubah ke yang baru
        }
        printf("\nNode inserted\n");
    }
}

void insertion_last(){
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("\nOverflow");
    }
    else { // jika bukan null
        printf("Enter value : ");
        scanf("%d", &item); // masukkan data
        ptr->data = item; // data dimasukkan  ke ptr item
        if(head==NULL){ // jika data masih kosong
            ptr->next = NULL; // next dan
            ptr->prev = NULL; // prev nya null
            head = ptr; // head di isi dengan ptr
        }
        else { // jika data bukan kosong
            temp = head; // head dimasukkan ke variabel sementara
            while(temp->next != NULL){ // selama node selanjutnya bukan null
                temp = temp->next; // geser node
            }
            temp->next = ptr; // jika nextnya sudah null, berarti sudah node terakhir, maka nextnya di buat menunjuk node baru
            ptr->prev = temp; // node baru, prev nya menunjuk node sebelumnya
            ptr->next = NULL; // node baru, nextnya null
        }
    }
    printf("\nNode inserted\n");
}

void insertion_specified(){
    struct node *ptr, *temp;
    int item, loc, i;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("\nOverflow");
    }
    else {
        temp = head; // temp adalah node pertama
        printf("Enter the location : ");
        scanf("%d", &loc); // masukkan lokasi
        for(i = 0; i < loc; i++){ // selama i kurang dari lokasi
            temp = temp->next; // geser node temp ke node selanjutnya
            if(temp == NULL){ // jika node yang sudah digeser adalah null
                printf("\nThere are less than %d elements", loc); // kembalikan elemen kurang dari data yang dimasukkan
                return; // program berhenti
            }
            printf("Enter value : "); // jika bukan null
            scanf("%d", &item); // input data
            ptr->data = item; 
            ptr->next = temp->next; // node baru, nextnya menunjuk ke next dari node dengan lokasi yang ditentukan(temp)
            ptr->prev = temp; // prev node baru menunjuk ke node temp
            temp->next = ptr; // next dari temp adalah node baru
            temp->next->prev = ptr; // next dari temp, adalah ptr,,,, nahh prev dari ptr alias node baru adalah ptr->prev, diisi dengan ptr
            printf("\nNode inserted\n");
        }
    }
}

void deletion_beginning(){
    struct node *ptr;
    if(head == NULL){
        printf("\nUnderflow");
    }
    else if(head->next == NULL) { // jika node selanjutnya adalah null, berarti data hanya ada 1
        head = NULL; // head diubah ke null
        free(head); // bebaskan memori head
        printf("\nNode deleted\n");
    }
    else { // jika node > 1
        ptr = head; // head dimasukkan ke ptr
        head->prev = NULL; // node sebelumnya dari head di atur ke null
        head = head->next; // head sekarang adalh node kedua
        free(ptr); // bebskan memori pertama
        printf("\nNode deleted\n");
    }
}

void deletion_last(){
    struct node *ptr;
    if(head == NULL){
        printf("\nUnderflow");
    }
    else if(head->next == NULL) { // jika node selanjutnya dari head adalah null, alias hanya ada 1 data
        head = NULL; // hapus node itu
        free(head);
        printf("\nNode deleted\n");
    }
    else { // jika lebih dari 1 data
        ptr = head; // head dimasukkan ke ptr
        if(ptr->next != NULL){ // jika node kedua bukan null
            ptr = ptr->next; // geser ke node kedua
        }
        ptr->prev->next = NULL; // previous dari node kedua adalah node pertama, nextnya dari node pertama adalah node kedua, diisi dengan null
        free(ptr); // bebaskan node kedua
        printf("\nNode deleted\n");
    }

}

void deletion_specified(){
    struct node *ptr, *temp;
    int val;
    printf("\nEnter the data after which the node is to be deleated : ");
    scanf("%d", &val); // masukkan data yanng ingin di hapus
    ptr = head; // head dimasukkan ke ptr
    while(ptr->next != val) ptr = ptr->next; // selama node selanjutnya bukan val, geser node
    if(ptr->next == NULL){ // jika next adalah null, tidak bisa dihapuus
        printf("\nCan't delete\n");
    }
    else if(ptr->next->next == NULL){ // jika next nextnya adalah null
        ptr->next = NULL; // hapus next
    }
    else { // selain itu
        temp = ptr->next; // temp digeser ke node selanjutnya
        ptr->next = temp->next; // next ptr menunjuk next temp
        temp->next->prev = ptr; // next temp prev, temp itu sendiri, diisi dengan ptr
        free(temp);
        printf("\nNode deleted\n");
    }
}

void display(){
    struct node *ptr;
    printf("\nprinting values...\n");
    ptr = head; // ptr adalah head
    while(ptr != NULL){ // selama ptr bukan null
        printf("%d\n", ptr->data); // print data
        ptr = ptr->next;
    }
}

void search(){
    struct node *ptr;
    int item, i = 0, flag;
    ptr = head; // masukkan head ke ptr
    if(ptr == NULL){ // jika ptr null, tidak ada data
        printf("\nEmpty List\n");
    }
    else { // jika ada data
        printf("\nEnter item which you want to search?\n");
        scanf("%d", &item); // masukkan data yang ingin dicari
        while(ptr != NULL){ // selama ptr bukan null
            if(ptr->data == item){ // jika data tersimpan sama dengan yang di input
                printf("\nitem found at location %d", i+1); // munculkan dimana lokasi ditemukan
                flag = 0;
                break;
            }
            else { // jika tidak ada yang sama, atur flag jdi 1
                flag = 1;
            }
            i++; 
            ptr = ptr->next;
        }
        if(flag == 1){
            printf("\nItem not found\n");
        }
    }
}