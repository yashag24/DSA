#include <stdio.h>
int main()
{
    int n;
    printf("enter the no of rows: ");
    scanf("%d", &n);
    int nsp = 1;
    int nst = n - 1;
    for (int l = 1; l <= 2 * n - 1; l++)
    {
        printf(" * ");
    }
    printf("\n");

    for (int i = nst; i > 0; i--)
    {

        for (int j = 1; j <= nsp; j++)
        {
            printf("   ");
        }

        for (int k = 1; k <= 2 * i - 1; k++)
        {
            if (k == 1 || k == 2 * i - 1)
                printf(" * ");
            else
                printf("   ");
        }
        printf("\n");
        nsp++;
    }
}