#include<stdio.h>
int binarysearch(int a[],int size,int element){
int low=0,high=size-1,mid;
while(low<=high){
    mid=(low+high)/2; 
if(a[mid]==element){
    return mid;
}
else if(a[mid]<element){

    low = mid+1;
}
else{
    high=mid-1;
}
}

}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int m=binarysearch(arr,10,7);
    printf("at %d index",m);
    return 0;
}