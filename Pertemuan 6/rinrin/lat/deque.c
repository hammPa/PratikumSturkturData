/* Nama file : implementasi deque
   Pembuat   : Rindhiani Putri
   Tanggal pembuatan : 13 Maret 2024
*/

#include<stdio.h>
#define size 5
int deque[size];
int f=-1, r=-1;

void insert_front(int x) {
    if((f==0 && r==size-1) || (f==r+1))
    {
        printf("Overflow");
    }
    else if ((f==-1) && (r==-1))
    {
        f=r=0;
        deque[f]=x;
    }
    else if(f==0)
    {
        f=size-1;
        deque[f]=x;
    }
    else
    {
        f = (f - 1 + size) % size; // menggunakan modulus untuk memperbarui nilai f
        deque[f]=x;
    }
}

void insert_rear(int x) {
    if((f==0 && r==size-1) || (f==r+1))
    {
        printf("Overflow");
    }
    else if ((f==-1) && (r==-1))
    {
        r=0;
        deque[r]=x;
    }
    else if(r==size-1)
    {
        r=0;
        deque[r]=x;
    }
    else
    {
        r=(r+1)%size; // menggunakan modulus untuk memperbarui nilai r
        deque[r]=x;
    }
}

void display() {
    int i=f;
    printf("\nElements in a deque are: ");

    while(i!=r)
    {
        printf("%d ",deque[i]); // menambahkan spasi setelah setiap elemen
        i=(i+1)%size; // menggunakan modulus untuk traversal deque
    }
    printf("%d ",deque[r]); // menambahkan spasi setelah setiap elemen
}

void getfront() {
    if((f== -1) && (r== -1))
    {
        printf("Deque is empty: ");
    }
    else
    {
        printf("\nThe value of the element at front is: %d",deque[f]);      
    }
}

void getrear() {
    if((f==-1) && (r==-1))
    {
        printf("Deque is empty");
    }
    else
    {
        printf("\nThe value of the element at rear is %d",deque[r]);
    }
}

void delete_front() {
    if((f==-1) && (r==-1))
    {
        printf("Deque is empty");
    }
    else if( f==r)
    {
        printf("\nThe deleted element is %d",deque[f]);
        f=-1;
        r=-1;
    }
    else
    {
        printf("\nThe deleted element is %d",deque[f]);
        f=(f+1)%size; // menggunakan modulus untuk memperbarui nilai f
    }
}

void delete_rear() {
    if((f==-1) && (r==-1))
    {
        printf("Deque is empty");
    }
    else if( f==r)
    {
        printf("\nThe deleted element is %d",deque[r]);
        f=-1;
        r=-1;
    }
    else
    {
        printf("\nThe deleted element is %d",deque[r]);
        r=(r-1+size)%size; // menggunakan modulus untuk memperbarui nilai r
    }
}

int main() {
    printf("\n========Implementation Deque=======\n");
    printf("\n=====================================");
        insert_front(20);
        insert_front(10);
        insert_rear(30);
        insert_rear(50);
        insert_rear(80);
        display();
        getfront();
        getrear();
        delete_front();
        delete_rear();
        display();
        return 0;
}






