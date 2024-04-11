/* Nama file  : pointer2
Pembuat       : Rindhiani Putri
Tgl pembuatan : 23 February 2024
Deskripsi : Menukarkan isi 2 string dengan fasilitas pointer
*/

#include <stdio.h>
#include <string.h>

char *nama1 = "TEKNIK";
char *nama2 = "INFORMATIKA";

main(){

    char *namax;
    puts("OLD: ");
    printf("Nama 1 : %s\n", nama1); // Pointer yang menunjuk ke string TEKNIK
    printf("Nama 2 : %s\n", nama2); // Pointer yang menunjuk ke string INFORMATIKA

    namax = nama1;
    nama1 = nama2;
    nama2 = namax;
    puts("NEW: ");
    printf("Nama 1 : %s\n", nama1); 
    printf("Nama 2 : %s\n", nama2); 

    return 0;
}