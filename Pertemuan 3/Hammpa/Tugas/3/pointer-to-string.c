/*
    Pembuat : M. Ilham
    NIM : 23343008
    Tgl. 23 Februari 2024
    Nama File : pointer-to-string.c
*/

#include <stdio.h>

int main(){

    char kalimat[] = "Pendidikan Teknik Informatika";
    char *ptr = kalimat;
    printf("Kalimat : ");
    while(*ptr != '\0'){
        printf("%c", *ptr);
        ptr++;
    }
    printf("\n");


    return 0;
}
