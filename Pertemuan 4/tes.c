#include <stdio.h>
#include <stdbool.h>
struct Node {
    int data[4];
    long data2;
};

int main(){

    printf("%d", sizeof(struct Node));
    printf("\n");
    printf("%d", sizeof(struct Node*));

    return 0;
}