/*
    Nama file : struct data lagu
    Pembuat: Rindhiani Putri
    Tanggal Pembuatan: 23 Februari 2024
    Deskripsi: Buatlah struct untuk data lagu
*/

#include <stdio.h>
#include <string.h>

#define MAX_LAGU 20

typedef struct {
    char judul[100];
    char penyanyi[50];
    int tahun_produksi;
    int nomor_track;
    char kode_album[20];
} Lagu;

typedef struct {
    char kode[10];
    char judul[100]; // Tambahkan judul lagu dalam struktur KodeRBT
} KodeRBT;

void tampilkanJudulProgram() {
    printf("\t\t ======================================\n");
    printf("\t\t PROGRAM BAHASA C TENTANG DATA LAGU\n" );
    printf("\t\t Create by: Rindhiani Putri\n");
    printf("\t\t Departemen Teknik Elektronika\n");
    printf("\t\t ======================================\n");
}

void pilihData(int *pilihan) {
    printf("MENU: \n");
    printf("1. Input Data Lagu\n");
    printf("2. Tampilkan Semua Lagu\n");
    printf("3. Keluar\n\n");

    printf("Pilihan: ");
    scanf("%d", pilihan);
}

void inputLagu(Lagu lagu[], int *jumlahLagu) {
    if (*jumlahLagu < MAX_LAGU) {
        printf("Judul Lagu: ");
        getchar(); 
        fgets(lagu[*jumlahLagu].judul, sizeof(lagu[*jumlahLagu].judul), stdin);

        printf("Penyanyi: ");
        fgets(lagu[*jumlahLagu].penyanyi, sizeof(lagu[*jumlahLagu].penyanyi), stdin);

        printf("Tahun Produksi: ");
        scanf("%d", &lagu[*jumlahLagu].tahun_produksi);

        printf("Nomor Track: ");
        scanf("%d", &lagu[*jumlahLagu].nomor_track);

        printf("Kode Album: ");
        getchar(); 
        fgets(lagu[*jumlahLagu].kode_album, sizeof(lagu[*jumlahLagu].kode_album), stdin);

        (*jumlahLagu)++;
    } else {
        printf("Jumlah Lagu Telah Mencapai Batas Maksimum\n");
    }
}

void tampilkanSemuaLagu(Lagu lagu[], int jumlahLagu) {
	int i;
    for (i = 0; i < jumlahLagu; i++) {
        printf("Judul: %s", lagu[i].judul);
        printf("Penyanyi: %s", lagu[i].penyanyi);
        printf("Tahun Produksi: %d\n", lagu[i].tahun_produksi);
        printf("Nomor Track: %d\n", lagu[i].nomor_track);
        printf("Kode Album: %s", lagu[i].kode_album);
        printf("\n");
    }
}

int main() {
    Lagu lagu[MAX_LAGU];
    KodeRBT kodeRBT[MAX_LAGU];
    int jumlahLagu = 0;
    int jumlahKodeRBT = 0;
    int pilihan;
    tampilkanJudulProgram();
    int ulang = 1;

    do {
        pilihData(&pilihan);

        switch (pilihan) {
            case 1:
                inputLagu(lagu, &jumlahLagu);
                printf("Masukkan Kode RBT: ");
                getchar(); 
                fgets(kodeRBT[jumlahKodeRBT].kode, sizeof(kodeRBT[jumlahKodeRBT].kode), stdin);
                strcpy(kodeRBT[jumlahKodeRBT].judul, lagu[jumlahLagu - 1].judul);
                jumlahKodeRBT++;
                break;

            case 2:
                tampilkanSemuaLagu(lagu, jumlahLagu);
                break;

            case 3:
                ulang = 0;
                break;

            default:
                printf("Pilihan tidak valid\n");
                break;
        }

    } while (ulang);
    
    return 0;
}
