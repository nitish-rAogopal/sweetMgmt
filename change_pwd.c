#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
int setResetPassword()
{
    FILE *f_sec;      // pointers to security answer file
    FILE *f_ans;      // pointers to security question file & security answer file
    char secQ[100];   // string for security question
    char c;           // for navigating character of security file
    int count = 0;    // for counting character of security question
    char answer[100]; // string for answer to security question

    // password file
    FILE *f;
    f = fopen("PASSWORD.DAT", "w");
    if (f == NULL)
        printf("Cannot open file");

    // security answer file
    {
        f_ans = fopen("ANSWER.DAT", "ab+");
        if (f_ans == NULL)
            printf("Cannot open file");
    }

    // security question file
    {
        f_sec = fopen("SECURITY.DAT", "ab+");
        if (f_sec == NULL)
            printf("Cannot open file");
    }

    // checking whether the security question available or not
    {
        for (c = getc(f_sec); c != EOF; c = getc(f_sec))
            count += 1;
    }
    rewind(f_sec); // moving the pointer to begining of security file

    if (count > 0)
    {
        {
            fgets(secQ, 100, f_sec);
            printf("\n");
            puts(secQ);
        }
        // verification of security answer
        {
            char temp[100];
            printf("\nEnter your answer:");
            fflush(stdin);
            gets(temp);
            fflush(stdin);
            fgets(answer, 100, f_ans);
            if (!strcmp(temp, answer))
            {
                char tpwd[100];
                printf("\nEnter your new password:");
                gets(tpwd);
                printf("\nPassword is changed successfully!");
                fclose(f_ans);
                fputs(tpwd, f);
                fclose(f);
                // puts(tpwd); // testing
                return 1;
            }
            else
            {
                char x;
                printf("\nDo you want to retry? [Y/N]");
                x = getche();
                if (x == 'Y' || x == 'y')
                    x = setResetPassword();
                else
                    return 0;
            }
        }
    }
    else // 0: if security question is not set
    {
        printf("\nWelcome!");
        printf("\nIt's your very first time %c", 1);
        {
            printf("\nEnter the security question:");
            fflush(stdin);
            gets(secQ);
            fflush(stdin);
            fputs(secQ, f_sec);
        }

        {
            printf("\nEnter the answer of security question:");
            gets(answer);
            fputs(answer, f_ans);
            fclose(f_ans);
            {
                char tpwd[100];
                printf("\nEnter your password:");
                gets(tpwd);
                printf("\nPassword is saved successfully!");
                fclose(f_ans);
                fputs(tpwd, f);
                fclose(f);
                // puts(tpwd); // testing
                return 1;
            }
        }
        fclose(f_sec);
    }
    fclose(f_sec);

    return 1;
}