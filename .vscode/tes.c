#include <stdio.h>

void hello(){
    printf("Hello\n");
}

int main(){

    void(*func)() = hello;
    func();

    printf(stdin);
    int temp;
    printf("Masukkan angka : ");
    scanf("%d", temp);
    fflush(stdin);
    printf(stdin);

    // char tempCh[20];
    // printf("Masukkan string : ");
    // fgets(temp, 20, stdin);

    printf(stdin);

    return 0;
}