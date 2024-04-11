/* Nama file  : pointer2
Pembuat       : Rindhiani Putri
Tgl pembuatan : 23 February 2024
Deskripsi : Menampilkan nilai pada pointer to pointer
*/

#include <stdio.h>

main(){

    int var_x = 273;    
    int *ptr1;
    int **ptr2;

    ptr1 = &var_x;
    ptr2 = &ptr1;

    printf("Nilai var_x : %d\n", *ptr1);
    printf("Nilai var_x : %d\n", **ptr2);

    return 0;
}

