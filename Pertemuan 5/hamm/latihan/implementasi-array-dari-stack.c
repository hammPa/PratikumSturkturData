/* Nama file  : implementasi array dari stack 
Pembuat       : M. Ilham 23343008
Tgl pembuatan : 26 February 2024*/

#include <stdio.h>

int stack[100], i, j, choice = 0, n, top = -1;
void push();
void pop();
void show();


int main(){

    int choice = 0;
    printf("*********Stack operations using array*********\n");
    printf("\n**************************************************");
    printf("\nEnter the number of elements in the stack : ");
    scanf("%d", &n);
    printf("\n--------------------------------------------------");
    while(choice != 4){
        printf("\n\nChoose one from the below options...\n");
        printf("\n 1. Push\n 2. Pop\n 3. Show\n 4. Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                show();
                break;
            case 4:
                printf("Exiting...");
                break;
            default:
                printf("Please Enter valid choice");
                break;
        }
    }
    return 0;
}

void push(){
    int val;
    if(top == n - 1){
        printf("\nOverflow");
    }
    else {
        printf("Enter the value?");
        scanf("%d", &val);
        top = top + 1;
        stack[top] = val;
    }
}
void pop(){
    if(top == -1){
        printf("Underflow");
    }
    else {
        top = top - 1;
    }
}
void show(){
    for(i = top; i >= 0; i--){
        printf("%d\n", stack[i]);
    }
    if(top == -1){
        printf("Stack is empty");
    }
}
