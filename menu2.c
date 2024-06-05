#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "admin_curd.c"
extern SWEETS swt;
extern char swt_name[40];
extern char another;
extern long int recsize;
void make_order();
void view()
{
    printf("view");
    char s1[] = "s_id";
    char s2[] = "sweet_name";
    char s3[] = "rate";
    char s4[] = "quantity";
    printf("\n%5s %15s %10s %15s", s1, s2, s3, s4);
    rewind(fp);
    while (fread(&swt, recsize, 1, fp) == 1)
        printf("\n%5d %15s %10.2f %15.2f", swt.s_id, swt.s_name, swt.rate, swt.quantity);
}

void make_order()
{
    typedef struct
    {
        char sweets_name[50];
        float quantity;
    } ORDER_SWEETS;

    int no_var_sweets, i;
    printf("\nHow many variety sweets do you want: ");
    scanf("%d", &no_var_sweets);
    ORDER_SWEETS *order;
    order = (ORDER_SWEETS *)calloc(no_var_sweets, sizeof(ORDER_SWEETS));
    printf("Enter name of sweets and quantity:");
    for (i = 0; i < no_var_sweets; i++)
    {
        gets((order + i)->sweets_name);
        fflush(stdin);
        scanf("%f", &(order + i)->quantity);
    }
    char s2[] = "sweet_name";
    char s3[] = "rate";
    char s4[] = "quantity";
    char s5[] = "ammount";
    float rate;
    printf("\n%5s %15s %10s %10s", s2, s4, s3, s5);
    for (i = 0; i < no_var_sweets; i++)
    {
        rewind(fp);
        while (fread(&swt, recsize, 1, fp) == 1)
        {
            if (strcmp(swt.s_name, (order + i)->sweets_name) == 0)
            {
                rate = swt.rate;
            }
        }
        printf("\n%5s %15.2f %10.2f %10.2f", (order + i)->sweets_name, (order + i)->quantity,
               rate, (order + i)->quantity * rate);
    }
    free(order);
    order = NULL;
}