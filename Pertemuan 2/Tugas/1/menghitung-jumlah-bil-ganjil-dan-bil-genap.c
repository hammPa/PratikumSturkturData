/*
    23343008 - M. Ilham
    Tgl. 12 Februari 2024
    menghitung-jumlah-bil-ganjil-dan-bil-genap.c
*/

#include <stdio.h>

int main() {

    int array[] ={1,2,3,4,5,6,7,8,9, 10};
    int indexGenap = 0, indexGanjil = 0;
    int genap[sizeof(array)/sizeof(int)];
    int ganjil[sizeof(array)/sizeof(int)];
    int i;

    for(i = 0; i<sizeof(array)/sizeof(int); i++){
        if(array[i] % 2 == 0){
            genap[indexGenap] = array[i];
            indexGenap++;
        }
        else {
            ganjil[indexGanjil] = array[i];
            indexGanjil++;
        }
    }
    
    printf("Genap : ");
    for(i = 0; i < indexGenap; i++){
        printf("%d ", genap[i]);
    }
    printf("\nJumlah : %d\n", indexGenap);
    
    printf("Ganjil : ");
    for(i = 0; i < indexGanjil; i++){
        printf("%d ", ganjil[i]);
    }
    printf("\nJumlah : %d", indexGanjil);


    return 0;
}