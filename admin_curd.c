#include <conio.h>
#include <stdlib.h>
#include "log_in.c"
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
long int recsize;
int admin()
{
    if (log_in())
    {
        fp = fopen("SWEET.DAT", "rb+");
        if (fp == NULL)
        {
            fp = fopen("SWEET.DAT", "wb+");
            if (fp == NULL)
            {
                puts("Cannot open file");
                // exit(1);
            }
        }
        recsize = sizeof(swt);
        int x = 1; // for reverting control from admin to user(basically for back)
        while (x)
        {
            printf("\n1. Add new sweet to list");
            printf("\n2. View sweets list");
            printf("\n3. Modify sweet rate");
            printf("\n4. Delete sweet from list:");
            printf("\n5. Quit");
            printf("\nMake your choice:");
            int s_choice;
            scanf("%d", &s_choice);
            switch (s_choice)
            {
            case 1:
                printf("add");
                fseek(fp, 0, SEEK_END);
                another = 'Y';
                while (another == 'Y')
                {
                    printf("\nEnter sweet_Id, sweet_Name, Rate and Quantity ");
                    scanf("%d", &swt.s_id);
                    fflush(stdin);
                    gets(swt.s_name);
                    fflush(stdin);
                    scanf("%f", &swt.rate);
                    fflush(stdin);
                    scanf("%f", &swt.quantity);
                    fflush(stdin);
                    fwrite(&swt, recsize, 1, fp);
                    printf("\nAdd another Record (Y/N) ");
                    fflush(stdin);
                    another = getche();
                }
                break;
            case 2:
                printf("view");
                char s1[] = "s_id";
                char s2[] = "sweet_name";
                char s3[] = "(rs/kg)rate";
                char s4[] = "(kg)quantity";
                printf("\n%10s %15s %16s %20s", s1, s2, s3, s4);
                rewind(fp);
                while (fread(&swt, recsize, 1, fp) == 1)
                    printf("\n%10d %15s %14.2f %19.2f", swt.s_id, swt.s_name, swt.rate, swt.quantity);
                getch();
                break;
            case 3:
                printf("modify");
                another = 'Y';
                while (another == 'Y')
                {
                    printf("\nEnter name of sweet to modify ");
                    scanf("%s", swt_name);
                    rewind(fp);
                    while (fread(&swt, recsize, 1, fp) == 1)
                    {
                        if (strcmp(swt.s_name, swt_name) == 0)
                        {
                            printf("\nEnter new sweet_Id, sweet_Name, Rate and Quantity ");
                            // scanf("%d %s %f %f", &swt.s_id, swt.s_name, &swt.rate, &swt.quantity);
                            scanf("%d", &swt.s_id);
                            fflush(stdin);
                            gets(swt.s_name);
                            fflush(stdin);
                            scanf("%f", &swt.rate);
                            fflush(stdin);
                            scanf("%f", &swt.quantity);
                            fflush(stdin);
                            fseek(fp, -recsize, SEEK_CUR);
                            fwrite(&swt, recsize, 1, fp);
                            break;
                        }
                    }
                    printf("\nModify another Record (Y/N) ");
                    fflush(stdin);
                    another = getche();
                }
                break;
            case 4:
                another = 'Y';
                while (another == 'Y')
                {
                    printf("\nEnter name of sweet to delete ");
                    scanf("%s", swt_name);
                    ft = fopen("TEMP.DAT", "wb");
                    rewind(fp);
                    while (fread(&swt, recsize, 1, fp) == 1)
                    {
                        if (strcmp(swt.s_name, swt_name) != 0)
                            fwrite(&swt, recsize, 1, ft);
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("SWEET.DAT");
                    rename("TEMP.DAT", "SWEET.DAT");
                    fp = fopen("SWEET.DAT", "rb+");
                    printf("Delete another Record (Y/N) ");
                    fflush(stdin);
                    another = getche();
                }
                break;
            case 5:
                x = 0;
                fclose(fp);
                break;
            default:
                printf("\nOperation not allowed!");
            }
        }
    }
    else
    {
        printf("\nIncorrect Password!");
        char x;
        printf("\nDo you want to retry? [Y/N]");
        x = getche();
        if (x == 'Y' || x == 'y')
            x = log_in();
        else
            return 0;
    }
}