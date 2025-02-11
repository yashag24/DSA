#include<stdio.h>
int main(){
printf("Enter the number of lines: ");
int n;
scanf("%d",&n);
for(int i=n;i>=1;i--){
    for(int k = 1;i<n && k<=n-i;k++ ){
        printf(" ");
    }
for (int j=1;j<=2*i-1;j++){


printf("*");
}
printf("\n");

}


}