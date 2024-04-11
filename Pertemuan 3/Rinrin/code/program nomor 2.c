/*
    Nama file : program nomor 2
    Pembuat: Rindhiani Putri
    Tanggal Pembuatan: 23 Februari 2024
    Deskripsi: Perbaiki kesalahan pada program
*/

#include <stdio.h>

int main() {
    /*
    Program yang salah : 
    int *ptr;
    int k;
    k = 7;

    printf("Isi variabel k\t: %d", K);
    printf("\nAlamat variabel k\t: %d", &k);
    printf("\nAlamat variabe *ptr\t: %d", &ptr);
    printf("\nIsi variabel *ptr\t: %d", *ptr);

    ptr = &k;
    printf("\nAlamat variabe *ptr\t: %f", &ptr);
    printf("\nIsi variabel *ptr\t: %f", ptr);
    printf("\nIsi dari alamat %d\t: %f", ptr, *ptr);
    printf("\n");

    */

    //Program yang sudah diperbaiki:
    int *ptr;
    int k = 7; // Inisialisasi k saat deklarasi
    
    printf("Isi variabel k\t: %d", k);
    printf("\nAlamat variabel k\t: %p", (void*)&k); // Menggunakan cast ke (void*)
    printf("\nAlamat variabel ptr\t: %p", (void*)&ptr); // Menggunakan cast ke (void*)

    ptr = &k;
    printf("\nAlamat variabel ptr\t: %p", (void*)&ptr); // Menggunakan cast ke (void*)
    printf("\nIsi variabel ptr\t: %p", (void*)ptr); // Menggunakan cast ke (void*)
    printf("\nIsi dari alamat %p\t: %d", (void*)ptr, *ptr);

    printf("\n");

    return 0;
}
