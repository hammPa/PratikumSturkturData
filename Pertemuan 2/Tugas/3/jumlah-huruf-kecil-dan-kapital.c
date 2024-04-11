/*
    23343008 - M. Ilham
    Tgl. 12 Februari 2024
    jumlah-huruf-kecil-dan-kapital.c
*/

#include <stdio.h>

int main(){
    
    char input1[30];
    int jumlahHurufKecil = 0, jumlahHurufKapital = 0;
    int temp;
    int i;

    printf("Masukkan input :");
    gets(input1);
    
    for(i = 0; i < sizeof(input1)/sizeof(char); i++){
        if(input1[i] == '\0'){
            break;
        }
        temp = (int)input1[i];
        if(temp >= 65 && temp <= 90) jumlahHurufKapital++;
        if(temp >= 97 && temp <= 122) jumlahHurufKecil++;
    }
    
    printf("Jumlah huruf kapital pada teks %s adalah %d\n", input1, jumlahHurufKapital);
    printf("Jumlah huruf kecil pada teks %s adalah %d\n", input1, jumlahHurufKecil);
    
    return 0;
}