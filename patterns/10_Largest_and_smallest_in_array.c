#include <stdio.h>
int largest(int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("largest is %d",max);
}
int smallest(int brr[], int size)
{
    int min = brr[0];
    for (int i = 0; i < size; i++)
    {
        if (brr[i] < min)
        {
            min = brr[i];
        }
    }
    printf("\nsmallest is %d",min);
}
int main(){
    int a[]={45,65,8,6,1,3,53,5,3554,9,456,85};
    int size= sizeof a/sizeof a[0];
    largest(a,size);
    smallest(a,size);
}