/* Nama file  : queue-data-mhs.c
Pembuat       : M. Ilham 23343008
Tgl pembuatan : 13 Maret 2024*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 30

struct Mahasiswa {
    char nama[MAXCHAR];
    char nim[MAXCHAR];
    char prodi[MAXCHAR];
    struct Mahasiswa *next;
};

struct Mahasiswa *front, *rear;
void enque();
void deque();
void clear();
void print();
void check();

int main(){

    int pilihan;
    while(pilihan != 6){
        printf("PROGRAM QUEUE DATA MAHASISWA\n");
        printf(" MENU UTAMA : \n");
        printf("   [1]. Enque\n");
        printf("   [2]. Deque\n");
        printf("   [3]. Clear\n");
        printf("   [4]. Print\n");
        printf("   [5]. Cek Antrian\n");
        printf("   [6]. Exit\n");
        printf("\nPilihan Anda ?");
        scanf("%d", &pilihan);
        switch(pilihan){
            case 1:
                enque();
                break;
            case 2:
                deque();
                break;
            case 3:
                clear();
                break;
            case 4:
                print();
                break;
            case 5:
                check();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Tidak Valid");
        }
    }
    return 0;
}

void removeNewLine(char *string){
    int len = strcspn(string, "\n");
    string[len] = '\0';
}

void enque(){
    struct Mahasiswa *newMahasiswa;
    newMahasiswa = (struct Mahasiswa *)malloc(sizeof(struct Mahasiswa));
    printf("Masukkan Nama  : ");
    getchar();
    fgets(newMahasiswa->nama, sizeof(newMahasiswa->nama), stdin);
    removeNewLine(newMahasiswa->nama);

    printf("Masukkan NIM   : ");
    fgets(newMahasiswa->nim, sizeof(newMahasiswa->nim), stdin);
    
    removeNewLine(newMahasiswa->nim);
    
    printf("Masukkan Prodi : ");
    fgets(newMahasiswa->prodi, sizeof(newMahasiswa->prodi), stdin);
    removeNewLine(newMahasiswa->prodi);
    
    newMahasiswa->next = NULL;

    if(newMahasiswa == NULL){
        printf("\nOverflow\n");
        return;
    }
    else {
        if(front == NULL){
            front = newMahasiswa;
            rear = front;
        }
        else {
            rear->next = newMahasiswa;
            rear = newMahasiswa;
        }
    }
    printf("Data berhasil ditambahkan ke dalam antrian\n");
}

void deque(){
    struct Mahasiswa *del;
    del = front;
    front = front->next;
    free(del);
}

void clear(){
    struct Mahasiswa *del, *temp;
    temp = front;
    while(temp != NULL){
        del = temp;
        temp = temp->next;
        free(del);
    }
    front = rear = NULL;
    printf("Semua data berhasil d hapus\n");
}

void print(){
    struct Mahasiswa *temp;
    int index = 0;
    temp = front;
    if(temp == NULL){
        printf("Empty\n");
        return;
    }
    while(temp != NULL){
        printf("Data ke-%d : %s ---> NIM : %s ---> Prodi : %s\n", ++index, temp->nama, temp->nim, temp->prodi);
        temp = temp->next;
    }

}

void check(){
    struct Mahasiswa *temp;
    int indexInput, antrian = 1, isFound = 0;
    printf("Check value at-");
    scanf("%d", &indexInput);

    temp = front;
    while(temp != NULL){
        if(indexInput == antrian){
            printf("Data ke-%d : %s ---> NIM : %s ---> Prodi : %s\n", antrian, temp->nama, temp->nim, temp->prodi);
            return;
        }
        antrian++;
        temp = temp->next;
    }
    if(!isFound) printf("Data tidak ada\n");

}
