#include <stdio.h>
int main()
{
    int n;
    printf("Enter the no. of rows:");
    scanf("%d", &n);
    int nsp = n - 1;
    int nst = 1;
    for (int i = 1; i < n; i++)
    {

        for (int j = 1; j <= nsp; j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++)
        {
            if (k == 1 || k == 2 * i - 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
        nsp--;
    }
    for (int p = 1; p <= 2 * n - 1; p++)
    {
        printf("*");
    }
    return 0;
}
