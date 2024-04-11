/* Nama file  : Singly Linked List 
Pembuat       : M. Ilham 23343008
Tgl pembuatan : 26 February 2024*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head;

void beginInsert();
void lastInsert();
void randomInsert();
void begin_delete();
void last_delete();
void random_delete();
void search();
void display();

int main(){

    int choice = 0;
    while(choice != 9){
        printf("\n*********Singly Linked List*********\n");
        printf("\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list...\n");
        printf("\n==================================================\n");
    
        printf("\n1. Insert in beginning\n 2. Insert at last\n 3. Insert at any random location\n 4. Delete from Beginning\n 5. Delete from last\n 6. Delete node after specified location\n 7. Search for an element\n 8. Show\n 9. Exit\n");
        printf("\nEnter your choice\n");
        scanf("\n%d", &choice);
        switch(choice){
            case 1:
                beginInsert();
                break;
            case 2:
                lastInsert();
                break;
            case 3:
                randomInsert();
                break;
            case 4:
                begin_delete();
                break;
            case 5:
                last_delete();
                break;
            case 6:
                random_delete();
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
                break;
        }
    }
    


    return 0;
}

void beginInsert(){
    struct node *ptr; // buat var node sementara
    int item; 
    ptr = (struct node*)malloc(sizeof(struct node*));
    if(ptr == NULL){ // jika memori yang di alokasikan null, error
        printf("\nOverflow");
    }
    else { // selain itu
        printf("\nEnter Value\n"); // masukkan value
        scanf("%d", &item);
        ptr->data = item; // value dimasukkan ke ptr->data
        ptr->next = head; // next dari ptr adalah head
        head = ptr; // head adalah pointer itu sendiri
        printf("\nNode inserted\n");
    }
}

void lastInsert(){
    struct node *ptr, *temp; // variabel sementara
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("\nOverflow");
    }
    else {
        printf("\nEnter Value\n"); // masukkan data
        scanf("%d", &item);
        ptr->data = item;
        if(head == NULL){ // jika head adalah null
            ptr->next = NULL; // next nya null
            head = ptr; // head adalah si ptr
            printf("\nNode inserted\n");
        }
        else { // jika sudah ada
            temp = head; // head dimasukkan ke temp
            while(temp->next != NULL){ // selama nextnya bukan null
                temp = temp->next; // berjalan terus
            }
            temp->next = ptr; // jika nextnya sudah null, maka nextnya menunjuk data baru
            ptr->next = NULL; // next dari ptr adalah null sebagai node terakhiir
            printf("\nNode inserted\n");
        }
    }
}

void randomInsert(){
    int i, loc, item;
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("\nOverflow");
    }
    else {
        printf("\nEnter element value : "); // nilai dimasukkan
        scanf("%d", &item);
        ptr->data = item; 
        printf("\nEnter the location after which you want to insert");
        scanf("%d", &loc); // masukkan lokasi mana yang ingin node dimasukkan
        temp = head; // head dimasukkan ke temp
        for(i = 0; i < loc; i++){ // selama i kurang dari lokasi yang diinginkan
            temp = temp->next; // berjalan terus ke node selanjutnya
            if(temp == NULL){ // jika temp menyimpan null
                printf("\nCan't insert\n"); // return
                return;
            }
        }
        ptr->next = temp->next; // jika bukan null, ini dijalankan, pointer yang baru menunjuk yang sebelumnya ditunjuk temp
        temp->next = ptr; // temp menunjuk ptr
        printf("\nNode inserted\n");
    }
}

void begin_delete(){
    struct node *ptr;
    if(head ==  NULL){
        printf("\nList is empty\n");
    }
    else {
        ptr = head; // head dimasukkan ke ptr
        head  = ptr->next; // nilai head sekarang adalah node selanjutnya
        free(ptr); // node sebelumnya dibebaskan
        printf("\nNode deleted from the beginning\n");
    }
}

void last_delete(){
    struct node *ptr, *ptr1;
    if(head == NULL){
        printf("\nlist is empty...\n");
    }
    else if(head->next == NULL){ // jika selanjutnya dari head adalah null, alias hanya ada 1 data, bebaskan memorinya
        head = NULL;
        free(head);
        printf("\nOnly node of the list deleted...\n");
    }
    else { // jika lebih dari 1
        ptr = head; // masukkan head ke ptr
        while(ptr->next != NULL){ // selama node selanjutnya bukan null
            ptr1 = ptr; // masukkan ptr ke ptr1
            ptr = ptr->next; // lanjutkan node
        }
        ptr1->next = NULL; // hapus akses ke node terakhir
        free(ptr); // bebaskan memori node terakhir
        printf("\nDelete node from the last...\n");
    }
}

void random_delete(){
    struct node *ptr, *ptr1;
    int loc, i;
    printf("\nEnter the location of the node after which you want to perform deletion\n"); // masukkan lokasi yang akan di hapus
    scanf("%d", &loc);
    ptr = head; // head dimasukkan ke ptr
    for(i = 0; i < loc; i++){ // selama i kurang dari loc
        ptr1 = ptr; // masukkan ptr ke ptr1
        ptr = ptr->next; // lanjutlan node
        if(ptr == NULL){ // jika ptr adalah null
            printf("\nCan't delete");
            return 0; // berhenti
        }
    }
    ptr1->next = ptr->next; // jika ptr bukan null, ini berjalan, lalu node sebelumnya dibuat menunjuk ke next nya node yang akan di hapus
    free(ptr); // hapus node
    printf("\nDeleted node %d", loc + 1);
}

void search(){
    struct node *ptr;
    int item, i = 0, flag;
    ptr = head; // head dimasukkan ke ptr
    if(ptr == NULL){ // jika ptr menyimpan null
        printf("\nEmpty list...\n");
    }
    else { // selain null
        printf("\nEnter item which you want to search?\n");
        scanf("%d", &item); // masukkan data yang ingin di cari
        while(ptr != NULL){ // selama ptr bukan menyimpan null
            if(ptr->data == item){ // jika data yang disimpan ptr sama dengan item
                printf("item found at location %d", i + 1); // tunjukkan lokasi 
                flag = 0; // flag ditetapkan 0
            }
            else { // jika tidak sama, flag ditetapkan satu
                flag = 1;
            }
            i++;
            ptr = ptr->next; // lanjutkan node
        }
        if(flag == 1){ // jika flag 1, tampilkan tidak ditemukan
            printf("Item not found\n");
        }
    }
}

void display(){
    struct node *ptr;
    ptr = head;
    if(ptr == NULL){
        printf("Nothing to print");
    }
    else {
        printf("\nPrinting values...\n");
        while(ptr != NULL){
            printf("%d", ptr->data);
            ptr = ptr->next;
        }
    }
}