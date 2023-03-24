
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5
#define MAX_STACK 10

struct STACK
{
    char top;
    char data[MAX_STACK][50];
}tumpuk;

void inisialisasi()
{
    tumpuk.top = -1;
}

int IsFull()
{
    if(tumpuk.top == MAX_STACK) return 1; else return 0;
}

int IsEmpty()
{
    if (tumpuk.top == -1) return 1; else return 0;
}

void Push(char item[MAX_STACK])
{
    tumpuk.top++;
    strcpy(tumpuk.data[tumpuk.top],item);
}


void Pop()
{
    printf("Data yang diambil = %s\n", tumpuk.data[tumpuk.top]);
    tumpuk.top--;
}

void Clear()
{
    tumpuk.top=-1;
}

void TampilStack()
{
    for(int i=tumpuk.top; i>=0; i--){
        printf("Data Stack ke %d: %s\n", i, tumpuk.data[i]);
    }
}

struct antrian{
    int front;
    int rear;
    int data[MAX];
}q;

void inisialisasi2()
{
    q.front = -1;
    q.rear = -1;
}

int IsFull2()
{
    if(q.rear==MAX-1) return 1;
    else return 0;
}

int IsEmpty2()
{
    if(q.rear==-1) return 1;
    else
        return 0;
}

void enqueue(int item)
{
    fflush(stdin);
    if(IsEmpty2()==1){
        q.front=q.rear=0;
        q.data[q.rear]=item;
        printf("%d masuk\n", q.data[q.rear]);
    }
    else{
        if(IsFull()==0){
            q.rear++;
            q.data[q.rear]=item;
            printf("%d masuk\n", q.data[q.rear]);
        }
    }
}

void Dequeue()
{
    int i;
    int j = q.data[q.front];
    printf("Data yang keluar : %d", j);
    for(i=q.front; i<=q.rear-1; i++)
    {
        q.data[i] = q.data[i+1];
    }
    q.rear--;
}

void Clear2()
{
    q.front = -1;
    q.rear = -1;
    printf("Data sudah dibersihkan!");
}

void TampilQueue()
{
    if(IsEmpty2()==0)
    {
        for(int i=q.front; i<=q.rear; i++)
        {
            printf("Data ke %d = %d\n", i, q.data[i]);
        }
    }
    else printf("Data kosong!\n");
}

void print_menu(char head[100], char menu[10][100], int jumlah, int pilihan)
{
    fflush(stdin);
    printf("\n\n===========================\n");
    printf("%s\n", head);
    printf("===========================\n");
    int i;
    for (i = 1; i <= jumlah; i++)
    {
        if (pilihan == i)
        {
            printf("==> ");
        }
        else
        {
            printf("    ");
        }
        printf("%d. %s \n", i, menu[i - 1]);
    }
    printf("===========================\n");
}


void stackstring()
{
    fflush(stdin);
    int menu;
    char item[50];
    inisialisasi();
    do{
        system("cls");
        fflush (stdin);
        printf("1. Push Stack\n");
        printf("2. Pop Stack\n");
        printf("3. Print Stack\n");
        printf("4. Delete Stack\n");
        printf("5. Return Main Menu\n");
        printf("Pilihan : ");
        scanf("%d",&menu);
        switch(menu)
        {
            case 1:{
            system("cls");
            fflush(stdin);
            if(IsFull()!=1)
            {
                printf("Data yang ingin diinput = ");
                scanf("%[^\n]%*c",&item);
                tumpuk.top++;
                strcpy(tumpuk.data[tumpuk.top],item);
                //Push(item);
            }
            else printf("\nSudah Penuh\n");
            printf ("Press any key to continue .  .  .");

            break;
            }

            case 2:{
            system("cls");
                if(IsEmpty()!=1)
                {
                    Pop();
                }
            else
            printf("\nMasih kosong!\n");
            printf ("Press any key to continue .  .  .");

            break;
            }

            case 3:{
            system("cls");
            if(IsEmpty()!=1)
                {
                    TampilStack();
                }
            else printf("Masih kosong!\n");
            printf ("Press any key to continue .  .  .");

            break;
            }

            case 4:{
            system("cls");
            Clear();
            printf("Data sudah dihapus!\n");
            printf("Press any key to continue .  .  .");

            break;
            }

            case 5:main();break;
        }
        getch();
    } while(menu !=5);
    getch();
}

