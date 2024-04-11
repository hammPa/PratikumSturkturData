/* Nama file  : polindrom 
Pembuat       : M. Ilham 23343008
Tgl pembuatan : 26 February 2024*/

#include <stdio.h>
#include <string.h>

#define MAXSTACK 100
#define MAXCOLUMN 30
char stack[MAXSTACK][MAXCOLUMN];
int top = -1;

void check(){
    int i, j;
    int isPolyndrome = 1;
    int length = strlen(stack[top]);
    for(i = 0, j = length - 1; i < j; i++, j--){
        if(stack[top][i] != stack[top][j]){
            isPolyndrome = 0;
            break;
        }
    }
    if(!isPolyndrome) printf("Kalimat tersebut bukan polyndrom\n");
	else printf("Kalimat tersebut adalah polyndrom\n");
}

void push(char kalimat[]){
    if(top == MAXSTACK) puts("Penuh");
    else {
        if (kalimat[strlen(kalimat) - 1] == '\n')
            kalimat[strlen(kalimat) - 1] = '\0';
        ++top;
        strcpy(stack[top], kalimat);
    }
}

int main(){

	char kalimat[MAXCOLUMN];
	char run;

    do {
		printf("\nSelamat datang di program menentukan kalimat polyndrom dengan stack\n");
    	printf("Masukkan kalimat : ");
    	fgets(kalimat, sizeof(kalimat), stdin);
    	push(kalimat);
		check();
		printf("Ulang ? y/n : ");
		scanf("%c", &run);
		getchar();
	} while(run == 'y' || run == 'Y');
	
    return 0;
}
