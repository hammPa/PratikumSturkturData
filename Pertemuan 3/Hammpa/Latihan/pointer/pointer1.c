/* Nama file  : pointer1 
Pembuat       : M. Ilham 
Tgl pembuatan : 23 February 2024
*/

#include <stdio.h>

int main(){

    int x = 87, y; // x dan y berupa int
    int *px; // var ptr yang menunjuk data bertipe int

    px = &x; // px di isi dengan alamat dari variabel x
    y = *px; // y disi dengan nilai yg ditunjuk oleh px

    printf("Alamat x    = %p\n", &x);
    printf("Isi px      = %p\n", px);
    printf("Isi x       = %d\n", x);
    printf("Nilai yang ditunjuk oleh px = %d\n", *px);
    printf("Nilai y     = %d\n", *px);


    return 0;
}