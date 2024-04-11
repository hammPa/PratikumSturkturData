/* Nama File: Singly Linked List
    Pembuat: Rindhiani Putri (23343017)
    Tanggal Pembuatan: 28 Februari 2024
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head;

void beginsert();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();

int main () {
    int choice = 0;
    while (choice != 9 )
    {
        printf("\n*****Singly Linked List*****\n");
        printf("\n*****Main Menu *****\n");
        printf("\nChoose one option from the following list... \n");
        printf("=====================================\n");
        printf("\n1.Insert in beginning \n2.Insert at last \n3.Insert at any random location\n4.Delete node from beginning \n5.Delete from last \n6.Delete node after specified location \n7.Search for an element \n8.Show \n9.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                beginsert();
                break;

            case 2:
                lastinsert();
                break;

            case 3:
                randominsert();
                break;

            case 4:
                begin_delete();
                break;

            case 5:
                last_delete();
                break;

            case 6:
                random_delete();
                break;

            case 7:
                search();
                break;
                
            case 8:
                display();
                break;

            case 9:
                exit(0);
                break;

            default:
                printf("Please enter a valid choice..\n");
        }
    }
}

void beginsert() {
    struct node *ptr;
    int item;
    ptr = (struct node *) malloc (sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW");
    } else {
        printf("\nEnter Value\n");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("\nNode Inserted");
    }
}

void lastinsert() {
    struct node *ptr, *temp;
    int item;
    ptr = (struct node*) malloc(sizeof(struct node));
    if(ptr == NULL) {
        printf("\nOVERFLOW");
    } else {
        printf("\nEnter Value?\n");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL) {
            ptr->next = NULL;
            head = ptr;
            printf ("\nNode inserted");
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            printf("\nNode inserted");   
        }
    }
}

void randominsert() {
    int i, loc, item;
    struct node *ptr, *temp;
    ptr = (struct node *) malloc (sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW");
    } else {
        printf("\nEnter element value: ");
        scanf("%d", &item);
        ptr->data = item;
        printf("\nEnter the location after which you want to insert: ");
        scanf("%d", &loc);
        temp = head;
        for (i = 0; i < loc; i++) {
            temp = temp->next;
            if(temp == NULL) {
                printf("\nCan't insert\n");
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("\nNode inserted");
    }
}

void begin_delete() {
    struct node *ptr;
    if (head == NULL) {
        printf("\nList is empty\n");
    } else {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\nNode deleted from the beginning...\n");
    }
}

void last_delete() {
    struct node *ptr, *ptrl;
    if (head == NULL) {
        printf("\nlist is empty");
    } else if (head->next == NULL) {
        head = NULL;
        free(head);
        printf ("\nOnly node of the list deleted...\n");
    } else {
        ptr = head;
        while (ptr->next != NULL) {
            ptrl = ptr;
            ptr = ptr->next ;
        }
        ptrl->next = NULL;
        free(ptr);
        printf ("\nDeleted node from the last..\n");
    }
}

void random_delete() {
    struct node *ptr, *ptrl;
    int loc, i;
    printf ("\nEnter the location of the node after which you want to perform deletion: ");
    scanf ("%d", &loc);
    ptr = head;
    for (i = 0; i < loc; i++) {
        ptrl = ptr;
        ptr = ptr->next;
        if (ptr == NULL) {
            printf ("\n Can't delete");
            return;
        }
    }
    ptrl->next = ptr->next;
    free(ptr);
    printf("\nDeleted node %d", loc + 1);
}

void search() {
    struct node *ptr;
    int item, i = 0, flag = 0;
    ptr = head;
    if (ptr == NULL) {
        printf ("\nEmpty List\n");
    } else {
        printf ("\nEnter item which you want to search: ");
        scanf("%d", &item);
        while (ptr != NULL) {
            if (ptr->data == item) {
                printf("Item found at location %d\n", i + 1);
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }
        if (flag == 0) {
            printf("Item not found\n");
        }
    }
}

void display() {
    struct node *ptr;
    ptr = head;
    if (ptr == NULL) {
        printf ("Nothing to print\n");
    } else {
        printf("\nPrinting values...\n");
        while (ptr != NULL) {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}
