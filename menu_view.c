#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
void make_order();
int count_rec = 0;
typedef struct
{
    int s_id;
    char s_name[50];
    float rate;
    float quantity;
} SWEETS;
FILE *fp, *ft;
SWEETS swt;
char swt_name[40];
char another;
long int recsize = sizeof(swt);
void view()
{
    fp = fopen("SWEET.DAT", "rb+");
    if (fp == NULL)
    {
        fp = fopen("SWEET.DAT", "wb+");
        if (fp == NULL)
            printf("Cannot open file");
    }
    char s1[] = "s_id";
    char s2[] = "sweet_name";
    char s3[] = "(rs/kg)rate";
    char s4[] = "quantity";
    printf("\n%10s %20s %20s", s1, s2, s3);
    rewind(fp);
    while (fread(&swt, recsize, 1, fp) == 1)
    {
        fflush(stdout);
        printf("\n%10d %20s %18.2f", swt.s_id, swt.s_name, swt.rate);
        count_rec++;
    }
    make_order(count_rec);
}

void make_order(int count_rec)
{
    typedef struct
    {
        int id;
        char sweets_name[50];
        float rate;
        float quantity;
        float ammount;
    } ORDER_SWEETS;
    int no_var_sweets = 0, i;
    ORDER_SWEETS order[count_rec];
    printf("\nHow many variety sweets do you want: ");
    scanf("%d", &no_var_sweets);
    fflush(stdin);
    printf("Enter name of sweets and quantity:");
    for (i = 0; i < no_var_sweets; i++)
    {
        printf("\nmake %d order ", (i + 1));
        order[i].id = (i + 1);
        gets(order[i].sweets_name);
        fflush(stdin);
        order[i].rate = 0;
        scanf("%f", &order[i].quantity);
        order[i].ammount = 0;
        fflush(stdin);
    }
    char s1[] = "s_no";
    char s2[] = "sweet_name";
    char s3[] = "(rs/kg)rate";
    char s4[] = "(kg)quantity";
    char s5[] = "(rs)ammount";
    printf("\n%10s %20s %20s %20s %20s", s1, s2, s4, s3, s5);
    float total = 0;
    char s6[] = "(rs)Total:";
    for (i = 0; i < no_var_sweets; i++)
    {
        rewind(fp);
        while (fread(&swt, recsize, 1, fp) == 1)
        {
            if (strcmp(swt.s_name, order[i].sweets_name) == 0)
            {
                if (order[i].quantity <= swt.quantity)
                {
                    order[i].rate = swt.rate;
                    order[i].ammount = order[i].rate * order[i].quantity;
                    total += order[i].ammount;
                    swt.quantity = swt.quantity - order[i].quantity;
                    fseek(fp, -recsize, SEEK_CUR);
                    fwrite(&swt, recsize, 1, fp);
                    break;
                }
                else
                {
                    printf("Max order quantity can be : %0.2f", swt.quantity);
                    printf("\n1. retry");
                    printf("\n2. exit");
                    int x = getche();
                    switch (x)
                    {
                    case 1:
                        make_order(count_rec);
                        break;
                    case 2:
                        exit(1);
                    default:
                        printf("\nInvalid choice");
                    }
                }
            }
        }
        printf("\n%10d %20s %17.2f %19.2f %22.2f", (i + 1), order[i].sweets_name,
               order[i].quantity, order[i].rate, order[i].ammount);
    }
    printf("\n%73s", s6);
    printf("%19.2f", total);
    fclose(fp);
}