#include <stdio.h>
int main()
{
    int arr[] = {2, 5, 9, 4, 1, 3};
    int n = sizeof arr / sizeof arr[0];
    int min ;
    for (int i = 0; i < n; i++)
    {
        min=i;
        for(int k=i+1;k<n;k++){

        
        if (arr[k] < arr[min])
        {
            min = k;
        }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    for (int j = 0; j < n; j++)
    {
        printf("%d , ", arr[j]);
    }
    return 0;
}