#include <stdlib.h>
#include "admin_curd.c"
#include "change_pwd.c"
int main()
{
    int ch, r = 1;
    while (r)
    {
        printf("\n1. Login");
        printf("\n2. Set/Reset Password");
        printf("\n3. Quit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            admin();
            break;
        case 2:
            r = setResetPassword();
            break;
        case 3:
            r = 0;
            break;

        default:
            break;
        }
    }
    return 0;
}