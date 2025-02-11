#include <stdio.h>
int main()
{
    int n;
    printf("Enter the no.:");
    scanf("%d", &n);
    int nsp = n - 1;
   
    for (int i = 1; i <= n; i++)
    {
         int m = i;
        for (int j = 1; j <= nsp; j++)
        {

            printf("   ");
        }
        for (int k = 1; k <=i; k++)
        {
            printf(" %d ", m);
m++;
            
        }
        m--;
        m--;
        for (int l=1;l<i;l++){

printf(" %d ", m);
m--;

        }
        printf("\n");
        nsp--;
    }
    return 0;
}