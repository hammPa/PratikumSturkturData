/* Nama File: Tugas Jobsheet 3
    Pembuat: Rindhiani Putri (23343017)
    Tanggal Pembuatan: 28 Februari 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 20

struct node
{
    int AlbumNumber;
    char albumName[MAXCHAR];
    char date[MAXCHAR];
    struct node *next;
};

struct node *head;

void printAlbum();
void addAtBeginning();
void addAtEnd();
void deleteFromBeginning();
void deleteFromEnd();

int main()
{
    int choice = 0;
    while (choice != 6)
    {
        printf("\n***** Album Simulation *****\n");
        printf("\n***** Main Menu *****\n");
        printf("\nChoose one option from the following list...\n");
        printf("\n============================================\n");
        printf("1. Print Album\n");
        printf("2. Add Album at Beginning\n");
        printf("3. Add Album at End\n");
        printf("4. Delete Album from Beginning\n");
        printf("5. Delete Album from End\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printAlbum();
            break;
        case 2:
            addAtBeginning();
            break;
        case 3:
            addAtEnd();
            break;
        case 4:
            deleteFromBeginning();
            break;
        case 5:
            deleteFromEnd();
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please enter a number between 1 to 6.\n");
        }
    }
    return 0;
}

void printAlbum()
{
    struct node *temp = head;
    if (temp == NULL)
    {
        printf("Album masih kosong.\n");
        return;
    }
    printf("\nAlbum Contents:\n");
    while (temp != NULL)
    {
        printf("Nomor Album: %d\n", temp->AlbumNumber);
        printf("Judul Album: %s\n", temp->albumName);
        printf("Tanggal Album: %s\n", temp->date);
        printf("\n");
        temp = temp->next;
    }
}

void addAtBeginning()
{
    struct node *newAlbum = (struct node *)malloc(sizeof(struct node));
    if (newAlbum == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Masukkan Nomor Album: ");
    scanf("%d", &newAlbum->AlbumNumber);
    printf("Masukkan Judul Album: ");
    scanf(" "); 
    scanf("%[^\n]s", newAlbum->albumName); 
    printf("Masukkan Tanggal Album: ");
    scanf(" "); 
    scanf("%[^\n]s", newAlbum->date); 
    newAlbum->next = head;
    head = newAlbum;
    printf("Lagu ditambahkan ke awal album.\n");
}

void addAtEnd()
{
    struct node *newAlbum = (struct node *)malloc(sizeof(struct node));
    if (newAlbum == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Masukkan Nomor Album: ");
    scanf("%d", &newAlbum->AlbumNumber);
    printf("Masukkan Judul Album: ");
    scanf(" ");  
    scanf("%[^\n]s", newAlbum->albumName); 
    printf("Masukkan Tanggal Album: ");
    scanf(" "); 
    scanf("%[^\n]s", newAlbum->date); 
    newAlbum->next = NULL;
    if (head == NULL)
    {
        head = newAlbum;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newAlbum;
    }
    printf("Lagu ditambahkan ke akhir album.\n");
}

void deleteFromBeginning()
{
    if (head == NULL)
    {
        printf("Album kosong.Tidak ada yang perlu dihapus.\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    printf("Lagu dihapus dari awal album.\n");
}

void deleteFromEnd()
{
    if (head == NULL)
    {
        printf("Album kosong.Tidak ada yang perlu dihapus.\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("Lagu terakhir dihapus dari album.\n");
        return;
    }
    struct node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Lagu terakhir dihapus dari album.\n");
}
