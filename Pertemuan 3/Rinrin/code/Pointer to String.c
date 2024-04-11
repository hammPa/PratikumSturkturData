/*
    Nama file : Pointer to String
    Pembuat: Rindhiani Putri
    Tanggal Pembuatan: 23 Februari 2024
    Deskripsi: Program untuk menampilkan sebaris string 
*/

#include <stdio.h>

int main() {
  
    char kalimat[] = "Rindhiani Putri dari jurusan teknik informatika";

    char *ptr = kalimat;

    printf("Kalimat yang ditampilkan: ");
    while (*ptr != '\0') {
        printf("%c", *ptr);
        ptr++; 
	}
    printf("\n");

    return 0;
}
