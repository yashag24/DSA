#include <stdio.h>
int main()
{
    int n;
    printf("Enter the no. of rows: ");
    scanf("%d", &n);
    int nsp = n;
    int nst = 1;
    char c = 'A';
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        for (int j = 1; j < nsp; j++)
        {

            printf(" ");
        }

        for (int k = 1; k <= nst; k++)
        {

            if (k == 1 || k == nst)
            {
                printf("%c", c);
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
        if (i < n)
        {
            nsp--;
            nst += 2;
            c++;
        }
        else
        {
            nsp++;
            nst -= 2;
            c--;
        }
    }
    return 0;
}