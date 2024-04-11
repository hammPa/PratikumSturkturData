#include <stdio.h>

int main(){

    // int *ptr;
    // int k;
    // k = 7;

    // printf("Isi variabel k\t: %d", K);
    // printf("\nAlamat variabel k\t: %d", &k);
    // printf("\nAlamat variabe *ptr\t: %d", &ptr);
    // printf("\nIsi variabel *ptr\t: %d", *ptr);

    // ptr = &k;
    // printf("\nAlamat variabe *ptr\t: %f", &ptr);
    // printf("\nIsi variabel *ptr\t: %f", ptr);
    // printf("\nIsi dari alamat %d\t: %f", ptr, *ptr);
    // printf("\n");


    // yang salah : 
    int *ptr;
    int k;
    k = 7;

    printf("Isi variabel k\t: %d", k); // ubah variabel K ke k
    printf("\nAlamat variabel k\t: %p", &k); // ubah format specifier %d ke %p
    printf("\nAlamat variabe *ptr\t: %p", &ptr); // ubah format specifier %d ke %p
    // printf("\nIsi variabel *ptr\t: %d", *ptr);  // baris ini dihapus karena pada saat ini, ptr masih berupa wild pointer

    ptr = &k;
    printf("\n\nAlamat variabe *ptr\t: %p", &ptr); // ubah format specifier %f ke %p
    printf("\nIsi variabel *ptr\t: %p", ptr); // ubah format specifier %f ke %p
    printf("\nIsi dari alamat %p\t: %d", ptr, *ptr); // ubah format specifier %d ke %p dan %f ke %d
    printf("\n");
    

    return 0;
}