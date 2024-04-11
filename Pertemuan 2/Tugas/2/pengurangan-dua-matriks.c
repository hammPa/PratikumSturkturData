/*
    23343008 - M. Ilham
    Tgl. 12 Februari 2024
    pengurangan-dua-matriks.c
*/

#include <stdio.h>

int main(){
    
    int matriks[2][2] = {};
    
    int matriks2[2][2] = {};
    int hasilKurang[2][2];
    int i, j;

    printf("Masukkan matriks pertama : \n");
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            scanf("%d", &matriks[i][j]);
        }
    }

    printf("Masukkan matriks kedua : \n");
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            scanf("%d", &matriks2[i][j]);
        }
    }

    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            hasilKurang[i][j] = matriks[i][j] - matriks2[i][j];
        }
    }
    
    printf("Hasil pengurangan matriks1 dan matriks2 adalah :\n");
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            printf("%d ", hasilKurang[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
