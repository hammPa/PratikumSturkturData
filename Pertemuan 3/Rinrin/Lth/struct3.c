/* Nama file  : struct3 
Pembuat       : Rindhiani Putri
Tgl pembuatan : 23 February 2024
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char tipe[5];
    int masaUji;
}machine;

typedef struct{
    char model[15];
    char warna[10];
    char bahanBakar[15];
    machine mesin;
}moto;


void tampilInfo(moto);
void gantiBahanBakar(moto *);

int main(void){

    moto mx = {"Jupiter MX", "Merah", "Pertamax", {"DOHC", 5}};
    tampilInfo(mx);
    gantiBahanBakar(&mx);
    tampilInfo(mx);
    return 0;
}

void tampilInfo(moto items){
    puts("Moto Info");
    puts("====================");
    printf("Model: %s (%s) \nBahan Bakar: %s \nTipe Mesin: %s \nMasa Uji Mesin: %d (tahun) \n", items.model, items.warna, items.bahanBakar, items.mesin.tipe, items.mesin.masaUji);
    puts("====================");
}

void gantiBahanBakar(moto *items){
    printf("Bahan bakar motor saat ini : %s\n", items->bahanBakar);
    printf("Ketikkan bahan bakar yang ingin digunakan : ");
    fgets((*items).bahanBakar, 15, stdin);
    items->bahanBakar[strlen(items->bahanBakar) - 1] = '\0';
}

// tidak ada kesalahan
