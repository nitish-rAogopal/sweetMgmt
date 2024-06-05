#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int view_menu();
FILE *openFile(FILE *);
typedef struct
{
    int s_id;
    char s_name[50];
    float rate;
    float quantity;
} SWEETS;

int main()
{
    return 0;
}
int view_menu()
{
    FILE *f;
    SWEETS swt;
    long int recsize = sizeof(swt);
    f = openFile(f);
    if (f)
    {
        char s1[] = "s_id";
        char s2[] = "sweet_name";
        char s3[] = "rate";
        char s4[] = "quantity";
        printf("\n%5s %15s %10s %10s", s1, s2, s3, s4);
        while (fread(&swt, recsize, 1, f) == 1)
        {
            fflush(stdout);
            printf("\n%5d %15s %10.2f %15.2f", swt.s_id, swt.s_name, swt.rate, swt.quantity);
        }
    }
    else
    {
        printf("\nSweets not available!");
    }
}
FILE *openFile(FILE *f)
{
    f = fopen("SWEET.DAT", "rb+");
    if (f == NULL)
    {
        printf("File can't open");
        return NULL;
    }
    else
        return f;
}