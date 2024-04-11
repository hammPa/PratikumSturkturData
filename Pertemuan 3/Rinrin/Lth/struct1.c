/* Nama file  : struct1 
Pembuat       : Rindhiani Putri
Tgl pembuatan : 23 February 2024
*/

#include <stdio.h>

struct mahasiswa {
    char nim[25];
    char nama[25];
    int usia;
};

struct matakuliah {
    char namamk[25];
    int semester;
    int sks;
};

void main(){
    struct mahasiswa mhs1 = {"1700001", "Ari Andana", 18}; // jika berdasarkan nama identifier pada struct, maka :
    struct matakuliah mk1 = {"Struktur Data", 2, 2};

    // tampilkan data mahasiswa
    printf("NIM\t\t: %s\n", mhs1.nim); // tetap
    printf("Nama Mahasiswa\t: %s\n", mhs1.nama); // ubah mhs1.nama_mhs menjadi mhs1.nama
    printf("Usia Mahasiswa\t: %d\n\n\n", mhs1.usia); // ubah %s menjadi %d dan ubah mhs.usia menjadi mhs1.usia

    // tampilkan data matakuliah
    printf("Mata Kuliah\t: %s\n", mk1.namamk); // ubah mk1.nama_mk menjadi mk1.namamk
    printf("Semester\t: %d\n", mk1.semester); // tetap
    printf("SKS\t\t: %d\n\n\n", mk1.sks); // ubah mk1.ipk menjadi mk1.sks
}
