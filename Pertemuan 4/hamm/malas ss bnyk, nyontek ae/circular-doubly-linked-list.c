/* Nama File: Circular Doubly Linked List
    Pembuat: M.ilham (23343008)
    Tanggal Pembuatan: 28 Februari 2024
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    struct node *next;
    int data;
};

struct node *head = NULL;

void insertion_beginning();
void insertion_last();
void deletion_beginning();
void deletion_last();
void display();
void search();

int main()
{
    int choice = 0;
    while (choice != 7)
    {
        printf("\n*****Circular Doubly Linked List*****\n");
        printf("\n*****Main Menu *****\n");
        printf("\nChoose one option from the following list... \n");
        printf("=====================================\n");
        printf("\n1.Insert in beginning\n2.Insert at last\n3.Delete from beginning\n4.Delete from last\n5.Search\n6.Show\n7.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            insertion_beginning();
            break;

        case 2:
            insertion_last();
            break;

        case 3:
            deletion_beginning();
            break;

        case 4:
            deletion_last();
            break;

        case 5:
            search();
            break;

        case 6:
            display();
            break;

        case 7:
            exit(0);
            break;

        default:
            printf("Please enter valid choice..\n");
        }
    }
}

void insertion_beginning()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter Item Value\n");
        scanf("%d", &item);

        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
            ptr->prev = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            head->prev = ptr;
            ptr->next = head;
            head = ptr;
        }
        printf("\nNode inserted\n");
    }
}

void insertion_last()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter Value?\n");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
            ptr->prev = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            head->prev = ptr;
            ptr->next = head;
        }
        printf("\nNode inserted");
    }
}

void deletion_beginning()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL;
        printf("\nNode deleted\n");
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        head->next->prev = temp;
        free(head);
        head = temp->next;
    }
}

void deletion_last()
{
    struct node *ptr, *preptr;
    if (head == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL;
        printf("\nNode deleted\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        ptr->next->prev = preptr;
        free(ptr);
        printf("\nNode deleted");
    }
}

void display()
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("\nNothing to print");
    }
    else
    {
        printf("\nPrinting values...\n");
        do
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
    }
}

void search()
{
    struct node *ptr;
    int item, flag = 0, i = 0;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search?\n ");
        scanf("%d", &item);
        do
        {
            if (ptr->data == item)
            {
                printf("Item found at location %d\n", i + 1);
                flag = 1;
                break;
            }
            i++;
            ptr = ptr->next;
        } while (ptr != head);
        if (flag == 0)
        {
            printf("Item not found\n");
        }
    }
}