void quequestring()
{
    fflush (stdin);
    int menu, item;
    inisialisasi2();
    do{
        system("cls");
        fflush (stdin);
        printf("1. Enqueue Int\n");
        printf("2. Dequeue Int\n");
        printf("3. Print Queue\n");
        printf("4. Delete Queue\n");
        printf("5. Return Main Menu\n");
        printf("Pilihan : ");
        scanf("%d",&menu);
        switch(menu)
        {
            case 1:{
            system("cls");
            if(IsFull2()!=1)
                {
                    printf("Data = "); scanf("%d", &item);
                    enqueue(item);
                }
            else printf("\nSudah Penuh\n");
            printf ("Press any key to continue .  .  .");
            break;
            }

            case 2:{
            system("cls");
            if(IsEmpty2()!=1)
                {
                    Dequeue();
                }
            else
            printf("Tidak ada Data yang keluar");
            printf ("\nPress any key to continue .  .  .");
            break;
            }

            case 3:{
            system("cls");
            if(IsEmpty2()!=1)
                {
                    TampilQueue();
                }
            else printf("Tidak ada data dalam antrian!\n");
            printf ("Press any key to continue .  .  .");
            break;
            }

            case 4:{
            system("cls");
            Clear2();
            printf ("\nPress any key to continue .  .  .");
            break;
            }

            case 5:main();break;
        }
        getch();
    } while(menu !=5);
    getch();
}
//672022186

void definisistack()
{
    fflush(stdin);
    system("cls");
    puts("Stack, atau tumpukan, adalah salah satu proses penyimpanan dan pengambilan data");
    puts("yang menggunakan sistem penyimpanan LIFO, atau Last In First Out");
    puts("atau dalam bahasa diartikan sebagai Terakhir Masuk, Pertama Keluar");
    puts("Yang berarti Data yg masuk/disimpan terakhir, akan dikeluarkan pertama");
    puts("Stack adalah sebuah kumpulan data dimana data diletakkan di atas data yang lain");
    puts("Function PushUntuk menambahkan elemen ke dalam stack");
    puts("Function Pop Untuk menghapus elemen dari urutan terakhir / bagian atas stack");
    puts("IsEmpty Memeriksa apakah stack kosong, sedangkan IsFull: Memeriksa apakah stack penuh");
    printf ("Press any key to continue .  .  .");
    getch();
}

void definisiqueue()
{
    fflush (stdin);
    system("cls");
    puts("Queue, atau antrian, adalah salah satu proses penyimpanan dan pengambilan data");
    puts("yang menggunakan sistem penyimpanan FIFO, atau First In First Out");
    puts("atau dalam bahasa diartikan sebagai Pertama Masuk, Pertama Keluar");
    puts("Yang berarti Data yg masuk/disimpan pertama, akan dikeluarkan pertama");
    puts("Function Enqueue Berfungsi untuk menambahkan elemen ke akhir antrian");
    puts("Function Push Untuk menambahkan elemen ke dalam stack");
    puts("Function Dequeue Berfungsi untuk menghapus elemen dari depan antrian");
    puts("IsEmpty: Memeriksa apakah antrian kosong, sedangkan IsFull: Memeriksa apakah antrian penuh");
    printf ("Press any key to continue .  .  .");
    getch();
}


void main()
{
    fflush(stdin);
    system("COLOR F8");
    int pil = 1;
    char menu[5][100] = {"Stack String", "Queue Integer", "Penjelasan Stack", "Penjelasan Queue", "Exit Program"};
    int jumlah = 5;
    char j;
    while (1)
    {
        system("cls");
        print_menu("Tugas Quiz Stack and Queue", menu, jumlah, pil);
        j = getch();
        if(j == 72)
        {
            if (pil > 1)
            {
                pil--;
            }
        }
        else if (j == 80)
        {
            if (pil < 5)
            {
                pil++;
            }
        }
        else if (j == 13)
        {
            if (pil == 1)
            {
                stackstring();
            }
            else if (pil == 2)
            {
                quequestring();
            }
            else if (pil == 3)
            {
                definisistack();
            }
            else if (pil == 4)
            {
                definisiqueue();
            }
            else
            {
                system("cls");
                printf("Terima Kasih\n");
                printf("~Good Luck~");
                exit(0);
                return 1;
            }
        }
    }

    return 0;
}
