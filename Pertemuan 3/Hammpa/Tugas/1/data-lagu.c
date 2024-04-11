/*
    Pembuat : M. Ilham
    NIM : 23343008
    Tgl. 23 Februari 2024
    Nama File : data-lagu.c
*/

#include <stdio.h>
#define MAX 20
#define MAXCHAR 30
int indexNow = 0;


struct KodeRbt {
    char kodeLagu[MAX];
};

struct Lagu {
    char judul[MAX];
    char penyanyi[MAX];
    int tahunProduksi, nomorTrack;
    char kodeAlbum[MAX];
};

void inputKodeRBT(struct KodeRbt code[], struct Lagu songs[]){
    printf("Masukkan kode lagu ke-%d (%s): ", indexNow+1, songs[indexNow].judul);
    fgets(code[indexNow].kodeLagu, MAXCHAR, stdin);
}

void inputLagu(struct Lagu songs[], struct KodeRbt code[]){
    int jumlah;
    printf("Masukkan berapa data yang akan dimasukkan : ");
    scanf("%d", &jumlah);
    while(getchar() != '\n');

    if(indexNow + jumlah > 20){
        puts("Ukuran melebihi batas (20 data)\n");
        return;
    }

    int i = 0;
    while(i < jumlah){
        printf("Masukkan judul lagu : ");
        fgets(songs[indexNow].judul, MAXCHAR, stdin);
        // getchar();
        // while(getchar()!='\n');

        printf("Masukkan penyanyi : ");
        fgets(songs[indexNow].penyanyi, MAXCHAR, stdin);
        printf("Masukkan tahun produksi lagu : ");
        scanf("%d", &songs[indexNow].tahunProduksi);
        printf("Masukkan nomor track : ");
        scanf("%d", &songs[indexNow].nomorTrack);
        printf("Masukkan kode album : ");
        getchar();
        fgets(songs[indexNow].kodeAlbum, MAXCHAR, stdin);
        inputKodeRBT(code, songs);
        indexNow++;
        i++;
    }
}

void display(struct Lagu *songs, struct KodeRbt *code, int nomor){
    printf("\nJudul lagu ke-%d : %s", nomor, songs->judul);
    printf("Penyanyi lagu ke-%d : %s", nomor, songs->penyanyi);
    printf("Tahun produksi lagu ke-%d : %d\n", nomor, songs->tahunProduksi);
    printf("Nomor Track lagu ke-%d : %d\n", nomor, songs->nomorTrack);
    printf("Kode Album lagu ke-%d : %s", nomor, songs->kodeAlbum);
    printf("Kode RBT lagu ke-%d : %s", nomor, code->kodeLagu);
}

int main(){
    
    struct Lagu songs[MAX];
    struct KodeRbt code[MAX];

    int pilihan;
    int run = 1;
    int i;
    do {
        puts("Pilihan : ");
        puts("1. Input Lagu");
        puts("2. Tampilkan Lagu");
        puts("3. Keluar");
        printf("Masukkan pilihan anda : ");
        scanf("%d", &pilihan);
        fflush(stdin);
        switch(pilihan){
            case 1: 
                inputLagu(songs, code);
                break;
            case 2:
                i = 0;
                while(i < indexNow){
                    display(&songs[i], &code[i], i);
                    i++;
                }
                break;
            case 3: run = 0;
                break;
            default: puts("Pilihan tidak tersedia\n");
                break;
        }
    }while (run);
    

    
    return 0;
}
