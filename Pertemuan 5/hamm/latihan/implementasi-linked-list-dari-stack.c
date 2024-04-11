/* Nama File: implementasi linked list dari stack
   Pembuat : Rindhiani Putri (23343017)
   Tanggal Pembuatan: 4 Maret 2024
*/

#include <stdio.h>

void push();
void pop();
void display();

struct node {
    int val;
    struct node *next;
};

struct node *head;

int main(){

    int choice = 0;
    printf("*********Stack operations using linked list*********\n");
    printf("\n--------------------------------------------------");
    while(choice != 4){
        printf("\n\nChoose one from the below options...\n");
        printf("\n 1. Push\n 2. Pop\n 3. Show\n 4. Exit");
        printf("\nEnter your choice : \n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
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
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("just and only able to push the element");
    }
    else {
        printf("Enter the value : ");
        scanf("%d", &val);
        if(head == NULL){
            ptr->val = val;
            ptr->next = NULL;
            head = ptr;
        }
        else {
            ptr->val = val;
            ptr->next = head;
            head = ptr;
        }
        printf("Item pushed");
    }
}

void pop(){
    int item;
    struct node *ptr;
    if(head == NULL){
        printf("Underflow");
    }
    else {
        item = head->val;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Item popped");
    }
}

void display(){
    int i;
    struct node *ptr;
    ptr = head;
    if(ptr == NULL){
        printf("Stack if empty\n");
    }
    else {
        printf("Printing Stack elements\n");
        while(ptr != NULL){
            printf("%d\n", ptr->val);
            ptr = ptr->next;
        }
    }
}
