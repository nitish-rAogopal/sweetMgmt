#include <stdio.h>
#include <string.h>

int log_in()
{
    FILE *f;
    char pwd[100];
    char in_pwd[100];
    f = fopen("PASSWORD.DAT", "r");
    if (f == NULL)
        printf("Cannot open file");
    fgets(pwd, 100, f);
    fclose(f);
    printf("\nEnter password :");
    fflush(stdin);
    gets(in_pwd);
    if (!strcmp(pwd, in_pwd))
        return 1;
    else
        return 0;
}