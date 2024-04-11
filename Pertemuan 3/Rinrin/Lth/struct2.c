/* Nama file  : struct1 
Pembuat       : Rindhiani Putri
Tgl pembuatan : 23 February 2024
*/

#include <stdio.h>

struct human {
    char nama[25];
    int usia;
};

struct pegawai {
    char nip[7];
    char jabatan[20];
    struct human manusia;
};

int main(void){

    // berdasarkan identifier pada struct, maka yang perlu di perbaiki adalah 
    struct pegawai seseorang = {"010110", "Programmer", {"Abdul Kadir", 22}}; // menambahkan \" pada sebelum huruf P pada programmmer

    printf("Pegawai dengan NIP: %s \nJabatan: %s\nBernama: %s (%d tahun)\n",seseorang.nip, seseorang.jabatan,seseorang.manusia.nama,seseorang.manusia.usia);

    // mengubah nip menjadi %s
    // mengubah seseorang.manusia.umur menjadi seseorang.manusia.usia

    return 0;
}
