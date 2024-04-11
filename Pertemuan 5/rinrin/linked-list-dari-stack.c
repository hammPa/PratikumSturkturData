/* Nama File: implementasi linked list dari stack
   Pembuat : Rindhiani Putri (23343017)
   Tanggal Pembuatan: 4 Maret 2024
*/

#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();

struct node
{
    int val;
    struct node *next;   
};
struct node *head = NULL; 

int main () {
    int choice = 0;
    printf("\n********Stack operations using linked list********\n");
    printf("\n--------------------------------------------------\n");
    while (choice != 4)
    {
        printf("\nChoose one from the below options...\n");
        printf("\n1.Push \n2.Pop \n3.Show \n4.Exit");
        scanf("%d",&choice);
        switch (choice)
        {
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
            printf("Exiting...\n");
            break;
        default:
            printf("Please enter valid choice\n");
        }
    }
    return 0;
}

void push() {
    int val;
    printf("Enter the value: ");
    scanf("%d", &val);
    struct node *ptr = (struct node*) malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("Not able to push the element, stack is full.\n");
    }
    else 
    {
        ptr->val = val;
        ptr->next = head;
        head = ptr;
        printf("Item pushed\n");
    }
}

void pop () {
    int item;
    struct node *ptr;
    if (head == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        item = head->val;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Item popped\n");
    }   
}

void display () {
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Printing stack elements:\n");
        while(ptr != NULL)
        {
            printf("%d\n", ptr->val);
            ptr = ptr->next;
        }
    } 
}
